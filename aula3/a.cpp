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

int n, original[8], queens[8];
int answer = 100000;

int count(){
    int r = 0;
    range(0, 8){
        if(original[i] != queens[i])
            r++;
    }
    return r;
}

bool place(int r, int c){
    for(int prev = 0; prev < c; prev++){
        if((queens[prev] == r) || (abs(queens[prev] - r) == abs(prev - c))){
            return false;
        }
    }
    return true;
}

void backtrack(int c){
    
    if(c == 8){
        int counter = count();
        if(counter < answer)
            answer = counter;
    }
    else{
        for(int r = 0; r < 8; r++){
            if(place(r, c)){
                queens[c] = r;
                backtrack(c + 1);
            }
        }
    }
}

int main(){
    
    int cases = 1;
    while(cin >> n){
        queens[0]=n-1; original[0]=n-1;
        range(1,8){ cin >> queens[i]; queens[i]--; original[i]=queens[i];}
        answer = 100000;
        
        backtrack(0);
        
        cout << "Case " << cases << ": " << answer << endl;
	    cases++;

    }

    return 0;
}
