#include <string>
#include <vector>

using namespace std;
//1¡° substr»∞ 
vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string temp = "";
    /*for (int i=0; i<my_str.length(); i+=n){
        answer.push_back(my_str.substr(i,n));
    }*/
    int i = 0;
    if (n == 0)answer.push_back(my_str);
    for (int i = 0; i < my_str.size(); i++)
    {
        temp += my_str[i];
        if ((i+1)%n == 0)øÎ 
        {
            answer.push_back(temp);
            temp = "";
        }
        else if (i == (my_str.size() - 1))
        {
            answer.push_back(temp);
        }
    }
    return answer;
}

