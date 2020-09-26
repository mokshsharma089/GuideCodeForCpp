#include "Basics.cpp"
using namespace std;
//topological sort is only maybe possible for acyclic directed graphs
//not at all possible for cyclic graph

// Definition
// In computer science, a topological sort or topological ordering of a directed graph is a linear ordering of its vertices
// such that for every directed edge uv from vertex u to vertex v, u comes before v in the ordering


//it is assumed that the graph is acyclic Directed graph so it will give an answer for cyclic graph but would be wrong {so only give input that graph if DAG }
void Graph::topological_sort(){
  if(this->Bidirectional==true){
    cout<<endl<<"Topological sort can't be done on undirected graphs."<<endl;
    return;
  }
  //Algortihm for topological topological_sort
  //Perform DFS on every node ,maintain a visited array and a list or stack which would hold the result of
  //only push a node on top of answer stack{or front of answer list} when all its neighbours have already been visited
  map<string,bool> visited;
  list<string> ans;
  //mark all nodes with false in visited array
  for(auto p:this->adj_l){
    visited[p.first]=false;
  }
  //could start from anywhere but this loop also takes care of unconnected components as if any node is visited then wont call again
  for(auto p:this->adj_l){
    string node=p.first;
    if(!visited[node]){
      dfs_helper_for_topological_sort(node,visited,ans);
    }
  }
  //Now the result is in ans just display it
  cout<<endl<<"-----------TOPOLOGICAL SORT-----------"<<endl;
  for(auto a:ans){
    cout<<a<<" , ";
  }
  cout<<endl<<"---------------Finished---------------"<<endl;
}

void Graph::dfs_helper_for_topological_sort(string src,map<string,bool>& visited,list<string>& ans){
  visited[src]=true;
  for(auto p:this->adj_l[src]){
    string nbr=p.first;
    if(!visited[nbr]){
      dfs_helper_for_topological_sort(nbr,visited,ans);
    }
  }
  ans.push_front(src);//push in front of list or on top of stack depending on what DS we are using
  return;
}
int main(){
  Graph g;
  g.addEdge("1","2",1);
  g.addEdge("1","3",1);
  g.addEdge("2","4",1);
  g.addEdge("4","3",1);
  g.display();
  g.topological_sort();
  return 1;
}
