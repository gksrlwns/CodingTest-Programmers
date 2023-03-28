#include <string>
#include <vector>
#include <cmath>
using namespace std;

//9�� 
vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer = {0,0};
    for (auto a : keyinput)
    {
        if (a == "up")
        {
            if (answer[1] == board[1]/2) continue;
            answer[1]++;
        }
        else if (a == "down")
        {
            if (answer[1] == board[1] / 2 * -1) continue;
            answer[1]--;
        }
        else if (a == "left")
        {
            if (answer[0] == board[0] / 2 * -1) continue;
            answer[0]--;
        }
        else if (a == "right")
        {
            if (answer[0] == board[0] / 2) continue;
            answer[0]++;
        }
        /* �� �����ϰ� ������ continue������� �ʰ� 
        if     (s=="up"    && v[1]<+board[1]/2) v[1]++;
        else if(s=="down"  && v[1]>-board[1]/2) v[1]--;
        else if(s=="left"  && v[0]>-board[0]/2) v[0]--;
        else if(s=="right" && v[0]<+board[0]/2) v[0]++;
        */
    }
    //������ ������ �̵��� �� ������ ��) [l,l,l,l,r,r,r,r] / [5,5] ��� :  [2,0] �ؿ� �������� �� �� [0,0] 
    /*for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;*/
    /*if (abs(answer[0]) > board[0] / 2 && answer[0] > 0) answer[0] = board[0] / 2;
    else if (abs(answer[0]) > board[0] / 2 && answer[0] < 0) answer[0] = board[0] / 2 * -1;
    if (abs(answer[1]) > board[1] / 2 && answer[1] > 0) answer[1] = board[1] / 2;
    else if (abs(answer[1]) > board[1] / 2 && answer[1] < 0) answer[1] = board[1] / 2 * -1;*/
    return answer;
}
