#include <string>
#include <vector>
#include<iostream>
#include<sstream>
#include <algorithm>
vector<string> v = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

class MatchAndIndex {
public :
    bool isMatch = false;
    char index = 0;
};
MatchAndIndex MatchIndex(string s)
{
    MatchAndIndex mi;
    for (int j = 0; j < v.size(); j++)
    {
        if (s == v[j])
        {
            mi.isMatch = true;
            mi.index = j+'0';
            cout << "MatchIndex(" << mi.isMatch << "," << mi.index << ")" <<endl;
            break;
        }
    }
    return mi;
}
string DeleteString(string s, int index)
{
    for (int i = 0; i < index; i++)
        s.erase(s.begin()+0);
    return s;
}


//영어가싫어요 3점 / find,replace 활용 && regex,replace활용
long long solutionHateEng(string numbers) {
    long long answer = 0;
    string answer2 = "";
    string temp = "";
    int i = 0;
    /*vector<string> num = {
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"
    };
    int tmp;

    for (int i = 0; i < num.size(); i++)
    {
        while ((tmp = numbers.find(num[i])) != string::npos)
        {
            cout << "tmp : " << tmp << endl;
            cout << "num[i].size() : " << num[i].size() << endl;
            numbers.replace(tmp, num[i].size(), to_string(i));
        }
    }
    numbers = regex_replace(numbers, regex("zero"), "0");
    numbers = regex_replace(numbers, regex("one"), "1");
    numbers = regex_replace(numbers, regex("two"), "2");
    numbers = regex_replace(numbers, regex("three"),"3");
    numbers = regex_replace(numbers, regex("four"), "4");
    numbers = regex_replace(numbers, regex("five"), "5");
    numbers = regex_replace(numbers, regex("six"), "6");
    numbers = regex_replace(numbers, regex("seven"), "7");
    numbers = regex_replace(numbers, regex("eight"), "8");
    numbers = regex_replace(numbers, regex("nine"), "9");
    answer = stoll(numbers);
    return answer;*/
    while (numbers.size() != 0)
    {
        MatchAndIndex result;
        if (i <= 2)
        {
            temp.push_back(numbers[i]);
            i++;
            cout << "i가 3보다 작은 경우 :" << i << endl;
            cout << "temp : " << temp << endl;
            continue;
        }
        //cout <<"isMatch :" << isMatch(temp) << endl;
        
        result = MatchIndex(temp);
        cout << "mi :" << result.isMatch << "," << result.index << endl;
        if (result.isMatch == true) {
            answer2.push_back(result.index);
            numbers = DeleteString(numbers, i);
            temp = "";
            i = 0;
        }
        else
        {
            temp.push_back(numbers[i]);
            i++;
        }
        cout << "-----------------------" << endl;
        cout << "i :"<< i << endl;
        cout << "answer :"<< answer2 << endl;
        cout << "numbers :"<< numbers << endl;
        cout << "temp : " << temp << endl;
    }
    answer = stoll(answer2);
    return answer;
}
int main()
{
    vector<int> v = {1,2,3,4,5};
    string s = "onefourzerosixseven";
    //cout << DeleteString(s,3);
    
    
}
