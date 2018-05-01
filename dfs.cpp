 /// Depth-first search
/*  God Help Me
    Indrojit Mondal
    Department of Computer Science and Engineering,
    University of Barisal
    Using Corman
    */
#include<bits/stdc++.h>
using namespace std;
int Vertex,Edge;
int G[100][100];
//vector<int>G[100];
int Time=0;
int Color[100];
int Par[100];
 /* 0==>White
   1==>Gray
   2==>Black
   */

int D[100]; // D->Discovery Time
int F[100]; // F->Finishing Time
void DFS_VISIT(int U);

void DFS(int x)
{
    DFS_VISIT(x);
    for(int I=1; I<=Vertex; I++)
    {
        if(Color[I]==0)
        {
            DFS_VISIT(I);
        }
    }
}

string StringHome[101];
int StrCount=0;

int Search_Index(string str)
{
    int ck=0;
    for(int I=1; I<=StrCount; I++)
    {
        if(str==StringHome[I])
        {
            ck=1;
            return I;
        }
    }
      if(ck==0){
    StrCount = StrCount +1;
    StringHome[StrCount] = str;
    return StrCount;
      }
}

void DFS_VISIT(int U)
{
    Color[U]=1;
    Time=Time+1;
    D[U]=Time;

      for(int V=1; V<=Vertex; V++)
     {
        if(G[U][V]==1 && Color[V]==0)
        {
            Par[V]=U;
            DFS_VISIT(V);
        }

     }
    Color[U]=2;
    Time = Time +1;
    F[U]=Time;

}
void PathPrint(int s,int v)
{
      if(s==v)
      {
          cout<<StringHome[s]<<" ";
          //return;
      }
      else if(Par[v]==0) cout<<"No Path From Source To Destination"<<endl;
      else {PathPrint(s,Par[v]);
      cout<<StringHome[v]<<" ";
      }
}

int main()
{
    int i,j;

    cin>>Vertex>>Edge;
    int Node1,Node2;
    string S1, S2;
    for(i=1; i<=Edge; i++)
    {
        cin>>S1>>S2;
        Node1 = Search_Index(S1);
        Node2 = Search_Index(S2);
        //cin>>Node1>>Node2;
        //G[Node1].push_back(Node2);
        G[Node1][Node2]=1;

    }

    for(int I=1; I<=Vertex; I++)
    {
        Color[I]=0;
        Par[I]=0;
    }
    string src;
    cout<<"Enter Source :  ";
    cin>>src;

    DFS(Search_Index(src));

    for( int V=1; V<=Vertex; V++)
    {
        cout<<StringHome[V]<<" 's Discovery Time = "<<D[V]<<" & Finishing Time = "<<F[V]<<endl;

    }
    ///Check kore dekhlam 3 theke kothai kothai jaoa jai
     //cout<<src<<" ";
    // cin>>src;
    string Dsn;
     cout<<"Enter Destination : ";
     cin>>Dsn;

     //cout<<Search_Index(Dsn)<<endl;

    PathPrint(Search_Index(src),Search_Index(Dsn));


    return 0;
}



