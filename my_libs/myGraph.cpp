/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
using namespace std;
class Graph
{
    public:
        Graph(int vertices){
            V = vertices;
            adjL.resize(V);
        }
        void addEdge(int u, int v){
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        void displayGraph(){
            for(int i=0;i<V;++i)
            {
                std::cout<<"i : "<<i<<" ";
                for(auto v:adjL[i])
                {
                    std::cout<<" ->"<<v;
                }
                std::cout<<"\n";
            }
        }
        void BFS(int start){
            std::vector<bool> Vis(V, false);
            std::queue<int>q;
            Vis[start] = true;
            q.push(start);
            
            while(!q.empty()){
                int v = q.front();
                std::cout<<v<<" ";
                q.pop();
                
                for(auto x:adjL[v]){
                    if(!Vis[x]){
                        Vis[x] = true;
                        q.push(x);
                    }
                }
            }
            std::cout<<"\n";
        }
        void DFS(int start){
            std::vector<bool> vis(V, false);
            std::stack<int>s;
            s.push(start);
            
            while(!s.empty()){
                int ver = s.top();
                s.pop();
                if(!vis[ver]){
                    std::cout<<ver<<" ";
                    vis[ver] = true;
                }
                for(auto x: adjL[ver]){
                    if(!vis[x]){
                        s.push(x);
                    }
                }
            }
            std::cout<<"\n";
        }
    private:
        int V;
        std::vector<std::list<int>>adjL;
};
int main()
{
    Graph g(5);
    
    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    
    // Display the graph
    std::cout << "Graph:" << std::endl;
    g.displayGraph();
    std::cout<<"BFS\n";
    g.BFS(0);
    std::cout<<"DFS\n";
    g.DFS(0);
    return 0;
}
