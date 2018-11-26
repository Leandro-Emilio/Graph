/*
                    TRABALHO PRÁTICO 

    ALUNOS: LEANRODRO EMÍLIO DE PAULA

                    ENGENHARIA DE SISTEMAS

*/


#include "Graph.h"
//Estrutura no que armazena valor do vertice, valor da distancia e vertice de conexao.
struct No{
    int vert;
    int dist;
    int dist2;
    No* prox;
    No* Cabeca;
    No* Ultimo;
};
//Construtor que constroi a classe Graph
Graph::Graph(const int n){
    matriz = new int*[n];
    for (int i = 1; i <= n; i++){
        matriz[i] = new int[n]; //cria a matriz de tamanho nxn
    }
    num = n;                            //armazena tamanho de matriz
    vertices = 0;                       //inicia quantidade de vertices
    arestas = 0;                        //inicia quantidade de arestas
    componentes = 0;                    //inicia a quantidade de componentes conectados
    cont = 0;                           //contador inicial
    cout << " ";                // matriz construida
    for(int l=1;l<=n;l++){
        cout <<" "<<  l;
    }
    cout << endl << endl;
    for(int i=1;i<=n;i++){
        cout << i << " ";
        for(int j=1;j<=n;j++){
            matriz[i][j]=0;
            cout  << matriz[i][j] << " ";
        }
        cout << endl << endl;
    }
    Cabeca = new No;                    //cria lista
    Ultimo = new No;
    Tam = 0;
    Ultimo->prox = NULL;
    Cabeca->prox = Ultimo;
}
//Destrutor que destroi a classe Graph
Graph::~Graph(){
    for (int i = 1; i <= num; i++){
        delete matriz[i];
    }
    delete matriz;
    No *aux;                            //cria nos auxiliares para deletar elementos de lista
    No *aux1;
    No *aux2;
    aux = Cabeca;
    aux1 = aux->prox;
    while (Tam > 0){//deleta apontador por apontador da lista, desalocando a memoria
        aux2 = aux;
        delete aux2;
        aux = aux1;
        aux1 = aux1->prox;
        Tam--;
    }
    delete Cabeca;
}
//Funcao que verifica a existencia de aresta
int Graph::ContaLinhasArquivo ( FILE* entrada){
    int caractere, existe_linhas = 0;
    int quant_linhas = 0;
    while((caractere = fgetc(entrada)) != EOF){
        existe_linhas = 1; // há conteúdo no arquivo
        if(caractere == '\n')
            quant_linhas++;
    }
    if(existe_linhas)
        quant_linhas++;
    return quant_linhas;
}
bool Graph::ExisteAresta(const int a, const int b){
    if(matriz[a][b]== 0 && matriz[b][a]== 0 ){          //verifica se aresta nao existe
        cout<< "\nAresta nao existe"<< endl << endl;
        return false;
    }
    else
        cout << "\nAresta existe"<< endl << endl;
    return true;
}
//Funcao que inseri uma aresta na matriz
bool Graph::InserirAresta(const int a, const int b){

    int cont=0, cont1=0;

        if(ExisteAresta(a,b)){                              //verifica se aresta existe
            cout << "Aresta nao inserida"<< endl << endl;
            return false;
                             }
        else
            for ( int i = 1; i <= num; i++){                 //Compara vertices da aresta a ser inserida com os outros vertices da matriz
                if(matriz[a][i] == 1)
                    cont++;
                                          }

            for ( int j = 1; j <= num; j++){
                if(matriz [j][a]== 1)
                    cont++;
                                         }

            for ( int l = 1; l <= num; l++){
                if(matriz[b][l] == 1 )
                    cont1++;
                                          }

            for ( int k = 1; k <= num; k++){
                if(matriz[k][b]== 1)
                    cont1++;
                                          }
                if (cont == 0){                             //Se depois da comparacao , nao existe o vertice inserido, vertices aumenta em mais um
                    vertices++;
                              }

                if (cont1 == 0){
                    vertices++;
                               }

    matriz[a][b]= 1;                                        //Aresta inserida e recebe igual a 1 na matriz de adjacencia
    matriz[b][a]= 1;

   // matriz[num][num]=8;
    arestas++;                                              //Arestas aumenta em mais um.

    cout << "Aresta inserida com sucesso!"<< endl << endl;
    cout << " ";
            for(int s=1;s<=num;s++){                         //Imprime matriz modificada
                cout <<" "<<  s;
                                  }
                cout << endl << endl;

            for(int i=1;i<=num;i++){
                cout << i << " ";
                for(int j=1;j<=num;j++){
                    cout << matriz[i][j] << " ";
                                      }
                        cout << endl << endl;
                                  }
        return true;
    }
