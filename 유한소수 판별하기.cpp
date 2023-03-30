#include <string>
#include <vector>
//7Á¡ 
using namespace std;
vector<int> Divisor(int a){
    vector<int> divisor;
    int i = 2;
    while (a >= i)
    {
        if (a % i == 0)
        {
            divisor.push_back(i);
            a /= i;
            i = 2;
        }
        else i++;
    }
    return divisor;
}
int solution(int a, int b) {
    vector<int> numerator = Divisor(a);
    vector<int> denominator = Divisor(b);
    for (auto a : numerator)
    {
        for (int i = 0; i < denominator.size(); i++)
            if (a == denominator[i])
            {
                denominator.erase(denominator.begin() + i);
                break;
            }
    }
    for (auto a : denominator)
        if (a != 2 && a != 5) return 2;
    return 1;
}
/* ¹ÌÃÆ´Ù.. 
int solution(int a, int b) {
    int answer = 0;
    while(b % 2 == 0)
    {
        b /= 2;
    }
    while(b % 5 == 0)
    {
        b /= 5;
    }
    return (a % b == 0)?1:2;
}
