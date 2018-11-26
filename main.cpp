/*
                    TRABALHO PRÁTICO 

    ALUNO: LEANRODRO EMÍLIO DE PAULA

                    ENGENHARIA DE SISTEMAS

*/
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Graph.cpp"
using namespace std;

int main(){
    int i,n,a,b;
    FILE *arq_entrada;
    arq_entrada = fopen ( "Matriz.txt", "r" );
    if ( ! arq_entrada ){  // Verifica se o arquivo está vazio e, caso esteja, fecha o arquivo
        printf ( "\n Falha ao abrir o arquivo de entrada! \n " );
    }
    else{
        fscanf ( arq_entrada,"%d", &n); // Leitura da primeira linha do arquvio que contem a informacao da quantidade de vertices.
        Graph g(n);
        for (i = 0; i <=n+1  ; i++){
            fscanf ( arq_entrada,"%d %d\n",&a,&b); //leitura dos pares de arestas do arquivo
            cout<<a<<" "<<b<<endl;
            if ( a > ((g.num)) || b > ((g.num)) ){//compara vertice inserido pelo usuario com quantidade de vertices
                cout<< "\nVertice invalido, maior vertice valido = "<< (g.num)-1 <<  endl << endl;
            }
            else if(a == b){//compara se dois vertices iguais sao inseridos
                cout<< "\nVertices sao iguais, insira vertices diferentes" <<  endl << endl;
            }
            else
                g.InserirAresta(a,b);//insere par de vertices
        }
        while (1){
            cout << "\n Escolha uma opcao:\n";
            cout << "\n                    1 - Inserir uma aresta no grafo\n";
            cout << "\n                    2 - Retirar uma aresta no grafo\n";
            cout << "\n                    3 - Verificar numero de vertices,arestas e conexoes\n";
            cout << "\n                    4 - Verificar existencia de aresta no grafo\n";
            cout << "\n                    5 - Imprimir grafo\n";
            cout << "\n                    6 - Verificar se grafo e completo\n";
            cout << "\n                    7 - Completar grafo\n";
            cout << "\n                    8 - Buscar distancia em largura de um vertice\n";
            cout << "\n                    9 - Buscar distancia em profundidade\n";
            cout << "\n                    10 - Buscar menor caminho entre dois vertices\n";
            cout << "\n                    11 - Sair\n\n";
            cin >> a;
            system("pause");system("cls");
            switch(a){
                {
                    case 1:
                    cout << "\nInsira uma aresta(separando os vertices por espaco): ";
                    cin >> a >> b;
                    if ( a > ((g.num)) || b > ((g.num)) ){//compara vertice inserido pelo usuario com quantidade de vertices
                        cout<< "\nVertice invalido, maior vertice valido = "<< (g.num) <<  endl << endl;
                    }
                    else if(a == b){//compara se dois vertices iguais sao inseridos
                        cout<< "\nVertices sao iguais, insira vertices diferentes" <<  endl << endl;
                    }
                    else
                        g.InserirAresta(a,b);//insere par de vertices
                        break;
                    case 2:
                        cout << "\nRetira uma aresta(separando os vertices por espaco): ";
                        cin >> a >> b;
                        if ( a > ((g.num)) || b > ((g.num)) ){//compara vertice inserido pelo usuario com quantidade de vertices
                            cout<< "\nVertice invalido, maior vertice valido = "<< (g.num) <<  endl << endl;
                        }
                        else if(a == b){//compara se dois vertices iguais sao inseridos
                        cout<< "\nVertices sao iguais, insira vertices diferentes" <<  endl << endl;
                        }
                        else
                            g.RetirarAresta(a,b);//insere par de vertices
                        break;
                    case 3:
                        g.BuscarArestas();
                        break;
                    case 4:
                        cout << "\nInsira a aresta a ser verificada(separando os vertices por espaco): ";
                        cin >> a >> b;
                        g.ExisteAresta(a,b);
                        break;
                    case 5:
                        g.ImprimeGrafo();
                        break;
                    case 6:
                            g.VerificaCompleto();
                        break;

                        case 7:
                            g.CompletaGrafo();
                        break;

                    case 8:
                        cout << "\nInsira o vertice a ser verificado: ";
                        cin >> a ;
                        b = 0;
                        if ( a > ((g.num)-1) ){//compara vertice inserido pelo usuario com quantidade de vertices
                            cout<< "\nVertice invalido, maior vertice valido = "<< (g.num)-1 <<  endl << endl;
                        }
                        else
                            g.BuscarLargura2(a,b,a,a);//insere vertice para fazer a busca em largura
                            g.ImprimirLista();
                            g.ConstroiLista();
                            break;
                    case 9:
                        g.BuscarProfundidade();//faz a busca em profundidade em todos os vertices do grafo.
                        break;
                    case 10:
                        cout << "\nInsira dois vertices para achar menor caminho(separando os vertices por espaco): ";
                        cin >> a >> b;
                        if ( a > ((g.num)) || b > ((g.num)) ){//compara vertice inserido pelo usuario com quantidade de vertices
                            cout<< "\nVertice invalido, maior vertice valido = "<< (g.num) <<  endl << endl;
                        }
                        else if(a == b){//compara se dois vertices iguais sao inseridos
                            cout<< "\nVertices sao iguais, insira vertices diferentes, distancia igual a zero" <<  endl << endl;
                        }
                        else
                            g.MenorCaminho(a,b);//insere os dois vertices para buscar a menor distancia
                        break;
                    case 11:
                        return 0;
                        break;
                        default:
                        cout << "\nOpcao invalida!\n" << endl;
                        break;
                        }
                    }
                }
            }
    fclose ( arq_entrada );
return 0;
}
