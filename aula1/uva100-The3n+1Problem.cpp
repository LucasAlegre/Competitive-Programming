#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

long cycle(long x, vector<long> &con){
    long c = 1;
    long aux = x;
    if(con[x] == 0){
        while(x != 1){
            if (x % 2 != 0) x = 3*x+1;
            else x = x/2;
            c++;
        }
        con[aux] = c;

        return c;
    }
    else return con[x];

}

int main(){
    vector<long> con(1000002,0);
    long i, j, ai, aj;
    vector<long> v;
    while(scanf("%ld %ld", &i, &j)!=EOF){
      	if(i > j){
            ai = j;
            aj = i;
        }
	    else{
	        ai = i;
            aj = j;
	    }
        v.clear();
        
        for(long c=ai; c<=aj;c++){
            v.push_back(cycle(c, con));
        }
        cout <<i<<" "<< j << " " <<  *max_element(v.begin(), v.end()) << endl;

    }

    return 0;
}
