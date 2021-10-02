// The following code solves the below problem: 
/* Given a directed unweighted graph, write a code for depth first traversal. For each vertex,
print start time (st) and finish time (fin). Also, print the edges and their types as Tree edge,
Back Edge, Forward Edge and Cross Edge */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void insert(vector<int> v[], int a, int b)
{
    // Since the graph given is directed and unweighted
    // The edges are uni-directional in nature and therefore 
    // in the adjacency list, the vertex are being added to parent set
    v[a].push_back(b);
}

void pgraph(vector<int> v[], int n)
{
    // This is a check on how the graph looks like via adjacency list representation
    for(int i=0; i<n; i++)
    {
        cout << i  << " ->";
        for(int j=0; j<v[i].size(); j++)
        {
            cout << v[i][j]  << " ->";
        }
        cout << "NULL" << endl;
    }
}

void presult(vector<int> a[], int n, int st[], int fin[], int parent[])
{
    cout << "Vertex (Start time, Finish Time) :- " << endl;
    for(int i=0; i<n; i++)
    {
        cout << i << " " << "( " << st[i] << ", " << fin[i] <<  ")" << endl;
    }

    cout << endl << "Classification of each edge are as follows: " << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<a[i].size(); j++)
        {
            cout << "Edge from " << i << " to " << a[i][j] << " is a";
            int u = i;
            int v = a[i][j];

            if((parent[v] == u) && (st[u] < st[v]) && (st[v] < fin[v]) && (fin[v] < fin[u]))
            {
                cout << " Tree Edge." << endl;
            }
            else if((parent[v] != u) && (st[u] < st[v]) && (st[v] < fin[v]) && (fin[v] < fin[u]))
            {
                cout << " Forward Edge." << endl;
            }
            else if((st[v] < st[u]) && (st[u] < fin[u]) && (fin[u] < fin[v]))
            {
                cout << " Back Edge." << endl;
            }
            else
            {
                cout << " Cross Edge." << endl;
            }
        }
    }
}

void DFS_visit(vector<int> v[], int n, int start, int visited[], int entry[], int exit[], int p[])
{
    static int time = 0;
    time++;
   // cout << "Vertex: " << start << "Entry " << time << " " << endl;
    entry[start] = time;
    for(int i=0; i<v[start].size(); i++)
    {
        int temp = v[start][i];
        if(visited[temp] == 0)
        {
            visited[temp] = 1;
            p[temp] = start;
            DFS_visit(v, n, temp, visited, entry, exit, p);
        }
    }
    time++;
    exit[start] = time;    
}

void DFS(vector<int> v[], int n)
{
    int parent[n];
    int visited[n] = {0};
    int entry[n] = {-1};
    int exit[n] = {-1};
    for(int i=0; i<n; i++)
    {
        if(visited[i] == 0)
        {
            parent[i] = -1;
            visited[i] = 1;
            DFS_visit(v, n, i, visited, entry, exit, parent);
        }
    }

    presult(v, n, entry, exit, parent);
}

int main()
{
    // Currently based on 0 - based indexing
    // 0 - based indexing means that if number of vertices are n, then vertex number should lie between 0 to n-1
    int n, e;
    cout << "Enter the total number of vertices in the graph: ";
    cin >> n;
    cout << "Enter the total number of edges in the Graph: ";
    cin >> e;

    // v is our adjacency list
    vector<int> v[n];
    cout << "Enter the directed edges- " << endl;
    cout << "Vertex-1, Vertex-2 " << endl;
    for(int i=0; i<e; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        insert(v, a, b);
    }

    cout << endl;
    cout << "The Directed Graph looks like: " << endl;
    cout << "Vertex: Adjacent Vertex" << endl; 
    pgraph(v, n);
    cout << endl;

    DFS(v, n);
}