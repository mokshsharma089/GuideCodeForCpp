#include "Basics.cpp"
using namespace std;

//undirected Graph cycle detection
bool Graph::Detect_cycle_undirected_graph(){
  map<string,bool> visited;
  for(auto p:this->adj_l){
    visited[p.first]=false;
  }
  for(auto p:this->adj_l){
    if(!visited[p.first]){
      if(Detect_cycle_undirected_graph_helper(p.first,"",visited)==true){
        cout<<endl<<"-------Yes, A cycle Exists in this undirected Graph-------"<<endl;
        return true;
      }
    }
  }
  cout<<endl<<"-------No, cycle Doesn't Exists in this undirected Graph-------"<<endl;
  return false;
}

// Algorithm for helper
//if we can reach a node {is a neighbour of the current node we are at} which has been visited previously then we can say a cycle exists in the graph
// But dont consider the parent{the node which called Detect_cycle_undirected_graph_helper(){which is like dfs_helper} function for the current node } in checking for cycle
// because that would lead to wrong answer
bool Graph::Detect_cycle_undirected_graph_helper(string src,string parent ,map<string,bool>& visited){
  visited[src]=true;
  for(auto nbr:this->adj_l[src]){
    string node=nbr.first;
    if(node!=parent and visited[node]==true){
      return true;
    }
    if(node!=parent and visited[node]==false){
        if(Detect_cycle_undirected_graph_helper(node,src,visited)==true){
          return true;
        }
    }
  }
  return false;
}


//Directed Graph Cycle detection
//not as easy as undirected graph

//maintain a visited array to mark which nodes have already been checked or not
//maintain an ancestor stack(can be an array if use recursion) which stores all the nodes we have visited or travelled to get to this node
//cycle only exists if we can go to an already visited ancestor {stored in ancestor stack/array}
//when we are returning from helper function at extreme end {haven't found cycle here and are going to check other possible ways}
//perform backtracking at ancestor array/stack {remove the current node from ancestor stack as this node wont have anything to do with cycle}

//we maintain visited array to see if cycle_check has been performed on the node or not
//but we dont check cycle with help of visited array/map
//we check cycle with help of ancestor array/stack

bool Graph::Detect_cycle_directed_graph(){
  map<string,bool> visited,ancestor;
  for(auto p:this->adj_l){
    string node=p.first;
    //initiate both visited and ancestor for all node as false
    visited[node]=ancestor[node]=false;
  }
  for(auto p:this->adj_l){
    string node=p.first;
    if(!visited[node]){
      if(Detect_cycle_directed_graph_helper(node,ancestor,visited)==true){
        cout<<endl<<"-------Yes, A cycle Exists in this Directed Graph-------"<<endl;
        return true;
      }
    }
  }
  cout<<endl<<"-------No, cycle Doesn't Exists in this Directed Graph-------"<<endl;
  return false;
}
bool Graph::Detect_cycle_directed_graph_helper(string src,map<string,bool>& ancestor,map<string,bool>& visited){
  ancestor[src]=true;
  visited[src]=true;
  for(auto nbr:this->adj_l[src]){
    string node=nbr.first;
      if(ancestor[node]==true){
        return true;
      }
      if(!visited[node] and !ancestor[node]){
        if(Detect_cycle_directed_graph_helper(node,ancestor,visited)==true){
          return true;
        }
      }
  }
  ancestor[src]=false;//remove this from ancestor list as now we are going to return to calling function
  return false;
}
//this functions check if graph is directed or undirected and calls the right function  
bool Graph::is_cyclic(){
  cout<<endl<<"----------IS CYCLIC FUNCTION CALLED-----------"<<endl;
  if(!this->Bidirectional){
    return Detect_cycle_directed_graph();
  }
  return Detect_cycle_undirected_graph();
}
int main(){
  Graph g(true);
    g.addEdge("1","2",1);
    g.addEdge("3","1",1);
    g.addEdge("2","4",1);
    g.addEdge("4","5",1);
    g.display();
    g.is_cyclic();
  return 1;
}
