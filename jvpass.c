#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node * esquerda;
    struct node * direita;
    
    int info;
}Node;


Node * insereEmArvore(Node * arvore, int info){
    Node * new = malloc(sizeof(Node));
    new->info = info;

    if(arvore == NULL || arvore->info == 0){
        arvore = new;
    }else{
        if(info < arvore->info){
            arvore ->esquerda = insereEmArvore(arvore->esquerda,info);
            
        }else{
            arvore->direita = insereEmArvore(arvore->direita,info);
            
        }
        
    }
    return arvore;
    
}

void preOrdem(Node * node){
    
    if(node!= NULL){
        printf("%d ",node->info);
        preOrdem(node->esquerda);
        preOrdem(node->direita);
    }
}

void inOrdem(Node * node){
    
    if(node!= NULL){
        inOrdem(node->esquerda);
        printf("%d ",node->info);
        inOrdem(node->direita);
    }
}

void posOrdem(Node * node){
    
    if(node!= NULL){
        posOrdem(node->esquerda);
        posOrdem(node->direita);
        printf("%d ",node->info);
    }
      
}

int main(){
    int c;
    scanf("%d",&c);
    Node * arvore = malloc(sizeof(Node));
    int i;
    for(i=1;i<=c;i++){
        printf("Case %d:\n",i);
        
        int n;
        scanf("%d",&n);
        while(n--){
            int info;
            scanf("%d",&info);
            arvore = insereEmArvore(arvore,info);
            
        }
        printf("Pre.: ");
        preOrdem(arvore);
        printf("\n");
        printf("In..: ");
        inOrdem(arvore);
        printf("\n");
        printf("Post: ");
        posOrdem(arvore);
        printf("\n");
        
    }
    
}