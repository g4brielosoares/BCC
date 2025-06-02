#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Lista;

void leituraGrafo(Lista &G, int m) {
    int a, b;
    while (m--) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

void escritaGrafo(Lista &G) {
    int n = G.size();
    cout << "Lista de Adjacencia:" << endl;
    for (int u = 0; u < n; u++) {
        cout << u << ": ";
        for (auto v : G[u]) 
            cout << v << " ";
        cout << endl;
    }
}

// Verifica se um vértice pode ser adicionado ao conjunto atual
bool podeAdicionar(int v, const vector<bool> &atual, const Lista &G) {
    for (int vizinho : G[v])
        if (atual[vizinho]) return false;
    return true;
}

// Estimativa otimista (poda)
int estimativaSuperior(int indice, const vector<bool> &usados, int n) {
    int livres = 0;
    for (int i = indice; i < n; ++i)
        if (!usados[i]) livres++;
    return livres;
}

void branchAndBound(int indice, vector<bool> &atual, int tamanhoAtual, vector<bool> &usados, const Lista &G, int &melhorTamanho, vector<bool> &melhorSolucao) {
    int n = G.size();

    // Poda: se não pode superar melhor solução, aborta
    int estimado = tamanhoAtual + estimativaSuperior(indice, usados, n);
    if (estimado <= melhorTamanho) return;

    // Atualiza melhor solução
    if (tamanhoAtual > melhorTamanho) {
        melhorTamanho = tamanhoAtual;
        melhorSolucao = atual;
    }

    for (int i = indice; i < n; ++i) {
        if (!usados[i] && podeAdicionar(i, atual, G)) {
            atual[i] = true;

            // Marca i e seus vizinhos como usados
            usados[i] = true;
            for (int vizinho : G[i]) {
                usados[vizinho] = true;
            }

            branchAndBound(i + 1, atual, tamanhoAtual + 1, usados, G, melhorTamanho, melhorSolucao);

            // Desmarca i e vizinhos
            usados[i] = false;
            for (int vizinho : G[i]) {
                usados[vizinho] = false;
            }
            atual[i] = false;
        }

        // Caso não escolha i
        usados[i] = true;
        branchAndBound(i + 1, atual, tamanhoAtual, usados, G, melhorTamanho, melhorSolucao);
        usados[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Lista Grafo(n);
    leituraGrafo(Grafo, m);
    escritaGrafo(Grafo);

    vector<bool> atual(n, false);
    vector<bool> usados(n, false);
    vector<bool> melhorSolucao(n, false);
    int melhorTamanho = 0;

    branchAndBound(0, atual, 0, usados, Grafo, melhorTamanho, melhorSolucao);

    cout << "\nConjunto Independente Maximo: ";
    for (int i = 0; i < n; ++i)
        if (melhorSolucao[i])
            cout << i << " ";
    cout << "\nTamanho: " << melhorTamanho << endl;

    cout << "\nTotal Vertices: " << n << endl;
    cout << "Total Arestas: " << m << endl;

    return 0;
}