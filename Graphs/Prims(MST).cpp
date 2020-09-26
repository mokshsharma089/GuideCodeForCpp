#include "Basics.cpp"
using namespace std;
//Prims algo for minimum spanning tree
void Graph::Prims(string starting_Node){
  if(this->adj_l.find(starting_Node)==this->adj_l.end()){
    cout<<endl<<"No such node exists. Enter a valid node";
    return;
  }
  priority_queue<pair<int,pair<string,string> >,vector<pair<int,pair<string,string> > >,greater<pair<int,pair<string,string> > > > pq;
  //in above priority queue we will give first as weight of edge and second pair is ued to store the node which it will take{TO} and the node due to this edge was pushed
  map<string,bool> visited;
  for(auto p:this->adj_l){
    visited[p.first]=false;
  }
  int mst_wt=0;
  string mst_ans="";
  visited[starting_Node]=true;
  for(auto mem:this->adj_l[starting_Node]){
    pq.push(make_pair(mem.second,make_pair(mem.first,starting_Node)));
    //first
  }
  while(!pq.empty()){
    pair<int,pair<string,string> > top=pq.top();
    pq.pop();
    int wt=top.first;
    string to=top.second.first;
    if(visited[to]==true){
      //node has already been visited if included will result in cycle_check
      continue;
    }
    //now if the to node has not been visited before add to mst result and push its neighbours to pq;
    mst_ans+="{ ";
    mst_ans+=top.second.second;
    mst_ans+=" ---> ";
    mst_ans+=to;
    mst_ans+=" }, ";
    mst_wt+=wt;
    visited[to]=true;
    for(auto mem:this->adj_l[to]){
      pq.push(make_pair(mem.second,make_pair(mem.first,to)));
    }
  }
  cout<<endl<<"-------------PRIMS MST from starting node "<<starting_Node<<"----------------";
  cout<<endl<<"Wt is "<<mst_wt<<endl<<"And Mst edges Are"<<endl<<mst_ans;
  cout<<endl<<"-------------------End Prims----------------------------"<<endl;
}

int main(){
  Graph g(true);
    g.addEdge("1","2",34);
    g.addEdge("3","1",2);
    g.addEdge("2","4",1);
    g.addEdge("2","3",101);
    g.addEdge("4","3",1);
    g.addEdge("2","6",6);
    g.addEdge("2","5",2);
    g.addEdge("4","5",45);
    g.addEdge("5","6",1);
    g.display();
    g.Prims("1");
    return 1;
}
