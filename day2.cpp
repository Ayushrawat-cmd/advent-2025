#include<iostream>
#include<fstream>
using namespace std;
unsigned long long invalid_ids(unsigned long long low, unsigned long long high){
    unsigned long long total = 0;
    while(low<=high){
        int i =0;
        string &&tmp = to_string(low);
        if(tmp.size()%2==0 and tmp.substr(0,tmp.size()/2)==tmp.substr(tmp.size()/2,tmp.size()/2)){
            // cout<<tmp<<endl;
            total+=low;
        }
        low++;
    }
    return total;
}

int main(){
    ifstream file("day2_input.txt");
    if(!file.is_open())   {
        cerr << "Error opening file" << endl;
        return 1;

    }
    // int total = 0;
    string line;
    // vector<pair<int,int>> v;
    unsigned long long ans = 0; 
    // ans +=invalid_ids(1,99999999999);
    while(getline(file, line)){ 
        int i =0;
        while(i<line.size()){
            unsigned long long left = 0;
            while(i<line.size() and line[i]!='-'){
                left = left*10+(line[i]-'0');
                i++;
            }
            i++;
            // cout<<left<<endl;
            unsigned long long right = 0;
            while(i<line.size() and line[i]!=','){
                right = right*10+(line[i]-'0');
                i++;
            }
            // cout<<right<<endl;
            ans += invalid_ids(left, right);
            cout<<ans<<endl;
            i++;

        }

    }
    cout<<ans<<endl;
    return 0;
}