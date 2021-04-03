#include <string>
#include <vector>

using namespace std;

bool ch(string u) {
    int co = 0;
    for (int i = 0; i < u.size(); i++) {
        if (u[i] == '(')
            co++;
        if (u[i] == ')')
            co--;
        if (co < 0)
            return 0;
    }
    return 1;
}

int divide(string p) {
    int pos = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')
            pos++;
        if (p[i] == ')')
            pos--;
        if (i && !pos)
            return i;
    }
}

string req(string p) {
    if (!p.size())
        return "";
    string u, v;
    int d = divide(p);
    for (int i = 0; i < p.size(); i++) {
        if (i <= d)
            u += p[i];
        else
            v += p[i];
    }
    if (ch(u))
        return u + req(v);
    else {
        string ret = "(";
        ret += req(v);
        ret += ')';
        string nu;
        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(')
                nu += ')';
            if (u[i] == ')')
                nu += '(';
        }
        ret += nu;
        return ret;
    }
}

string solution(string p) {
    string answer = req(p);
    return answer;
}