#include<iostream>
#include<fstream>
#include<string>
using namespace std;
 long long solve(string & num, int i, int digits, vector<vector<long long>>&dp){
    if(digits == 0){
        return 0;
    }
    if(i == num.size()){
        return LLONG_MIN;
    }
    if(dp[i][digits] != -1){
        return dp[i][digits];
    }
     long long val = (num[i]-'0')*pow(10, digits-1); ;
    // cout<<i<<endl;
    // unsigned lon
    return dp[i][digits] = max(val+solve(num, i+1, digits-1,dp), solve(num, i+1, digits,dp));
}
int main(){
    string line ;
    ifstream file("input.txt");
      long long ans = 0;
    vector<string>nums;
    if(file.is_open()){
        while(std::getline(file, line)){
            nums.push_back(line);
        }
        // cout<<ans;
    }
    for(auto num: nums){
        vector<vector<long long>>dp(nums.size(), vector<long long>(13,-1));
         long long x = solve(num, 0, 12,dp);
        cout<<num<<" "<<x<<endl;
        // break;
        ans += x;

    }
    cout<<ans;
    return 0;
}
