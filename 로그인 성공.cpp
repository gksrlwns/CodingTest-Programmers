#include <string>
#include <vector>

using namespace std;

//3�� 
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
/* Ʋ�ȴ� ���� else�� fail�� �־ wrong pw���� �������� fail�̶�� ���� answer�� ���� 
map<string,string> m;
    for(auto i: db){
        m[i[0]]=i[1];
    }

    if(m.find(id_pw[0])!=m.end()){
        if(m[id_pw[0]]==id_pw[1]) return "login";
        else return "wrong pw";
    }
    else return "fail";
