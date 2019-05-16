//Domino 
//Júlia P.S.   

#include <stdio.h> 
#include<stdlib.h> 
#define MAX 10 

/************************************************/   
// Implemente aqui o arquivo TADArvBin.h

typedef struct TLista Lista;
typedef struct TCelula Celula;
typedef struct TGrafo Grafo;
 
struct TCelula{
    int p;
    Celula *prox;
};
 
struct TLista{
    Celula *inicio,*fim;
};
 
struct TGrafo{
    Lista g[MAX];//cria um vetor de listas para representar o grafo
    int na, nv;
};
 
/************************************************/
 
// Implemente aqui o arquivo TADArvBin.c
 
void ListaIniciar(Lista *l)
{
    l->inicio=NULL;//inicia os apontadores do inicio e fim apontando para NULL
    l->fim=NULL;
}
 
int ListaVazia(Lista *l)
{
    if(l->inicio==NULL)//se o inicio apontar para NULL entao a lista está vazia
        return 1;
    else return 0;
}
 
int ListaTamanho(Lista *l)
{
    int cont=0;//cria uma variavel para contar o tamanho
    Celula *aux=l->inicio;//cria um apontador auxiliar para percorrer a lista, então ele recebe o endereço da primeira posição
    while(aux!=NULL)//equanto nao chegar ao fim da lista sera realizado a contagem
    {
        cont++;//aumenta o contador
        aux=aux->prox;// vai para a proxima celula
    }
    return cont;//retorna o tamanho
}
 
