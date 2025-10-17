#include <stdio.h>


// Desafio Super Trunfo - Países (Nível Mestre) - Tema 3

/*Função para comparar 2 atributos. O parâmetro "compTipo" assinala o tipo de comparação, podendo ser também utilizado para inverter a lógica para, por exemplo
o valor de densidade demográfica, cujo menor vence, e não o maior.
Auxilia a função de batalha na comparação de atributos.  

suas variáveis "atributoCaUm" e "AtributoCaDois" recebem os valores do de atributo das cartas 1 e 2, respectivamente.

*/
int comparador(float atributoCaUm, float atributoCaDois, int compTipo)
    {

        //conversão dos atributos, caso sejam do tipo Int e não float.
        if (compTipo == 0 || compTipo == 2) 
            {
                atributoCaUm = (int) atributoCaUm;
                atributoCaDois = (int) atributoCaDois;
            }
        //variável que armazenará o resultado a ser retornado
        int resultado;
        //Verificando se está sendo calculada a densidade populacional, representada pelo compTipo = 1
        if (compTipo == 1) 
            {
                if (atributoCaUm < atributoCaDois) 
                    {
                        //atribui vitória a carta 1
                        resultado = 1;
                    } 
                else if (atributoCaUm > atributoCaDois) 
                    {
                        //atribui vitória a carta 2
                        resultado = 2;
                    } 
                else 
                    {
                        //indica um empate entre as cartas 1 e 2
                        resultado = 0;
                    }
            } 
        //Verificando e calculando atributos numérios (exceto densidade populacional).
        else
            {
                if (atributoCaUm < atributoCaDois) 
                    {
                        //vitória da segunda carta
                        resultado = 2;
                    }
                else if (atributoCaUm > atributoCaDois) 
                    {
                        //vitória da primeira carta
                        resultado = 1;
                    } 
                else 
                    {
                        //empate entre as duas cartas
                        resultado = 0;
                    }
        };

        if (compTipo == 0 || compTipo == 2) 
            {
                //Conversão do resultado para Int pois os valores de compTip iguais a 0 e 2 são do tipo Int e não float.
                resultado = (int) resultado;
                //Retornando o resultado para a variável que chamou a função.
                return resultado;
            } 
        else 
            {   
                //Apenas restorna o resultado para a variável que chamou a função, sem sonversões.
                return resultado;
            }

        
    };
//Função que auxilia a função principal, exibirComparacao(), a nomear cada atributo com base no valor "NumeroDoAtributo" (Similar a "compTipo, da função comparador()").  
char *tipoDeAtributo(int NumeroDoAtributo)
    {
        if(NumeroDoAtributo == 0)
            {
                return "População";
            }
        else if (NumeroDoAtributo == 1)
            {
                return "Densidade demográfica";
            }
        else if (NumeroDoAtributo == 2)
            {
                return "Número de pontos turísticos";
            }
        else if (NumeroDoAtributo == 3) 
            {
                return "PIB";
            }
        else if (NumeroDoAtributo == 4)
            {
                return "Área";
            }
    }

//Função que gerencia, com auxilio da função comparador(), as batalhas/comparações entre as cartas 1 e 2.
int batalhas
    (
        char cartaUm[1000], //Nome da primeira carta
        char cartaDois[1000], //Nome da segunda carta
        float atributoCartaUm, //Atributo da primeira carta
        float atributoCartaDois, //Atributo da segunda carta
        int tipoAtributoUm, //Tipo de atributo a ser comparado
        char atributoNome[1000] //Nome do atributo a ser comparado
    )
        {
            //Variável que armazena o resultado da comparação
            int resultadoComparacao = comparador(atributoCartaUm, atributoCartaDois, tipoAtributoUm);

            //Estrutura de decisão que imprime corretamente valores Int (0 ou 2) e float (1,3 e 4)
            if ((tipoAtributoUm == 0 || tipoAtributoUm == 2))
                {
                    printf("%s: %d\tVS\t%s: %d", cartaUm, (int) atributoCartaUm, cartaDois, (int) atributoCartaDois);
                    
                }
            else 
                {
                    printf("%s: %.2f\tVS\t%s: %.2f", cartaUm, atributoCartaUm, cartaDois, atributoCartaDois);
                }
    
            //Determinação do resultado conforme o valor retornado pela função comparador, armazenada na variavel resultadoComparacao.
            if (resultadoComparacao == 1) 
                {
                printf("\n\nA Carta 1 - (%s) venceu na batalha de %s!\n", cartaUm, atributoNome);
                } 
            else if (resultadoComparacao == 2) 
                {
                    printf("\n\nA Carta 2 - (%s) venceu na batalha de %s!\n", cartaDois, atributoNome);
                }
            else
                {
                    printf("\n\nHouve um empate entre as cartas %s e %s na batalha de %s!\n", cartaUm, cartaDois, atributoNome);
                }
        }

