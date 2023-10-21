//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   //color component 
  bool dfs(int node,int col, int* color,vector<int>adj[]){
	    color[node] = col;
	
	   for(auto &it: adj[node]){
	           // if adjacent node is not colored yet
	           //you will give the opposite color of the node
	            if(color[it] == -1){
	               if(dfs(it, !color[node], color, adj) == false) return false;
	            }
	           //is the adjacent guy having same color
	           //someone did color it on some other path 
	           else if(color[it] == color[node]){
	               return false;
	           }
	        }
	    
	    return true; 
	}
 
	bool isBipartite(int v, vector<int>adj[]){
	    
	    int color[v];
	    
	    for(int i = 0;i < v;i++){
	        color[i] = -1;
	    }
	    
	    for(int i = 0;i < v;i++){
	        if(color[i] == -1){
	            if(dfs(i, 0, color, adj) == false){
	                 return false;
	            }
	        }
	    }
	   
	    return true;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends