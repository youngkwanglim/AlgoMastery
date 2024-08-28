#include<bits/stdc++.h>
using namespace std;
const int max_n = 500000; 
int a, b, visited[2][max_n + 4], ok, turn = 1;
queue<int> q;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	if(a == b) {cout << 0; return 0;}
	visited[0][a] = 1;
	q.push(a);
	while(q.size()){
		b += turn;
		if(b > max_n) break;
		if(visited[turn % 2][b]){
			ok = 1;
			break;
		}
		int qSize = q.size();
		for(int i = 0; i < qSize; i++){
			int x = q.front(); q.pop();
			for(int nx : {x + 1, x - 1, x * 2}){
				if(nx < 0 || nx > max_n || visited[turn % 2][nx]) continue;
				visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
				if(nx == b){
					ok = 1; break;
				}
				q.push(nx);
			}
			if(ok) break;
		}
		if(ok)break;
		turn++;
	}
	if(ok) cout << turn << '\n';
	else cout << -1 << '\n';
}