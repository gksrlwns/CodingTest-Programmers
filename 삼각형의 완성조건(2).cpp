#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//1�� 
int solution(vector<int> sides) {
    int answer = 0;
    sort(sides.begin(), sides.end());
    int sum = accumulate(sides.begin(), sides.end(), 0);
    for (int i = 1; i <= sum; i++)
    {
        if (i < sides[1] && (i + sides[0]) > sides[1])
        	answer++;
        else if (i >= sides[1] && i < sum)
        	answer++;
    }
    return answer;
}
/* ��� https://tnsgh9603.tistory.com/137
���������� Ǯ �� �ִ� ����� �ִ�.

������ �˰� �ִ� ���� a, b��� ����.(a>b)

�̶�, ���� �Է� �޴� c�� a���� Ŭ ���� �ְ� ���� ���� �ְ� ���� ���� �ִ�.

 

i) c�� a���� ũ�� ��Ұ���� c > a > b�� �ȴ�.

a + b > c  �̹Ƿ� a + b > c > a�� �ȴ�.

�� �̶� ������ c�� ������ b - 1��

 

ii) c�� a���� ������ ��Ұ���� a > b, a > c �� �ȴ�.

b + c > a �̹Ƿ� b + c > a > c�� �ȴ�.

�� �̶� ������ c�� ������ b - 1��

 

iii) c�� a�� ������ c = a �� ���� �ۿ� �������� �ʴ´�.

 

�׷��Ƿ� �� ���ϸ� (b - 1) + (b - 1) + 1 = 2 * b - 1 ���� �ȴ�.

�̶� �ʱ� ���ǿ� ���� b�� a���� ����
int solution(vector<int> v)
{
    if(v[0] < v[1])
        swap(v[0],v[1]);
    return v[1] * 2 - 1;
}
