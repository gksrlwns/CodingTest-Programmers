#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int solutionAdd(int n);
int main()
{
    vector<int> v = { 1,2,3,4,5 };
    //cout << solutionCompare()
}
//개미군단
int solutionAnt(int hp) {
    int answer = 0;
    while (1)
    {
        if (hp >= 5)
        {
            answer = hp / 5;
            hp %= 5;
        }
        else if (hp >= 3)
        {
            answer += hp / 3;
            hp %= 3;
        }
        else
        {
            answer += hp;
            break;
        }
    }
    return answer;
}

//스트링 속 자연수
int solutionNum(string my_string) {
    int answer = 0;
    
    return answer;
}

//문자여 비교
int solutionCompare(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for(auto a : s1)
        for (auto b : s2)
        {
            if (b.compare(a) == 0)
                answer++;
        }
    return answer;
}

// 자릿수더하기
int solutionAdd(int n) {
    string toString = to_string(n);
    cout << toString << endl;
    int answer = 0;
    for (int a : toString)
    {
        cout << a << endl;
        answer += a;
    }
    /*int answer = 0;
    while (n > 0)
    {
        answer += n % 10;
        n /= 10;
    }
    return answer;*/
    return answer;
}

//편지
int solutionLetter(string message) {
    int answer = message.length() * 2;
    return answer;
}
//짝수 싫어요
vector<int> solutionOddNum(int n) {
    vector<int> answer;
    for (int i = 1; i <= n; i ++) if (i % 2 == 1) answer.push_back(i);
    return answer;
}


//삼각형 변 2점? 3점?
int solutionSides(vector<int> sides) {
    sort(sides.begin(), sides.end());
    return sides[2] < sides[0] + sides[1] ? 1 : 2;
}

//중앙값 3점
int solutionCenter(vector<int> array) {
    sort(array.begin(), array.end());
    int i = array.size() / 2;
    return array[i];
}

//최댓값 만들기 다르게풀기
int solutionMax(vector<int> numbers) {
    int max = 0;
    int j = 0;
    int max2 = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
            j = i;
        }
    }
    for (int i = 0; i < numbers.size(); i++)
    {
        if (i != j && numbers[i] <= max) max2 = numbers[i];
    }
    /*sort(numbers.begin(), numbers.end()); \
     answer = numbers[numbers.size() - 2] * numbers[numbers.size() - 1];*/
    
    return max*max2;
}

//최댓값 만들기 1
//int solutionMax(vector<int> numbers) {
//    int max = 0;
//    int max2 = 0;
//    for (auto a : numbers)
//    {
//        if (a > max)
//        {
//            max = a;
//            cout << max << endl;
//        }
//    }
//    
//    for (auto a : numbers)
//    {
//        if (a <= max && a > max2)
//        {
//            max2 = a;
//            cout << max2 << endl;
//        }
//    }
//    cout << "max =" << max << ", max2 =" << max2 << endl;
//    return max * max2;
//}

//10점이요 옷가게할인
//int solution(int price) {
//    float discount = 0;
//    discount = price >= 500000 ? 0.2 : (price >= 300000 ? 0.1 : (price >= 100000 ? 0.05 : 0));
//    return price - price*discount;
//}

//2
int solution(vector<int> dot) {
    int answer = 0;
    if (dot[0] * dot[1] > 0)
    {
        if (dot[0] > 0) answer = 1;
        else answer = 3;
    }
    else
    {
        if (dot[0] > 0) answer = 4;
        else answer = 2;
    }
    //return dot[0] > 0 ? (dot[1] > 0 ? 1 : 4) : (dot[1] < 0 ? 3 : 2);
    return answer;
}

int solution(vector<int> array, int n) {
    int answer = 0;
    //answer = count(array.begin(), array.end(), n);
    for (auto a : array)
    {
        if (a == n)
            answer++;
    }
    return answer;
}
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

vector<int> solution1(vector<int> num_list) {
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
vector<int> solution2(vector<int> num_list) {
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
