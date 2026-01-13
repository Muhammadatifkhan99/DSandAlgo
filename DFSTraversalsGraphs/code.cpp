#include<iostream>
#include<vector>


using namespace std;


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



    


    return 0;
}