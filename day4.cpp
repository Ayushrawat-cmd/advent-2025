#include<bits/stdc++.h>
using namespace std;
bool is_valid(int i, int j , int n , int m ){
    return i>=0 and j >=0 and i <n and j<m;
}
void solve(vector<string>&grid){
    int rows[] = {1,1,1,-1,-1,-1,0,0};
    int cols[] = {-1,0,1,-1,0,1,-1,1};
    int n = grid.size(), m =grid[0].size();
    long long ans = 0;
    for(int i = 0; i<n; i++){
        for(int j =0; j<m; j++){
            int count = 0;
            for(int idx = 0; idx<8; idx++){
                int new_i = i+rows[idx];
                int new_j = j+cols[idx];
                if(is_valid(new_i, new_j, n, m) and grid[new_i][new_j] == '@'){
                    count++;
                }

            }
            if(count <4 and grid[i][j] == '@'){
                cout<<i<<" "<<j<<endl;
                ans++;
            }
        }
    }
    cout<<ans<<endl;

}
int main(){
    string line;
    ifstream file("input.txt");
    long long ans = 0;
    vector<string>grid;
    if(file.is_open()){
        while(std::getline(file, line)){
            grid.push_back(line);
        }
    }

    solve(grid);
}