/*Função principal de comparação das cartas. Exibe as comparações individuais e calcula a comparação final (soma dos atributos individuais de cada cidade). 
Também dispõe de um terceiro switch para comparar novamente OU finalizar o programa.*/
int exibirComparacao
    (
        char cartaUm[1000], //Nome da carta 1
        char cartaDois[1000], //Nome da carta 2
        float atributoUmCartaUm, //Atributo 1 da carta 1
        float atributoDoisCartaUm, //Atributo 2 da carta 1
        float atributoUmCartaDois, //Atributo 1 da carta 2
        float atributoDoisCartaDois, //Atributo 2 da carta 2
        int tipoAtributoUm, //Tipo do primeiro atributo das duas cartas, selecionado no primeiro menu switch
        int tipoatributoDois //Tipo do segundo atributo das duas cartas, selecionado no segundo menu switch 
    ) 
    
        {
            //Variáveis que convertem o tipo de atributo, em valor numérico, em uma string, para ser usado como informação ao usuário nas printf() subsequentes. 

            char *atributoNomeUm = tipoDeAtributo(tipoAtributoUm);
            char *atributoNomeDois = tipoDeAtributo(tipoatributoDois);

            //Exibição da comparação de um atributo específico, em duas batalhas/comparações distintas
            printf("\n\n\n\n\n--------------------Comparando as duas cidades(%s e %s)---------------:\n\n", cartaUm, cartaDois);
            printf("\n> Atributos sendo comparados: \n* %s\n* %s\n\n\n", atributoNomeUm, atributoNomeDois);

            printf("----------Primeira batalha----------\nParâmetro: %s\n\n", atributoNomeUm);
            batalhas(cartaUm, cartaDois, atributoUmCartaUm, atributoUmCartaDois, tipoAtributoUm, atributoNomeUm);

            printf("\n\n\n----------Segunda batalha----------\nParâmetro: %s\n\n", atributoNomeDois);
            batalhas(cartaUm, cartaDois, atributoDoisCartaUm, atributoDoisCartaDois, tipoatributoDois, atributoNomeDois);

            //Variáveis que realizam a soma dos dois atributos, das duas cartas, para cada carta. é feita a conversão explicita para float para minizar erros advindos de somar um Int a um Float.

            float somacarta1 = (float) atributoUmCartaUm + (float) atributoDoisCartaUm;
            float somacarta2 = (float) atributoUmCartaDois + (float) atributoDoisCartaDois;

            //A batalha final é dada pela soma dos dois atributos em comparação, de cada carta. A carta com a maior soma vence. 
            printf("\n\n\n\t***BATALHA FINAL***\n\n");
            printf("Os atributos %s e %s para cada uma das duas cartas serão somados. Vence a carta com maior valor da soma!\n\n\n", atributoNomeUm, atributoNomeDois);

            //Exibindo dados de soma da carta um
            
            printf("\tCidade: %s\n\n%s (%.2f) + %s (%.2f)\n", cartaUm, atributoNomeUm, atributoUmCartaUm, atributoNomeDois, atributoDoisCartaUm);
            printf("Resultado da soma: %.2f\n", somacarta1);

            //Exibindo dados de soma da carta dois            
            printf("\n\n\n\tCidade: %s\n\n%s (%.2f) + %s (%.2f)\n", cartaDois, atributoNomeUm, atributoUmCartaDois, atributoNomeDois, atributoDoisCartaDois);
            printf("Resultado da soma: %.2f\n", somacarta2);

            //estrutura de decisão que determina qual carta venceu a batalha final, ou se há um empate.
            if (somacarta1 > somacarta2)
                {
                    printf("\n\n\nA Carta 1 - %s venceu a batalha final!", cartaUm);
                }
            else if(somacarta1 < somacarta2) 
                {
                    printf("\n\n\nA Carta 2 - %s venceu a batalha final!", cartaDois);
                }
            else 
                {
                    printf("\n\n\nA batalha final acabou com um empate entre as cartas %s e %s!", cartaUm, cartaDois);
                }

            //Variável que armazenará a escolha do usuário no terceiro switch, que o permite comparar novamente, ou sair.
            int desejaCompararDenovo;

            printf("\n\nGostaria de comparar novamente?\n1. Sim / Retornar ao menu de comparações\n2. Não / Sair do programa");
            printf("\nOpção: ");
            scanf("%d", &desejaCompararDenovo);
            /*Terceiro Switch, reinicia a comparação em caso de opção 1 e em caso de opção inválida (return 2;). 
            Em caso de opção 2, o programa retorna 1 para a função exibirComparacao(). Isto faz com que a estrutura de decisão ao fim do código seja ativada
            de modo a interromper o loop que mantém o menu de comparação ativo. Finalizando assim, o programa.
            */
            switch(desejaCompararDenovo) {
                case 1:
                    printf("Reiniciando comparação...");
                    return 2;
                break;

                case 2:
                    printf("Obrigado por jogar! Até a próxima! :)");
                    printf("Finalizando Super Trunfo...");
                    return 1;
                break;

                default:
                    printf("Opção inválida, reiniciando comparação...");
                    return 2;
                break;
            }
            
    };    

