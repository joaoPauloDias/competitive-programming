#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
int n,k,e;

// int cache[MAXN][MAXN][2];

/*short int dp(int left, int right, int k) {
    if (cache[left][right][k] > 0) return cache[left][right][k]-1;

    if (k <= 0) {
        return left + right;
    }

    int pickLeft = (left <= k && k != k_i) ? dp(left-k, right, k-1) : INT_MAX;
    int pickRight = (right <= k && k != k_i) ? dp(left, right-k, k-1) : INT_MAX;
    int pickNone = dp(left, right, k-1);

    int answer = min(min(pickLeft, pickRight), pickNone);
    cache[left][right][k] = answer + 1;
    return answer;
}*/

// _ _ _ _X X X _ _ 

int resolve(int left, int right) {
    vector<int> solucoes;

    for (int i = left; i > 0; i++) {
        int complement_left = left - i;
        if (complement_left >= i) break;
    
        if (i == k || complement_left == k) continue;
        // Solucao exata para left

        for (int j = right; j > 0; j++) {
            int complement_right = right - j;
            if (complement_right >= j) break;

            if (j == k || complement_right == k || j == i || j == complement_left || complement_right == k || complement_right == complement_left) {
                continue;
            }
            // Solucao exata para right

            solucoes.push_back(0);
            break;
        }

        for (int j = right; j > 0; j++) {
            int complement_right = right - j - 1;
            if (complement_right >= j) break;

            if (j == k || complement_right == k || j == i || j == complement_left || complement_right == k || complement_right == complement_left) {
                continue;
            }
            // Solucao margem 1 para right

            solucoes.push_back(1);
            break;
        }

        for (int j = right; j > 0; j++) {
            int complement_right = right - j - 2;
            if (complement_right >= j) break;

            if (j == k || complement_right == k || j == i || j == complement_left || complement_right == k || complement_right == complement_left) {
                continue;
            }
            // Solucao margem 2 para right

            solucoes.push_back(2);
            break;
        }
    }

    for (int i = left; i > 0; i++) {
        int complement_left = left - i - 1;
        if (complement_left >= i) break;
    
        if (i == k || complement_left == k) continue;
        // Solucao com margem 1 para left

        for (int j = right; j > 0; j++) {
            int complement_right = right - j;
            if (complement_right >= j) break;

            if (j == k || complement_right == k || j == i || j == complement_left || complement_right == k || complement_right == complement_left) {
                continue;
            }
            // Solucao exata para right

            solucoes.push_back(1);
            break;
        }

        for (int j = right; j > 0; j++) {
            int complement_right = right - j - 1;
            if (complement_right >= j) break;

            if (j == k || complement_right == k || j == i || j == complement_left || complement_right == k || complement_right == complement_left) {
                continue;
            }
            // Solucao margem 1 para right

            solucoes.push_back(2);
            break;
        }

        for (int j = right; j > 0; j++) {
            int complement_right = right - j - 2;
            if (complement_right >= j) break;

            if (j == k || complement_right == k || j == i || j == complement_left || complement_right == k || complement_right == complement_left) {
                continue;
            }
            // Solucao margem 2 para right

            solucoes.push_back(3);
            break;
        }
        break;
    }

    for (int i = left; i > 0; i++) {
        int complement_left = left - i - 2;
        if (complement_left >= i) break;
    
        if (i == k || complement_left == k) continue;
        // Solucao com margem 1 para left

        for (int j = right; j > 0; j++) {
            int complement_right = right - j;
            if (complement_right >= j) break;

            if (j == k || complement_right == k || j == i || j == complement_left || complement_right == k || complement_right == complement_left) {
                continue;
            }
            // Solucao exata para right

            solucoes.push_back(2);
            break;
        }

        for (int j = right; j > 0; j++) {
            int complement_right = right - j - 1;
            if (complement_right >= j) break;

            if (j == k || complement_right == k || j == i || j == complement_left || complement_right == k || complement_right == complement_left) {
                continue;
            }
            // Solucao margem 1 para right

            solucoes.push_back(3);
            break;
        }

        for (int j = right; j > 0; j++) {
            int complement_right = right - j - 2;
            if (complement_right >= j) break;

            if (j == k || complement_right == k || j == i || j == complement_left || complement_right == k || complement_right == complement_left) {
                continue;
            }
            // Solucao margem 2 para right

            solucoes.push_back(4);
            break;
        }
        break;
    }

    sort(solucoes.begin(), solucoes.end());

    return solucoes[0];
}

// _ _ _ X X _ _ 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> e;

    int left = e;
    int right = n - left - k;
    int solucao = resolve(left, right);
    cout << solucao << endl;
    
    // for (int i = 1; i < max(left, right); i++) {
    //     int k = i % 2;

    //     if (left == k) {

    //     } else if (right == k) {

    //     } else {
    //         int prevSol = cache[left][right][(k-1) % 2];
    //     }
    // }

    // int spacesLeft = e;
    // int spacesRight = n-k_i-e;    

    // auto res = dp(spacesLeft, spacesLeft, max(spacesLeft, spacesLeft));
    // cout << res << endl;
    
    


    // // a = left - b;
    // // a = left - b - 1;
    // // c + d = right;

    // // k \not\in {a, b, c, d}
    // // |{a, b, c, d}| = 4

    
    // min left + right;
    // s.a. i != k
    // Inleft[i] + InRight[i] <= 1
    
    
    return 0;
}
