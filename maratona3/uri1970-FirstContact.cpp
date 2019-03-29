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



int N,Na, K;
vector<int> tempo, tempoOriginal;
int cabe[10], total[102+1][55];

int knap(int mochila){


    for(int i=0; i <= Na; i++){
        for(int w=0; w <= cabe[mochila]; w++){
            if(i == 0 || w == 0)
                total[i][w] = 0;
            else if(w >= tempo[i-1]){
                total[i][w] = max(tempo[i-1] + total[i-1][w - tempo[i-1]], total[i-1][w]);
            }
            else
                total[i][w] = total[i-1][w];
        }
    }

    return total[Na][cabe[mochila]];

}


void aux(int mochila){

    int line = cabe[mochila];
    int i = Na; 
    vector<int> in;
    while(i > 0){
        if(total[i][line] - total[i-1][line - tempo[i-1]] == tempo[i-1]){
            in.push_back(i-1);
            i--;
            line -= tempo[i];
        }
        else{
            i--;
        }
    }
    vector<int> tempo2;
    for(int i=0; i < Na; i++)
        if(find(in.begin(), in.end(), i) == in.end())
            tempo2.push_back(tempo[i]);
    tempo = tempo2;
    Na = tempo.size();
}



int main(){
    
    cin >> N; cin >> K;

    range(0, N){
        int num;
        cin >> num;
        tempoOriginal.push_back(num);
    }
    sort(tempoOriginal.begin(), tempoOriginal.end());
    range(0, K){
        cin >> cabe[i];
    }
    tempo.clear();
    for(int i : tempoOriginal)
        tempo.push_back(i);
    Na = N;
    int sumT = 0;
    if(K == 1){
        range(0, K){
            sumT += knap(i);
            aux(i);
        }
    }
    else if(K == 2){
        int sumTa = 0;
        range(0, K){
            sumT += knap(i);
            aux(i);
        }
	tempo = tempoOriginal;
	Na = N;
        for(int i=1; i >= 0; i--){ 
            sumTa += knap(i);
            aux(i);
        }
        sumT = max(sumT, sumTa);
    }
    else{
        int sumTa = 0;
        sumT += knap(0);
        aux(0);
        sumT += knap(1);
        aux(1);
        sumT += knap(2);
        aux(2);
	//cout << sumT << endl;
	
	tempo = tempoOriginal;
	Na = N;
	sumTa = 0;
	sumTa += knap(0);
        aux(0);
        sumTa += knap(2);
        aux(2);
        sumTa += knap(1);
        aux(1);
	//cout << sumTa << endl;
	sumT = max(sumT, sumTa);
	
	tempo = tempoOriginal;
	Na = N;
	sumTa = 0;
	sumTa += knap(1);
        aux(1);
        sumTa += knap(0);
        aux(0);
        sumTa += knap(2);
        aux(2);
        //cout << sumTa << endl;
	sumT = max(sumT, sumTa);

	tempo = tempoOriginal;
	Na = N;
	sumTa = 0;
	sumTa += knap(1);
        aux(1);
        sumTa += knap(2);
        aux(2);
        sumTa += knap(0);
        aux(0);
        //cout << sumTa << endl;
	sumT = max(sumT, sumTa);

	tempo = tempoOriginal;
	Na = N;
	sumTa = 0;
	sumTa += knap(2);
        aux(2);
        sumTa += knap(0);
        aux(0);
        sumTa += knap(1);
        aux(1);
        //cout << sumTa << endl;
	sumT = max(sumT, sumTa);

	tempo = tempoOriginal;
	Na = N;
	sumTa = 0;
	sumTa += knap(2);
        aux(2);
        sumTa += knap(1);
        aux(1);
        sumTa += knap(0);
        aux(0);
        //cout << sumTa << endl;
	sumT = max(sumT, sumTa);
    }
    cout << sumT << endl;

    return 0;
}
