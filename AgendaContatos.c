#include <stdio.h>// declaração das bibliotecas
#include <string.h>

//declarando dado composto
struct Contato
{  
    char Nome[50][30];
    char Email[50][60];
    char Telefone[50][20];
};

int main(){

    //funções
    int cadastrarConato(int receber_novo_total_cadastro, int TotalContatos, int Sair, struct Contato *ct);
    void listaContatos(int receber_novo_total_cadastro, int contato_encontrado, int Sair, struct Contato *ct);
    void BuscaContato(char BuscarNome[50],int receber_novo_total_cadastro, int contato_encontrado, int Sair, struct Contato *ct );
    int RemoverContato(int receber_novo_total_cadastro, struct Contato *ct);
    
    //declaração de variáveis e constante
    struct Contato ct;

    #define MAX_CONTATO 59
    
    int TotalContatos = 0;
    int Opcao;
    char BuscarNome[50];
    int Sair;
    int contato_encontrado = 0;
    int receber_total_cadastro = 0;
    int receber_novo_total_cadastro = 0;


   while(Sair != 1)//laço do inicio do programa
   {
    
    //Menu do programa
   printf("-------MENU------------\n");
        printf("1 - Cadastrar contato\n");
            printf("2 - Listar contato\n");
                printf("3 - Buscar contato\n");
                    printf("4 - Remover contato\n");
                        printf("5 - Sair\n\n");
                            printf("Escolha uma opção:\n");
                                scanf("%d", &Opcao);

                                if(Opcao == 1 || Opcao == 2 || Opcao == 3 || Opcao == 4|| Opcao == 5)//opcões do menu
                                {

                                    if(Opcao == 1)// opção de cadastrar contato
                                    {
                                        receber_total_cadastro = cadastrarConato(receber_novo_total_cadastro, TotalContatos,  Sair, &ct);
                                        receber_novo_total_cadastro += receber_total_cadastro;          
                                    }
                                        else
                                        {
                                            if(Opcao == 2)//opção de lista todos os contatos
                                            {
                                                listaContatos( receber_novo_total_cadastro,  contato_encontrado,  Sair, &ct);              
                                            }
                                                else
                                                {
                                                    if(Opcao == 3)//opção de buscar um contato especifico
                                                    {
                                                        BuscaContato( BuscarNome, receber_novo_total_cadastro,  contato_encontrado,  Sair, &ct ) ;   
                                                    }
                                                        else
                                                        {
                                                            if(Opcao == 4)//opção para remover contato
                                                            {
                                                               receber_novo_total_cadastro = RemoverContato(receber_novo_total_cadastro, &ct);
                                                            }
                                                                else
                                                                {
                                                                    if(Opcao == 5){ break;}// opção de sair do programa
                                                                }
                                                        }
                                                    
                                                } 


                                        }
                                                                                                                              
                                }
                                    else
                                    {
                                        printf("Opção inválida\n");
                                    }

 }
    return 0;
}


int cadastrarConato(int receber_novo_total_cadastro, int TotalContatos, int Sair, struct Contato *ct)
{
    printf("----------Cadastrar contato--------------\n\n");
    for (int i = receber_novo_total_cadastro; i < MAX_CONTATO; i++) // laço do inicio da opção de cadastro de contatos
    { 
        printf("Digite seu Nome:%d\n ", i+1);//inputs
          while (getchar() != '\n');
            fgets(ct->Nome[i], 30, stdin);

                    printf("Digite seu E-mail:%d\n ", i+1);
                        scanf("%49s", ct->Email[i]);
                            while (getchar() != '\n');

                            printf("Digite seu Telefone:%d\n ", i+1);
                                scanf("%19s", ct->Telefone[i]);
                                    while (getchar() != '\n');

                        TotalContatos += 1; // contador de contato

            if (TotalContatos > MAX_CONTATO)//verificação de limite de contato
            {
                printf("Limite de contatos atingido! %d\n ",TotalContatos);

                    printf("Digite 0 para sair ou 2 para continuar:\n");//input para sair da opção
                        scanf("%d",  &Sair);

                        while(Sair != 0 && Sair != 2)//validação de saida da opção
                        {
                            printf("Digite 0 para sair ou 2 para continuar:\n");
                                scanf("%d",  &Sair);
                                    
                        }

                        if(Sair == 0){break;}
            }
                else//feedback de conclusão de cadastro
                {
                    printf("Contato cadastrado com sucesso!\n");

                        printf("(1)- Continuar:\n");//input para sair da opção
                        printf("(2)- Sair \n");//input para sair da opção
                            scanf("%d",  &Sair);

                            while(Sair != 1 && Sair != 2)//validação de saida da opção
                            {                 
                                scanf("%d",  &Sair);
                            }

                            if(Sair == 2){return TotalContatos; break;}
                            
                }    
    }    

}

