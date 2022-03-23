210. Course Schedule II
Medium

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.



Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]

Algo -
Perform topological sort using indegree method

Code -
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         if(prerequisites.empty()){
             vector<int> result;
             for(int i=0;i<numCourses;i++)
             result.push_back(i);
            return result;
        }
        vector<int> indegree(numCourses,0);
        map<int,list<int>> adjList;
        for(auto edge:prerequisites){
            int to, from;
            to = edge[0];
            from = edge[1];
            adjList[from].push_back(to);
            indegree[to]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            cout<<endl<<i<<" - "<< indegree[i];
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> result;
        int count=0;
        cout<<"\n";
        while(q.empty()==false){
            int node = q.front();
            count++;
            q.pop();
            cout<<node<<"->";
            result.push_back(node);
            for(int nbr: adjList[node]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }
        cout<<endl<<count;
        return count==numCourses?result:vector<int>();
    }
};
