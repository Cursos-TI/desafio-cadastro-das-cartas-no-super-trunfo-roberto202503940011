/*
 * ============================================================================
 * PROGRAMA: Sistema Intermediário de Cadastro de Cartas do Super Trunfo
 * AUTOR: Roberto
 * DESCRIÇÃO: Este programa implementa um sistema intermediário para cadastrar duas
 *            cartas do jogo Super Trunfo, permitindo ao usuário inserir
 *            informações detalhadas sobre cidades, calcular atributos derivados
 *            (densidade populacional e PIB per capita) e exibir os dados de forma
 *            organizada e legível.
 * ============================================================================
 */

#include <stdio.h>  // Biblioteca padrão para entrada e saída de dados

/*
 * FUNÇÃO PRINCIPAL: main()
 * 
 * DESCRIÇÃO: Controla todo o fluxo do programa intermediário, incluindo:
 *            - Definição de variáveis para dados básicos e calculados
 *            - Coleta de dados de duas cartas via entrada padrão
 *            - Cálculos de atributos derivados (densidade populacional e PIB per capita)
 *            - Exibição completa dos dados coletados e calculados
 * 
 * FLUXO DO ALGORITMO:
 * 1. Declaração de variáveis para armazenar dados de duas cartas
 * 2. Coleta de dados da primeira carta via entrada padrão
 * 3. Coleta de dados da segunda carta via entrada padrão  
 * 4. Cálculo de atributos derivados para ambas as cartas
 * 5. Exibição formatada dos dados básicos e calculados
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
     * dados das duas cartas do Super Trunfo, incluindo tanto os atributos
     * básicos inseridos pelo usuário quanto os atributos calculados.
     * Utilizamos sufixos "1" e "2" para diferenciar as cartas.
     */
    
    // === VARIÁVEIS DA PRIMEIRA CARTA ===
    char estado1;              // Estado representado por uma letra (A-H)
    char codigo1[4];           // Código da carta (ex: "A01") - array de 4 chars para acomodar 3 caracteres + '\0'
    char nome1[100];           // Nome da cidade - array grande para acomodar nomes extensos
    int populacao1;            // População da cidade (número inteiro de habitantes)
    float area1;               // Área da cidade em km² (número decimal para precisão)
    float pib1;                // PIB em bilhões de reais (número decimal para valores fracionários)
    int pontos_turisticos1;    // Quantidade de pontos turísticos (número inteiro)
    
    // === VARIÁVEIS CALCULADAS DA PRIMEIRA CARTA ===
    float densidade_pop1;      // Densidade populacional calculada (hab/km²)
    float pib_per_capita1;     // PIB per capita calculado (reais por habitante)
    
    // === VARIÁVEIS DA SEGUNDA CARTA ===
    char estado2;              // Estado representado por uma letra (A-H)
    char codigo2[4];           // Código da carta (ex: "B02") - array de 4 chars
    char nome2[100];           // Nome da cidade - array para strings longas
    int populacao2;            // População da cidade (número inteiro)
    float area2;               // Área da cidade em km² (número decimal)
    float pib2;                // PIB em bilhões de reais (número decimal)
    int pontos_turisticos2;    // Quantidade de pontos turísticos (número inteiro)
    
    // === VARIÁVEIS CALCULADAS DA SEGUNDA CARTA ===
    float densidade_pop2;      // Densidade populacional calculada (hab/km²)
    float pib_per_capita2;     // PIB per capita calculado (reais por habitante)
    
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
    
    // Leitura da população (inteiro) - %d para números inteiros
    printf("Digite a população: ");
    scanf("%d", &populacao1);
    
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
    
    printf("Digite a população: ");
    scanf("%d", &populacao2);
    
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
     * derivados das cartas: densidade populacional e PIB per capita.
     * Os cálculos são realizados após a coleta de todos os dados.
     */
    
    // === CÁLCULOS PARA A PRIMEIRA CARTA ===
    
    // Densidade populacional = população / área
    // Resultado: habitantes por quilômetro quadrado (hab/km²)
    // Conversão de int para float para garantir precisão decimal
    densidade_pop1 = (float)populacao1 / area1;
    
    // PIB per capita = PIB / população
    // Atenção: PIB está em bilhões, então multiplicamos por 1 bilhão (1e9)
    // para converter para reais antes de dividir pela população
    // Resultado: reais por habitante
    pib_per_capita1 = (pib1 * 1e9) / (float)populacao1;
    
    // === CÁLCULOS PARA A SEGUNDA CARTA ===
    
    // Aplicação dos mesmos cálculos para a segunda carta
    densidade_pop2 = (float)populacao2 / area2;
    pib_per_capita2 = (pib2 * 1e9) / (float)populacao2;
    
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
    printf("População: %d\n", populacao1);              // %d para número inteiro
    printf("Área: %.2f km²\n", area1);                  // %.2f para float com 2 casas decimais
    printf("PIB: %.2f bilhões de reais\n", pib1);       // %.2f para formatação monetária
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1); // %d para contagem
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_pop1); // Valor calculado
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);          // Valor calculado
    
    // === EXIBIÇÃO DA SEGUNDA CARTA ===
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);                    // Formatação idêntica à primeira carta
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nome2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_pop2); // Valor calculado
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);          // Valor calculado

    /*
     * FINALIZAÇÃO DO PROGRAMA
     * Retorna 0 para indicar que o programa foi executado com sucesso
     * sem erros ou problemas durante a execução.
     */
    return 0;
}

