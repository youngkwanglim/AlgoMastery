#include<bits/stdc++.h>
using namespace std;
int n, m, a[5][5], ret;
string s;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            a[i][j] = s[j] - '0';
        }
    }

    for(int s = 0; s < (1 << (n * m)); s++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            int cur = 0;
            for(int j = 0; j < m; j++){
                int k = i * m + j;
                if((s & (1<<k)) == 0){
                    cur = cur * 10 + a[i][j];
                }else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        for(int j = 0; j < m; j++){
            int cur = 0;
            for(int i = 0; i < n; i++){
                int k  = i * m + j;
                if((s & (1<<k))){
                    cur = cur * 10 + a[i][j];
                }else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        ret = max(ret, sum);
    }
    cout << ret << '\n';
}
