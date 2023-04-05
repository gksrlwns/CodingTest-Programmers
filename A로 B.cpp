//8Á¡
int solutionAB(string before, string after) {
    sort(before.begin(), before.end());
    sort(after.begin(), after.end());
    if (before.compare(after) == 0)
        return 1;
    else
        return 0;
}
 
