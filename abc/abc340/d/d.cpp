#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
using namespace std;
typedef pair< long long, long long > Pi;
const long long INF = 1 << 30;
struct edge: vector< Pi > {
  void add_edge(long long to, long long cost){
    push_back(Pi(to,cost));
  }
} info[1000000];
unsigned long long hoge[200000];

void bfs(const long long& st, const long long& V){
  fill_n( hoge, V, 1e19);
  queue< long long > que;
  que.push(st);
  hoge[st] = 0;
  while(!que.empty()){
    long long p = que.front();
    que.pop();
    // printf("%d ", p);
    
    for(long long i = 0 ; i < info[p].size() ; i++){
      unsigned long long cost = info[p][i].second;
      long long to = info[p][i].first;
    //   printf("%d %d\n", i,to);
      if( cost + hoge[p] < hoge[to]){
        que.push(to);
        hoge[to] = cost + hoge[p];
        // printf("%d\n", hoge[to]);
      }
    }
  }
}

int main(){
  long long V, E, r;
  long long n;
  scanf("%d", &n);
  V=n;
  E=2*(n-1);
  r=0;
  for(long long i = 0; i < n-1; i++){
    long long a,b,x;
    scanf("%d %d %d", &a, &b, &x);
    x--;
    info[i].add_edge( i+1, a);
    if(i!=x)info[i].add_edge( x, b);
  }
  bfs(r,V);
    printf("%d\n", hoge[n-1]);

}