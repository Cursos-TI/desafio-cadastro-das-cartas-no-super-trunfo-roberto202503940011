/*
 * ============================================================================
 * PROGRAMA: Sistema Avançado de Cadastro e Comparação de Cartas do Super Trunfo
 * AUTOR: Roberto
 * DESCRIÇÃO: Este programa implementa um sistema completo para cadastrar duas
 *            cartas do jogo Super Trunfo, calcular atributos derivados
 *            (densidade populacional, PIB per capita, Super Poder) e realizar
 *            comparações detalhadas entre as cartas para determinar vencedores.
 * ============================================================================
 */

#include <stdio.h>  // Biblioteca padrão para entrada e saída de dados

/*
 * FUNÇÃO PRINCIPAL: main()
 * 
 * DESCRIÇÃO: Controla todo o fluxo do programa avançado, incluindo:
 *            - Definição de variáveis para dados básicos e calculados
 *            - Coleta de dados de duas cartas via entrada padrão
 *            - Cálculos de atributos derivados (densidade populacional, PIB per capita, Super Poder)
 *            - Comparações entre cartas atributo por atributo
 *            - Exibição completa dos dados e resultados das comparações
 * 
 * FLUXO DO ALGORITMO:
 * 1. Declaração de variáveis para armazenar dados de duas cartas
 * 2. Coleta de dados da primeira carta via entrada padrão
 * 3. Coleta de dados da segunda carta via entrada padrão  
 * 4. Cálculo de atributos derivados para ambas as cartas
 * 5. Comparação das cartas atributo por atributo
 * 6. Exibição formatada dos dados e resultados das comparações
 * 
 * RETORNO: 0 (indicando execução bem-sucedida)
 */
