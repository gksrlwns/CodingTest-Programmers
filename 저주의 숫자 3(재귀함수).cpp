#include <iostream>
using namespace std;
int dp(int number, int i,int j){
        if (j % 3 == 0 || j % 10 == 3 || j / 10 == 3 || (j/10)%10 == 3) {
            cout << "number : " << number << ", i : " << i << ", j : " << j << endl;
            dp(number, i, j + 1);
        }

        else if (number == i) {
            cout << "number : " << number << ", i : " << i << ", j : " << j << endl;
            return j;
        }
        else
        {
            cout << "number : " << number << ", i : " << i << ", j : " << j << endl;
            dp(number, i + 1, j + 1);
        }
}
int CurseNum3Test(int n)
{
    int answer = 0;
    answer = dp(n, 1, 1);
    return answer;
}
int main()
{
	cout << CurseNum3Test(15);
 } 
