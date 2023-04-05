//10점 틀렸던 이유 : 마지막이 자연수인 경우 생각x 
int solutionNumAdd(string my_string) {
    
    my_string += 'a';
    int answer = 0;
    vector<int>v;
    for (int i = 0; i < my_string.size(); i++)
    {
        if (my_string[i] >= '0' && my_string[i] <= '9')
        {
            cout << my_string[i] - '0'<< endl;
            v.push_back(my_string[i] - '0');
        }
        else
        {
            for (int j = 0; j < v.size(); j++)
            {
                answer += v[j] * pow(10, v.size() - 1 - j);
            }
            v.clear();
        }
                
    }
    return answer;
}
/*sstream사용  
int answer = 0;
    for (auto& v : my_string)
    {
        if (!isdigit(v))
        {
            v = ' ';
        }
    }

    stringstream ss;
    ss.str(my_string);

    int tmp = 0;
    while (ss)
    {
        answer += tmp;
        ss >> tmp;
    }*/
