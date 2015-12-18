//4.2 IsConnect.cc
#include <map>
#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>

using namespace std;

#define PROB 60

// construct a directed graph has @size nodes.
vector<pair<int, int> > DirectedGraph(int size) {
    vector<pair<int, int> > result;
    srand(time(NULL));
    int direction = 0;
    pair<int, int> temp;
    for (int i = 0; i < size-1; ++i) {
        for (int j = i+1; j < size; ++j) {
            if (rand() % 100 < PROB) {
                direction = rand() % 2;
                if (direction)
                    temp = make_pair(i, j);
                else
                    temp = make_pair(j, i);
                result.push_back(temp);
            }
        }
    }
    return result;
}
bool Connect(int start, int end, map<int,bool>Visited, vector<pair<int, int> >& edges);
//Given a directed graph, design an algorithm to  nd out whether there is a route be- tween two nodes.

bool IsConnect(int start, int end, vector<pair<int, int> >& edges){
    map<int,bool>Visited;
    return Connect(start,end,Visited,edges);
}

bool Connect(int start, int end, map<int,bool>Visited, vector<pair<int, int> >& edges){
    if(start==end)return true;
    vector<int>next;
    for(auto p:edges){
        if(p.first==start){
            if(Visited.find(p.second)!=Visited.end()){
                next.push_back(p.second);
                Visited[p.second]=true;
            }
        }
    }

    for(auto n:next){
        if(Connect(n,end,Visited,edges)==true){
            return true;
        }
    }
    return false;
}
int main() {
    int n = 5;
    vector<pair<int, int> > g = DirectedGraph(n);
    cout << IsConnect(0, 3, g) << endl;
    for (int i = 0; i < n; ++i) {
        cout << g[i].first << " " << g[i].second << endl;
    }

}
