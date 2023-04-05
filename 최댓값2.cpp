//6Á¡
int solutionMax2(vector<int> numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    int a = numbers[0] * numbers[1];
    int b = numbers[numbers.size() - 1] * numbers[numbers.size() - 2];
    answer = a > b ? a : b;
    return answer;
} 
