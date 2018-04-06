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

int main(){
    
    
    int n;
    cin >> n;
    range(0, n){
        int numPegs;
        cin >> numPegs;
        vector<stack<int>> pegs;
        range(0, numPegs){
            pegs.push_back(stack<int>());
        }
        int num = 0;
        bool inseriu = true;
        while(inseriu){
            inseriu = false;
            num++;
            for(int i=0; i<numPegs;i++){
                if(pegs[i].size() == 0){
                    pegs[i].push(num);
                    inseriu = true;
                    break;
                }
                int s = sqrt(pegs[i].top() + num);
                if((s*s) == (pegs[i].top() + num)){
                    pegs[i].push(num);
                    inseriu = true;
                    break;
                }
            }
        }
        cout << num-1 << endl;
    }

    return 0;
}
