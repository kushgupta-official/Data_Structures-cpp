#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

ll distance(vector<vector<ll> > &adj, ll s, ll t) {
  ll inf=adj.size();
  vector <ll> d(adj.size(),inf);   //taking n+2=infinite as distance can't be greater than number
                    //of vertices in graph
  d[s]=0;
  queue <ll> q;
  q.push(s);
  while(!q.empty()){
    ll curr_ver=q.front();
    for (ll i=0;i<adj[curr_ver].size();i++){
      if(d[adj[curr_ver][i]]==inf){
        q.push(adj[curr_ver][i]);
        d[adj[curr_ver][i]]=d[curr_ver]+1;
      }
    }
    q.pop();
  }
  if(d[t]!=inf){
    return d[t];
  }
  else{
    return -1;
  }
}

int main() {
  kush_gupta();
  ll n, m;
  std::cin >> n >> m;
  vector<vector<ll> > adj(n+2);
  for (ll i = 0; i < m; i++) {
    ll x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  ll s, t;
  std::cin >> s >> t;
  std::cout << distance(adj, s, t);
}
