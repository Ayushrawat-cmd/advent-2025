#include<bits/stdc++.h>
using namespace std;
int main(){
    string line ;
    ifstream file("input.txt");
    long long ans = 0;
    if(file.is_open()){
        while(std::getline(file, line)){
            int i =0;
            int first = 0;
            int second = 0;
            int first_idx = -1;
            int second_idx=  -1;
            while(i<line.size()){
                if(line[i]-'0'>first and i<line.size()-1){
                    first =line[i]-'0';
                    first_idx = i;
                }
                else{
                    if(second_idx<first_idx or  ( second<line[i]-'0')){
                        second = line[i]-'0';
                        second_idx = i;

                    }
                }
                i++;
            }
            cout<<first*10+second<<endl;
            ans += first*10+second;
            
        }
        cout<<ans;
    }
    return 0;
}