void InserirP(Lista *l, int d)//para inserir na primeira posição
{
    Celula *Nova=(Celula*)malloc(sizeof(Celula));//cria e aloca uma nova celula
    Nova->p=d;// a nova celula recebe a informação
    if(ListaVazia(l)==1)//se estiver vazia
    {
        l->inicio=Nova;//entao o inicio aponta para a nova celula
        l->fim=Nova;//e o fim tambem
        Nova->prox=NULL;// e o prox da nova celula aponta para NULL
    }
    else//caso contrario
    {
        Nova->prox=l->inicio;//a nova celula aponta o proxima para a atual primeira celula
        l->inicio=Nova;//atualiza o apontador inicio
    }
}
Celula* Endereco(Lista *l, int p)
{
    Celula *aux=l->inicio;//cria um apontador auxiliar para percorrer a lista
    int cont=0;// cria uma variavel para contar a posição de cada celula
    while(cont!=p && aux->prox!=NULL)//enquanto não achar a posição desejada ou não chegar ao fim da lista
    {
        cont++;//vai para a proxima posição
        aux=aux->prox;// vai para a proxima celula
    }
    return aux;//retorna o endereço da celula na posição p ou da ultima celula
}
void ListaInserir(Lista *l, int d, int p)
{
    if(ListaVazia(l)==1 || p==0)// se a posição for a primeira ou lista estiver vazia
    {
        InserirP(l,d);//chama a função inserir na primeira posição
    }
    else//caso contrario
    {
        Celula *Nova=(Celula*)malloc(sizeof(Celula));//cria e aloca uma nova celula
        Nova->p=d;//a nova celula recebe a informação
        Celula *posicao;//cria um apontador para receber o endereço da posição
        posicao=Endereco(l,p-1);// ele recebe a posição da celula anterior a posição que se deseja inserir a nova celula
        Nova->prox=posicao->prox;//a nova celula aponta o prox para o prox da posição
        posicao->prox=Nova;//e a celula que será anterior a nova aponta o prox para ela
        if(l->fim==posicao)//se a posição for a ultima celula
        {
               l->fim=Nova;//atualiza o fim
           }
       }
   }
   void RemoverP(Lista* l, int *d)//para remover da primeira posição
   {
       Celula *aux;//cria um apontador auxiliar
       aux=l->inicio;// o aux recebe o endereço da primeira celula
       *d=aux->p;//a variavel é alterada recebendo a informação contida na primeira celula
       l->inicio=aux->prox;//o inicio é a atulizado apontando para a celula seguinte da antiga primeira
       free(aux);//libera a celula
   }
    
   int ListaRemover(Lista *l, int *d, int p)
   {
       if(ListaVazia(l)==1)
       {
           return 0;//se a lista estiver vazia nao ha o que remover retorna fracasso
       }
       else
       {
           if(p==0)//se for pra remover do inicio
           {
               RemoverP(l,d);//chama a função especifica
           }
           else//caso contrario
           {
               Celula *aux,*posicao;//cria um apontador auxiliar e um para receber a posição anterior da que se deseja retirar a celula
               posicao=Endereco(l,p-1);//recebe o endereço anterior
               aux=posicao->prox;//o aux recebe o endereço da celula que se deseja retirar
               *d=aux->p;//altera a informação da variavel recebendo a informação da celula a ser removida
               posicao->prox=aux->prox;//atualiza o prox da posição apontando para o seguinte da celula que vai ser removida
               if(aux==l->fim)//se a celula a ser removida for a ultima
               {
                   l->fim=posicao;//atualiza o apontador fim
               }
               free(aux);//libera a celula
           }
           return 1;//retorna sucesso
       }
   }
    
   void LiberarLista(Lista *l)
   {
       Celula *aux;//cria um apontador auxiliar
       while(aux!=NULL)//enquanto nao chegar ao fim da lista
       {
           aux=l->inicio;//o aux recebe o endereço da primeira celula
           l->inicio=aux->prox;//atualiza o apontador inicio para a seguinte celula
           free(aux);//libera a celula
       }
   }
    
   int BuscaP(Lista *l,int n)//para buscar a posição dado um elemento
   {
       int p=-1,cont=0;//p recebe -porque caso não seja encontrado o elemento será para fazer essa indicação
       Celula *aux=l->inicio;//cria um apontador auxiliar para percorrer a lista
       while(aux!=NULL)//equanto nao chegar ao fim da lista
       {
           if(aux->p==n)//se achar o elemento
           {
               p=cont;// p recebe a posição desse elemento
           }
           cont++;// vai para a proxima posição
           aux=aux->prox;//vai para a proxima celula
       }
       return p;//retorna a posição
   }
    
   void IniciarGrafo(Grafo *g, int v)
   {
       int i;
       g->na=0;//inicia o numero de vertices com zero
       g->nv=v;//o numero de vertices é fixo
       for(i=0;i< g->nv;i++)
       {
           ListaIniciar(&g->g[i]);//inicia a quantidade de lista que serão utilizadas, ou seja, igual ao numero de vertices
       }
   }
    
   void InserirGrafo(Grafo *g, int vint v2)
   {
       ListaInserir(&g->g[v1],v2,ListaTamanho(&g->g[v1]));//insere na lista na ultima posição
       g->na++;//aumenta o numero de arestas
   }
    
   int RemoverGrafo(Grafo *g, int vint v2)
   {
       int a,p;
       p=BuscaP(&g->g[v1],v2);//busca a posição do elemento na lista desejada
       if(p==-1)//se nao for encontrado nao ha como remover
       {
           return 0;//retorna fracasso
       }
       else//caso contrario
       {
           ListaRemover(&g->g[v1],&a,p);//remove da lista desejada na determinada posição encontrada
           g->na--;//diminui o numero de arestas
           return 1;//retorna sucesso
       }
   }
    
   void AdjLista(Grafo *g, int v, int *lista)
   {
       int i=0,gs;
       gs=Grau(g,v);
       while(ListaVazia(&g->g[v])!=1)//enquanto não for passado todos os elementos dessa lista para a lista de adjacencia
       {
           ListaRemover(&g->g[v],&lista[i],0);//remove da lista auxiliar e coloca na lista de adjacencia
           i++;//vai apra a proxima posiçao da lista de adj
       }
       for(i=0;i<gs;i++)
       {
           InserirGrafo(g,v,lista[i]);//para não haver alteração no grafo, retorna os elementos retirados na mesma ordem
       }
   }
   int Grau(Grafo *g, int v)
   {
       int gs;
       gs=ListaTamanho(&g->g[v]);//o grau  é correspondente ao tamanho da lista
       return gs;//retorna o grau
   }
    
   int ExisteAresta(Grafo *g, int vint v2)
   {
       if(BuscaP(&g->g[v1],v2)!=-1)//se for encontrado v1 na lista v2 independente da posição
           return 1;//retorna que existe adjacencia entre os vertices
       else return 0;//caso contrario não
   }
    
   /************************************************/
    
   int main()
   {
     int peca,i,a,b,g,impar=0;
       Grafo grafo;//cria um grafo
       IniciarGrafo(&grafo,7);//inicializa o grafo
       scanf("%d",&peca);//le a quantidade de peças
    
       for(i=0;i<peca;i++)
       {
           scanf("%d %d", &a,&b);//le os valores das extremidades da peça
           InserirGrafo(&grafo,a,b);//insere nas duas porque é um grafo não orientado
           InserirGrafo(&grafo,b,a);
       }
    
       for(i=0;i<7;i++)
       {
           g=Grau(&grafo,i);//recebe o grau de cada aresta
           if(g%2!=0)
           {
               impar++;//faz a contagem da quantidade de arestas que tem grau impar
           }
       }
    
       if(impar>2)//se houver mais de duas arestas que tem grau impar,
       {
           printf("0");//vai haver mais de dois lados que não tem semelhantes,
           //então não é possivel organizar todas as peças em  uma formação valida, entao imprime zero
       }
       else
       {
           printf("1");//caso contrario,é possivel entao imprime 1
       }
    
     return 0;
   }
