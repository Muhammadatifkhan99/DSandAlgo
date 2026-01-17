#include<iostream>
#include<vector>


using namespace std;


void dfs(int node,vector<vector<int>> adjLs,int vis[]){
    vis[node] = 1;

    for(auto it: adjLs[node]){
        if(!vis[it]){
            dfs(it,adjLs,vis);
        }
    }
}
int findCircleNum(vector<vector<int>>& isConnected) {
    vector<int> adjLs[V];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(isConnected[i][j] == 1 && i != j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    vector<int> vis(0);
    int count = 0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            count++;
            dfs(i,adjLs,vis);
        }
    }
    return count;
}


int main(){

    int n, m;
    cin>>n>>m;

//     int adj[n+1][n+1];

// // initialize matrix with 0
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= n; j++){
//             adj[i][j] = 0;
//         }
//     }

//     //adjacency matrix way
//     for(int i{0};i<m;i++){
//         int u,v;
//         cin>>u>>v;
//         adj[u][v] = 1;
//         adj[v][u] = 1;
//     }


    //list way to store these values...........

    vector<vector<int>> adjv(n+1);
    for(int i{0};i<m;i++){
        int u,v;
        cin>>u>>v;
        adjv[u].push_back(v);
        adjv[v].push_back(u);
    }

    // cout << "using adjacency matrix method" << endl;
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout << adj[i][j] << " ";
    //     }
    // cout << endl;
    // }


    cout<<"using list method " << endl;
    for(int i = 1; i <= n; i++){
    cout << i << ": ";
    for(int v : adjv[i]){
        cout << v << " ";
    }
    cout << endl;
}

    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    cout << findCircleNum(isConnected) << endl;



    


    return 0;
}