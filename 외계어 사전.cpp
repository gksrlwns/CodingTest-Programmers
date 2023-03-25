#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

//3Á¡ 
int solution(vector<string> spell, vector<string> dic) {
    string v = "";
    for (auto a : spell)
        v += a;
    sort(v.begin(), v.end());
    for (auto a : dic)
    {
        sort(a.begin(), a.end());
        if (a == v) return 1;
    }
    return 2;
}
/*
int solution(vector<string> spell, vector<string> dic) {
    int answer = 0;
    for(auto i : dic){
        map<char, int> m;
        for(int j=0; j<i.size(); j++){
            for(auto k: spell){
                if(i[j]==k[0]){
                    m[i[j]]++;
                }
            }
        }
        if(spell.size()==m.size())return 1;

    }
    return 2;
}
