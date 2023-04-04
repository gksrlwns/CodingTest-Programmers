#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//3�� ó���� Ʋ������ �ּڰ��� 10001�� �����Ͽ��� if���� �������� ��� �ּڰ��� answer�� �� 
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
****sort�� �̿��Ͽ� �� 
 sort(numlist.begin(), numlist.end(),
         [n](int a, int b)
int num; <<--- �����Լ��� �̿��Ͽ� n���� ������ 

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
***Pair�� ��� 
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
