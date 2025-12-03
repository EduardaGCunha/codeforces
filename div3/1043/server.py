# RASPBERRY PI PYTHON SERVER
# This script manages Serial communication with the Arduino and uploads data to REAL Firestore.

import serial
import time
import json
import uuid
from datetime import datetime

# --- IMPORTANT: Firebase and Firestore Imports ---
# Make sure you have installed 'firebase-admin' using pip
import firebase_admin
from firebase_admin import credentials, firestore
from google.cloud.firestore_v1.base_client import BaseClient
from google.cloud.firestore_v1.base_collection import BaseCollection

# --- Configuration ---
SERIAL_PORT = '/dev/ttyACM0'  # CHECK THIS! May be 'COM3' or '/dev/ttyUSB0'
BAUD_RATE = 9600
APP_ID = "claw-1cb4e" # MUST match the ID used in the Web Dashboard
KEY_FILE_PATH = "/home/eduarda/proj/services.json" # <--- YOUR KEY LOCATION

# Firebase Global Variables
db: BaseClient = None # Will be initialized later
games_collection: BaseCollection = None # The specific collection reference

def init_firebase():
    """Initializes Firebase Admin SDK using the downloaded service account key."""
    global db
    global games_collection
    
    try:
        # Load the Service Account Key
        cred = credentials.Certificate(KEY_FILE_PATH)
        
        # Initialize the app. If it's already initialized, this avoids error.
        if not firebase_admin._apps:
            firebase_admin.initialize_app(cred)
            print("[FIREBASE] App Initialized successfully.")
        
        db = firestore.client()
        
        # Define the exact collection path where the RPi will write data
        # /artifacts/{appId}/public/data/games
        games_collection = db.collection('artifacts').document(APP_ID).collection('public').document('data').collection('games')
        print(f"[FIREBASE] Data will be written to: {games_collection.path}")
        
    except FileNotFoundError:
        print(f"[ERROR] Service account key not found at: {KEY_FILE_PATH}")
        print("Please check the file path and security permissions.")
        db = None
    except Exception as e:
        print(f"[ERROR] Firebase initialization failed: {e}")
        db = None
        
def init_serial():
    """Initializes and returns the Serial connection."""
    try:
        ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
        time.sleep(2)  # Wait for the connection to establish
        print(f"Serial connection established on {SERIAL_PORT}")
        return ser
    except serial.SerialException as e:
        print(f"Error opening serial port {SERIAL_PORT}: {e}")
        print("Please check the port name and if the Arduino is connected.")
        return None

def upload_game_data(game_id):
    """Function to upload game data to Firestore."""
    if not games_collection:
        print("[DB] ERROR: Firestore collection not ready.")
        return
        
    try:
        # Create the document data
        new_game_data = {
            'gameId': game_id, # The timestamp ID provided by the Arduino
            'timestamp': firestore.SERVER_TIMESTAMP, # Use server timestamp for accuracy
            'method': 'Claw Machine Button', # Assumes all games started are from the machine's button
            'machineId': APP_ID,
            'logTime': datetime.now().isoformat()
        }
        
        # Add the document to the collection
        doc_ref = games_collection.add(new_game_data)
        print(f"[DB] New Game Uploaded to Firestore: Doc ID {doc_ref[1].id}")
        
    except Exception as e:
        print(f"[DB] ERROR uploading data to Firestore: {e}")
    
def send_credit_to_arduino(ser, count=1):
    """Sends a credit command to the Arduino."""
    command = f"CREDIT:{count}\n"
    if ser:
        try:
            ser.write(command.encode('utf-8'))
            print(f"[TX] Sent command: {command.strip()} (Simulating PIX Payment Success)")
        except serial.SerialTimeoutException:
            print("[ERROR] Serial write timeout.")
    else:
        print("[ERROR] Serial not initialized.")

def main_loop(ser):
    """Main loop for reading from Arduino and handling user input for PIX simulation."""
    print("\n--- Running Main Loop ---")
    print("Press 'p' + Enter to simulate a successful PIX Payment.")
    print("Press Ctrl+C to exit.")
    
    while True:
        # --- 1. Read Serial from Arduino ---
        if ser and ser.in_waiting > 0:
            try:
                line = ser.readline().decode('utf-8').strip()
                if line:
                    print(f"[RX] Received: {line}")

                    if line.startswith("GAME_START:"):
                        game_id = line.split(':')[1]
                        upload_game_data(game_id)
                        
            except Exception as e:
                print(f"[ERROR] Serial read/decode error: {e}")
        
        # --- 2. Simulate PIX Payment (User Input) ---
        # This blocks until input is received.
        if input(">> ").lower() == 'p':
            send_credit_to_arduino(ser, 1)
        
        time.sleep(0.01) # Small sleep to ensure responsiveness

if __name__ == "__main__":
    init_firebase() # Initialize Firebase first
    
    if db:
        ser = init_serial() # Then initialize Serial
        if ser:
            try:
                main_loop(ser)
            except KeyboardInterrupt:
                print("\nExiting program.")
            finally:
                if ser and ser.is_open:
                    ser.close()
                    print("Serial connection closed.")
        else:
            print("Cannot start main loop without serial connection.")
    else:
        print("Application cannot run because Firebase failed to initialize.")