#include <string>
#include <vector>
#include <cmath>
using namespace std;

//9점 
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
        /* 더 간결하게 가능함 continue사용하지 않고 
        if     (s=="up"    && v[1]<+board[1]/2) v[1]++;
        else if(s=="down"  && v[1]>-board[1]/2) v[1]--;
        else if(s=="left"  && v[0]>-board[0]/2) v[0]--;
        else if(s=="right" && v[0]<+board[0]/2) v[0]++;
        */
    }
    //끝에서 끝으로 이동할 시 실패함 예) [l,l,l,l,r,r,r,r] / [5,5] 결과 :  [2,0] 밑에 형식으로 할 시 [0,0] 
    /*for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << endl;*/
    /*if (abs(answer[0]) > board[0] / 2 && answer[0] > 0) answer[0] = board[0] / 2;
    else if (abs(answer[0]) > board[0] / 2 && answer[0] < 0) answer[0] = board[0] / 2 * -1;
    if (abs(answer[1]) > board[1] / 2 && answer[1] > 0) answer[1] = board[1] / 2;
    else if (abs(answer[1]) > board[1] / 2 && answer[1] < 0) answer[1] = board[1] / 2 * -1;*/
    return answer;
}
