#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
int main(){
    int n;

    while(cin >> n && n!=0){
        int edges;
        cin >> edges;

        map<string, int> stations;
        vector<pii> graph[n];
        string s;

        for(int i = 0; i < n; i++){
            cin >> s;
            stations[s] = i;
        }

        for(int i = 0; i < edges; i++){
            string a, b;
            int cost;
            cin >> a;
            cin >> b;
            cin >> cost;

            graph[stations[a]].push_back(pii(cost, stations[b]));
            graph[stations[b]].push_back(pii(cost, stations[a]));
        }
        cin >> s;
        int first = stations[s];

        int costs[n];
        int marked[n];

        for(int i = 0; i < n; i++){
            costs[i] = 9999999;
            marked[i] = 0;
        }

        costs[first]  = 0;

        priority_queue< pii, vector<pii>, greater<pii> > q;

        q.push(pii(costs[first], first));

        while(true){
            int current_node = -1;
            while(!q.empty()){
                int node = q.top().second;
                q.pop();

                if(!marked[node]){
                    current_node = node;
                    break;
                }
            }

            if(current_node == -1)
                break;

            marked[current_node] = 1;

            for(int i = 0;i < graph[current_node].size();i++){

                int cost  = graph[current_node][i].first;
                int node = graph[current_node][i].second;

                if(costs[node] > cost && !marked[node]){
                    costs[node] = cost;
                    q.push(pii(cost, node));
                }
            }
        }

        int result = 0;
        bool impossible = false;
        for(int i = 0; i < n; i++){
            if(costs[i] == 9999999){
                cout << "Impossible" << endl;
                impossible = true;
                break;
            }
            result += costs[i];
        }

        if(!impossible)
            cout << result << endl;
    }
    return 0;
}