//Código principal
int main() 
    {

        //***DECLARAÇÃO DE VARIÁVEIS***



        //BLOCO DE VARIÁVEIS DA PRIMEIRA CIDADE:

        //Variáveis do nome, código e estado da primeira cidade.
        char nomeCidade1[1000], codigoCidade1[1000], estadoCidade1;
        //Variáveis de população total e quantidade de pontos turísticos da primeira cidade. 
        int populacao1, pontosTuristicos1; 
        //Variáveis de área e PIB da primeira cidade.
        float area1, PIB1; 
    
    



        //BLOCO DE VARIÁVEIS DA SEGUNDA CIDADE:

        //Variáveis do nome, código e estado da segunda cidade.
        char nomeCidade2[1000], codigoCidade2[1000], estadoCidade2; 
        //Variáveis da população total e quantidade de pontos turísticos da segunda cidade. 
        int populacao2, pontosTuristicos2; 
        //Variáveis de área e PIB da segunda cidade
        float area2, PIB2; 

    
    
    
    


    
        //***CADASTRO DE CARTAS***
    


        /*os blocos abaixo, formados pelas funções "printf" e "scanf" constituem a parte funcional do preenchimento da PRIMEIRA CARTA, 
        bem como uma mensagem de boas vindas e instruções gerais. */



        //Boas vindas + instruções gerais, com 3 linhas para melhor legibilidade.
        printf("Bem Vindo(a) ao Super Trunfo! Preencha cada campo conforme as instruções abaixo!\n\n\n");
    
    


        //Instruções sobre o nome do Estado.
        printf("Primeiramente, é necessário informar um Estado!\nInstruções: Informe apenas uma única letra, de 'A' a 'H', para o nome!\n\nEstado: ");
        //scanf que captura o caracter inserido pelo usuário e o endereça à variável char "estadoCidade1", ou seja, da primeira cidade.
        scanf(" %c", &estadoCidade1);
    
    

        //Instruções de criação da primeira cidade e de como preencher seu nome.
        printf("\nLindo! Agora, vamos criar o nome da sua PRIMEIRA cidade!\nInstruções: use '_' para marcar quaisquer espaços. Por exemplo: João_Pessoa\n\nCidade: ");
        //Uso da função scanf, para capturar o nome da cidade escolhida em formato string (%s) e endereçar este valor à variável.
        scanf("%s", nomeCidade1); 
    
    

        //Instruções sobre a forma de preenchimento do código da primeira cidade, exibindo o nome selecionado na etapa anterior, para melhor entendimento e imersão do usuário.
        printf("\nÓtimo! Agora, utilize letras maiúsculas de 'A' a 'H' + números de 01 a 04 para o código de %s!\nExemplos: A01, B04, C03, D01 etc\n\nCódigo: ", nomeCidade1);
        //Recolhe o código da primeira cidade, informado pelo usuário e, em seguida, endereça o valor à variável "CodigoCidade1".
        scanf("%s", codigoCidade1);
    


        //Instruções de preenchimento da área da primeira cidade, novamente exibindo o nome registrado, para melhor experiência do usuário.
        printf("\nMaravilha! Agora, informe o valor da área total de %s em KM²!\nExemplos: 975, 560.29 etc.\n\nÁrea: ", nomeCidade1);
        //Scanf responsável por formatar o valor de entrada (a área informada pelo usuário) como float e, em seguida, endereça-lo à variável area1.
        scanf("%f", &area1); 

        

        //Instruções de preenchimento da população da primeira cidade, novamente exibindo seu nome.
        printf("\nExplêndido! Agora, insira o total de habitantes de %s! \nExemplo: Se sua cidade tem 10 mil habitantes, insira 10000! NÃO USE '.' OU ','!\n\nPopulação: ", nomeCidade1);
        //Recolhe o valor fornecido como "população" e o endereça à variável "populacao1", ou seja, a população da primeira cidade.
        scanf("%d", &populacao1);
        



        // Instruções de preenchimento do PIB da primeira cidade.
        printf("\nEstupendo! Insira o valor do PIB (em bilhões de Reais) de %s!\nexemplo: 700, 185.78 etc (não use o formato '1.000.000' e similares)\n\nPIB: ", nomeCidade1);
        //Escaneia o valor de entrada para o PIB da primeira cidade e o atribui à variável "PIB1".
        scanf("%f", &PIB1);
        



        //Instruções de preenchimento do total de Pontos turísticos da primeira cidade.
        printf("\nQuase lá! Insira o número total de pontos turísticos em %s!\nExemplo: 5, 10, 20 etc\n\nNúmero de pontos turísticos: ", nomeCidade1);
        //Captura e atribui o valor informado pelo usuário à variável "pontosTuristicos1".
        scanf("%d", &pontosTuristicos1);
    



        /*Os blocos abaixo constituem o cadastro da carta da >>SEGUNDA CIDADE<<*/



        //Espaçamento entre as linhas.
        printf("\n\n");
        //A printf abaixo exibe as informações para que o usuário preencha os campos da segunda carta.
        printf("Espetacular! Sua primeira carta já está pronta! Agora, é só preencher os dados da sua SEGUNDA CIDADE! Os passos são os mesmos da primeira!\n\n");
        

        //Instruções para o nome do estado
        printf("Insira o Estado. Lembre-se, apenas de 'A' a 'H'!\n\nEstado: ");
        //Coleta e atribuição do valor inserido à variável estadoCidade2.
        scanf(" %c", &estadoCidade2);
        

        //Instruções de preenchimento para a segunda cidade.
        printf("\nMagnífico! Agora, o nome da sua SEGUNDA cidade!\nLembre-se: use '_' caso necessite de espaços, como em 'Porto_Alegre', por exemplo!\n\nCidade: ");
        //Coleta e atribuição do nome da segunda cidade para a variável nomeCidade2.
        scanf("  %s", nomeCidade2);
        


        //Instruções de preenchimento do código para a segunda cidade
        printf("\nLegal! Agora, digite um código para %s! Certifique-se de inserir um código diferente!\nRelembrando: Letra do Estado + 01 a 04! Exemplo: D03\n\nCódigo: ", nomeCidade2);
        //Coleta e atribuição do valor informado à variável codigoCidade2
        scanf("  %s", codigoCidade2);
        



        //Instruções de preenchimento da área da segunda cidade.
        printf("\nInsira a área de %s (em KM²). Lembre-se dos formatos aceitos: 1300|1300.87|45.78 etc.\n\nÁrea: ", nomeCidade2);
        //Coleta e atribui o valor informado da área da segunda cidade à variável area2.
        scanf(" %f", &area2);
    
    

        //Prompt de preenchimento da população da segunda cidade.
        printf("\nQuantos habitantes %s possui?\n\nPopulação: ", nomeCidade2);
        //Escaneamento do valor e atribuição do mesmo à variável populacao2
        scanf(" %d", &populacao2);
        


        //Intruções de preenchimento do PIB da segunda cidade.
        printf("\nQual é o PIB (em bilhões de Reais) de %s? Lembre-se: Não utilze formatos como: '1.352.48' ou similares. Exemplos de formato correto: 352 ou 352.48\n\nPIB: ", nomeCidade2);
        //Escaneamento e atribuição do valor coletado à variável PIB2
        scanf(" %f", &PIB2);
        


        //Instruções de preenchimento do número total de pontos turísticos da segunda cidade.
        printf("Qual o número de pontos turísticos totais em %s?\n\nNúmero de pontos turísticos: ", nomeCidade2);
        //coleta e atribui o valor informado à variável pontosTuristicos2.
        scanf(" %d", &pontosTuristicos2);


        //DENSIDADE POPULACIONAL E PIB PER CAPITA DAS DUAS CARTAS

        //Variável de densidade populacional da primeira cidade
        float DenPopulacional1 = (float) populacao1 / area1;
        //Variável de PIB per capita da primeira cidade
        float PIBPerCapita1 = (PIB1 * 1000000000) / (float) populacao1;

        //Variável de densidade populacional da segunda cidade
        float DenPopulacional2 = (float) populacao2 / area2;
        //Variável de PIB per capita da segunda cidade
        float PIBPerCapita2 = (PIB2 * 1000000000) / ((float) populacao2);
    


        //***EXIBIÇÃO DAS INFORMAÇÕES CADASTRADAS PARA AMBAS AS CARTAS***
        printf("\n\nSUCESSO! Você cadastrou as suas cartas! Confira abaixo como ficaram a sua primeira e segunda carta, respectivamente:");
        


        //Exibição dos dados da PRIMEIRA carta:
        //Cabeçalho da fase de exibição de informações da primeira cidade.
        printf("\n\nDADOS DE SUA PRIMEIRA CIDADE:");
    


        //Exibição das informações da primeira cidade.
        printf("\n\nEstado: %c\nCódigo: %s\nNome da Cidade: %s\nPopulação: %d\nÁrea: %.2f KM²\nPIB: %.2f Bilhões de Reais\nNúmero de pontos turísticos: %d\nDensidade populacional: %.2f habitantes/KM²\nPIB per capita: R$ %.2f", estadoCidade1, codigoCidade1, nomeCidade1, populacao1, area1, PIB1, pontosTuristicos1, DenPopulacional1, PIBPerCapita1);
        


        //Exibição dos dados da SEGUNDA carta:
        //Quebra-linhas.
        printf("\n\n");
        //Cabeçalho da fase de exibição das informações da segunda cidade.
        printf("DADOS DA SUA SEGUNDA CIDADE:\n\n");


        //Exibição das informações da segunda cidade.
        printf("Estado: %c\nCódigo: %s\nNome da Cidade: %s\nPopulação: %d\nÁrea: %.2f KM²\nPIB: %.2f Bilhões de Reais\nNúmero de pontos turísticos: %d\nDensidade populacional: %.2f habitantes/KM²\nPIB per capita: R$ %.2f\n", estadoCidade2, codigoCidade2, nomeCidade2, populacao2, area2, PIB2, pontosTuristicos2, DenPopulacional2, PIBPerCapita2);


        //BLOCO DE VARIÁVEIS DE COMPARAÇÃO DE ATRIBUTOS ENTRE AS CARTAS


        //Comparador de população.
        int compPopulacao = populacao1 > populacao2;
        //Comparador de área.
        float compArea = area1 > area2;
        //Comparador de PIB.
        float compPIB = PIB1 > PIB2;
        //Comparador de pontos turísticos (número total).
        int compPontosTuristicos = pontosTuristicos1 > pontosTuristicos2;
        //Comparador de densidade populacional.
        float compDenPopulacional = DenPopulacional1 < DenPopulacional2;
        //Comparador de PIB per capita.
        float compPIBPerCapita = PIBPerCapita1 > PIBPerCapita2;
        //Cálculo do Super Poder da primeira cidade.
        float superPoder1 = (float) populacao1 + area1 + PIB1 + (float) pontosTuristicos1 + PIBPerCapita1 + (1 / DenPopulacional1);
        //Cálculo do Super Poder da segunda cidade.
        float superPoder2 = (float) populacao2 + area2 + PIB2 + (float) pontosTuristicos2 + PIBPerCapita2 + (1 / DenPopulacional2);
        //Comparador de Super Poder.
        float compSuperPoder = superPoder1 > superPoder2;

    
        int saidaDoPrograma = 0;

    
    

        do 
            {   

                //Variável que recebe as opções do primeiro switch
                int opcaoComparacao;
                //Variável que recebe as opções do segundo switch
                int opcaoComparacao2;
                //**Bloco de variáveis da primeira decisão**

                //Atributo 1 da primeira cidade
                float AtributoUmCidadeUm;
                //Atributo 1 da sergunda cidade
                float AtributoUmCidadeDois;
                /*Armazena o tipo de comparação do primeiro atributo, entre as duas cidades. 
                Este valor é utilizado posteriormente para determinar qual atributo está sendo utilizado (retornando um nome com base no valor)
                e também pelas funções que farão o cálculo dos dois valores (AtributoUmCidadeUm e AtributoDoisCIdadeDois), assegurando que as devidas conversões 
                (int para float e vice versa) sejam realizadas, evitando erros.
                */
                int tipoComparacaoUm;
                
                //**Bloco de variáveis da segunda decisão**

                //Atributo 2 da primeira cidade
                float AtributoDoisCidadeUm;
                //Atributo 2 da segunda cidade
                float AtributoDoisCidadeDois;
                //Mesma lógica de sua contraparte "tipoComparacaoUm"
                int tipoComparacaoDois;
                

                //Menu construído com printf() que instrui o usuário a cerca das opções de comparação das cartas por ele registradas.
                printf("\n\n\n\t***MENU DE COMPARAÇÃO***\n\n\n");
                printf("Vamos comparar dois atributos de suas cidades: %s e %s!\nInsira abaixo os números que correspondem ao tipo de comparação que você deseja realizar!\n\n", nomeCidade1, nomeCidade2);
                printf("1. População\n");
                printf("2. Densidade demográfica\n");
                printf("3. Número de pontos turísticos\n");
                printf("4. PIB\n");
                printf("5. Área\n");
                printf("6. Sair do programa\n");
                printf("Qual será o primeiro parâmetro?: ");

                scanf("%d", &opcaoComparacao);
                
                //Primeiro switch, faz o tratamento da entrada de usuário para o primeiro atributo de comparação entre as duas cidades.
                switch (opcaoComparacao) 
                    {
                        case 1:
                            AtributoUmCidadeUm = populacao1;
                            AtributoUmCidadeDois = populacao2; 
                            tipoComparacaoUm = 0; 
                            
                        break;
                        case 2:
                            AtributoUmCidadeUm = (float) DenPopulacional1;
                            AtributoUmCidadeDois = (float) DenPopulacional2; 
                            tipoComparacaoUm = 1; 
                            
                        break;
                        case 3:
                            AtributoUmCidadeUm = pontosTuristicos1;
                            AtributoUmCidadeDois = pontosTuristicos2; 
                            tipoComparacaoUm = 2; 
                            
                        break;
                        case 4:
                            AtributoUmCidadeUm = PIB1;
                            AtributoUmCidadeDois = PIB2; 
                            tipoComparacaoUm = 3; 
                            
                        break;
                        case 5:
                            AtributoUmCidadeUm = area1;
                            AtributoUmCidadeDois = area2; 
                            tipoComparacaoUm = 4; 
                            
                        break;
                        case 6:
                            saidaDoPrograma = 1;
                        break;
                        default:
                            printf("Opção inválida! Reiniciando comparação...");
                        break;
                    };
                //Condicional para GARANTIR que, caso o usuário opte por sair, nenhuma instrução adicional será imprimida e o programa será finalizado.
                if (saidaDoPrograma == 0) 
                    {

                        //Instruções extras para preenchimento do parâmetro 2/2 para comparação entre duas cidades. Incluindo um aviso para não repetir números, e indicando qual não repetir.
                        printf("\n\nÓtimo! Agora insira o número que corresponde ao segundo atributo que você deseja comparar!\n");
                        printf("****** A T E N Ç Ã O ******\n\nNÃO insira o número %d, pois você já o selecionou antes!", opcaoComparacao);
                        printf("\n\nQual será o segundo parâmetro?: ");
                        scanf("%d", &opcaoComparacao2);
                    
                    //Segundo switch que trata as opções relativas ao segundo parâmetro de comparação entre as duas cidades. Em caso de sucesso, ativa-se a função. caso contrário, o processo reinicia.
                    switch (opcaoComparacao2) 
                        {
                            
                            case 1:
                                AtributoDoisCidadeUm = populacao1;
                                AtributoDoisCidadeDois = populacao2; 
                                tipoComparacaoDois = 0; 
                                
                            break;
                            case 2:
                                AtributoDoisCidadeUm = (float) DenPopulacional1;
                                AtributoDoisCidadeDois = (float) DenPopulacional2; 
                                tipoComparacaoDois = 1; 
                                
                            break;
                            case 3:
                                AtributoDoisCidadeUm = pontosTuristicos1;
                                AtributoDoisCidadeDois = pontosTuristicos2; 
                                tipoComparacaoDois = 2; 
                            
                            break;
                            case 4:
                                AtributoDoisCidadeUm = PIB1;
                                AtributoDoisCidadeDois = PIB2; 
                                tipoComparacaoDois = 3; 
                                
                            break;
                            case 5:
                                AtributoDoisCidadeUm = area1;
                                AtributoDoisCidadeDois = area2; 
                                tipoComparacaoDois = 4; 
                                
                            break;
                            case 6:
                                return saidaDoPrograma = 1;
                            break;
                            default:
                                printf("Opção inválida! Reiniciando comparação...\n\n\n");
                            break;
                        };
                        
                        //Verifica se o usuário escolheu a mesma opção e o impede de prosseguir se for um caso de opções repetidas.
                        if (opcaoComparacao == opcaoComparacao2) 
                                {
                                    printf("Você não deve escolher o mesmo atributo! Selecione números distintos!\n\n\nReiniciando comparação...");
                                } 
                        else 
                                {
                                    /*Variável duplo proósito que executa a função principal e recebe os valores do terceiro menu switch, que indaga o usuário sobre realizar
                                    uma nova comparação, ou não (sair do programa)*/
                                    int programafinaliza = exibirComparacao(
                                        nomeCidade1,
                                        nomeCidade2,
                                        AtributoUmCidadeUm,
                                        AtributoDoisCidadeUm,
                                        AtributoUmCidadeDois,
                                        AtributoDoisCidadeDois,
                                        tipoComparacaoUm,
                                        tipoComparacaoDois
                                    );
                                    
                                    //Caso o usuário, ao final da comparação, opte por sair do programa, a variavel "saidaDoPrograma" será marcada como 1 (verdadeiro) e o programa finalizará.
                                    if (programafinaliza == 1) {
                                        saidaDoPrograma = 1;
                                    }
                                }
                    
                    }
                   

                    
        
            }  while (saidaDoPrograma == 0);

   
    
     

    return 0;
}