#include<bits/stdc++.h>
using namespace std;

vector<vector<int> >a;
vector<int>vis;
vector<int>ans;
vector<int>p;
vector<int>sp;

void dfs(int u, int fi)
{
    if(vis[u])return;
    vis[u] = 1;
    ans[fi] += p[u];

    for(auto v : a[u])
    {
        dfs(v, fi);
    }
}

int main()
{
    int c, r, l, f;
    cin>>c>>r>>l>>f;

    a.resize(c);

    for(int i = 0 ; i<r ; i++)
    {
        int c1, c2;
        cin>>c1>>c2;

        a[c1].push_back(c2);
        a[c2].push_back(c1);
    }
    p.resize(c);

    for(int i = 0; i<l ; i++ )
    {
        int ci, pi;
        cin>>ci>>pi;

        p[ci] = pi;
    }

    vis.resize(c);
    ans.resize(f);
    sp.resize(f);

    for(int i = 0 ; i<f ; i++)
    {
        int ci, fi;
        cin>>ci>>fi;
        sp[fi] = ci;
    }

    for(int i = 0 ; i<f ; i++)
    {
        int ci = sp[i];

        if(vis[ci])continue;
        dfs(ci,i);
    }

    int total = 0;
    int collected = 0;
    for(int i = 0 ; i<c ; i++)
    {
        if(p[i])total +=p[i];
        if(vis[i])collected += p[i];
    }

    ofstream file("output(dfs).txt",ios::out|ios::trunc);

    if(total != collected)file<<"Mission Impossible"<<endl;
    else file<<"Mission Accomplished"<<endl;

    file<<collected<<" out of "<<total<<" pieces are collected"<<endl;
    for(int i = 0 ; i<f ; i++)file<<i<<" collected "<<ans[i]<<" pieces"<<endl;

}
