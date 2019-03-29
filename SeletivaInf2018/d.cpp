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

const int MAXN = 100100;

ll seg[4*MAXN], lazy[4*MAXN];
 
/*
    Propaga lazy armazenada no nó para seus filhos (se existirem).
    Atualiza o valor do próprio nó utilizando o valor da lazy.
    Devemos chamar essa função toda vez que passamos por um nó,
    garantindo assim que seu valor estará correto para utilização.
    Complexidade O(1)
*/
void propagate(int node, int l, int r) {
    if(l != r){
        lazy[2*node + 1] += lazy[node];
        lazy[2*node + 2] += lazy[node];
    }
    seg[node] += (r - l + 1) * lazy[node];
    lazy[node] = 0;
}
 

/*
    Resolve a atualização do intervalo [a, b], adicionando valor val.
    Atualiza subárvore enraizada em node, responsável pelo intervalo [l, r].
    
    Se [l, r] está contido em [a, b], atualizamos seu valor e marcamos que seus filhos
    devem ser atualizados pela próxima chamada que passar por ele (lazy propagation).
    
    Caso contrário, chamamos recursivamente para os filhos.
    Invariante diz que após o retorno dessa função, o valor de seg[node] está correto.
    Complexidade O(lgn)
*/
void update(int node, int l, int r, int a, int b, int val) {
    int mid = (l + r) /2;
    propagate(node, l, r);
    if(l > b || r < a) return;
    if(l >= a && r <= b){
        if(l != r){
            lazy[2*node + 1] += val;
            lazy[2*node + 2] += val;
        }
        seg[node]+= (r - l + 1) * ll(val);
        return;
    }
    update(2*node + 1, l, mid, a, b, val);
    update(2*node + 2, mid+1, r, a, b, val);
    seg[node] = seg[2*node + 1] + seg[2*node + 2];
}

/*
    Resolve a consulta do intervalo [a, b], somando valores na subárvore enraizada em node,
    responsável pelo intervalo [l, r].
    
    Se [l, r] está contido em [a, b], podemos retornar a soma já computada (seg[node]).
    
    Caso contrário, chamamos recursivamente para os filhos, somando as respostas destes.
    Complexidade O(lgn)
*/ 
ll query(int node, int l, int r, int a, int b) {
    int mid = (l + r) / 2;
    propagate(node, l, r);
    if(l > b || r < a) return 0;
    if(l >= a && r <= b){
        return seg[node];
    }
    return query(2*node + 1, l, mid, a, b) + query(2*node + 2, mid+1, r, a, b);
}
 
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, c;
        cin >> n >> c;
        for(int i = 0; i < 4*n; i++){
            seg[i] = lazy[i] = 0;
        }
        for(int i = 0; i < c; i++){
            int cc, a, b;
            cin >> cc;
            if(!cc){
                int val;
                cin >> a >> b >> val;
                a--; b--;
                update(0, 0, n - 1, min(a, b), max(a, b), val);
            }
            else{
                cin >> a >> b;
                a--; b--;
                cout << query(0 , 0, n - 1, min(a, b), max(a, b)) << endl;
            }
 
        }
 
    }
}