/*
 * ============================================================================
 * NOTAS TÉCNICAS E CONSIDERAÇÕES:
 * 
 * 1. GERENCIAMENTO DE MEMÓRIA:
 *    - Arrays de char são alocados estaticamente com tamanhos fixos
 *    - codigo[4] comporta códigos de 3 caracteres + terminador nulo
 *    - nome[100] oferece espaço suficiente para nomes de cidades extensos
 * 
 * 2. CÁLCULOS MATEMÁTICOS:
 *    - Densidade populacional: divisão simples população/área
 *    - PIB per capita: conversão de bilhões para reais (×1e9) antes da divisão
 *    - Cast (float) usado para garantir precisão decimal nos cálculos
 * 
 * 3. FORMATAÇÃO DE ENTRADA:
 *    - scanf(" %c") usa espaço para consumir whitespace residual
 *    - scanf("%[^\n]") permite leitura de strings com espaços
 *    - scanf("%s") adequado para códigos sem espaços
 * 
 * 4. FORMATAÇÃO DE SAÍDA:
 *    - %.2f garante exibição de 2 casas decimais para valores monetários e calculados
 *    - %d usado para números inteiros (população, pontos turísticos)
 *    - %c para caracteres individuais (estado)
 *    - %s para strings (código, nome da cidade)
 * 
 * 5. CONVERSÃO DE UNIDADES:
 *    - PIB inserido em bilhões de reais
 *    - PIB per capita calculado em reais (unidade base)
 *    - Densidade em habitantes por km² (hab/km²)
 * 
 * 6. PRECISÃO E EFICIÊNCIA:
 *    - Uso de float para cálculos decimais
 *    - Conversões realizadas apenas quando necessário
 *    - Cálculos executados uma única vez após entrada completa dos dados
 * 
 * 7. USABILIDADE:
 *    - Prompts claros indicam formato esperado de entrada
 *    - Separação visual entre seções através de headers
 *    - Exibição organizada facilita verificação dos dados inseridos e calculados
 * 
 * 8. LIMITAÇÕES CONHECIDAS:
 *    - Não há validação de entrada (divisão por zero, valores negativos)
 *    - Não há tratamento de erros de entrada inválida
 *    - Tamanhos de array são fixos e podem ser limitantes
 *    - Precisão limitada do tipo float (~7 dígitos significativos)
 * ============================================================================
 */
