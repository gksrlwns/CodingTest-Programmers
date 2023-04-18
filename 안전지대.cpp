#include <string>
#include <vector>

using namespace std;
//4Á¡ 
int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<vector<int>> x;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 1)
            {
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                x.push_back(temp);
            }
        }
	}	
    
    for (auto a : x)
    {
        for (int i = a[0] - 1; i <= a[0] + 1; i++)
        {
            if (i == -1 || i == board.size())
                continue;
            for (int j = a[1] - 1; j <= a[1] + 1; j++)
            {
                if (j == -1 || j == board.size())
                    continue;
                if(board[i][j] == 0)
                    board[i][j] = 1;
            }
        }
    }
    
    for (auto a : board)
        for (auto b : a)
            if (b == 0) answer++;

    return answer;
}
