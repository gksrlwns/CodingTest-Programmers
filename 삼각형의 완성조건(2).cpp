#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

//1점 
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
/* 대박 https://tnsgh9603.tistory.com/137
수학적으로 풀 수 있는 방법이 있다.

기존에 알고 있는 변이 a, b라고 하자.(a>b)

이때, 새로 입력 받는 c가 a보다 클 수도 있고 같을 수도 있고 작을 수도 있다.

 

i) c가 a보다 크면 대소관계는 c > a > b가 된다.

a + b > c  이므로 a + b > c > a가 된다.

즉 이때 가능한 c의 갯수는 b - 1개

 

ii) c가 a보다 작으면 대소관계는 a > b, a > c 가 된다.

b + c > a 이므로 b + c > a > c가 된다.

즉 이때 가능한 c의 갯수는 b - 1개

 

iii) c와 a가 같으면 c = a 한 가지 밖에 존재하지 않는다.

 

그러므로 다 합하면 (b - 1) + (b - 1) + 1 = 2 * b - 1 개가 된다.

이때 초기 조건에 따라 b는 a보다 작음
int solution(vector<int> v)
{
    if(v[0] < v[1])
        swap(v[0],v[1]);
    return v[1] * 2 - 1;
}