void listaContatos(int receber_novo_total_cadastro, int contato_encontrado, int Sair, struct Contato *ct)
{
    printf("----------Lista de Contatos---------\n\n");
    for(int i = 0; i < receber_novo_total_cadastro; i++)// laço que vai lista todos os contatos existentes
    {
        contato_encontrado = 1;

        printf(" Contato: %d\n ",i+1);
            printf("Nome: %s", ct->Nome[i]);
                printf(" Email: %s\n", ct->Email[i]);
                    printf(" Telefone: (%c%c) %s \n\n", ct->Telefone[i][0],ct->Telefone[i][1], &ct->Telefone[i][2]);

    }

        if(contato_encontrado == 0)//contato não encotrado
        {
            printf("Nenhum Contato encontrado\n");
        }

            contato_encontrado = 0;

            printf("\n\n ");
                 printf("(0)- Sair\n");//input para sair da opção
            scanf("%d", &Sair);

            while(Sair != 0)//validação de saida da opção
            {
                printf("(0)- Sair\n");
                    scanf("%d", &Sair);         
            }

}

void BuscaContato(char BuscarNome[50],int receber_novo_total_cadastro, int contato_encontrado, int Sair, struct Contato *ct )
{
       printf("----------Buscar Contatos---------\n \n");            
       for(int i = 0; i < MAX_CONTATO; i++)//laço do inicio da opção
       {

            printf("Digite o nome do contato que deseja buscar:\n");//input para buscar contato pelo nome
                while(getchar() != '\n');
                fgets(BuscarNome, 50, stdin);
                 printf("\n");

           for(i = 0; i < receber_novo_total_cadastro; i++)// laço que vai verificar todas os posições do array nome
           {

                if(strcmp(ct->Nome[i], BuscarNome) == 0)// verificando se existe o nome, para poder lista o contato especifico
                {
                    contato_encontrado = 1;

                    printf("Nome: %s", ct->Nome[i]);
                    printf("Email: %s\n", ct->Email[i]);
                    printf("Telefone: (%c%c) %s \n\n", ct->Telefone[i][0],ct->Telefone[i][1], &ct->Telefone[i][2]);

                } 
            }

                if(contato_encontrado == 0)//contato não encotrado
                {
                    printf("Contato não encontrado\n");
                }

                 contato_encontrado = 0;

                 printf("(1)- Continuar\n");//input de saida da opção
                 printf("(2) Sair\n");//input de saida da opção
                    scanf("%d", &Sair);

                            while(Sair != 1 && Sair != 2)//validação de saida da opção
                            {
                                scanf("%d", &Sair);                                                                                  
                            }

                             if(Sair == 2){break;}
       }

}

int RemoverContato(int receber_novo_total_cadastro, struct Contato *ct)
{
    int contato_encontrado = 0;
    int opcao = 0;
    int contato = 0;
    int receber_result_final = 0;

    printf("----------Lista de Contatos---------\n\n");

    for(int i = 0; i < receber_novo_total_cadastro; i++)// laço que vai lista todos os contatos existentes
    {
       contato_encontrado = 1;
    
       printf(" Contato: %d\n ",i+1);
           printf("Nome: %s", ct->Nome[i]);
               printf(" Email: %s\n", ct->Email[i]);
                   printf(" Telefone: (%c%c) %s \n\n", ct->Telefone[i][0],ct->Telefone[i][1], &ct->Telefone[i][2]);
    
    }
    
       if(contato_encontrado == 0)//contato não encotrado
       {
           printf("Nenhum Contato encontrado\n");
       }
    
           contato_encontrado = 0;
    
           printf("\n\n ");
                printf(" (1)- Remover Contato\n");//input para Remover da opção
                printf(" (2)- Sair\n");//input para sair da opção
           scanf("%d", &opcao);
    
           while(opcao != 0 && opcao != 1)//validação de saida da opção
           {
                printf(" (1)- Remover Contato\n");//input para Remover da opção
                printf(" (2)- Sair\n");//input para sair da opção
                scanf("%d", &opcao);         
           }

           if(opcao == 1)
           {
                printf("Digite o número do Contato\n");
                scanf("%d", &contato);

                while(contato == 0 || contato > receber_novo_total_cadastro)
                {
                    printf("Digite o número do Contato\n");
                    scanf("%d", &contato);
                }

                if(contato == 1)
                {
                    contato = 0;
                }

                for(int x = contato; x < receber_novo_total_cadastro; x++)
                {
                    strcpy(ct->Nome[x],ct->Nome[x + 1]);
                    strcpy(ct->Email[x],ct->Email[x + 1]);
                    strcpy(ct->Telefone[x],ct->Telefone[x + 1]);
                }

                printf("Contato Removido sucesso!\n");
                receber_novo_total_cadastro--;
                receber_result_final = receber_novo_total_cadastro;
                return receber_result_final;
           }
}