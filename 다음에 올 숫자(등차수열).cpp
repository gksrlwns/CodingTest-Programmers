#include <string>
#include <vector>

using namespace std;
//3Á¡ 
int solution(vector<int> common) {
  	int temp = common[1] - common[0];
    if (temp == common[common.size() - 1] - common[common.size() - 2])
    {
        return common[common.size() - 1] + temp;
    }
    else
    {
        return common[common.size() - 1] * common[1] / common[0];
    }
}
/* common.back() = common[common.size() - 1]
