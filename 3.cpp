//James Adams

#include <iostream>
#include<cstdlib>
#include <queue>
#include <fstream>
#define V 5
using namespace std;

int main(int argc, char* argv[]) {
    ifstream myfile(argv[1]);
    int n;
    myfile>>n;
    int G[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            myfile>>G[i][j];
        }
    }

    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;
    colorArr[0] = 1;

    queue <int>q;
    q.push(0);
    while (!q.empty())
    {

        int u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v)
        {

            if (G[u][v] && colorArr[v] == -1)
            {

                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            else if (G[u][v] && colorArr[v] == colorArr[u]){
                cout << "Not a Tree";
                return 0;
            }
        }
    }
    cout << "The graph is A Tree"  << endl;

    return 0;
}