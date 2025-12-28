#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream file("input.txt");
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
                cout<<"l "<<" "<<curr<<endl;
                if(!curr)
                    ans++;
            }
            else{
                rotation-=curr;
                if(curr)
                    ans++;
                curr = (100-(rotation%100))%100;
                ans += rotation/100;
                
            }
            
        }
        else{
            int rotation = stoi(line.substr(1));
            ans += (curr+rotation)/100;
            curr= (curr+rotation)%100;
        }
        // cout<<curr<<endl;
        // if(curr == 0){
        //     // cout<<line_num<<endl;
        //     ans++;
        // }
        cout<<ans<<endl;
        line_num++;
    }
    cout<<"ans: "<<ans<<endl;
    return 0;
}