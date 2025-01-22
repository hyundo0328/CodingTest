#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int width=0, height=0;
    for(auto card:sizes){
        if(card[0] < card[1]){
            int tmp = card[1];
            card[1] = card[0];
            card[0] = tmp;
        }
        
        if(width < card[0]){
            width = card[0];
        }
        if(height < card[1]){
            height = card[1];
        }
    }
    
    return width*height;
}