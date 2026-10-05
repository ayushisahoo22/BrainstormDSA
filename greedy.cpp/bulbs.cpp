#include <bits/stdc++.h>
using namespace std;

double maxAverageWorkingRatio(vector<vector<int>>& bulbs, int n, int extra) {
    priority_queue<tuple<double, int, int> > pq;
    for(auto it : bulbs) {
        int w = it[0];
        int t = it[1];
        double gain = (double)(w + 1) / (t + 1) - (double)w / t;
        pq.push(make_tuple(gain, w, t));
    }
    while(extra--) {
        tuple<double, int, int> top = pq.top();
        pq.pop();
        double gain = get<0>(top);
        int w = get<1>(top);
        int t = get<2>(top);
        w++;
        t++;
        gain = (double)(w + 1) / (t + 1) - (double)w / t;
        pq.push(make_tuple(gain, w, t));
    }
    double sum = 0;
    while(!pq.empty()) {
        tuple<double, int, int> top = pq.top();
        pq.pop();
        int w = get<1>(top);
        int t = get<2>(top);
        sum += (double)w / t;
    }
    return sum / n;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n, extra;
        cin >> n >> extra;
        vector<vector<int>> bulbs(n, vector<int>(2));
        for(int i = 0; i < n; i++) {
            cin >> bulbs[i][0] >> bulbs[i][1];
        }
        double ans = maxAverageWorkingRatio(bulbs, n, extra);
        cout << fixed << setprecision(5) << ans << endl;
    }
    return 0;
}