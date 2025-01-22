#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> student1 = {1, 2, 3, 4, 5};
    int oneCnt = 0;
    vector<int> student2 = {2, 1, 2, 3, 2, 4, 2, 5};
    int twoCnt = 0;
    vector<int> student3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int threeCnt = 0;
    
    for(int i=0; i<answers.size(); i++){
        if(student1[i%5] == answers[i]) oneCnt++;
        if(student2[i%8] == answers[i]) twoCnt++;
        if(student3[i%10] == answers[i]) threeCnt++;            
    }
    
    int maxCnt = max(oneCnt, twoCnt);
    maxCnt = max(maxCnt, threeCnt);

    if(maxCnt == oneCnt) answer.push_back(1);
    if(maxCnt == twoCnt) answer.push_back(2);
    if(maxCnt == threeCnt) answer.push_back(3);
    
    return answer;
}