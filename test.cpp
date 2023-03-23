#include <string>
#include <vector>
#include <sstream>
#include <iostream> 
using namespace std;

int solution(string my_string) {
    int answer = 0;

    stringstream ss;
    ss.str(my_string);

    ss>>answer;
	cout << answer << endl;
    char ch;
    int tmp = 0;
    while(ss)
    {
        if(ch == '+')
        {
            answer += tmp;
        }
        else if(ch == '-')
        {
            answer -= tmp;
        }
        cout <<"temp :"<< tmp <<endl;
    	cout <<"ch :"<< ch <<endl;
    	cout <<"answer :"<< answer << endl;
        ss >> ch >> tmp;
        cout <<"temp :"<< tmp <<endl;
    	cout <<"ch :"<< ch <<endl;
    	cout <<"answer :"<< answer << endl;
    	cout <<"天天天天天天天天天天天天天"<<endl;
    }
    return answer;
}
int main()
{
	string s = "30 + 4 + 3 - 5";
	cout << solution(s);
}
