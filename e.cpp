/**
 *  Lucas Alegre - 00274693
 *  Computer Science - UFRGS
 *
 *  C++ Competitive Programming Template
 *
 */
#include <bits/stdc++.h> 

using namespace std;

#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())               
#define range(a,b) for(int i=a;i<b;i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

int flag = false;

vector<vector<int>> v(5, vector<int>(5));

void test(vector<vector<int>> l, int row, int col){
    
    if(row == 4 && col == 4 && !l[4][4])
        flag=true;

    if(row+1 < 5)
        if(!v[row+1][col] && !l[row+1][col]){
        v[row+1][col] = 1;
        test(l,row+1,col);
    }

    if(col+1 < 5) if(!v[row][col+1] && !l[row][col+1]){
        v[row][col+1] = 1;
        test(l,row,col+1);
    }
       
    if(col-1 >= 0 ) if(!v[row][col-1] && !l[row][col-1]){
        v[row][col-1] = 1;
        test(l,row,col-1);
    }
   
    if(row-1 >= 0) if(!v[row-1][col] && !l[row-1][col]){
        v[row-1][col] = 1;
        test(l,row-1,col);
    }
}


int main(){
    

    int n;
    cin >> n;
    range(0,n){
        
        for(int i =0; i < 5; i++)
            for(int j =0;j<5;j++)
                v[i][j] = 0;

        vector<vector<int>> g(5, vector<int>(5));
        for (auto &i : g)
           for (auto &j : i)            
              cin >> j;

        flag = false;
        test(g, 0,0);
        if(flag)
            cout << "COPS" << endl;
        else
            cout << "ROBBERS" << endl;
    }
    return 0;
}

