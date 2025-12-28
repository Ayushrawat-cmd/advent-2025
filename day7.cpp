#include<bits/stdc++.h>
using namespace std;
int main(){
    string line;
    vector<string>lines;
    ifstream file("input.txt");
    if(file.is_open()){
        while(std::getline(file, line)){
            lines.push_back(line);
        }
    }
    int start_col = 0;
    int m = lines[0].size();
    for(int j=0; j<m; j++){
        if(lines[0][j] == 'S'){
            start_col = j;
            break;
        }
    }
    lines[1][start_col] = '|';
    int ans =0;
    for(int i=2; i<lines.size(); i++){
        for(int j =0; j<m; j++){
            if(lines[i-1][j] == '|'){
                if(lines[i][j] == '^'){
                    lines[i][j-1]= '|';
                    lines[i][j+1] = '|';
                    ans ++;

                }
                else
                    lines[i][j] = '|';
            }
        }
    }
    for(auto i: lines){
        cout<<i<<endl;
    }
    cout<<ans<<endl;
}