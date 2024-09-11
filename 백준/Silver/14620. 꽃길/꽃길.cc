#include<bits/stdc++.h>
using namespace std;
int n, ret = 987654321, visited[14][14], a[14][14];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool check(int y, int x){
    if (visited[y][x]) return 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny<0 || ny>=n || nx < 0 || nx >= n || visited[ny][nx]) {
            return 0;
        } 
    } 
    return 1;  
}
int setFlower(int y, int x){
    visited[y][x] = 1;
    int s = a[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 1;
        s += a[ny][nx];
    }
    return s;
}
void eraseFlower(int y, int x) {
    visited[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}
void flower(int cnt, int sum){
    if(cnt == 3){
        ret = min(ret, sum);
        return;
    }
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < n - 1; j++){
            if(check(i,j)){
                flower(cnt+1, sum + setFlower(i,j));
                eraseFlower(i,j);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    flower(0, 0);
    cout << ret;
}