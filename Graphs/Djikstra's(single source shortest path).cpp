#include "Basics.cpp"
using namespace std;
//Djikstras doesn,t work with negative weight cycle{a cycle whose sum of all edges is -ve}

//If a node has been visited before{performed relaxation from it}, then don't perform relaxation from it again

void Graph::Djikstras(string src){
  if(this->adj_l.find(src)==this->adj_l.end()){
    cout<<endl<<"No such node exists. Enter a valid node";
    return;
  }
  map<string,int> visited,distance;
  for(auto p:this->adj_l){
    visited[p.first]=false;
    distance[p.first]=INT_MAX;
  }
  priority_queue<pair<int,string>,vector<pair<int,string> >,greater<pair<int,string> > > pq;
  distance[src]=0;
  pq.push(make_pair(0,src));
  while(!pq.empty()){
    pair<int,string> top=pq.top();
    int dt_to_Node=top.first;
    string node=top.second;
    cout<<endl<<"Entered for"<<node;
    pq.pop();
    if(visited[node]==true){
      //if true that means we have already performed relaxation throught this node then don't perform again
      cout<<"But Already relaxed from this go back";
      continue;
    }
    cout<<endl<<"Relaxation is being performed on all neighbours of : "<<node<<endl;
    visited[node]=true;
    for(auto mem:this->adj_l[node]){
      int cost_of_NODE_to_NBR=mem.second;
      string nbr=mem.first;
      int newDist=dt_to_Node+cost_of_NODE_to_NBR;
      if(distance[nbr] > newDist ){
        distance[nbr]=newDist;
        pq.push(make_pair(newDist,nbr));
      }
      // pq.push(make_pair(distance[nbr],nbr));
      // no need for above line as it would already be relaxed before this element of pq is accessed
    }
  }
  cout<<endl<<"-----------------------Djikstras algo performed from Source "<<src<<"-----------------------"<<endl;
  for(auto t:distance){
    cout<<endl<<"Distance to "<<t.first<<" is "<<t.second<<" units";
  }
  cout<<endl<<"-----------------------Djikstras algo ended -----------------------"<<endl;

}


int main(){
  Graph g;
    g.addEdge("1","2",2);
    g.addEdge("1","3",100);
    g.addEdge("1","5",2);
    g.addEdge("3","4",6);
    g.addEdge("4","5",19);
    g.addEdge("5","3",4);
    g.addEdge("2","1",1000);
    g.display();
    g.Djikstras("1");
    //works perfectly 
    return 1;
}
