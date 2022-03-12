#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "functions.h"

#define N 20

typedef struct Element{
    char sb[3], nome[N];
    float mssat;
    int nat, gr;

} element;

FILE *fp, *tfp;

int main(){
    
    element el;
    float fqr, fx, vmssat[N];
    char ch, cqr[N];
    int op, i, n, ix, iqr, ich, size, vnat[N];
    

    main:

    do{
        printf("\n\nTABELA PERIODICA MODERNA \n\n");
        printf("[1] REGISTRAR ELEMENTO\n[2] PROCURAR ELEMENTO\n[3] LISTAR TODOS OS ELEMENTOS\n[0] SAIR\n\nDIGITE UMA OPÇÃO VÁLIDA: ");
        scanf("%i", &op);
    }while(op != 0 && op != 1 && op != 2 && op != 3);

    switch(op){
        case 0:

            printf("Bye! \n");
            break;

        case 1:

            /* unistd.h para checar se o arquivo ja existe funça access()

                if(access(fname, F_OK) == 0)
                    // file exists
                else
                    // file doesn't exist
                

                // a fim de evitar **core dumping** se o vetor ultrapassar N posições;
                for(n = 0; fread(&el, sizeof(el), 1, fp) != 0;){n++;} 
                printf("n: %i \n\n", n);

            */

            fp = fopen("tabela.data", "a"); 
            
            for(i = 0;; i++){   /* aqui o for() inicializa com i = n */
                getchar();
                
                printf("Nome do Elemento: ");
                fgets(el.nome, N, stdin);
                fflush(stdin);
                
                printf("Simbolo: ");
                fgets(el.sb, 3, stdin);
                fflush(stdin);
                
                printf("Massa Atomica: ");
                scanf("%f", &el.mssat);
                fflush(stdin);
                
                printf("Numero Atomico: ");
                scanf("%i", &el.nat);
                fflush(stdin);

                printf("Grupo: ");
                scanf("%i", &el.gr);
                fflush(stdin);
                printf("\n");

                fwrite(&el, sizeof(el), 1, fp);

                printf("NOVO ELEMENTO? (y/n): ");
                scanf(" %c", &ch);
                
                if(ch == 'n' || i == N-1){
                    fclose(fp);
                    goto main;
                }

            }

        case 2:
            fp = fopen("tabela.data", "r");

            search:

            do{
                printf("\n\nBUSCAR POR:\n[1] NOME\n[2] SIMBOLO\n[3] MASSA ATOMICA (exibe o elemento de massa atomica mais proxima)\n[4] NUMERO ATOMICO\n[5] GRUPO (exibe todos os elementos do grupo escolhido)\n[0] MENU\n\nDIGITE UMA OPCAO VALIDA: ");
                scanf("%i", &ich);
            }while(ich != 0 && ich != 1 && ich != 2 && ich != 3 && ich != 4 && ich != 5);
            
                switch(ich){
                    case 0:

                        fclose(fp);
                        goto main;
                    
                    case 1:
                        getchar();

                        printf("Buscar: ");
                        fgets(cqr, N, stdin);
                        
                        for(n = 0; fread(&el, sizeof(el), 1, fp) != 0;){
                            if(strcmp(el.nome, cqr) == 0){
                                printf("Nome: %sSimbolo: %s\nMassa Atomica: %f\nNumero Atomico: %i\nGrupo: %i", el.nome, el.sb, el.mssat, el.nat, el.gr);
                                n++;
                            }
                        }

                        if(n == 0)
                            printf("NADA ENCONTRADO!\n");
                        
                        goto search;
                    
                    case 2:

                        getchar();
                        printf("Buscar: ");
                        fgets(cqr, 3, stdin);

                        for(n = 0; fread(&el, sizeof(el), 1, fp) != 0;){
                            if(el.sb == cqr){
                                printf("Nome: %s\nSimbolo: %s\nMassa Atomica: %f\nNumero Atomico: %i\nGrupo: %i", el.nome, el.sb, el.mssat, el.nat, el.gr);
                                n++;
                            }
                        }

                        if(n == 0)
                            printf("NADA ENCONTRADO!\n");
                        
                        goto search;

                    case 3:

                        printf("Buscar: ");
                        scanf("%f", &fqr);

                        for(i = 0; fread(&el, sizeof(el), 1, fp) != 0; i++) {vmssat[i] = el.mssat;}
                        size = sizeof(vmssat)/sizeof(float);

                        fx = fget_closest(vmssat, size, fqr); /* função referenciada em functions.h e implementada em get_closest.c */
                        for(n = 0; fread(&el, sizeof(el), 1, fp) != 0;){
                            if(el.mssat == fx){
                                printf("Nome: %s\nSimbolo: %s\nMassa Atomica: %f\nNumero Atomico: %i\nGrupo: %i", el.nome, el.sb, el.mssat, el.nat, el.gr);
                                n++;
                            }
                        }

                        if(n == 0)
                            printf("NADA ENCONTRADO!\n");
                        
                        goto search;

                    case 4:

                        printf("Buscar: ");
                        scanf("%i", &iqr);

                        for(i = 0; fread(&el, sizeof(el), 1, fp) != 0; i++) {vnat[i] = el.nat;}
                        size = sizeof(vnat)/sizeof(int);

                        ix = iget_closest(vnat, size, iqr); /* função referenciada em functions.h e implementada em get_closest.c */
                        for(n = 0; fread(&el, sizeof(el), 1, fp) != 0;){
                            if(el.nat == ix){
                                printf("Nome: %s\nSimbolo: %s\nMassa Atomica: %f\nNumero Atomico: %i\nGrupo: %i", el.nome, el.sb, el.mssat, el.nat, el.gr);
                                n++;
                            }
                        }

                        if(n == 0)
                            printf("NADA ENCONTRADO!\n");
                        
                        goto search;

                    case 5:

                        printf("Buscar: ");
                        scanf("%i", &iqr);

                        for(n = 0; fread(&el, sizeof(el), 1, fp) != 0;){
                            if(el.gr == iqr){
                                printf("Nome: %s\nSimbolo: %s\nMassa Atomica: %f\nNumero Atomico: %i\nGrupo: %i", el.nome, el.sb, el.mssat, el.nat, el.gr);
                                n++;
                            }
                        }

                        if(n == 0)
                            printf("NADA ENCONTRADO!\n");
                        
                        goto search;
                }   
            
        case 3: 
                        
            fp = fopen("tabela.data", "r");

            for(n = 0; fread(&el, sizeof(el), 1, fp) != 0;){
                n++;
                printf("Nome: %sSimbolo: %s \nMassa Atomica: %f \nNumero Atomico: %i \nGrupo: %i \n\n", el.nome, el.sb, el.mssat, el.nat, el.gr);
            }            

            fclose(fp);                
            goto main;              
    }
    
    return 0;
}
