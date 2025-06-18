#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
I want to make both arrays SORTED
and also arr[i] has to be smaller than brr[i]
the operations I can make are 
swap arr[i] and arr[i]+1
swap brr[i] and brr[i]+1
swap arr[i] and brr[i]
the total number of operations cannot exceed 1709
why is this number relevant?

*/

void solve(){
	int n; cin >> n;
	int arr[n], brr[n];
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < n; i++) cin >> brr[i];

	vector<pair<int, int>> op;
	for(int i = 0; i < n; i++){
		if(arr[i] > brr[i]){
			op.push_back({3, i+1});
			swap(arr[i], brr[i]);
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			if(arr[j] > arr[j+1]){
				op.push_back({1, j+1});
				swap(arr[j], arr[j+1]);
			}
		}
	}


	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-1; j++){
			if(brr[j] > brr[j+1]){
				op.push_back({2, j+1});
				swap(brr[j], brr[j+1]);
			}
		}
	}

	cout << op.size() << endl;
	for(auto [a, b] : op){
		cout << a << " " << b << endl;
	}
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}