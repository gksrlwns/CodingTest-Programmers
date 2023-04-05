//5점 틀린 이유: 둘 다 0일 경우를 생각x 
string solutionBinary(string bin1, string bin2) {
    string answer = "";
    int num = 0;
    for (int i = 0; i < bin1.size(); i++)
    {
        if (bin1[i] == '1')
            num += pow(2, bin1.size() - i - 1);
    }
    for (int i = 0; i < bin2.size(); i++)
    {
        if (bin2[i] == '1')
            num += pow(2, bin2.size() - i - 1);
    }
    if (num == 0) answer.push_back('0');
    while (num != 0)
    {
        if (num % 2 == 1) answer.push_back('1');
        else answer.push_back('0');
        num /= 2;
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}
