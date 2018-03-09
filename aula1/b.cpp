#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cycle(int x, vector<int> &con){
    int c = 1;
    
    if(con[x] == 0){
        while(x != 1){
            if (x % 2 != 0) x = 3*x+1;
            else x = x/2;
            c++;
        }
        con[x] = c;
        
        return c;
    }
    else return con[x];

}   

int main(){
    vector<int> con(10000,0);
    int i, j;
    vector<int> v;
    while(cin >> i >> j){
        v.clear();
        con= vector<int>(10000,0);
        for(int c=i; c<=j;c++){
            v.push_back(cycle(c, con));
        }
        cout <<i<<" "<< j << " " <<  *max_element(v.begin(), v.end())<<endl;
        
    }

    


    return 0;
}
