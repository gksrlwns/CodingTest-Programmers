#include <string>
#include <vector>

using namespace std;

//12Á¡ 
int solution(int balls, int share) {
    long long answer = balls;
    long long sizeFac = 1;
    int size = balls - share;
    int temp = balls;
    if (size == 0) return 1;
    while (size != 1)
    {
        temp--;
        answer *= temp;        
        if (answer % size == 0) answer /= size;
        else sizeFac *= size;
        size--;
    }
    return answer/sizeFac;
}
/*int combi(int n, int r){
    if(r == 0) return 1;
    if(n == 1) return 1;
    if(r >= n) return 1;
    return combi(n-1, r) + combi(n-1, r-1);
}

int solution(int balls, int share) {
    int answer = 0;
    answer = combi(balls, share);
    return answer;
}
