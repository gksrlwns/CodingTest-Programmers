#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int tmp = 0;
    while (chicken >= 1) {
        cout <<"치킨 수(나누기 전) : " << chicken << endl;
        answer += chicken / 10;
        tmp += chicken % 10;
        chicken /= 10;
        cout << "치킨 수(나누기 후) : " << chicken << endl;
        cout << "서비스 수 : " << answer << endl;
        cout << "쿠폰 수 : " << tmp << endl;
    }
    return answer + tmp/10;
}
