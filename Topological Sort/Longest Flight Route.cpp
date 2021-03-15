/*
    * Author: HungVoCs47
    * Status: AC
*/
#include <bits/stdc++.h>
using namespace std;
const int oo = 1000111000;
typedef pair<int, int> ii;
vector<ii>a[100005];
int n, m;
int d[100005];
int path[100005];
void dijkstra() {
    priority_queue<ii>pq;
    for (int i = 1; i <= n; i++)
    d[i] = -1;
    d[1] = 0;
    pq.push(ii(0,1));
    while (pq.size()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du != d[u])
            continue;

        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] < du + uv) {
            	path[v]=u;
                d[v] = du + uv;
                pq.push(ii(d[v], v));
            }
        }
    }
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int p, q, w;
    cin>>n>>m;
    while (m--) {
        cin>>p>>q;
        a[p].push_back(ii(1,q));
    }
    dijkstra();
    if (d[n]==-1) cout << -1;
    else {
        int u = n;
        vector <int> a;
        do {
            a.push_back(u);
            u = path[u];
        } while (u != 0);
        cout<<a.size()<<" ";
        for (int i = a.size() - 1; i>=0; i--) cout << a[i] <<' ';
    }
}
