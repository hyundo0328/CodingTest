#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    
    int day = 0;
    for(int i=0;i<progresses.size();i++){
    if((100-progresses[i]) % speeds[i] == 0){
      day = (100-progresses[i]) / speeds[i];
    } else {
      day = (100-progresses[i]) / speeds[i] + 1;
    }
    days.push_back(day);
    }

    int count = 1;
    int max = days[0];
    for(int i=1;i<days.size();i++){
        if(days[i] > max){
          max = days[i];
          answer.push_back(count);
          count = 1;
        } else {
          count++;
        }
    }
    answer.push_back(count);
    
    return answer;
}