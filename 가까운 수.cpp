//10�� ����� ���� �������� ��� ���� ���� ���� 
int solutionClose(vector<int> array, int n) {
    int answer = 0;
    int min = 101;
    sort(array.begin(), array.end());
    for (int i = 0; i < array.size(); i++)
    {
        if (abs(array[i] - n) < min) {
            min = abs(array[i] - n);
            answer = array[i];
        }
    }
    return answer;
}
