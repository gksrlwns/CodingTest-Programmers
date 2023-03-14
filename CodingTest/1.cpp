#include<iostream>
#include<sstream>
#include<map>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <cmath>
using namespace std;
string solutionMos(string letter);
string solutionDuplicate(string my_string);
int main()
{
    cout <<solutionDuplicate("peolzzz");
}
map<string, char> m = {
    {".-",'a'},{"-...",'b'},{"-.-.",'c'},{"-..",'d'},
    {".",'e'},{"..-.",'f'},{"--.",'g'},{"....",'h'},
    {"..",'i'},{".---",'j'},{"-.-",'k'},{".-..",'l'},
    {"--",'m'},{"-.",'n'},{"---",'o'},{".--.",'p'},
    {"--.-",'q'},{".-.",'r'},{"...",'s'},{"-",'t'},
    {"..-",'u'},{"...-",'v'},{".--",'w'},{"-..-",'x'},
    {"-.--",'y'},{"--..",'z'}
};
//모스부호
string solutionMos(string letter) {
    string answer = "";
    string letterTemp = "";
    vector<string> v = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
    /*stringstream ss(letter);
    string s;

    while (!ss.eof()) {
        ss >> s;
        auto t = m.find(s);
        if (t != m.end()) {
            answer += t->second;
        }
    }
    return answer;*/
    for (int i = 0; i < letter.size(); i++)
    {
        if (letter[i] != ' ')
            letterTemp.push_back(letter[i]);
        else
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (letterTemp == v[j])
                {
                    answer.push_back(j + 'a');
                    break;
                }
            }
            letterTemp = "";
        }
        if (i == letter.size() - 1)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (letterTemp == v[j])
                {
                    answer.push_back(j + 'a');
                    break;
                }
            }
        }
    } 
    return answer;
}

//중복문자제거
string solutionDuplicate(string my_string) {
    string answer = "";
    int size = my_string.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (my_string[i] == my_string[j])
                my_string.erase(my_string.begin() + j);
            cout <<i << ","<<j<<","<< my_string << endl;
        }
        answer.push_back(my_string[i]);
    }
    return my_string;
    /*string answer = "";
    my_string.erase(unique(my_string.begin(), my_string.end()), my_string.end());
    return my_string;*/
}
//합성수찾기 약수 3개 4점
int solutionDivisor2(int n) {
    int answer = 0;
    int a = 0;
    for (int i = 1; i <= n; i++)
    {
        int divisor = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0) divisor++;
            if (divisor >= 3)
            {
                answer++;
                cout << i << ",";
                break;
            }
        }        
    }
    return answer;
}
//문자열정렬
string solutionString2(string my_string) {
    string answer = "";
    for (auto a : my_string)
        answer.push_back(tolower(a));
    sort(answer.begin(),answer.end());
    return answer;
}
//숫자찾기 4점
int solutionFindNum(int num, int k) {
    int answer = 0;
    string a = to_string(num);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i]<< " ";
        if ((a[i]-'0') == k) {
            answer = i + 1;
            break;
        }
        else answer = -1;
        cout << answer << endl;
    }
    return answer;
}

//369 8점
int solution369(int order) {
    int answer = 0;
    string a = to_string(order);
    for (auto a : a) if (a == '3' || a == '6' || a == '9') answer++;
    return answer;
}
//약수
vector<int> solutionDivisor(int n) {
    vector<int> answer;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            answer.push_back(i);
    }
    return answer;
}
//외계행성 나이+49
string solution(int age) {
    string answer = "";
    answer = to_string(age);
    for (auto& a : answer) a += 49;
    return answer;
}
//피자나눠먹기2 3점
int solutionpizza(int n) {
    int answer = 0;
    while (1)
    {
        answer++;
        if ((answer * 6) % n == 0)
            break;
    }
    return answer;
}

