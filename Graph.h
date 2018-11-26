/*
                    TRABALHO PRÁTICO 

    ALUNOS: LEANRODRO EMÍLIO DE PAULA

                    ENGENHARIA DE SISTEMAS

*/

#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>
using namespace std;
struct No;//estrutura No que e o apontador do procedimento ListaGrafo.
class Graph{
    public:
        Graph(const int n);                             //Constroi a classe Graph, construindo a matriz de adjacencia de tamanho nxn.
        ~Graph();                                       //Destroi a classe Graph, deletando todos os elementos da matriz de adjacencia.
        int **matriz;                                   //Matriz que recebe os valores 1 e 0 para construir a matriz de adjacencia.
        bool ExisteAresta(const int a, const int b);    //Funcao que compara vertices com indices da matriz para verificar existencia de aresta.
        bool InserirAresta(const int a, const int b);   //Funcao que inseri uma aresta na matriz, se a mesma nao existe.
        bool RetirarAresta(const int a, const int b);   //Funcao que retira uma aresta da matriz se a mesma existe.
        void BuscarArestas();                           //Procedimento que verifica quantidade de arestas e vertices da matriz.
        void VerificaCompleto();                        //Procedimento que verifica se matriz esta completa, ou seja, todos elementos igual a 1, menos os da diagonal principal.
        void CompletaGrafo();                           //Procedimento que faz com que matriz fique completa, todos os elementos igual a 1, menos os da diagonal principal.
        void BuscarLargura(int a, int b,int c, int v);  //Procedimento que busca conexoes e distancia entre o vertice escolhido e os vertices da matriz que estao conectados.
        void BuscarLargura2(int a, int b,int c, int v); //Procedimento complementar do BuscaLargura, e o procedimento que faz a recursao com este procedimento.
        void BuscarProfundidade();                      //Procedimento que busca niveis de todos os vertices da matriz, suas distancias e conexoes.
        void MenorCaminho(int a , int b);               //Procedimento que verifica distancia entre dois vertices da matriz.
        void ImprimeGrafo();                            //Procedimento que imprime a matriz de adjacencia na tela.
        void ListaGrafo(int a , int b, int c);          //Procedimento que usa lista para armazenar os vertices nos procedimentos de busca.
        bool ListaVazia();                              //Procedimento que verifica se lista do vertices esta vazia.
        void ImprimirLista();                           //Procedimento que imprime os vertices da listagrafo da busca em largura.
        void ImprimirLista2();                          //Procedimento que imprime os vertices da listagrafo da busca em profundidade.
        void ImprimirLista3(int a , int b);             //Procedimento que imprime os vertices da listagrafo do menor caminho,
        void ConstroiLista();                           //Procedimento que constroi lista, ja que a mesma e deletada nos procedimentos de impressao.
        int ContaLinhasArquivo(FILE* entrada);
        int num;                                        //Valor da quantidade de vertices inicial.
        No* prox(No* no);                               //Apontador da lista usada em ListaGrafo.
        int vert;                                       //Valor do vertice armazenado na lista.
        int dist;                                       //Valor  do vertice de conexao
        int dist2;                                      //Valor da distacia do vertice com os demais vertices
        int cont;                                       //Contador que e usado para comparacoes nos procedimentos de busca
        int componentes;                                //Valor dos componentes conectados na matriz.
    private:
        int vertices;                                   //Valor da quantidade de vertices da matriz.
        int arestas;                                    //Valor da quantidade de arestas da matriz.
        int Tam;                                        //Valor do tamanho da lista usada para armazenar os vertices nas buscas
        No* Cabeca;                                     //No inicial da lista de listagrafo.
        No* Ultimo;                                     //No final da lista de listagrafo.
};
#endif // GRAPH_H_INCLUDED