//Funcao que retira um aresta da matriz
bool Graph::RetirarAresta(const int a, const int b){

    int cont = 0, cont1 = 0;

        if(!ExisteAresta(a,b)){                             //verifica se aresta existe
            cout << "Aresta nao retirada"<< endl << endl;
                return false;
                              }
        else
            for ( int i = 1; i <= num; i++){                 //Compara vertices da aresta a ser inserida com os outros vertices da matriz
                if(matriz[a][i] == 1 )
                    cont++;
                                          }
            for ( int j = 1; j <= num; j++){
                if(matriz[j][a] == 1 )
                    cont++;
                                          }
            if (cont == 2){                                 //Se depois da comparacao ,se existe apenas o vertice escolhido, vertices diminui mais um
                vertices--;
                          }

            for ( int l = 1; l <= num; l++){
                if(matriz[b][l] == 1 )
                    cont1++;
                                          }

            for ( int k = 1; k <= num; k++){
                if(matriz[k][b] == 1 )
                    cont1++;
                                          }
            if (cont1 == 2){                              //Se depois da comparacao ,se existe apenas o vertice escolhido, vertices diminui mais um
                vertices--;
                           }
    matriz[a][b]= 0;                                      //Aresta retira recebe 0 na matriz de adjacencia
    matriz[b][a]= 0;
    arestas--;                                            //Arestas diminui menos um.

    cout << "Aresta removida com sucesso!"<< endl << endl;
    cout << " ";
            for(int s=1;s<=num;s++){                       //Imprime matriz modificada
                cout <<" "<<  s;
                                  }
                cout << endl << endl;

            for(int i=1;i<=num;i++){
                cout << i << " ";
                for(int j=1;j<=num;j++){
                    cout << matriz[i][j] << " ";
                                      }
                        cout << endl << endl;
                                  }
    return true;
}
//Procedimento que imprime os valores atualizados de vertices e arestas da matriz
void Graph::BuscarArestas(){
    componentes = vertices;
    cout << "Quantidade de arestas:"<< arestas << endl;
    cout << "Quantidade de vertices:"<< vertices << endl;
    cout << "Quantidade de componentes conectados:"<< componentes << endl << endl;
}
//Procedimento que imprime a matriz de adjacencia que possui o grafo.
void Graph::ImprimeGrafo(){

            cout << " ";
            for(int s=1;s<=num;s++){
                cout <<" "<<  s;
                                  }
                cout << endl << endl;

            for(int i=1;i<=num;i++){
                cout << i << " ";
                    for(int j=1;j<=num;j++){
                        //if(i==j){
                            //matriz[i][j]=0;}
                        cout << matriz[i][j] << " ";
                                          }
                            cout << endl << endl;
                                 }
                                 //cout<<matriz[6][6];
}
//Procedimento que verifica se todo o grafo esta completo.
void Graph::VerificaCompleto(){

    int cont = 0, comp = 2 * num;

        for(int i=1;i<=num;i++){                                 //Se elemento(menos os da diagonal principal)possui valor igual a 1, contador soma mais um
            for(int j=1;j<=num;j++){

                if (matriz[i][j] == 1){
                    cont++;
                                      }
                                  }
                              }

        if ( cont == comp ){                                    //Se contador e igual a doblo do numero de vertice. grafo esta completo
            cout << "\n Grafo e completo! "  << endl << endl;
                           }
        else
            cout << "\n Grafo nao e completo! "  << endl << endl;
}
//Procedimento que completa grafo da matriz de adjacencia
void Graph::CompletaGrafo(){

        for(int i=1;i<=num;i++){                                 //Faz com que todos os elementos , menos os da diagonal principal, ficarem igual a 1
            for(int j=1;j<=num;j++){
                if ( i == j){
                    matriz[i][j] = 0;
                            }
                else
                    matriz[i][j] = 1;
                                  }
                              }
    vertices = num;                                             //Atualiza numero de vertices e arestas
    arestas = (num* (num - 1))/2;
        cout << "\n Grafo esta agora completo! "  << endl << endl;
}
//Procedimento que insere em um lista, vertices para as buscas
void Graph::ListaGrafo(int a , int b, int c){

    int cont5 = 0;
    No* no;
    no = Cabeca;
    No* aux = new No;                           //cria um novo no para a lista.
    No* aux0 = Ultimo;
    No* aux1 = this->Cabeca;

        while(aux1 != aux0){

                aux1 = aux1->prox;

                    if( aux1->vert == a ){    //compara se elemento ja existe na lista
                        cont5++;

                                         }
                            }
                    if (cont5 == 0){

                        aux->vert = a;        //insere informaçoes para o novo elemento da lista
                        aux->dist = b;
                        aux->dist2 = c;
                        aux->prox = no->prox;
                        no->prox = aux;
                        Tam++;
                                   }
}
//Procedimento que busca informacoes de um vertice em largura
void Graph::BuscarLargura(int a, int b,int c,int v){                            //Recebe valor de vertice, distancia com vertice anterio e vertice de conexao, e vertice inicial

    No *aux = this->Cabeca->prox;
    No *aux1 = Ultimo;

        for(int i = 1; i <= num; i++){                                           //compara vertice com o vertice anterior e sua existencia no grafo(matriz)

            if ( a != i && matriz[a][i] == 1 &&  i != c  ){
                ListaGrafo(i , b,a);
                                                          }
            if( i == v  && matriz[v][i] == 0 && i == a){
                int b2 = 0;
                ListaGrafo(i , b2,a);
                                                       }
                                    }
            for(int i = 1; i <= num; i++){

                while(aux != aux1){

                    aux = aux->prox;

                    if( aux->vert == i  && matriz[a][i] == 1  ){                //compara vertice com o vertice anterior e sua existencia no grafo(matriz)
                        cont++;
                                                               }
                                  }
                    if ( a != i && matriz[a][i] == 1 &&  i != c && cont == 0  ){//Este procedimento usa recursividade com BuscarLargura2, para caminhar no grafo

                        BuscarLargura2(i,b,a,v);
                                                                               }
                                        }
}
//Procedimento que faz recursividade com BuscarLargura e inicia processo.
void Graph::BuscarLargura2(int a, int b, int c, int v){

    cont = 0;
    b =  b + 1;                 //Atualiza o valor de distancia entre vertices
    BuscarLargura(a,b,c,v);
}
//Procedimento que verifica se lista usada em listagrafo esta vazia
bool Graph::ListaVazia(){

        if (Cabeca->prox == Ultimo)
            return true;
}
//Procedimento que imprime lista da busca em largura
 void Graph::ImprimirLista(){

        No *aux = this->Cabeca->prox;
        No *aux2 = Ultimo;
        int vetor[Tam],vetor2[Tam],vetor3[Tam];     //Vetores para ordenar vertices, distancias e conexoes
        int con = 0;

                while(aux != Ultimo){               //insere valores de lista em vetores

                        vetor[con] = aux->vert;
                        vetor2[con] = aux->dist;
                        vetor3[con] = aux->dist2;
                        con++;

                        aux = aux->prox;
                                    }
                    for(int i = Tam-1 ; i >=1; i--){    //Usa o metodo de ordenacao em bolha para ordenar vetores
                        for(int j = 0; j < i; j++){
                            if(vetor2[j]>=vetor2[j+1]){
                                int temp = vetor2[j];
                                int temp2 = vetor[j];
                                int temp3 = vetor3[j];
                                vetor2[j] = vetor2[j+1];
                                vetor[j] =vetor[j+1];
                                vetor3[j]=vetor3[j+1];
                                vetor2[j+1]=temp;
                                vetor[j+1] = temp2;
                                vetor3[j+1] = temp3;
                                                      }
                                                  }
                                                    }

        cout << "\nOrdem de visita em Busca em Largura\n"<<endl;//Imprime vetores dos vertices

                    for(int i = 0; i <= Tam-1; i++){

                        cout<<"\t" << "Vertice:" <<" "<<vetor[i]<< " "<< "Distancia:" <<" "<<vetor2[i]<<" "<< "Vertice de conexao:" <<" "<<vetor3[i]<<endl;
                                                }
        No *aux0;                                               //Destroi lista.
        No *aux1;
        aux0 = Cabeca->prox;
        aux1 = aux0->prox;

                while (aux0 != Ultimo){
                    aux1 = aux0->prox;
                    delete aux0;
                    aux0 = aux1;
                                      }
                    delete aux2;
}
//Procedimento que inicia um nova lista vazia.
void Graph::ConstroiLista(){

        Cabeca = new No;
        Ultimo = new No;
        Tam = 0;
        Cabeca->prox = Ultimo;
}
//Procedimento que busca informacoes em profundidade de todos os vertices do grafo
void Graph::BuscarProfundidade(){

        for(int i=1;i<=num;i++){
            BuscarLargura2(i, 0 ,i , i);
            ImprimirLista2();
            ConstroiLista();
                              }
}
//Idem para ImprimirLista, porem usado para a busca em profundidade
void Graph::ImprimirLista2()
    {
            No *aux = this->Cabeca->prox;
            No *aux2 = Ultimo;
            int vetor[Tam],vetor2[Tam],vetor3[Tam];
            int con = 0;

  while(aux != Ultimo)
                    {

                        vetor[con] = aux->vert;
                        vetor2[con] = aux->dist;
                        vetor3[con] = aux->dist2;
                                        con++;


                                aux = aux->prox;

                    }
for(int i = Tam-1 ; i >=1; i--){
    for(int j = 0; j < i; j++){
        if(vetor2[j]>=vetor2[j+1]){
            int temp = vetor2[j];
            int temp2 = vetor[j];
            int temp3 = vetor3[j];
            vetor2[j] = vetor2[j+1];
            vetor[j] =vetor[j+1];
            vetor3[j]=vetor3[j+1];
            vetor2[j+1]=temp;
            vetor[j+1] = temp2;
            vetor3[j+1] = temp3;

        }



    }


}


cout << "\nOrdem de visita em Busca em Profundidade\n"<<endl;
                  for(int i = 0; i < Tam; i++){


                    cout<<"\t" << "Vertice:" <<" "<<vetor[i]<< " "<< "Profundidade:" <<" "<<vetor2[i] <<" "<< "Vertice de conexao:" <<" "<<vetor3[i]<<endl;



                  }
        No *aux0;
        No *aux1;


        aux0 = Cabeca->prox;
        aux1 = aux0->prox;


            while (aux0 != Ultimo)
                {
                    aux1 = aux0->prox;
                    delete aux0;
                    aux0 = aux1;
                }

                    delete aux2;


    }


