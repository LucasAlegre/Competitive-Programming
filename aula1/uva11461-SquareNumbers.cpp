#include <iostream>
#include <math.h>
using namespace std;
int main(){
    double a, b, c=0, i=0;
    double raiz;
    while(cin >> a >> b){
        if(a == 0 && b == 0)
            break;
        c = 0;
        i = a;
        while(i <= b){
            raiz = sqrt(i);
            
            if(raiz == floor(raiz)) 
                c++;
            i ++;
        }
        cout << c << endl; 

        
    }   



    return 0;
}
