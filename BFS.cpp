#include<bits/stdc++.h>
using namespace std;

int main()
{
    int c, r, l, f;
    cin>>c>>r>>l>>f;

     vector<vector<int> >a(c);

     for(int i = 0 ; i<r ; i++)
     {
         int c1, c2;
         cin>>c1>>c2;

         a[c1].push_back(c2);
         a[c2].push_back(c1);
     }
     vector<int>p(c);

     for(int i = 0; i<l ;i++ )
     {
         int ci, pi;
         cin>>ci>>pi;

         p[ci] = pi;
     }

     vector<int>vis(c);
     vector<int>ans(f);

     vector<int>sp(f);

     for(int i = 0 ; i<f ; i++)
     {
         int ci, fi;
         cin>>ci>>fi;
         sp[fi] = ci;
     }

     for(int i = 0; i<f ; i++)
     {
         int ci = sp[i];
         if(vis[ci])continue;

         queue<int>q;
         q.push(ci);

         vis[ci]  = 1;
         ans[i] += p[ci];

         while(!q.empty())
         {
             int u = q.front();
             q.pop();

             for(auto v : a[u])
             {
                 if(vis[v])continue;
                 vis[v] = 1;
                 ans[i] += p[v];
                 q.push(v);
             }
         }
     }

     int total = 0;
     int collected = 0;
     for(int i = 0 ; i<c ; i++)
     {
         if(p[i])total +=p[i];
         if(vis[i])collected += p[i];
     }


     ofstream file("output(bfs).txt",ios::out|ios::trunc);

     if(total != collected)file<<"Mission Impossible"<<endl;
     else file<<"Mission Accomplished"<<endl;

     file<<collected<<" out of "<<total<<" pieces are collected"<<endl;
     for(int i = 0 ; i<f ; i++)file<<i<<" collected "<<ans[i]<<" pieces"<<endl;

     return 0;
}
