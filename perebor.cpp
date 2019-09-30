#include <iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0, s1, s2;
    for(int i = 0; i < (1 << n); i++){
        s1 = s2 = 0;
        for(int j = 0; j < n / 2; j++){
            if (i & (1 << j)){
                s1 += (s[j] - '0');
            }
            else {
                s1 -= (s[j] - '0');
            }
        }
        for(int j = n / 2; j < n; j++){
            if (i & (1 << j)){
                s2 += (s[j] - '0');
            }
            else {
                s2 -= (s[j] - '0');
            }
        }
        if (s1 == s2){
            ans++;
        }
    }
    cout << ans;
}


============================================

#include <iostream>
#include <vector>
using namespace std;
void calc(string s, int k, int n, vector<int> &a, int &ans){
    if (k == n){
        int s1, s2;
        s1 = s2 = 0;
        for(int i = 0; i < n / 2; i++){
            if (a[i] == 0){
                s1 -= (s[i] - '0');
            }
            else {
                s1 += (s[i] - '0');
            }
        }
        for(int i = n / 2; i < n; i++){
            if (a[i] == 0){
                s2 -= (s[i] - '0');
            }
            else {
                s2 += (s[i] - '0');
            }
        }
        if (s1 == s2){
            ans++;
        }
    }
    else {
        for(int i = 0; i < 2; i++){
            a[k] = i;
            calc(s, k + 1, n, a, ans);
        }
    }
}
int main(){
    string s;
    cin >> s;
    int n = s.size(), ans = 0;
    vector <int> data(n);
    calc(s, 0, n, data, ans);
    cout << ans;
}


================================================
  
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector <int> data(k);
    for(int i = 0; i < k; i++){
        data[i] = i + 1;
    }
    while (true){
        for(int i = 0; i < k; i++){
            cout << data[i] << " ";
        }
        cout << endl;
        int s = k;
        while (s > 0 && data[s - 1] >= n - k + s){
            s--;
        }
        data[s - 1]++;
        for(int i = s; i < k; i++){
            data[i] = data[i - 1] + 1;
        }
        if (data[0] == n - k + 1){
            break;
        }
    }
}

=================
  
  
#include <iostream>
#include <vector>
using namespace std;

void rec(int k, int n, vector<int> &p, vector<char> &a){
    if (k == n){
        for(int i = 0; i < n; i++){
            cout << p[i] << " ";
        }
        cout << endl;
    }
    else {
        for(int i = 0; i < n; i++){
            if (!a[i]){
                a[i] = 1;
                p[k] = i + 1;
                rec(k + 1, n, p, a);
                a[i] = 0;
            }
        }
    }
}

int main(){
    int n; // длина перестановки
    cin >> n;
    vector<int> p(n, 0);
    vector<char> a(n, 0);
    rec(0, n, p, a);
    // a[i] = 0, если число i ещё не добавлено в перестановку
    // a[i] = 1, если число i уже было добавлено в перестановку
}


==============
  
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(){
    int n; // длина перестановки
    cin >> n;
    vector <int> p(n);
    for(int i = 0; i < n; i++){
        p[i] = i + 1;
    }
    do{
        for(int i = 0; i < n; i++){
            cout << p[i] << " ";
        }
        cout << endl;
    }while (next_permutation(p.begin(), p.end()));
}
