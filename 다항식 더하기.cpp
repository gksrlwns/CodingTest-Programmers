#include <string>
#include <vector>
#include <sstream>

using namespace std;
//11점이다! 
string solution(string polynomial) {
    string answer = "";
    int a = 0;
    int b = 0;
    int temp;
    string x;
    stringstream ss;
    ss.str(polynomial);
    while (ss >> x)
    {
        stringstream sstemp(x);
        if (x == "x") a++;
        else if (x.find('x') != -1) while (sstemp >> temp) a += temp;
        else while (sstemp >> temp) b += temp;
    }
    if (a == 0) answer += to_string(b);
    else if (a > 1)
    {
        if (b >= 1) answer = to_string(a) + "x + " + to_string(b);
        else answer = to_string(a) + "x";
    }
    else
    {
        if (b >= 1) answer = "x + " + to_string(b);
        else answer = "x";
    }
    return answer;
}
/*
비슷한 형식 sstream을 사용하는 방법이 달랐음 
stringstream ss(p);
    string temp;
    int xsum = 0, nsum = 0;
    while (getline(ss, temp, ' ')) {
        if (temp.back() == 'x') {
            if (temp.size() == 1) xsum++;
            else xsum += stoi(string(temp.begin(), temp.end() - 1));
        }
        else if(temp!="+") nsum += stoi(temp);
    }
    if (xsum == 0) return to_string(nsum);
    else {
        string xres;
        if (xsum == 1) xres = "x";
        else xres = to_string(xsum) + "x";
        if (nsum == 0) return xres;
        else return xres + " + " + to_string(nsum);
    }
