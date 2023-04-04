#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//3점 처음에 틀린이유 최솟값을 10001로 지정하여서 if문이 돌지않은 경우 최솟값이 answer에 들어감 
vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    while (numlist.size() != 0)
    {
        int min = numlist[numlist.size()-1];
        int index = numlist.size() - 1;
        for (int i = 0; i < numlist.size(); i++)
        {
            if (abs(n - numlist[i]) < abs(n - min)) {
                index = i;
                min = numlist[i];
            }
            else if (abs(n - numlist[i]) == abs(n - min)) {
                index = numlist[i] > min ? i : index;
                min = numlist[i] > min ? numlist[i] : min;
            }
        }
        answer.push_back(min);
        numlist.erase(numlist.begin() + index);
    }
    
    return answer;
}
/*
****sort를 이용하여 비교 
 sort(numlist.begin(), numlist.end(),
         [n](int a, int b)
int num; <<--- 전역함수를 이용하여 n값을 가져옴 

bool compare(int prev, int next) {
    if (abs(prev - num) == abs(next - num)) 
        return prev > next;
    return abs(prev - num) < abs(next - num);
}

vector<int> solution(vector<int> numlist, int n) {
    num = n;
    sort(numlist.begin(), numlist.end(), compare);
    return numlist;
}
***Pair를 사용 
bool comp(pair<int,int> a, pair<int,int> b)
{
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<pair<int,int>> ans;
    //first -> absolute number
    //second -> real number

    for(int i = 0; i<numlist.size(); i++)
        ans.push_back(make_pair(abs(numlist[i]-n),numlist[i]));

    sort(ans.begin(),ans.end(),comp);
    for(int i = 0; i<ans.size(); i++)
    {
        answer.push_back(ans[i].second);
    }
    return answer;
}
