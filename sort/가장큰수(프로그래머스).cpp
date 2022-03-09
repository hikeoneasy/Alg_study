#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool CMP(string a, string b)
{
    return a + b > b + a;
}
// numbers_len은 배열 numbers의 길이입니다.
string solution(vector<int> numbers) {
    vector<string> tmp;

    for (int i = 0; i < numbers.size(); i++) tmp.push_back(to_string(numbers[i]));

    sort(tmp.begin(), tmp.end(), CMP);
    string answer = "";

    if (tmp[0] == "0") return "0";
    for (int i = 0; i < numbers.size(); i++) answer += tmp[i];



    return answer;
}
