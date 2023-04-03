#include <string>
#include <vector>

using namespace std;

//4점 너무 생각없이 풀었음 재귀함수를 활용하도록 
bool Divisor3(int n)
{
    if (n % 3 == 0) return true;
    else return false;
}
int solution(int n) {
    int answer = 0;
    int count = 1;
    while (count != n+1)
    {
        answer++;
        if ((answer / 10) == 3){
        	answer += 10;
		}
        if (Divisor3(answer)) answer++;
        if (answer > 10 && (answer % 10) == 3|| Divisor3(answer))
        {
        	answer++;
		}
        if (Divisor3(answer)) answer++;
        if(((answer / 10) % 10) == 3)answer += 10;
        count++;
    }
    return answer;
}
/*

for(int i=0;v.size()<=n;i++){
        string s=to_string(i);
        if(i%3!=0 && find(s.begin(),s.end(),'3')==s.end()){
            v.push_back(i);
        }
    }
    return v[n-1];
    나머지는 비슷 
for(int i = 1; i <= n; i++){
        answer++;
        while (answer%3 == 0 || answer%10 == 3 || (answer/10)%10 == 3) answer++;
    }
    int cnt = 0;
	for(int i = 1; i<=n; i++)
    {
        cnt++;
        if( (cnt % 3 == 0)|| isThree(cnt) )  {
            while( (cnt % 3 == 0)|| isThree(cnt) )
                cnt++;
        }
    }
