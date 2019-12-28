/*

https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/

There are a total of A courses you have to take, labeled from 1 to A.

Some courses may have prerequisites, for example to take course 2 you have to first take course 1, which is expressed as a pair: [1,2].

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Return 1 if it is possible to finish all the courses, or 0 if it is not possible to finish all the courses.

*/

class Solution {
public:

    int solve(int n, vector<int> &B, vector<int> &C) {
        
        vector<int> indegree(n,0);
        vector<vector<int>> e(n);
    
        for(int i=0;i<B.size();i++){
            e[B[i]-1].push_back(C[i]-1);
            indegree[C[i]-1]++;
        }
        
        
        int count = 0;
        queue<int> q;
        
        for (int i=0; i<n; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            
            int course = q.front();
            q.pop();
            count++;
                
                for(auto j=e[course].begin();j!=e[course].end();j++)
                {
                        if (--indegree[*j] == 0)
                        q.push(*j);
                }
            }
        return count == n?1:0;
        
    }
};
