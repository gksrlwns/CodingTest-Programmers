#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int tmp = 0;
    while (chicken >= 1) {
        cout <<"ġŲ ��(������ ��) : " << chicken << endl;
        answer += chicken / 10;
        tmp += chicken % 10;
        chicken /= 10;
        cout << "ġŲ ��(������ ��) : " << chicken << endl;
        cout << "���� �� : " << answer << endl;
        cout << "���� �� : " << tmp << endl;
    }
    return answer + tmp/10;
}
