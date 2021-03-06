#include<iostream>
#include<list>
using namespace std;
 
class Graph
{
    int V; 
    list<int> *adj;  
    void DFSUtil(int v, bool visited[]);  
public:
    Graph(int V);   
    void addEdge(int v, int w);   
    void DFS(int v); 
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); 
 }
 
void Graph::DFSUtil(int v, bool visited[])
{
    
    visited[v] = true;
    cout << v << " ";
 
   
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}
 

void Graph::DFS(int v)
{
  
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFSUtil(i, visited);
}
 
int main()
{ 
   int v,u;
   cout<<"\n Enter no. of vertices =";
   cin>>v;
   Graph g(v);
   int i,j;
   char ch='y';
   do{
   	cout<<"Enter edges ";
   	cout<<"\n Enter edge between = ";
  	cin>>i>>j;
   	g.addEdge(i,j);
   	cout<<"Continue?";
   	cin>>ch;
   }while(ch=='y'||ch=='Y');
   
   cout<<"DFS on node = ";
   cin>>u;
   g.DFS(u);
   cout<<"\n";
 
 
    return 0;
}
