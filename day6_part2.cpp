#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    string line;
    ifstream file("input.txt");
    vector<string>number_lines;
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
                number_lines.push_back(' '+line);
                // vector<int>temp;
                // while(i<line.size()){
                //     int num =0;
                //     while(i<line.size() and line[i]!=' '){
                //         num = num*10 + (line[i]-'0');
                //         i++;
                //     }
                //     while (i<line.size() and line[i] == ' ')
                //     {
                //         i++;
                //     }
                //     // cout<<num<<endl;
                //     // cout<<line<<endl;
                //     temp.push_back(num);
                // }
                // numbers.push_back(move(temp));
            }

            // cout<<line<<endl;
        }

    }
    size_t &&n=number_lines.size();
    size_t &&m = number_lines[0].size();
    int oper_idx = operations.size()-1;
    long long prod = 1;
    long long ans = 0;
    for(int j= m-1; j>=0; j--){
        int && num = 0;
        bool flag = false;
        for(int i =0; i<n; i++){
            if(number_lines[i][j] >='0' and number_lines[i][j] <='9'){
                num = num*10 + number_lines[i][j]-'0';
                flag = true;
            }
        }
        // cout<<num<<endl;
        if (flag){
            if(operations[oper_idx] == '*')
                prod*=num;
            else
                ans += num;

        }
        else{
            if(operations[oper_idx] == '*'){

                ans += prod;
                // cout<<prod<<endl;
            }
            // cout<<ans<<endl;
            prod = 1;
            oper_idx--;
        }
    }
    cout<<ans<<endl;
}