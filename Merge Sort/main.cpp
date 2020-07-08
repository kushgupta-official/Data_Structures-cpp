# include <bits/stdc++.h>

using namespace std;
# define ll long long
# define rep(i,a,b) for(ll i=a;i<b;i++)
# define vi std::vector<int>
# define vll std::vector<ll>

void kush_gupta(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin) ;
  freopen("output.txt", "w", stdout) ;
  #endif
}

void merge(vector<ll>& array, ll l, ll m, ll r){
  ll n1=m-l+1;
  ll n2=r-m;
  std::vector<ll> temp_a(n1);
  std::vector<ll> temp_b(n2);
  ll i=0,j=0,k=l;
  for (i=0;i<n1;i++){
    temp_a[i]=array[l+i];
  }
  for (i=0;i<n2;i++){
    temp_b[i]=array[m+i+1];
  }
  i=0;j=0;k=l;
  while(i<n1 && j<n2){
    if (temp_a[i]<temp_b[j]){
      array[k++]=temp_a[i++];
    }
    else{
      array[k++]=temp_b[j++];
    }
  }
  while(i<n1){
    array[k++]=temp_a[i++];
  }
  while(j<n2){
    array[k++]=temp_b[j++];
  }
}

void mergeSort(vector<ll> &array,ll l,ll r){
  if (l<r){
    ll m=l+(r-l)/2;
    mergeSort(array,l,m);
    mergeSort(array,m+1,r);
    merge(array,l,m,r);
  }
}
int main()
{
	kush_gupta();
  ll n=0;
  cin>>n;
	std::vector<ll> array(n);
  for (ll i=0;i<n;i++){
    cin>>array[i];
  }
  mergeSort(array,0,n-1);
  for (ll i=0;i<array.size();i++){
    cout<<array[i]<<" ";
  }
  cout<<endl;
	return 0;
}