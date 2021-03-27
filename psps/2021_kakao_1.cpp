#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 0;
    answer = s.size();
    int co = 0;
    int tc = 0;

    for (int a = 1; a < s.size(); a++) {
        int tem = s.size();
        co = 0;
        tc = 0;
        for (int i = 0; i <= s.size() - a + 1; i += a) {
            bool flag = true;
            for (int j = 0; j < a; j++) {
                if (s[i + j] != s[i + a + j]) {
                    flag = false;
                }
            }
            if (flag) {
                co += a;
                tc++;
            }

            else {
                if (tc > 0 && tc < 9)
                    tem -= co - 1;
                if (tc >= 9 && tc < 99)
                    tem -= co - 2;
                if (tc >= 99 && tc < 999)
                    tem -= co - 3;
                if (tc >= 999)
                    tem -= co - 4;
                co = 0;
                tc = 0;
            }
        }
        answer = min(answer, tem);
    }
    return answer;
}