#include <bits/stdc++.h>
using namespace std;
#define ll long long int
using std::vector;
using std::pair;

std::vector<bool> visited(10000,0);
std::vector<int> res;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

void explore(vector<vector<ll> > &adj, ll x){
  visited[x]=1;
  res.push_back(x);
  for (ll i=0;i<adj[x].size();i++){
    if(visited[adj[x][i]]==0){
      explore(adj,adj[x][i]);
    }
  }
}

ll reach(vector<vector<ll> > &adj, ll x, ll y) {
  explore(adj,x);
  for (ll i=0;i<res.size();i++){
    if(res[i]==y){
      return 1;
    }
  }
  return 0;
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
  ll x, y;
  std::cin >> x >> y;
  std::cout << reach(adj,x,y);
  return 0;
}
