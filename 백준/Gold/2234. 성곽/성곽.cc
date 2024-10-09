#include<bits/stdc++.h>
using namespace std;
int n, m, a[54][54], visited[54][54], cnt, compSize[2504], mx, big;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
int dfs(int y, int x, int cnt){
    int ret = 1;
    for(int i = 0; i < 4; i++){
        if(!(a[y][x] & (1 << i))){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(visited[ny][nx]) continue;
            visited[ny][nx] = cnt;
            ret += dfs(ny, nx, cnt);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]) {
                cnt++;
                visited[i][j] = cnt;
                compSize[cnt] = dfs(i, j, cnt);
                mx = max(mx, compSize[cnt]);
            }
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i + 1 < m){
                int a = visited[i][j];
                int b = visited[i + 1][j];
                if(a != b){
                    big = max(big, compSize[a] + compSize[b]);
                }
            }
            if(j + 1 < n){
                int a = visited[i][j];
                int b = visited[i][j + 1];
                if(a != b){
                    big = max(big, compSize[a] + compSize[b]);
                }
            }
        }
    }
    
    cout << cnt << '\n' << mx << '\n' << big << '\n';
}