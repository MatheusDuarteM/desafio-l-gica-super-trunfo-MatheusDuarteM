

#include <stdio.h>
#include <math.h>  
#include <string.h> // Para usar strcmp()




// Definir uma estrutura para armazenar os dados de uma carta
typedef struct {
    char estado;
    char codCarta[4];
    char nomeDaCidade[50];
    int populacao;
    float area;
    float pib; // Em bilhões
    int pontosTuristicos;
    float densidade;
    float pibPessoa;
    double superPoder; // Usar double para acomodar a soma grande
    char opcao[50];
    char opcao2[50];
} CartaInfo;

int main()
{

    // Criar um array para guardar as informações das 2 cartas
    CartaInfo cartas[3];
    
    
    for(int i = 1; i < 3; i++){
    char estado;
    char codCarta[3];
    char nomeDaCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade = 0.0;
    float pibPessoa = 0.0;
    float superPoder = 0.0;
    char opcao[50];
    char opcao2[50];
        
    printf("Carta %d\n",i);
    printf("Qual o estado:");
    scanf(" %c",&cartas[i].estado);
    printf("Qual o codigo:");
    scanf("%3s",&cartas[i].codCarta);
    printf("Qual o nome da cidade:");
    scanf("%s",&cartas[i].nomeDaCidade);
    printf("Tamanho da população:");
    scanf("%d",&cartas[i].populacao);
    printf("O tamanho da Área:");
    scanf("%f",&cartas[i].area);
    printf("O PIB:");
    scanf("%f",&cartas[i].pib);
    printf("Numero de pontos turisticos:");
    scanf("%d",&cartas[i].pontosTuristicos);
    printf("\n");
        
    cartas[i].pibPessoa = (cartas[i].pib*pow(10.0,9.0))/cartas[i].populacao;
    cartas[i].densidade = cartas[i].populacao/cartas[i].area;
    cartas[i].superPoder = cartas[i].populacao+cartas[i].area+cartas[i].pib+cartas[i].pontosTuristicos+cartas[i].pibPessoa+cartas[i].densidade;
    // CORREÇÃO: Para tornar as strings vazias, coloque '\0' no índice 0
    cartas[i].opcao[0] = '\0';
    cartas[i].opcao2[0] = '\0';
    
    printf(" Carta %d: \n Estado: %c\n Código: %c%s\n Nome da cidade: %s\n População: %d\n Área: %.2f km²\n PIB: %.2f bilhões de reais\n Número de Pontos Turísticos: %d\n Densidade Populacional: %.2f hab/km²\n PIB per Capita: %.2f reais",i,cartas[i].estado,cartas[i].estado,cartas[i].codCarta,cartas[i].nomeDaCidade,cartas[i].populacao,cartas[i].area,cartas[i].pib,cartas[i].pontosTuristicos,cartas[i].densidade,cartas[i].pibPessoa);
    printf("\n\n");

    }
    
    double getAtributoValor(CartaInfo carta, const char* nomeAtributo) {

    // Compara a string recebida com os nomes conhecidos dos atributos
    if (strcmp(nomeAtributo, "populacao") == 0) {
        // Se for "populacao", retorna o valor de carta.populacao
        // Convertido para double para manter o tipo de retorno consistente
        return (double)carta.populacao;
    }
    else if (strcmp(nomeAtributo, "area") == 0) {
        // Se for "area", retorna carta.area (convertido para double)
        return (double)carta.area;
    }
    else if (strcmp(nomeAtributo, "pib") == 0) {
        // Se for "pib", retorna carta.pib (convertido para double)
        // (O valor retornado estará em bilhões, como na struct)
        return (double)carta.pib;
    }
    else if (strcmp(nomeAtributo, "pontosTuristicos") == 0) { // Usando "pontos" como nome curto
        // Se for "pontos", retorna carta.pontosTuristicos (convertido para double)
        return (double)carta.pontosTuristicos;
    }
    else if (strcmp(nomeAtributo, "densidade") == 0) {
        // Se for "densidade", retorna carta.densidade (convertido para double)
        return (double)carta.densidade;
    }
    else if (strcmp(nomeAtributo, "superPoder") == 0) { // Usando "pib_pessoa" como nome curto
        // Se for "pib_pessoa", retorna carta.pibPessoa (convertido para double)
        return (double)carta.pibPessoa;
    }
    else if (strcmp(nomeAtributo, "pibPessoa") == 0) { // Usando "super_poder"
        // Se for "super_poder", retorna carta.superPoder (já é double)
        return carta.superPoder;
    }
    else {
        // Se a string nomeAtributo não corresponder a nenhum nome conhecido:
        // 1. Imprime uma mensagem de erro (opcional, mas útil para depuração)
        fprintf(stderr, "Erro interno: Atributo '%s' desconhecido na função getAtributoValor.\n", nomeAtributo);
        // 2. Retorna NAN (Not a Number) para sinalizar que ocorreu um erro.
        //    O código que chama a função deve verificar se recebeu NAN.
        return NAN;
    }
}

    
    int escolha;
    printf("Para comparar 1 valor escolha 1 para comparar 2 valores escolha 2\n");
    scanf("%d",&escolha);
    if(escolha == 1)
    {
    int escolha2;
    printf("Para comparar a população digite 1\n Para comparar a área digite 2\n" 
    "Para comparar o PIB digite 3\n Para comparar Pontos turisticos digite 4\n"
    "Para comparar a densidade digite 5\n Para mostrar os nomes das cidades digites 6\n");
    scanf("%d",&escolha2);
    
    switch(escolha2){
    
    case 1:
        if(cartas[1].populacao > cartas[2].populacao)
        {
        printf("População: Carta 1 - %s venceu \n",cartas[1].nomeDaCidade);
        }else
        {
        printf("População: Carta 2 - %s venceu\n",cartas[2].nomeDaCidade);
        }
    break;
    case 2:
        if(cartas[1].area > cartas[2].area)
        {
        printf("Área: Carta 1 - %s venceu \n",cartas[1].nomeDaCidade);
        }
        else
        {
        printf("Área: Carta 2 - %s venceu \n",cartas[2].nomeDaCidade);
        }
    break;
    case 3:
        if (cartas[1].pib < cartas[2].pib)
        {
        printf("PIB: Carta 2 - %s venceu \n",cartas[2].nomeDaCidade);
        }
        else
        {
        printf("PIB: Carta 1 - %s venceu \n",cartas[1].nomeDaCidade);
        }
    break;
    case 4:
        if(cartas[1].pontosTuristicos < cartas[2].pontosTuristicos)
        {
        printf("Pontos Turísticos: Carta 2 - %s venceu \n",cartas[2].nomeDaCidade);
        }
        else
        {
        printf("Pontos Turísticos: Carta 1 - %s venceu \n",cartas[1].nomeDaCidade);
        }
    break;
    case 5:
        if(cartas[1].densidade > cartas[2].densidade)
        {
        printf("Densidade Populacional: Carta 1 - %s venceu \n",cartas[1].nomeDaCidade);
        }
        else
        {
        printf("Densidade Populacional: Carta 2 - %s venceu \n",cartas[2].nomeDaCidade);
        }
    break;
    case 6:
        printf("O nome da cidade 1 é %s e o nome da cidade 2 é %s", cartas[1].nomeDaCidade,cartas[2].nomeDaCidade);
    break;
    default:
    printf("Escolha invalida!");
    break;
    }
    }else if(escolha == 2){
        // Variáveis LOCAIS para guardar os NOMES dos atributos
    char nome_atributo1[50];
    char nome_atributo2[50];

    // Variáveis para guardar os VALORES numéricos obtidos
    double valor_c1_at1, valor_c2_at1;
    double valor_c1_at2, valor_c2_at2;
    int erro = 0; // Flag de erro

    // --- Ler os NOMES dos atributos do usuário ---
    printf("Escolha o PRIMEIRO atributo a comparar (ex: populacao, pib, area): ");
    // Lê para a variável LOCAL nome_atributo1
    scanf(" %49s", nome_atributo1);

    printf("Escolha o SEGUNDO atributo a comparar (ex: pontos, densidade): ");
    // Lê para a variável LOCAL nome_atributo2
    scanf(" %49s", nome_atributo2);

    // --- Obter os VALORES usando os nomes lidos ---
    // Passa o NOME (string da variável local) para a função
    valor_c1_at1 = getAtributoValor(cartas[1], nome_atributo1);
    valor_c2_at1 = getAtributoValor(cartas[2], nome_atributo1);
    valor_c1_at2 = getAtributoValor(cartas[1], nome_atributo2);
    valor_c2_at2 = getAtributoValor(cartas[2], nome_atributo2);

    // --- Verificar se nomes eram válidos (se getAtributoValor retornou erro NAN) ---
     if (isnan(valor_c1_at1) || isnan(valor_c2_at1) || isnan(valor_c1_at2) || isnan(valor_c2_at2)) {
        printf("\nErro: Um ou ambos os nomes de atributos digitados ('%s', '%s') são inválidos.\n",
               nome_atributo1, nome_atributo2);
        erro = 1;
    }

    // --- Realizar a comparação dos VALORES numéricos (se não houve erro) ---
    if (!erro) {
        printf("\n--- Comparando '%s' e '%s' ---\n", nome_atributo1, nome_atributo2);
        // Comparar os VALORES obtidos
        if (valor_c1_at1 > valor_c2_at1 && valor_c1_at2 > valor_c2_at2) {
            printf("Resultado: Carta 1 (%s) venceu em AMBOS os atributos!\n", cartas[1].nomeDaCidade);
        } else {
            printf("Resultado: Carta 1 (%s) NÃO venceu em ambos os atributos simultaneamente.\n", cartas[1].nomeDaCidade);
             // Opcional: Adicionar detalhes sobre qual atributo falhou
             if(valor_c1_at1 <= valor_c2_at1) printf("  (Não venceu ou empatou em '%s': C1=%.2f vs C2=%.2f)\n", nome_atributo1, valor_c1_at1, valor_c2_at1);
             if(valor_c1_at2 <= valor_c2_at2) printf("  (Não venceu ou empatou em '%s': C1=%.2f vs C2=%.2f)\n", nome_atributo2, valor_c1_at2, valor_c2_at2);
        }
         printf("---------------------------------\n");
    }

} else {
    // ... (seu código para escolha != 2) ...
}
    return 0;
}