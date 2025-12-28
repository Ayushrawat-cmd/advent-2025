#include<bits/stdc++.h>
using namespace std;
int main(){
    string line ;
    vector<string>ranges, fruits;
    ifstream file("input.txt");
    // map<long long,long long>fresh_fruits_map, fresh_fruits_map2;
    vector<pair<long long , long long>>fresh_fruits, fresh_fruits2;
    if(file.is_open()){
        while(std::getline(file, line) and line != ""){
            ranges.push_back(line);
        }
        while(std::getline(file, line)){
            fruits.push_back(line);
        }
        
    }
    // cout<<ranges[ranges.size()-1]<<" "<<fruits[0]<<" "<<frui2ts.size()<<endl;
    for(auto range : ranges){
        int i =0;
        long long first = 0;
        while(i<range.size() and range[i] != '-'){
            first= first*10 + range[i]-'0';
            i++;
        }
        long long second = 0;
        i++;
        while(i<range.size()){
            second = second*10 + range[i]-'0';
            i++;
        }
        fresh_fruits.push_back({first,second});
        fresh_fruits2.push_back({second,first});
        // cout<<first<<" "<<second<<endl;
        // fresh_fruits_map[first] = second;
        // fresh_fruits_map2[second] = first;
    }
    sort(fresh_fruits.begin(), fresh_fruits.end());
    sort(fresh_fruits2.begin(), fresh_fruits2.end());
    int ans = 0;
    // fresh_fruits_map.
    for(auto fruit : fruits){
        long long num = 0;
        for(int i = 0; i<fruit.size(); i++){
            num = num*10 + fruit[i]-'0';
        }
        // cout<<num<<endl;
        bool flag = false;
        for(auto it: fresh_fruits){
            if(  num-it.first>=0 and it.second - num>=0){
                // cout<<num<<" "<< it.first<<" "<<it.second<<endl;
                ans++;
                flag = true;
                break;
            }
        }
        // if(!flag){
        //     cout<<num<<endl;
        // }
        // auto lower_bound_val = std::make_pair(num, 0ll);

        // auto it  = lower_bound(fresh_fruits.begin(), fresh_fruits.end(), lower_bound_val);
        // auto it2 = upper_bound(fresh_fruits2.begin(), fresh_fruits2.end(), lower_bound_val);
        // bool flag = false;
        // while(it != fresh_fruits.end() and (it->first) <=num){
        //     if((it->second) >= num){
        //         ans++;
        //         flag = true;
        //         break;
        //     }
        //     ++it;
        // }
        // if(!flag){
        //     while( (it2->first) >=num){
        //         if((it2->second) <= num){
        //             flag = true;
        //             ans++;
        //             break;
        //         }
        //         if(it2 == fresh_fruits2.begin()){
        //             break;
        //         }
        //         --it2;
        //     }
            
        // }
    }
    cout<<ans<<endl;
}