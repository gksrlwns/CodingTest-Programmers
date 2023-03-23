#include<iostream>
#include<sstream>
#include<map>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <cmath>
#include <set>

using namespace std;

long long solutionHateEng(string numbers);
string DeleteString(string s, int index);
int solutionCalString(string my_string);

int main()
{
    vector<int> v = {1,2,3,4,5};
    string s = "30 + 4 - 5 - 20";
    cout << solutionCalString(s);
    
}

int solutionCalString(string my_string) {
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
    
    cout << my_string << endl;
    iss.str(my_string);
    int x,i = 0;

    while (iss>>x)
    {
        cout << v[i] << endl;
        cout << x << endl;
        if (v[i] == '+') answer += x;
        else answer -= x;
        i++;
    }
    return answer;
}

vector<string> v = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

vector<string> solutionCutVec(string my_str, int n) {
    vector<string> answer;
    string temp = "";
    int i = 0;
    if (n == 0)answer.push_back(my_str);
    for (int i = 0; i < my_str.size(); i++)
    {
        temp += my_str[i];
        if ((i + 1) % n == 0)
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

//컨트롤제트
int solutionCtrlZ(string s) {
    int answer = 0;
    int count = 0;
    int x = 0;
    int n = 0;
    //스택을 이용해서 Z일 경우 이전의 숫자를 삭제
    /*stringstream ss;
    ss.str(s);

    stack<int> st;

    int t = 0;
    string tmp = "0";
    while (ss >> tmp)
    {
        if (tmp == "Z")
        {
            st.pop();
        }
        else
        {
            t = stoi(tmp);
            st.push(t);
        }
    }

    while (!st.empty())
    {
        answer += st.top();
        st.pop();
    }*/
    stringstream ss;
    for (auto a : s) if (a == 'Z') count++;
    ss.str(s);
    cout << "count : " << count << endl;
    while (count != 0)
    {
        while (ss >> x)
        {
            //cout << "answer : " << answer << ", " << "x : " << x << endl;
            cout << "answer : " << answer << ", " << "x : " << x << endl;
            n = x;
            cout << endl;
        }
        cout << "x : " << n << endl;
        answer -= n;
        for (auto& a : s) if (a == 'Z') {
            a = ' ';
            break;
        }
        ss.clear();
        ss.str(s);
        count--;
        cout << "x 구하기-----------------------------" << endl;
    }
    
    //for (auto& a : s) if (a == 'Z') a = ' ';
    
    cout << "합 구하기-----------------------------" << endl;
    
    while (ss)
    {
        cout << "answer : " << answer << ", " << "n : " << x << endl;
        answer += x;
        ss >> x;
        cout << "answer : " << answer << ", " << "n : " << x << endl;
        cout << endl;
    }
        
    cout << "string의 합 : " << answer << endl;
    cout << "x의 합 : " << n << endl;
    
    
    //char형이기에 10이상일 경우 0을 출력함 잘못 만듬
    //vector<int> v;
    //for (int i = 0; i < s.size(); i++)
    //{
    //    if (s[i] == 'Z') v.push_back(i);
    //}
    //
    //for (int i = 0; i < v.size(); i++)
    //{
    //    cout << v[i] << "," << s[v[i] - 2] - '0';
    //    answer -= s[v[i] - 2]-'0';
    //    cout << "answer :" << answer << endl;
    //    //s.erase(s.begin() + v[i]);
    //}
    //s.erase(remove_if(s.begin(), s.end(), Zvalue), s.end());
    //ss.str(s);
    //cout << endl;
    //cout << s << endl;
    //while (ss >> n) {
    //    cout << n << endl;
    //    answer += n;
    //}
    return answer;
}
//공 던지기 4점
int solutionThrowball(vector<int> numbers, int k) {
    int answer = 0;
    //x &numbers 값이 0일 경우가 생기기 때문에 안됨
    //answer =(k*2 -1) % numbers.size(); k에 5 size가 5일 경우 0
    answer = numbers[((k - 1) * 2) % numbers.size()];
    
    return answer;
}

//7의 개수
int solutionSevenCount(vector<int> array) {
    // n%10 == 7로 해결
    int answer = 0;
    string str = "";
    for (auto a : array)
        str += to_string(a);
    for (auto a : str)
        if (a == '7') answer++;
    return answer;
}

//소인수분해 9점 틀렸었음
vector<int> solutionDivisor3(int n) {
    vector<int> answer;
    int i = 2;
    while (n != 1)
    {
        if (n % i == 0)
        {
            answer.push_back(i);
            n /= i;
            i = 2;
        }
        else
            i++;
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}

//이진수 더하기 5점 틀린이유 : 둘다 0일 경우를 생각x
string solutionBinary(string bin1, string bin2) {
    string answer = "";
    int num = 0;
    for (int i = 0; i < bin1.size(); i++)
    {
        if (bin1[i] == '1')
            num += pow(2, bin1.size() - i - 1);
    }
    for (int i = 0; i < bin2.size(); i++)
    {
        if (bin2[i] == '1')
            num += pow(2, bin2.size() - i - 1);
    }
    if (num == 0) answer.push_back('0');
    while (num != 0)
    {
        if (num % 2 == 1) answer.push_back('1');
        else answer.push_back('0');
        num /= 2;
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}

//숨어있는 숫자의 덧셈2 오 10점 틀린이유 : 마지막이 자연수일 경우를 생각x
int solutionNumAdd(string my_string) {
    /*int answer = 0;
    for (auto& v : my_string)
    {
        if (!isdigit(v))
        {
            v = ' ';
        }
    }

    stringstream ss;
    ss.str(my_string);

    int tmp = 0;
    while (ss)
    {
        answer += tmp;
        ss >> tmp;
    }*/
    my_string += 'a';
    int answer = 0;
    vector<int>v;
    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string[i] >= '0' && my_string[i] <= '9')
        {
            cout << my_string[i] - '0'<< endl;
            v.push_back(my_string[i] - '0');
        }
        else
        {
            for (int j = 0; j < v.size(); j++)
            {
                answer += v[j] * pow(10, v.size() - 1 - j);
            }
            v.clear();
        }
                
    }
    return answer;
}

//한번만 등장한 문자
string solutionOnce(string s) {
    /*string answer = "";

    map<char, int> m;
    for (const auto v : s)
    {
        m[v]++;
    }

    for (const auto& v : m)
    {
        if (v.second == 1)
        {
            answer.push_back(v.first);
        }
    }
    return answer;*/
    string answer = "";    
    sort(s.begin(), s.end());
    int count = 1;
    for (int i = 0; i < s.size(); i+=count)
    {
        count = 1;
        for (int j = i+1; j < s.size(); j++)
        {
            if (s[i] == s[j]) count++;
        }
        if(count == 1)
            answer.push_back(s[i]);
    }
    return answer;
}

//진료순서 정하기
vector<int> solutionClinic(vector<int> emergency) {
    /*auto amt = map<int, int>();
    for (auto& e : emergency) { amt[e]; }
    auto order = amt.size();
    for (auto& e : amt) { e.second = order--; }
    for (auto& e : emergency) { e = amt[e]; }
    return emergency;*/
    vector<int> answer;
    vector<int> temp = emergency;    
    sort(temp.begin(), temp.end(),greater<int>());
    for (int i = 0; i < emergency.size(); i++)
        for(int j = 0; j < temp.size(); j++)
            if (temp[j] == emergency[i])
                answer.insert(answer.begin() + i, j + 1);
    return answer;
}

//k의 개수 5점
int solutionKcount(int i, int j, int k) {
    int answer = 0;
    vector<string> v;
    vector<char> v2;
    for (int x = i; x <= j; x++)
        for (auto a : to_string(x))
            if (a == k + '0') answer++;
    return answer;
}

//가까운 수 10점: 가까운 수가 여러개일 경우 작은 수를 리턴
int solutionClose(vector<int> array, int n) {
    int answer = 0;
    int min = 101;
    sort(array.begin(), array.end());
    for (int i = 0; i < array.size(); i++)
    {
        if (abs(array[i] - n) < min) {
            min = abs(array[i] - n);
            answer = array[i];
        }
    }
    return answer;
}
//2차원으로 만들기
vector<vector<int>> solution2D(vector<int> num_list, int n) {
    /*int r = num_list.size() / n;
    vector<vector<int>> answer(r, vector<int>(n));

    int ind = 0;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            answer[i][j] = num_list[ind++];
        }
    }*/
    vector<vector<int>> answer;
    vector<int> a;
    for (int i = 0; i < num_list.size(); i++)
    {
        a.push_back(num_list[i]);
        if (i % n == n - 1)
        {
            answer.push_back(a);
            a.clear();
        }
    }
    return answer;
}

//팩토리얼 5점
int solutionFactorial(int n) {
    int factorial = 1;
    for (int i = 1; i <= 10; i++)
    {
        factorial *= i;
        if (n < factorial && n > factorial / (i - 1))
            return i - 1;
        else if (n == factorial)
            return i;
    }
}
//8점 a로 b
int solutionAB(string before, string after) {
    sort(before.begin(), before.end());
    sort(after.begin(), after.end());
    if (before.compare(after) == 0)
        return 1;
    else
        return 0;
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
int is_in(string answer, int size, char ch)
{
    for (int i = 0; i < size; i++)
        if (answer[i] == ch)
            return 1;
    return 0;
}
string solutionDuplicate(string my_string) {
    string answer = "";
    for (int i = 0; i < my_string.size(); i++)
    {
        if (answer.find(my_string[i]) == string::npos)
            answer += my_string[i];
    }
    return answer;
    //unique를 사용하려면 sort를 해야함
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
string solutionAeiou(string my_string) {
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
