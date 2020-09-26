#include <iostream>
#include <map>
#include <list>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
//this files contains basic structure of graph and will be used by other files so no main
//if want to run any file other than this than use #include "Basics.cpp" and comment all functions{not in the new file or this file} declarations and main function {of this }
class Graph{
  //store the graph as adjacency list
  //map<string,list<string,int>> l;
  //in this first string is the node and second parameter of map 'l' is a list of all its neighbours and weights incase of weighted Graph
  map<string,list<pair<string,int> > > adj_l;
  bool Bidirectional;
  //tells if graph represented by the object would be bidirectional or unidirectional
public:
  Graph(){
    Bidirectional=false;
  }
  Graph(bool bd){
    this->Bidirectional=bd;
  }
  void addEdge(string,string,int);//add edges and also creates node
  void display();//to display the adjacency list {which represents the Graph}
  void bfs(string);//In Traversals.cpp
  void dfs(string);//In Traversals.cpp
  void dfs_helper(string,map<string,bool>&);//In Traversals.cpp
  void topological_sort();//in topological Sort.cpp
  void dfs_helper_for_topological_sort(string,map<string,bool>&,list<string>&);//in topological Sort.cpp
  bool is_cyclic();//returns if a cycle is present in the graph
  bool Detect_cycle_undirected_graph();//used for detection in undirected graphs
  bool Detect_cycle_undirected_graph_helper(string,string,map<string,bool>&);//cycle helper similar to dfs_helper
  bool Detect_cycle_directed_graph();
  bool Detect_cycle_directed_graph_helper(string,map<string,bool>&,map<string,bool>&);
  void Prims(string);
  void Djikstras(string);

};
//can also have a bool bidirectional in function parameter which will tell if that edge is bidirectional or not
void Graph::addEdge(string from,string to,int wt){
  adj_l[from].push_back(make_pair(to,wt));
  if(Bidirectional==true){
    adj_l[to].push_back(make_pair(from,wt));
  }
}
void Graph::display(){
  cout<<endl<<"------------Graph in form of adjacency list------------";
  for(auto mem:this->adj_l){
    string M_name=mem.first;
    list<pair<string,int> > M_list=mem.second;
    cout<<endl<<M_name<<" === ";
    for(auto nbr:M_list){
      cout<<" { "<<nbr.first<<",wt="<<nbr.second<<" } ";
    }
  }
  cout<<endl<<"---------------------End of Graph----------------------"<<endl;
}
//main here is commented because this file here is used in all other files

// int main(){
//   Graph g;
//   g.addEdge("Agra","Bhuvneshwar",24);
//   g.addEdge("Amritsar","Chandigarh",15);
//   g.addEdge("Agra","Delhi",98);
//   g.addEdge("Bhuvneshwar","Delhi",47);
//   g.addEdge("Chandigarh","Delhi",65);
//   g.display();
//   g.addEdge("Mumbai","Agra",121);
//   g.display();
//   return 1;
// }
