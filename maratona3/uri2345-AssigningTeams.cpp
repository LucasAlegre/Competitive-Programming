#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <math.h>

using namespace std;
typedef pair<int, int> pii;

int main(){
    long int n[4];

    cin >> n[0] >> n[1] >> n[2] >> n[3];

    long int result = abs((n[0]+n[1]) - (n[2]+n[3]));

    if(abs((n[0]+n[2]) - (n[1]+n[3])) < result){
        result = abs((n[0]+n[2]) - (n[1]+n[3]));
    }
    if(abs((n[0]+n[3]) - (n[1]+n[2])) < result){
        result = abs((n[0]+n[3]) - (n[1]+n[2]));
    }

    cout << result << endl;
    return 0;
}
