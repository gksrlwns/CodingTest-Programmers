#include <string>
#include <vector>
#include <map>

using namespace std;

//6점 굳이 나누지 않아도 됐다.. 그냥 합으로 해도 상관 x 
vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<float> average;
    for (auto a : score) average.push_back((a[0] + a[1]) /(float) 2);
    map<float, int, greater<float>> m;
    for (auto e : average) m[e]++;
    int order = 1;
    int temp;
    for (auto& e : m) {
        temp = e.second;
        e.second = order;
        order += temp;
    }
    for (auto& e : average)
    {
        e = m[e];
        answer.push_back(e);
    }  
    return answer;
}
/*vector<int> answer;
    for(auto& s : score)
    {
        s.emplace_back(s[0] + s[1]);
    }

    for(const auto v : score)
    {
        int count = 0;
        for(const auto t : score)
        {
            count += (t[2] > v[2]);
        }
        answer.emplace_back(count + 1);
    }
