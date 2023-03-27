#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    for(auto a : keyinput)
	{
		if(a == "up") answer[1]++;
		else if(a == "down") answer[1]--;
		else if(a == "left") answer[0]--;
		else if(a == "right") answer[0]--;
	 } 
	 if(abs(answer[0]) > board[0]/2 && answer[0] > 0) answer[0] = board[0]/2;
	 else if(abs(answer[0]) > board[0]/2 && answer[0] < 0) answer[0] = board[0]/2 *-1;
	 if(abs(answer[1]) > board[1]/2 && answer[1] > 0) answer[1] = board[1]/2;
	 else if()abs(answer[1]) > board[1]/2 && answer[1] < 0) answer[1] = board[1]/2 *-1;
    return answer;
}
