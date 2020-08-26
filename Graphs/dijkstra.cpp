#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

long long distance(vector<vector<ll> > &adj, vector<vector<ll> > &cost, ll s, ll t) {
  vector<ll> distance(adj.size(),INT_MAX);
  distance[s]=0;
  priority_queue <pair<ll,ll>,vector <pair<ll,ll> >,greater<pair<ll,ll> > > pq;
  pq.push({0,s});
  std::vector<bool> visited(adj.size(),0);
  ll curr=-1;
  while(!pq.empty()){
  	/*if(visited[pq.top().second]){
  		pq.pop();
  		continue;
  	}*/
  	curr=pq.top().second;
  	visited[pq.top().second]=1;
  	//ll c_cost=pq.top().first;
  	pq.pop();
  	for (ll i=0;i<adj[curr].size();i++){
  		if(distance[adj[curr][i]]>distance[curr]+cost[curr][i]){
  			distance[adj[curr][i]]=distance[curr]+cost[curr][i];
  			pq.push({distance[adj[curr][i]],adj[curr][i]});
  		}
  	}
  }  
  if(distance[t]==INT_MAX){
  	return -1;
  }
  else{
  	return distance[t];
  }
}

int main() {
  //kush_gupta();
  ll n, m;
  std::cin >> n >> m;
  vector<vector<ll> > adj(n+2);
  vector<vector<ll> > cost(n+2);
  for (ll i = 0; i < m; i++) {
    ll x, y, w;
    std::cin >> x >> y >> w;
    adj[x].push_back(y);
    cost[x].push_back(w);
  }
  ll s, t;
  std::cin >> s >> t;
  //s--, t--;
  std::cout<<distance(adj, cost, s, t);
}
