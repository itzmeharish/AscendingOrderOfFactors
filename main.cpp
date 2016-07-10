#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    //cout << "Hello, World!" << endl;
    int n;
    cin >> n;
    vector<pair<double, string>> series;
    cout << 0 << "/" << 1;
    for(int i = 1; i < n; i++) {
        for(int j = n; j > 1; j--) {
            if(i/j > 0 || i/j == 1 || (j%i == 0 && i != 1))
                continue;
            stringstream ss;
            ss << i;
            ss << "/";
            ss << j;
            series.push_back(pair<double , string>(((double)i/(double)j), ss.str()));
        }
    }
    sort(series.begin(), series.end());
    unique(series.begin(), series.end());
    //for(int i = 0; i < series.size() && (i == 0 || series[i].first != series[i-1].first); i++) {
    for(int i = 0; i < series.size(); i++) {
        if(i != 0 && series[i].first == series[i-1].first)
            continue;
        cout << ",";
        cout << series[i].second;
    }
    cout << ",";
    cout << 1 << "/" << 1;
    return 0;
}