int main() {
    /*
     * ========================================================================
     * SEÇÃO 1: DECLARAÇÃO DE VARIÁVEIS
     * ========================================================================
     * 
     * Esta seção define todas as variáveis necessárias para armazenar os
     * dados das duas cartas do Super Trunfo, incluindo atributos básicos
     * e calculados. Utilizamos sufixos "1" e "2" para diferenciar as cartas.
     */
    
    // === VARIÁVEIS DA PRIMEIRA CARTA ===
    char estado1;                    // Estado representado por uma letra (A-H)
    char codigo1[4];                 // Código da carta (ex: "A01") - array de 4 chars para acomodar 3 caracteres + '\0'
    char nome1[100];                 // Nome da cidade - array grande para acomodar nomes extensos
    unsigned long int populacao1;   // População da cidade (unsigned long para números grandes)
    float area1;                     // Área da cidade em km² (número decimal para precisão)
    float pib1;                      // PIB em bilhões de reais (número decimal para valores fracionários)
    int pontos_turisticos1;          // Quantidade de pontos turísticos (número inteiro)
    
    // === VARIÁVEIS CALCULADAS DA PRIMEIRA CARTA ===
    float densidade_pop1;            // Densidade populacional calculada (hab/km²)
    float pib_per_capita1;           // PIB per capita calculado (reais por habitante)
    float super_poder1;              // Super Poder (soma de todos os atributos numéricos)
    
    // === VARIÁVEIS DA SEGUNDA CARTA ===
    char estado2;                    // Estado representado por uma letra (A-H)
    char codigo2[4];                 // Código da carta (ex: "B02") - array de 4 chars
    char nome2[100];                 // Nome da cidade - array para strings longas
    unsigned long int populacao2;   // População da cidade (unsigned long para números grandes)
    float area2;                     // Área da cidade em km² (número decimal)
    float pib2;                      // PIB em bilhões de reais (número decimal)
    int pontos_turisticos2;          // Quantidade de pontos turísticos (número inteiro)
    
    // === VARIÁVEIS CALCULADAS DA SEGUNDA CARTA ===
    float densidade_pop2;            // Densidade populacional calculada (hab/km²)
    float pib_per_capita2;           // PIB per capita calculado (reais por habitante)
    float super_poder2;              // Super Poder (soma de todos os atributos numéricos)
    
    /*
     * ========================================================================
     * SEÇÃO 2: CADASTRO DA PRIMEIRA CARTA
     * ========================================================================
     * 
     * Esta seção coleta todos os dados da primeira carta através de prompts
     * interativos ao usuário. Utiliza diferentes formatos de scanf() para
     * capturar adequadamente cada tipo de dado.
     */
    
    printf("=== CADASTRO DA PRIMEIRA CARTA ===\n");
    
    // Leitura do estado (char) - o espaço antes de %c consome whitespace residual
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado1);
    
    // Leitura do código da carta (string) - %s lê até encontrar espaço/newline
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", codigo1);
    
    // Leitura do nome da cidade (string com espaços) - %[^\n] lê até encontrar newline
    // O espaço inicial consome qualquer whitespace residual do scanf anterior
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nome1);
    
    // Leitura da população (unsigned long) - %lu para números inteiros grandes sem sinal
    printf("Digite a população: ");
    scanf("%lu", &populacao1);
    
    // Leitura da área (float) - %f para números decimais
    printf("Digite a área (km²): ");
    scanf("%f", &area1);
    
    // Leitura do PIB (float) - %f para valores decimais monetários
    printf("Digite o PIB (bilhões de reais): ");
    scanf("%f", &pib1);
    
    // Leitura dos pontos turísticos (inteiro) - %d para contagem
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos1);
    
    /*
     * ========================================================================
     * SEÇÃO 3: CADASTRO DA SEGUNDA CARTA
     * ========================================================================
     * 
     * Esta seção replica o processo de coleta de dados para a segunda carta,
     * utilizando as mesmas técnicas de entrada, mas armazenando em variáveis
     * diferentes (com sufixo "2").
     */
    
    printf("\n=== CADASTRO DA SEGUNDA CARTA ===\n");
    
    // Coleta de dados da segunda carta seguindo o mesmo padrão da primeira
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado2);
    
    printf("Digite o código da carta (ex: B02): ");
    scanf("%s", codigo2);
    
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nome2);
    
    // População como unsigned long int
    printf("Digite a população: ");
    scanf("%lu", &populacao2);
    
    printf("Digite a área (km²): ");
    scanf("%f", &area2);
    
    printf("Digite o PIB (bilhões de reais): ");
    scanf("%f", &pib2);
    
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &pontos_turisticos2);
    
    /*
     * ========================================================================
     * SEÇÃO 4: CÁLCULOS DE ATRIBUTOS DERIVADOS
     * ========================================================================
     * 
     * Esta seção realiza os cálculos necessários para determinar atributos
     * derivados das cartas, incluindo densidade populacional, PIB per capita
     * e o Super Poder. Atenção especial é dada à conversão de tipos.
     */
    
    // === CÁLCULOS PARA A PRIMEIRA CARTA ===
    
    // Densidade populacional = população / área
    // Resultado: habitantes por quilômetro quadrado (hab/km²)
    // Conversão: unsigned long para float na divisão
    densidade_pop1 = (float)populacao1 / area1;
    
    // PIB per capita = PIB / população
    // Atenção: PIB está em bilhões, então multiplicamos por 1 bilhão (1e9)
    // para converter para reais antes de dividir pela população
    // Resultado: reais por habitante
    // Conversão: multiplicação por 1e9 para converter bilhões para unidades
    pib_per_capita1 = (pib1 * 1e9) / (float)populacao1;
    
    // Super Poder = soma de todos atributos numéricos + inverso da densidade
    // Inclui: população + área + PIB + pontos turísticos + PIB per capita + (1/densidade)
    // Conversões cuidadosas entre tipos para evitar perda de precisão
    super_poder1 = (float)populacao1 + area1 + pib1 + (float)pontos_turisticos1 + 
                   pib_per_capita1 + (1.0 / densidade_pop1);
    
    // === CÁLCULOS PARA A SEGUNDA CARTA ===
    
    // Mesmos cálculos aplicados à segunda carta
    densidade_pop2 = (float)populacao2 / area2;
    pib_per_capita2 = (pib2 * 1e9) / (float)populacao2;
    super_poder2 = (float)populacao2 + area2 + pib2 + (float)pontos_turisticos2 + 
                   pib_per_capita2 + (1.0 / densidade_pop2);
    
    /*
     * ========================================================================
     * SEÇÃO 5: EXIBIÇÃO DOS DADOS CADASTRADOS
     * ========================================================================
     * 
     * Esta seção apresenta ao usuário todos os dados coletados e calculados
     * de forma organizada e legível. Inclui tanto os dados básicos inseridos
     * pelo usuário quanto os valores derivados calculados pelo programa.
     */
    
    // Cabeçalho da seção de exibição
    printf("\n=== DADOS DAS CARTAS CADASTRADAS ===\n");
    
    // === EXIBIÇÃO DA PRIMEIRA CARTA ===
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);                    // %c para exibir caractere
    printf("Código: %s\n", codigo1);                    // %s para exibir string
    printf("Nome da Cidade: %s\n", nome1);              // %s para string com possíveis espaços
    printf("População: %lu\n", populacao1);             // %lu para unsigned long int
    printf("Área: %.2f km²\n", area1);                  // %.2f para float com 2 casas decimais
    printf("PIB: %.2f bilhões de reais\n", pib1);       // %.2f para formatação monetária
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1); // %d para contagem
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_pop1); // Atributo calculado
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);          // Atributo calculado
    printf("Super Poder: %.2f\n", super_poder1);                      // Atributo calculado
    
    // === EXIBIÇÃO DA SEGUNDA CARTA ===
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);                    // Formatação idêntica à primeira carta
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nome2);
    printf("População: %lu\n", populacao2);             // %lu para unsigned long int
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_pop2); // Atributo calculado
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);          // Atributo calculado
    printf("Super Poder: %.2f\n", super_poder2);                      // Atributo calculado
    
    /*
     * ========================================================================
     * SEÇÃO 6: COMPARAÇÃO ENTRE CARTAS
     * ========================================================================
     * 
     * Esta seção realiza comparações atributo por atributo entre as duas cartas.
     * Regra especial: para densidade populacional, menor valor vence.
     * Para todos os outros atributos, maior valor vence.
     * Resultado: 1 = Carta 1 vence, 0 = Carta 2 vence
     */
    
    printf("\n=== COMPARAÇÃO DE CARTAS ===\n");
    
    // População: maior valor vence
    printf("População: Carta %d venceu (%d)\n", 
           (populacao1 > populacao2) ? 1 : 2, 
           (populacao1 > populacao2) ? 1 : 0);
    
    // Área: maior valor vence
    printf("Área: Carta %d venceu (%d)\n", 
           (area1 > area2) ? 1 : 2, 
           (area1 > area2) ? 1 : 0);
    
    // PIB: maior valor vence
    printf("PIB: Carta %d venceu (%d)\n", 
           (pib1 > pib2) ? 1 : 2, 
           (pib1 > pib2) ? 1 : 0);
    
    // Pontos Turísticos: maior valor vence
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", 
           (pontos_turisticos1 > pontos_turisticos2) ? 1 : 2, 
           (pontos_turisticos1 > pontos_turisticos2) ? 1 : 0);
    
    // Densidade Populacional: MENOR valor vence (regra especial)
    printf("Densidade Populacional: Carta %d venceu (%d)\n", 
           (densidade_pop1 < densidade_pop2) ? 1 : 2, 
           (densidade_pop1 < densidade_pop2) ? 1 : 0);
    
    // PIB per Capita: maior valor vence
    printf("PIB per Capita: Carta %d venceu (%d)\n", 
           (pib_per_capita1 > pib_per_capita2) ? 1 : 2, 
           (pib_per_capita1 > pib_per_capita2) ? 1 : 0);
    
    // Super Poder: maior valor vence
    printf("Super Poder: Carta %d venceu (%d)\n", 
           (super_poder1 > super_poder2) ? 1 : 2, 
           (super_poder1 > super_poder2) ? 1 : 0);

    /*
     * FINALIZAÇÃO DO PROGRAMA
     * Retorna 0 para indicar que o programa foi executado com sucesso
     * sem erros ou problemas durante a execução.
     */
    return 0;
}

