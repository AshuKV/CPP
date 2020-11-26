#include "bits/stdc++.h"
#define sz(x)       (int)x.size()
using namespace std;

void recur(string &s, vector<vector<bool>> &dp, int pos, vector<vector<string>> &res, vector<string> curr) 
{
    if (pos == sz(s)) 
    {
        res.push_back(curr);
        return;
    }
    for (int i = pos; i < sz(s); i++) 
    {
        if (dp[pos][i]) 
        {
            curr.push_back(s.substr(pos, i-pos+1));
            recur(s, dp, i+1, res, curr);
            curr.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    int len = s.size();
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    for (int j = 0; j < len; j++) 
    {
        for (int i = 0; i <= j; i++) 
        {
            if (tolower(s[i])==tolower(s[j]) && (j-i<=2 || dp[i+1][j-1])) 
            {
                dp[i][j] = true;
            }
        }
    }
    vector<vector<string>> res;
    recur(s, dp, 0, res, {});
    return res;
}
void solve(){
	string s;
	cin>>s;
	set<vector<string>> ans;
	vector<vector<string>> vec;
	vec = partition(s);
    for (int i = 0; i < sz(vec); ++i) 
    { 
    	vector<string> temp;
        for(int j = 0; j < sz(vec[i]); ++j) 
            temp.push_back(vec[i][j]);
        ans.insert(temp);
    } 
    for (auto i: vec)
    {
    	for(auto j:i)
    		cout << j << " ";
    	cout<<endl;
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
