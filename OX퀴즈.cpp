#include <string>
#include <vector>
#include <sstream> 

using namespace std;

//1�� 
string OX(string quiz)
{
    int x, y, z;
    char cal,t;
    
    istringstream iss(quiz);
    while (iss)
    {
        iss >> x;
        iss >> cal;
        iss >> y;
        iss >> t;
        iss >> z;
        cout << x << cal << y << t << z;
        if (cal == '+')  return x + y == z ? "O" : "X";
        else return x - y == z ? "O" : "X";
    }
}
vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for (auto a : quiz)
    {
        answer.push_back(OX(a));
    }
    return answer;
}
/*
order�� Ȱ���Ͽ� �ʿ��� ������ ���� 
while(ss >> str_buf) 
        {
            if(order == 0)
                num1 = stoi(str_buf);
            else if (order == 1) 
                op = str_buf;
            else if (order == 2)
                num2 = stoi(str_buf);
            else if (order == 4)
                res = stoi(str_buf);

            order++;   
        }
