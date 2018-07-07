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
    

    int N, P;
    while(cin >> N){
        if(N == 0) break;
        cin >> P;
        int tempo[N], quant[N], total[N+1][P+1];
        range(0, N){
            cin >> tempo[i];
            cin >> quant[i];
        }

        for(int i=0; i <= N; i++){
            for(int w=0; w <= P; w++){
                if(i == 0 || w == 0)
                    total[i][w] = 0;
                else if(w >= quant[i-1]){
                    total[i][w] = max(tempo[i-1] + total[i-1][w - quant[i-1]], total[i-1][w]);
                }
                else
                    total[i][w] = total[i-1][w];
            }
        }
        cout << total[N][P] << " min." << endl;

    }

    return 0;
}
