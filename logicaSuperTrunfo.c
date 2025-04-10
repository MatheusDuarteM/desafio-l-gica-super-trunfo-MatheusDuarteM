

#include <stdio.h>
#include <math.h>   

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
    
    printf(" Carta %d: \n Estado: %c\n Código: %c%s\n Nome da cidade: %s\n População: %d\n Área: %.2f km²\n PIB: %.2f bilhões de reais\n Número de Pontos Turísticos: %d\n Densidade Populacional: %.2f hab/km²\n PIB per Capita: %.2f reais",i,cartas[i].estado,cartas[i].estado,cartas[i].codCarta,cartas[i].nomeDaCidade,cartas[i].populacao,cartas[i].area,cartas[i].pib,cartas[i].pontosTuristicos,cartas[i].densidade,cartas[i].pibPessoa);
    printf("\n\n");

    }
    
    
    int escolha;
    printf("Para comparar a população digite 1\n Para comparar a área digite 2\n" 
    "Para comparar o PIB digite 3\n Para comparar Pontos turisticos digite 4\n"
    "Para comparar a densidade digite 5\n Para mostrar os nomes das cidades digites 6\n");
    scanf("%d",&escolha);
    
    switch(escolha){
    
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
    return 0;
}