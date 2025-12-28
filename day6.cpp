#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;
    ifstream file("input.txt");
    // long long ans = 0;
    vector<vector<int>>numbers;
    vector<char>operations;
    if(file.is_open()){
        while(std::getline(file, line)){
            // cout<<line<<endl;
            if(line[0] == '+' or line[0] == '*'){
                int i=0;
                while(i<line.size()){
                    if(line[i]!=' ')
                        operations.push_back(line[i]);
                    i++;
                }
            }
            else{
                int i=0;
                vector<int>temp;
                while(i<line.size()){
                    int num =0;
                    while(i<line.size() and line[i]!=' '){
                        num = num*10 + (line[i]-'0');
                        i++;
                    }
                    while (i<line.size() and line[i] == ' ')
                    {
                        i++;
                    }
                    // cout<<num<<endl;
                    // cout<<line<<endl;
                    temp.push_back(num);
                }
                numbers.push_back(move(temp));
            }

            // cout<<line<<endl;
        }

    }
    long long &&ans = 0;
    int n=numbers.size(), m = numbers[0].size();
    for(int j=0; j<m; j++){
        long long prod = 1;
        long long sum = 0;
        for(int i =0; i<n; i++){
            // cout<<numbers[i][j]<<" ";
            if(operations[j] == '+')
                sum += numbers[i][j]*1ll;
            else
                prod *= numbers[i][j]*1ll;
                
        }
        if(operations[j] == '+')
            ans += sum;
        else
            ans += prod;
        // cout<<sum<<" "<<prod<<endl;
        // ans += prod;
        // cout<<endl;
    }
    cout<<ans<<endl;
}