
string solutionMos(string letter) {
    string answer = "";
    string letterTemp = "";
    vector<string> v = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
    
    for (int i = 0; i < letter.size(); i++)
    {
        if (letter[i] != ' ')
            letterTemp.push_back(letter[i]);
        else
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (letterTemp == v[j])
                {
                    answer.push_back(j + 'a');
                    break;
                }
            }
            letterTemp = "";
        }
        if (i == letter.size() - 1)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (letterTemp == v[j])
                {
                    answer.push_back(j + 'a');
                    break;
                }
            }
        }
    } 
    return answer;
}
/*stringstream ss(letter);
    string s;

    while (!ss.eof()) {
        ss >> s;
        auto t = m.find(s);
        if (t != m.end()) {
            answer += t->second;
        }
    }
    return answer;*/


