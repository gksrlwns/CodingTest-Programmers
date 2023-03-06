#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string solution(string my_string, string letter) {
    string answer = "";
    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string[i] == letter[0]) continue;
        else answer.push_back(my_string[i]);
    }
    return answer;
}

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i * (n / i) == n)
            answer++;
    }
    return answer;
}

vector<int> solution(vector<int> num_list) {
    vector<int> answer = { 0,0 };
    for (int i = 0; i < num_list.size(); i++)
    {
        if (num_list[i] % 2 == 0)
            answer[1]++;
        else
            answer[0]++;
    }
    return answer;
}
vector<int> solution(vector<int> num_list) {
    vector<int> answer(2, 0);
    for (int num : num_list) {
        answer[num % 2]++;
    }
    return answer;
}

//int solution(vector<int> array, int height) {
//    int answer = 0;
//    for (int i = 0; i < array.size(); i++)
//    {
//        if (array[i] > height)
//            answer++;
//    }
//    return answer;
//}
////1
////vector<int> solution(int money) {
////    vector<int> answer;
////    answer.push_back(money / 5500);
////    answer.push_back(money % 5500);
////    return answer;
////}
////4
//string solution(string my_string, int n) {
//    string answer = "";
//    for (int i = 0; i < my_string.size(); i++)
//        for (int j = 0; j < n; j++)
//            answer.push_back(my_string[i]);
//    return answer;
//}
////다른사람
//string solution(string my_string, int n) {
//    string answer = "";
//    for (const auto v : my_string)
//    {
//        answer += string(n, v);
//    }
//    return answer;
//}
//vector<int> solution(vector<int> numbers, int num1, int num2) {
//    vector<int> answer;
//    for (int i = num1; i <= num2; i++)
//        answer.push_back(numbers[i]);
//    return answer;
//}
//
//vector<int> solution(vector<string> strlist) {
//    vector<int> answer;
//    for (int i = 0; i < strlist.size(); i++)
//    {
//        answer.push_back(strlist[i].size());
//    }
//    return answer;
//}
//
//string solution(string my_string) {
//    string answer = "";
//    reverse(my_string.begin(), my_string.end());
//    return my_string;
//}
//
//vector<int> solution(vector<int> num_list) {
//    vector<int> answer;
//    for (int i = num_list.size() - 1; i >= 0; i--)
//    {
//        answer.push_back(num_list[i]);
//    }
//    return answer;
//}
//vector<int> solution(vector<int> numbers) {
//    vector<int> answer;
//    answer = numbers;
//    for (int i = 0; i < answer.size(); i++)
//    {
//        answer[i] *= 2;
//    }
//    return answer;
//}
//double solution(vector<int> numbers) {
//    double answer = 0;
//    for (int i = 0; i < numbers.size(); i++)
//    {
//        answer += numbers.at(i);
//    }
//    return answer / numbers.size();
//}
int main()
{
    cout << solution(20);
}