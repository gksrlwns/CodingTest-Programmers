#include <string>
#include <vector>

using namespace std;

//4�� 
int solution(string A, string B) {
    int answer = 0;
    char temp;
    if (A == B) return 0;
    for (int i = 0; i < A.size() - 1; i++)
    {
        answer++;
        temp = A[A.size()-1];
        A.erase(A.begin()+ A.size() - 1);
        A.insert(A.begin(), temp);
        if (A == B) return answer;
    }
    return -1;
}
/* ���� ����ϰ� Ǭ ���� Rotate�Լ� ��� + i�� count�� ���������� ��� ����Ȱ�� 
int answer = -1;
    for(int i = 0; i < A.size(); ++i)
    {
        if(A == B)
        {
            answer = i;
            break;
        }
        rotate(A.begin(),A.end()-1,A.end());
    }
    return answer;
    
    ���ƴ� 
    B += B;
    return B.find(A);
