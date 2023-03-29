#include <string>
#include <vector>

using namespace std;

//3점 
string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    for (auto a : db)
    {
        if (a[0] == id_pw[0] && a[1] == id_pw[1]) return "login";
        else if (a[0] == id_pw[0]) answer = "wrong pw";
    }
    if (answer == "") answer = "fail";
    return answer;
}
/* 틀렸던 이유 else로 fail을 넣어서 wrong pw여도 마지막에 fail이라면 답은 answer로 나옴 
map<string,string> m;
    for(auto i: db){
        m[i[0]]=i[1];
    }

    if(m.find(id_pw[0])!=m.end()){
        if(m[id_pw[0]]==id_pw[1]) return "login";
        else return "wrong pw";
    }
    else return "fail";