//Procedimento para determinar distancia entre dois vertices
void Graph::MenorCaminho(int a , int b){

BuscarLargura2(a,0,a,a);
ImprimirLista3(a,b);
ConstroiLista();
BuscarLargura2(b,0,b,b);
ImprimirLista3(b,a);
ConstroiLista();

}
//Idem para ImprimirLista, porem usado para MenorCaminho
void Graph::ImprimirLista3(int a , int b){

        No *aux = this->Cabeca->prox;
        No *aux2 = Ultimo;
        int vetor[Tam],vetor2[Tam],vetor3[Tam];
        int con = 0;

            while(aux != Ultimo){

                        vetor[con] = aux->vert;
                        vetor2[con] = aux->dist;
                        vetor3[con] = aux->dist2;
                        con++;

                        aux = aux->prox;
                                }
                for(int i = Tam-1 ; i >=0; i--){
                    for(int j = 0; j <= i; j++){
                        if(vetor2[j]>=vetor2[j+1]){
                        int temp = vetor2[j];
                        int temp2 = vetor[j];
                        int temp3 = vetor3[j];
                        vetor2[j] = vetor2[j+1];
                        vetor[j] =vetor[j+1];
                        vetor3[j]=vetor3[j+1];
                        vetor2[j+1]=temp;
                        vetor[j+1] = temp2;
                        vetor3[j+1] = temp3;
                                                 }
                                              }
                                                }

        cout << "\nOrdem de distancias e conexoes do vertice\n"<<endl;

                  for(int i = 1; i <= Tam; i++){

                    cout<<"\t" << "Vertice:" <<" "<<vetor[i]<< " "<< "Distancia:" <<" "<<vetor2[i]<<" "<< "Vertice de conexao:" <<" "<<vetor3[i]<<endl;
                                              }
        int z,y,x;
                    cout << "\nMenor distancia entre os vertices:\n"<<endl;
                    for(int i = 1; i <= Tam; i++){
                        if(vetor[i]== a) {
                            z = a;
                            y = b;

                            for(int i = 1; i <= Tam; i++){
                                if(vetor[i]== b){
                                    x = vetor2[i];
                                                }
                                                        }
                                        }
                                                }

                    cout<<"\t" << "Vertice1:" <<" "<<z<< " "<<" "<< "Menor distancia:" <<" "<<x<<" "<<" "<< "Vertice2:" <<" "<<y<<endl;

        No *aux0;
        No *aux1;
        aux0 = Cabeca->prox;
        aux1 = aux0->prox;

                while (aux0 != Ultimo){
                    aux1 = aux0->prox;
                    delete aux0;
                    aux0 = aux1;
                                      }
                    delete aux2;
}

