#include <string>
#include <vector>

using namespace std;
//9�� 
int solution(int chicken) {
    int answer = 0;
    int coupon = 0;
    while (chicken/10 !=0) {
        cout <<"ġŲ �� : " << chicken << endl;
        cout << "�߱޵Ǵ� ���� �� : " << chicken << endl;
        coupon = chicken % 10;
        cout << "���� ���� �� : " << coupon << endl;
        chicken /= 10;
        answer += chicken;
        cout << "���� ġŲ �� : " << answer << endl;
        chicken += coupon;
        cout << "�� ������ �� : " << chicken << endl; 
        cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
    }
    return answer;
}
