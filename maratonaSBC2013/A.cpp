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
    

    int a,b,c;
    cin >> a >> b >>c;
    int s = a+b+c;
    if(s == 0 || s == 3)
        cout << "*" << endl;
    else if(a == 1 && b == 0 && c == 0)
        cout << "A" << endl;
    else if(a == 0 && b == 1 && c == 0)
        cout << "B" << endl;
    else if(a == 0 && b == 1 && c == 1)
        cout << "A" << endl;
    else if(a == 1 && b == 0 && c == 1)
        cout << "B" << endl;
    else if(a == 1 && b == 1 && c == 0)
        cout << "C" << endl;
    else if(a == 0 && b == 0 && c == 1)
        cout << "C" << endl;
    return 0;
}
