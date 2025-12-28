#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream file("day1_input.txt");
    if(!file.is_open())   {
        cerr << "Error opening file" << endl;
        return 1;

    }
    // int total = 0;
    string line;
    int ans = 0;
    int curr = 50;
    int line_num = 1;
    while(getline(file, line)){ 
        if(line[0] == 'L'){
            int rotation = stoi(line.substr(1));
            if(curr>=rotation){
                curr-=rotation;
            }
            else{
                rotation-=curr;
                curr = (100-(rotation%100))%100;
            }
            
        }
        else{
            int rotation = stoi(line.substr(1));
            curr= (curr+rotation)%100;

        }
        cout<<curr<<endl;
        if(curr == 0){
            // cout<<line_num<<endl;
            ans++;
        }
        line_num++;
    }
    cout<<"ans: "<<ans<<endl;
    return 0;
}