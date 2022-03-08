#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    int start = 0, end = 0, point = 0;
    
    vector<int> answer;  vector<int> ::iterator iter; vector<int> tmp;
    for(int i=0;i<commands.size();i++)
    {
        start = commands[i][0]-1; end = commands[i][1]-1; point = commands[i][2]-1;
        tmp.clear();
        for (iter = array.begin() + start; iter != array.begin() + end+1; iter++) tmp.push_back(*iter);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[point]);
    }
    return answer;
}


int main()
{
    vector<int> t { 1, 5, 2, 6, 3, 7, 4 };
    vector<vector<int>> a{ {2,5,3},{4,4,1},{1,7,3} };

    vector<int> tmp; vector<int> ::iterator iter;
    tmp = solution(t,a);
    for(int i=0;i<tmp.size();i++) cout << tmp[i] << " "<< endl;
   
    
    return 0;
}

