/// source code

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <sstream>
using namespace std;

const int INF = numeric_limits<int>::max();

void printpath(vector<int>& prev, int start, int end)
{
    stack<int> path;
    cout<<"route : ";
    for(int v = end;v != -1;v = prev[v])
    {
        path.push(v);
    }
    while(!path.empty())
    {
        //cout<<path.top()+1;
        char ch = path.top()+65;
        cout<<ch;
        path.pop();
        if(!path.empty()) cout<<" --> ";
    }
}

void dijkstra(vector<vector<int>>& graph, int start, int end)
{
    int size = graph.size();
    vector<int> dist(size, INF);
    vector<int> prev(size, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;

    pq.push({0, start});

    while(!pq.empty())
    {
        int currdist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for(int v = 0;v < size;v++)
        {
            if(graph[u][v] != 0)
            {
                int newdist = currdist + graph[u][v];
                if(newdist < dist[v])
                {
                    dist[v] = newdist;
                    prev[v] = u;
                    pq.push(pair<int, int>(dist[v], v));
                }
            }
        }
    }

    if(dist[end] != INF)
    {
        cout<<"shortest length : "<<dist[end]<<endl;
        printpath(prev, start, end);
    } else {
        cout<<"node cannot reach"<<endl;
    }
}

int main()
{
    int start, end;
    int nodes, num;
    char ch;
    cout<<"Number of nodes : ";
    cin>>nodes;
    cin.ignore();
    vector<vector<int>> graph(nodes);
    for(int i = 0;i < nodes;i++)
    {
        string input;
        string temp;
        cout<<"enter numbers in row "<<i+1<<" : ";
        getline(cin, input);
        stringstream ss(input);
        while(getline(ss, temp, ','))
        {
            graph[i].push_back(stoi(temp));
        }
        if(graph[i].size() != nodes)
        {
            cout<<"invalid input. expected "<<nodes<<" numbers"<<endl;
            i--;
        }
    }

    cout<<"#pls enter upper char : "<<endl;
    bool error = 1;
    while(error){
        cout<<"start : ";cin>>ch;start = ch;start -= 65;
        if(start < 0 || start > nodes - 1){
            cout<<"wrong !"<<endl;
        } else {
            error = 0;
        }
    }
    error = 1;
    while(error){
        cout<<"end : ";cin>>ch;end = ch;end -= 65;
        if(end < 0 || end > nodes - 1){
            cout<<"wrong !"<<endl;
        } else {
            error = 0;
        }
    }

    cout<<"graph : "<<endl;
    for(int i = 0;i < graph.size();i++)
    {
        for(int j = 0;j < graph.size();j++)
        {
            if(j == graph.size()-1){
                cout<<graph[i][j];
            } else {
                cout<<graph[i][j]<<", ";
            }
        }
        cout<<endl;
    }
    

    dijkstra(graph, start, end);

    return 0;
}
