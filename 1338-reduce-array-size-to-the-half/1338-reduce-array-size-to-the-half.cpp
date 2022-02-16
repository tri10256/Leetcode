class Solution {
public:
    int minSetSize(vector<int>& arr) {
	int n = arr.size();
	unordered_map<int,int> mp;
	for(int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}        
	priority_queue<int> pq;
	int count = n;
	int ans = 0;
	for(auto ele: mp) {
		pq.push(ele.second);
	}
	while(count > n/2) {
		int ele = pq.top();
		pq.pop();
		count -= ele;
		ans++;
	}
	return ans;
}

};