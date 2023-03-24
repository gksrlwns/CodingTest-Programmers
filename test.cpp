#include <string>
#include <vector>
#include <sstream>
#include <iostream> 
using namespace std;

int combi(int n, int r){
    if(r == 0) return 1;
    if(n == 1) return 1;
    if(r >= n) return 1;
    cout << "n : " << n <<"r : " << r <<endl;
    return combi(n-1, r) + combi(n-1, r-1);
}

int solution(int balls, int share) {
    int answer = 0;
    answer = combi(balls, share);
    return answer;
}
int main()
{
	string s = "30 + 4 + 3 - 5";
	cout << solution(10, 8);
}
