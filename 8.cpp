#include <iostream>
#include <string> 
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;
int main() {
    string s;
    vector <pair<int, int>> t;
    int count = 0;
    ifstream file("input.txt");
    while (getline(file, s)) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                int a = stoi(s.substr(0, i));
                int b = stoi(s.substr(i + 1, s.length()));
                pair <int, int> p;
                p.first = a;
                p.second = b;
                t.push_back(p);
                count++;
            }
        }
    }
    file.close();
    double mini = 1000000000000000000000.0;
    double maxi = 0.0;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (i != j) {
                double d = sqrt((t[i].first - t[j].first) * (t[i].first - t[j].first) + (t[i].second - t[j].second) * (t[i].second - t[j].second));
                if (d < mini) {
                    mini = d;
                }
                if (d > maxi) {
                    maxi = d;
                }
            }
        }
    }
    cout << mini << " " << maxi << endl;
    return 0;
}
