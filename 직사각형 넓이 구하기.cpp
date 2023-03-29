#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//6�� 
int solution(vector<vector<int>> dots) {
    vector<int> vx;
    vector<int> vy;
    //x ���� ������ ������ y�� ���� / y���� ������ ������ x�� ����.
    for (auto a : dots)
    {
        vx.push_back(a[0]);
        vy.push_back(a[1]);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    return (vx[2]-vx[1])* (vy[2] - vy[1]);
}
/*

[1][1]
[2][1]
[2][2]
[1][2]
�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�
[1][1]
[1][2]
[2][1]
[2][2]
    sort(dots.begin(), dots.end());
    answer=(dots[3][0]-dots[0][0])*(dots[3][1]-dots[0][1]);

    return answer;
