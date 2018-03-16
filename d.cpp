#include <bits/stdc++.h> 

typedef long long ll;
typedef std::vector<int> vi;
typedef std::pair<int,int> ii;

using namespace std;


int main(){
    
    int n;
    while(cin >> n){
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;
        bool fq = true;
        bool fs = true;
        bool fpq = true;
        for(int i = 0;i<n;i++){
            int op, x, aux;
            cin >> op >> x;
            if(op == 1){
                q.push(x);
                s.push(x);
                pq.push(x);
            }
            else{
                if(fs && s.size()!= 0){
                    aux = s.top();s.pop();
                    if(aux != x) fs = false;
                }
		else fs = false;
                if(fq && q.size()!= 0){
               	     aux = q.front();q.pop();
               	     if(aux != x) fq = false;
		}
		else fq = false;
                if(fpq && pq.size()!= 0){
                     aux = pq.top();pq.pop();
                     if(aux != x) fpq = false;
		}
		else fpq = false;
            }   
        }
        if(fq && !fs && !fpq)
            cout << "queue" << endl;
        else if(!fq && fs && !fpq)
            cout << "stack" << endl;
        else if(!fq && !fs && fpq)
            cout << "priority queue" << endl;
        else if(!fq && !fs && !fpq)
            cout << "impossible" << endl;
        else
            cout << "not sure" << endl;



    }

    return 0;
}
