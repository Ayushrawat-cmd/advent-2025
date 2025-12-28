#include<iostream>
#include<fstream>
using namespace std;
unsigned long long invalid_ids(unsigned long long low, unsigned long long high){
    unsigned long long total = 0;
    while(low<=high){
        string &&tmp = to_string(low);
        int win=1;
        int i =0;
        while(win<=tmp.size()/2){
            if(tmp.size()%win ==0 ){
                bool flag = true;
                for(int i =win; i<tmp.size(); i+=win){
                    if(tmp.substr(i-win,win)!=tmp.substr(i,win)){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    total+=low;
                    cout<<low<<endl;
                    break;
                }

            }
            win++;
        }
        low++;

    }
    return total;
}

int main(){
    ifstream file("input.txt");
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
            // cout<<ans<<endl;
            i++;

        }

    }
    cout<<ans<<endl;
    return 0;
}