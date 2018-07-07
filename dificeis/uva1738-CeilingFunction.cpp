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

class Node{
    public:
    int v;
    Node* left;
    Node* right;

    Node(int v){
        this->v = v;
        this->left = nullptr;
        this->right = nullptr;
    }

    void insert(int v){
        if(v < this->v){
            if(this->left == nullptr){
                this->left = new Node(v);     
            }
            else{
                this->left->insert(v);
            }
        }
        else{ 
            if(this->right == nullptr){
                this->right = new Node(v);     
            }
            else{
                this->right->insert(v);
            }
        }
    }

    string tree2string(string s){
        string a = "(";
        if(this->left != nullptr)
            a += this->left->tree2string("l");
        else
            a += "()";
        a += " " + s + " ";
        if(this->right != nullptr)
            a += this->right->tree2string("r");
        else
            a += "()";
        a += ")";
        return a;
    }
};

int main(){
    

    int n, k;
    while(cin >> n >> k){
        set<string> shapes;
        
        range(0, n){
            int v; cin >> v;
            Node *root = new Node(v);
            for(int j = 1; j < k; j++){
                int value; cin >> value;
                root->insert(value);
            }
            shapes.insert(root->tree2string("a"));
        }
        cout << shapes.size() << endl;
    }

    return 0;
}
