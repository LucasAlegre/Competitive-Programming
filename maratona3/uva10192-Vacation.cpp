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
    

    string s1, s2;
    int caso = 1;
    while(getline(cin, s1)){
        if(s1 == "#") break;
        getline(cin, s2);
        int matriz[s1.size()+1][s2.size()+1];
        for (int i=0; i <= s1.size(); i++){
            for (int j=0; j <= s2.size(); j++){
                if (i == 0 || j == 0)
                    matriz[i][j] = 0;                           
                else if (s1[i-1] == s2[j-1])
                    matriz[i][j] = matriz[i-1][j-1] + 1;                        
                else
                    matriz[i][j] = max(matriz[i-1][j], matriz[i][j-1]);
            }
        }             
        cout << "Case #" << caso << ": you can visit at most " << matriz[s1.size()][s2.size()] <<" cities." << endl;
        caso++;
    }

    return 0;
}
