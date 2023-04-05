//8Á¡
int solution369(int order) {
    int answer = 0;
    string a = to_string(order);
    for (auto a : a) if (a == '3' || a == '6' || a == '9') answer++;
    return answer;
} 
