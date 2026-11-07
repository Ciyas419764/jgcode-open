#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

int jmd_beer[MAXN];
int jmd_distance[MAXN];
long long qzh[MAXN + 1] = {0};

// ===== 原始代码逻辑开始 =====
void calculate_qzh_original(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += jmd_distance[i];
        qzh[i + 1] = sum;
    }
}

int calculate_distance_original(int jmd_a, int jmd_b, int n) {
    int jmd_min = min(jmd_a, jmd_b);
    int jmd_max = max(jmd_a, jmd_b);
    return min(qzh[jmd_max] - qzh[jmd_min],
               qzh[n] - qzh[jmd_max] + qzh[jmd_min]);
}

pair<int, long long> run_original(int n) {
    calculate_qzh_original(n);

    long long minCost = 2147483647LL;
    int min_idx = 0;

    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            sum += calculate_distance_original(i, j, n) * jmd_beer[j];
        }
        if (sum < minCost) {
            minCost = sum;
            min_idx = i;
        }
    }

    return {min_idx, minCost};
}
// ===== 原始代码逻辑结束 =====

int main() {
    const int n = 10000;

    // 距离上限。默认 100000，用于压测 O(n^2) 性能。
    // 注意：这个数据规模下原始代码的 int 乘法可能溢出，结果不保证正确，但计时有效。
    const int MAX_DIS = 100000;

    mt19937 rng(20261106);
    uniform_int_distribution<int> distBeer(1, 2000);
    uniform_int_distribution<int> distDis(1, MAX_DIS);

    long long totalDis = 0;

    for (int i = 0; i < n; i++) {
        jmd_beer[i] = distBeer(rng);
        jmd_distance[i] = distDis(rng);
        totalDis += jmd_distance[i];
    }

    // 写出 input.txt，方便你再用原程序单独测试
    ofstream fout("input.txt");
    fout << n << '\n';
    for (int i = 0; i < n; i++) {
        fout << jmd_beer[i] << ' ' << jmd_distance[i] << '\n';
    }
    fout.close();

    cout << "n = " << n << '\n';
    cout << "totalDis = " << totalDis << '\n';
    cout << "input.txt generated.\n";

    memset(qzh, 0, sizeof(qzh));

    auto start = chrono::high_resolution_clock::now();
    auto ans = run_original(n);
    auto end = chrono::high_resolution_clock::now();

    double ms = chrono::duration<double, milli>(end - start).count();

    cout << "original answer = " << ans.first << "," << ans.second << '\n';
    cout << fixed << setprecision(3);
    cout << "original time = " << ms << " ms\n";

    return 0;
}