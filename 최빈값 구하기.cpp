#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    map<int, int> m;
    for (auto& a : array) m[a]++;
    int max = 0;
    for (auto& a : m)
    {
        if (a.second > max)
        {
            max = a.second;
            answer = a.first;
        }
        else if (a.second == max)
        {
            answer = -1;
        }
    }
    return answer;
}
