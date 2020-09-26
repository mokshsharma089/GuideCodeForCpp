#include "Basics.cpp"
using namespace std;
//BFS
void Graph::bfs(string source){
  map<string,bool> visited;
  queue<string> q;
  q.push(source);
  visited[source]=true;
  cout<<endl<<"--------------bfs started from "<<source<<"--------------";
  while(!q.empty()){
    string node=q.front();
    q.pop();
    cout<<endl<<node;
    for(auto nbr:this->adj_l[node]){
      string nbr_name=nbr.first;
      if(visited[nbr_name]==false){
        q.push(nbr_name);
        visited[nbr_name]=true;
      }
    }
  }
  cout<<endl<<"-------------------bfs ended--------------------"<<endl;
}
//DFS
void Graph::dfs(string source){
  map<string,bool> visited;
  for(auto a:this->adj_l){
    visited[a.first]=false;
  }
  cout<<endl<<"--------------dfs started from "<<source<<"--------------";
  dfs_helper(source,visited);
  cout<<endl<<"-------------------dfs ended--------------------"<<endl;
}
void Graph::dfs_helper(string source,map<string,bool>& visited){
  visited[source]=true;
  cout<<endl<<source;
  for(auto nbr:this->adj_l[source]){
      string node=nbr.first;
      if(!visited[node]){
        dfs_helper(node,visited);
      }
  }
}
int main(){
  Graph g(true);
  g.addEdge("P","Q",1);
  g.addEdge("P","R",1);
  g.addEdge("P","S",1);
  g.addEdge("Q","R",1);
  g.addEdge("Q","S",1);
  g.addEdge("R","S",1);
  g.addEdge("Q","A",1);
  g.addEdge("S","B",1);
  g.addEdge("A","B",1);
  g.display();
  g.bfs("A");
  g.bfs("Q");
  g.dfs("A");
  g.dfs("P");
  return 1;
}
