#include <string>
#include <vector>

using namespace std;
//3점 너무 어렵게 풀어버렸다. 
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
int MulOfArray(vector<int> v)
{
    int x = 1;
    for (auto a : v)
        x *= a;
    return x;
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer,numer,denom;
    if (denom1 == denom2) numer1 += numer2;
    else {
        numer1 = numer1 * denom2 + numer2 * denom1;
        denom1 *= denom2;
    }
    numer = Divisor(numer1);
    denom = Divisor(denom1);
    
    for (int i = 0; i < denom.size();)
    {
        bool isEqual = false;
        
        for (int j = 0; j < numer.size();)
        {
            if (denom[i] == numer[j])
            {
                denom.erase(denom.begin() + i);
                numer.erase(numer.begin() + j);
                isEqual = true;
                break;
            }
            else
                j++;
        }
        if (!isEqual) i++;
    }

    answer.push_back(MulOfArray(numer));
    answer.push_back(MulOfArray(denom));

    return answer;
}
/*
약수를 구하는 동시에 나눠주면 된다.. 
vector<int> answer;
    int denum = (denum1 * num2) + (denum2 * num1);
    int num = num1 * num2;

    for(int i = min(denum, num); i >= 2 ; i--)
    {
        if(denum % i == 0 && num % i == 0)
        {
            denum /= i;
            num /= i;
            break;
        }
    }
    answer.push_back(denum);
    answer.push_back(num);

    return answer;
