#include <string>
#include <vector>

using namespace std;
//9薄 
int solution(int chicken) {
    int answer = 0;
    int coupon = 0;
    while (chicken/10 !=0) {
        cout <<"纂鑑 熱 : " << chicken << endl;
        cout << "嫦晝腎朝 瓔ア 熱 : " << chicken << endl;
        coupon = chicken % 10;
        cout << "陴朝 瓔ア 熱 : " << coupon << endl;
        chicken /= 10;
        answer += chicken;
        cout << "憮綠蝶 纂鑑 熱 : " << answer << endl;
        chicken += coupon;
        cout << "識 瓔ア曖 熱 : " << chicken << endl; 
        cout << "天天天天天天天天天天天天天天" << endl;
    }
    return answer;
}
