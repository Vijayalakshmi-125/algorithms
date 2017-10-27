/*

https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/

Given a sorted array, remove the duplicates in place such that each element can appear atmost twice and return the new length.

*/

class Solution {
public:

    int removeDuplicates(vector<int> &A) {
        
        int curr=A[0]; int seen=1, e=-1;
        
        for(int i=1;i<A.size();i++){

            if(A[i]==curr&&seen==1) 
                seen++;

            else if(A[i]==curr&&seen==2){
                if(e<0) e=i;
                seen++;
                continue;
            }

            else if(A[i]==curr&&seen>2) 
                continue;

            else if(A[i]!=curr){
                curr = A[i]; seen = 1;
            }
            
            if(e>0){
                A[e] = A[i]; 
                e++;
            }
        }
        
        return e>0? e: A.size();
    }
};