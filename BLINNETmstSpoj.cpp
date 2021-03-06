#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#ifndef ONLINE_JUDGE
#define gc getchar
#else
#define gc getchar_unlocked
#endif
#define ll long long
#define nl() printf ("\n")
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define pi(x) printf ("%d",x)
#define pl(x) printf ("%lld",x)
#define pc(x) printf ("%c",x)
#define ps(x) printf ("%s",x)
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define repu(i,a,n,step) for (i = a; i < n; i += step)
#define repd(i,a,n,step) for (i = a - 1; i >= n; i += step)
using namespace std;
int readi () {
	int n=0,sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
ll readl () {
	ll n=0;int sign=0;
	char c=gc();
	while (c<48) {
		if (c==45) sign=1;
		c=gc();
	}
	while (c>47) {
		n=n*10+c-'0';
		c=gc();
	}
	if (sign) return (-n);
	return n;
}
double power(double x, int y)
{
    double temp;
    if( y == 0)
       return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
}
vector <pair<int,pair<int,int> > > graph;
int edges,vertices,parent[10001];
int findset(int vertex, int parent[]) {
        if (vertex != parent[vertex])
                parent[vertex] = findset(parent[vertex],parent);
        return parent[vertex];
}
void kruskal() {
        //cout<<"here";
        int tot=0,i,parentU,parentV;
        sort(graph.begin(),graph.end());
        for (int i=0;i< edges; i++) {
                parentU = findset(graph[i].second.first,parent);
                parentV = findset(graph[i].second.second,parent);
                //cout<<parentU<<" "<<parentV<<" | ";
                if (parentU != parentV) {

                        tot += graph[i].first;
                        //MST.pb(mp(graph[i].first,mp(graph[i].second.first,graph[i].second.second)));
                        parent[parentU] = parent[parentV];
                }
        }
        /*for (int i=0;i<MST.size();i++) {
                cout<<"("<<MST[i].second.first<<" "<<MST[i].second.second<<") "<<MST[i].first<<"\n";
        }*/
        pi(tot);
        nl();
}
int main() {
        int t,u,v,w,n;
        string s;
        t = readi();
        while (t--) {
                vertices = readi();
                for (int i=1;i <= vertices;i++) {
                        parent[i] = i;
                        cin>>s;
                        n = readi();
                        edges += n;
                        u = i;
                        while (n--) {
                              v = readi();
                              w = readi();
                              graph.pb(mp(w,mp(u,v)));
                        }
                }
                kruskal();
                graph.clear();
                //MST.clear();
                edges = 0 ;
        }
return 0;
}
