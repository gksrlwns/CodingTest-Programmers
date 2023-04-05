//9Á¡ Æ²·È¾úÀ½ 
vector<int> solutionDivisor3(int n) {
    vector<int> answer;
    int i = 2;
    while (n != 1)
    {
        if (n % i == 0)
        {
            answer.push_back(i);
            n /= i;
            i = 2;
        }
        else
            i++;
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}