//가장 큰 수
vector<int> solution(vector<int> array) {
    vector<int> answer;
    /*auto t = max_element(array.begin(), array.end());
    answer.push_back(*t);
    answer.push_back(distance(array.begin(), t));*/
    int max = 0;
    int j = 0;
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] > max) {
            max = array[i];
            j = i;
        }
    }
    answer.push_back(max);
    answer.push_back(j);
    return answer;
}

//배열 회전
vector<int> solutionDir(vector<int> numbers, string direction) {
    vector<int> answer;
    /*if (direction == "left")
    {
        rotate(numbers.begin(), numbers.begin() + 1, numbers.end());
    }
    else
    {
        rotate(numbers.begin(), numbers.end() - 1, numbers.end());
    }*/
    if (direction == "right")
    {
        answer.push_back(numbers[numbers.size() - 1]);
        for (int i = 0; i < numbers.size()-1; i++)
        {
            answer.push_back(numbers[i]);
        }
    }
    else
    {
        for (int i = 1; i < numbers.size(); i++)
        {
            answer.push_back(numbers[i]);
        }
        answer.push_back(numbers[0]);
    }
    return answer;
}

//인덱스 바꾸기
string solutionIndex(string my_string, int num1, int num2) {
    char temp;
    temp = my_string[num2];
    my_string[num2] = my_string[num1];
    my_string[num1] = temp;
    //swap(my_string[num1], my_string[num2]);
    return my_string;
}
//최댓값2, 6점
int solutionMax2(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    int a = numbers[0] * numbers[1];
    int b = numbers[numbers.size() - 1] * numbers[numbers.size() - 2];
    answer = a > b ? a : b;
    return answer;
}
//n의 배수고르기
vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    for (auto a : numlist)
        if (a % n == 0) answer.push_back(a);
    return answer;
}

//주사위의개수
int solutionDice(vector<int> box, int n) {
    int answer = 1;
    for (auto a : box)
        answer *= a / n;
    return answer;
}

//세균증식
int solutionGerm(int n, int t) {
    for (int i = 1; i <= t; i++)
        n *= 2;
    return n;
}

//문자열정렬
vector<int> solutionSortString(string my_string) {
    vector<int> answer;
    //isdigit사용
    my_string = regex_replace(my_string, regex("[^0-9]"), "");
    sort(my_string.begin(),my_string.end());
    for (auto a : my_string)
        answer.push_back(a - '0');
    return answer;
}

//대문자 소문자
string solutiontoUpper(string my_string) {
    string answer = "";
    for (auto a : my_string)
        if (a >= 'A' && a <= 'Z')
            answer.push_back(a + 32);
        else
            answer.push_back(a - 32);
    return answer;
}
//암호해독
string solutionCode(string cipher, int code) {
    string answer = "";
    for (int i = code - 1; i < cipher.size(); i += code)
        answer.push_back(cipher[i]);
    return answer;
}
//가위바위보
string solutionRSP(string rsp) {
    string answer = "";
    for (auto a : rsp) answer.push_back(a == '0' ? '5' : (a == '5' ? '2' : '0'));
    return answer;
}

//제곱근
int solutionPow(int n) {
    double answer = sqrt(n);
    return (answer - (int)answer == 0) && answer > 0 ? 1 : 2;
    /*int answer = 0;
    for (int i = 0; i < n; i++) {
        if (i * i == n) return 1;
    }

    return 2;*/
}

//문자열 비교2
int solutionLetter2(string str1, string str2) {
    regex re(str2);
    int answer = regex_search(str1, re) ? 1 : 2;
    //return (str1.find(str2) == string::npos)?2:1;
    return answer;
}

//a e i o u 제거
string solution(string my_string) {
    return my_string = regex_replace(my_string ,regex("[aeiou]"),"");
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
    my_string = regex_replace(my_string, regex("[1-9]"), "");
    for (int a : my_string)
        answer += a-48;
    return answer;
    //for (const auto v : my_string)if (isdigit(v))answer += v - '0';
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
    /*sort(numbers.begin(), numbers.end()); 
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
int solution324(vector<int> dot) {
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

int solution12312(int n) {
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