/*
 * ============================================================================
 * NOTAS TÉCNICAS E CONSIDERAÇÕES AVANÇADAS:
 * 
 * 1. GERENCIAMENTO DE MEMÓRIA E TIPOS:
 *    - unsigned long int para população (suporta até ~4.3 bilhões)
 *    - Arrays de char alocados estaticamente com tamanhos fixos
 *    - codigo[4] comporta códigos de 3 caracteres + terminador nulo
 *    - nome[100] oferece espaço suficiente para nomes de cidades extensos
 * 
 * 2. CONVERSÕES DE TIPOS:
 *    - Cast (float) usado para conversões seguras em cálculos
 *    - Multiplicação por 1e9 para converter bilhões para unidades
 *    - Atenção especial na soma do Super Poder para evitar overflow
 * 
 * 3. CÁLCULOS MATEMÁTICOS:
 *    - Densidade = população / área (hab/km²)
 *    - PIB per capita = (PIB * 1 bilhão) / população (reais)
 *    - Super Poder = soma de todos atributos + inverso da densidade
 * 
 * 4. SISTEMA DE COMPARAÇÃO:
 *    - Regra geral: maior valor vence (retorna 1 para Carta 1, 0 para Carta 2)
 *    - Exceção: densidade populacional (menor valor vence)
 *    - Operador ternário (?:) para determinação concisa do vencedor
 * 
 * 5. FORMATAÇÃO DE ENTRADA E SAÍDA:
 *    - scanf("%lu") para unsigned long int
 *    - scanf(" %c") usa espaço para consumir whitespace residual
 *    - scanf("%[^\n]") permite leitura de strings com espaços
 *    - %.2f garante exibição de 2 casas decimais para valores calculados
 * 
 * 6. LIMITAÇÕES E MELHORIAS FUTURAS:
 *    - Não há validação de entrada (divisão por zero na área)
 *    - Não há tratamento de overflow em cálculos
 *    - Sistema de comparação poderia incluir tratamento de empates
 *    - Tamanhos de array são fixos e podem ser limitantes
 * 
 * 7. PRECISÃO E PERFORMANCE:
 *    - Uso de float para cálculos (precisão de ~7 dígitos)
 *    - Cálculos realizados uma única vez após entrada de dados
 *    - Comparações diretas sem loops para máxima eficiência
 * ============================================================================
 */
