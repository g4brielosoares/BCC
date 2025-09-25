#include <bits/stdc++.h>
using namespace std;

// time ./karatsuba < dados/100.txt > SaidaDadosKaratsuba/100.txt

/*
    10 = {
        time ./karatsuba < dados/10.txt > SaidaDadosKaratsuba/10.txt
    
        real    0m0.006s
        user    0m0.003s
        sys     0m0.003s

        diff SaidaDadosKaratsuba/10.txt SaidaDados/10.txt = { sem diferenças }
    }

    100 = {
        time ./karatsuba < dados/100.txt > SaidaDadosKaratsuba/100.txt

        real    0m0.056s
        user    0m0.004s
        sys     0m0.004s

        diff SaidaDadosKaratsuba/100.txt SaidaDados/100.txt = { sem diferenças }
    }
    
    1000 = {
        time ./karatsuba < dados/1000.txt > SaidaDadosKaratsuba/1000.txt

        real    0m0.132s
        user    0m0.131s
        sys     0m0.001s

        diff SaidaDadosKaratsuba/1000.txt SaidaDados/1000.txt = { sem diferenças }
    }

    10000 = {
        time ./karatsuba < dados/10000.txt > SaidaDadosKaratsuba/10000.txt

        real    0m4.839s
        user    0m4.831s
        sys     0m0.006s

        diff SaidaDadosKaratsuba/10000.txt SaidaDados/10000.txt = { sem diferenças }
    }

    100000 = {
        time ./karatsuba < dados/100000.txt > SaidaDadosKaratsuba/100000.txt

        real    3m5.231s
        user    3m5.132s
        sys     0m0.032s

        diff SaidaDadosKaratsuba/100000.txt SaidaDados/100000.txt = { sem diferenças }
    }
*/

//diff SaidaDadosKaratsuba/10.txt SaidaDados/10.txt
@g4brielosoares ➜ /workspaces/BCC/Análise e projeto de algoritmos (main) $ ./karatsuba < dados/100.txt > SaidaDadosKaratsuba/100.t
xt

string soma_str(string str1, string str2);
string sub_str(string str1, string str2);

string remover_zeros(string s) {
    while (s.size() > 1 && s[0] == '0') s.erase(s.begin());
    return s;
}

string add_zeros(string s, int m) {
    return s + string(m, '0');
}

string karatsuba(string x, string y) {
    x = remover_zeros(x);
    y = remover_zeros(y);

    int n = max(x.size(), y.size());

    // Caso base: se for 1 dígito, multiplica diretamente
    if (n == 1) {
        int val = (x[0] - '0') * (y[0] - '0');
        return to_string(val);
    }

    // Preenche com zeros à esquerda para igualar tamanhos
    if ((int)x.size() < n) x = string(n - x.size(), '0') + x;
    if ((int)y.size() < n) y = string(n - y.size(), '0') + y;

    // Se n for ímpar, ajusta para par
    if (n % 2 == 1) {
        x = "0" + x;
        y = "0" + y;
        n++;
    }

    int m = n / 2;

    string a = x.substr(0, n - m);
    string b = x.substr(n - m);
    string c = y.substr(0, n - m);
    string d = y.substr(n - m);

    string z0 = karatsuba(b, d);
    string z2 = karatsuba(a, c);
    string z1 = karatsuba(soma_str(a, b), soma_str(c, d));

    string mid = sub_str(sub_str(z1, z2), z0);

    string res = soma_str(soma_str(add_zeros(z2, 2 * m), add_zeros(mid, m)), z0);
    return remover_zeros(res);
}

string sub_str(string str1, string str2) {
    string resultado = "";
    int carry = 0;
    int n1 = str1.size();
    int n2 = str2.size();
    int n = max(n1, n2);
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for (int i = 0; i < n; i++) {
        int digit1 = (i < n1) ? (str1[i] - '0') : 0;
        int digit2 = (i < n2) ? (str2[i] - '0') : 0;
        int diff = digit1 - digit2 - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        resultado.push_back(diff + '0');
    }
    while (resultado.length() > 1 && resultado.back() == '0') {
        resultado.pop_back();
    }
    reverse(resultado.begin(), resultado.end());
    return resultado;
}

string soma_str(string str1, string str2) {
    string resultado = "";
    int carry = 0;
    int n1 = str1.size();
    int n2 = str2.size();
    int n = max(n1, n2);
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for (int i = 0; i < n; i++) {
        int digit1 = (i < n1) ? (str1[i] - '0') : 0;
        int digit2 = (i < n2) ? (str2[i] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        resultado.push_back((sum % 10) + '0');
    }
    if (carry)
        resultado.push_back(carry + '0');
    reverse(resultado.begin(), resultado.end());
    return resultado;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << karatsuba(a, b) << "\n";
    return 0;
}
