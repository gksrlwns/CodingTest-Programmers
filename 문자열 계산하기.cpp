#include <string>
#include <vector>
#include <sstream>

using namespace std;
//¿À 8Á¡ 
int solution(string my_string) {
    int answer = 0;
    istringstream iss;
    vector<char> v;
    v.push_back('+');
    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string[i] == '+' || my_string[i] == '-')
        {
            v.push_back(my_string[i]);
            my_string[i] = ' ';
        }
    }    

    iss.str(my_string);
    int x,i = 0;
    while (iss>>x)
    {
        if (v[i] == '+') answer += x;
        else answer -= x;
        i++;
    }
    return answer;
    /*
    stringstream ss(my_string);
    char op; int num;

    int result;
    ss >> result;
    while (!ss.eof()) {
        ss >> op;
        ss >> num;

        if (op == '+') result += num;
        else result -= num;
    }

    return result;*/
}

