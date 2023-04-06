#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    int x = 0;
    int y = 0;
    while (polynomial.find('x') != -1)
    {
        int index = polynomial.find('x');
        if (index == 0)
        {
            x++;
            polynomial.erase(polynomial.begin());
        }
        else if (polynomial[index - 1] == ' ')
        {
            x++;
            polynomial.erase(index - 1, index + 1);
        }
        else
        {
            x += polynomial[index - 1] - '0';
            polynomial.erase(index - 1, index + 1);
        }
    }
    
    
    for (auto& a : polynomial)
    {
        if (isdigit(a)) y += a - '0';
        
    }
    if (x == 1)
    {
        answer += "x";
    }
    else if (x > 1)
    {
        answer += x+'0';
        answer += "x";
    }
    if (x == 0 && y >= 1)
    {
        answer += y + '0';
    }
    else if (y != 0)
    {
        answer += " + ";
        answer += y + '0';
    }
    
    return answer;
}
