//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    # define ppi pair<int,int>
    
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dis(1001, INT_MAX);
        priority_queue<ppi,vector<ppi>,greater<ppi>>minheap;
        // {distance, node}
        minheap.push({0,S});
        dis[S] = 0;
        
        while(!minheap.empty()){
            int node = minheap.top().second;
            minheap.pop();
            
            for(auto v: adj[node]){
                  int curr_node_dis = dis[node] + v[1];
                  if(dis[v[0]] > curr_node_dis){
                      dis[v[0]] = curr_node_dis; 
                      minheap.push({dis[v[0]],v[0]});
                  }
            }
        }
        return dis; 
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends