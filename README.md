# Sistema de Gerenciamento de Estacionamento Rotativo

Disciplina: Laboratorio de Programacao - Engenharia da Computacao
Professor: Rondineli Seba Salomao
Instituicao: UFMA - Universidade Federal do Maranho

---

## Identificacao

Nome: Pedro Lucca Dantas
Matricula: 20240055510

---

## Descricao do Problema

Um estacionamento rotativo cobra pelo tempo de permanencia do veiculo. Diferente de estacionamentos mensalistas, o sistema cobra por hora e varia o preço conforme o tipo do veiculo. Este programa simula o sistema de cobranca desse modelo, calculando o valor a ser pago pelo cliente com base no tipo do veiculo e no tempo de permanencia, aplicando descontos ou multas quando as regras assim determinarem.

---

## Analise do Problema

Como funciona um estacionamento rotativo na vida real:

O cliente registra a entrada e, na saída, o sistema calcula o tempo decorrido e aplica a tarifa correspondente ao tipo de veículo. Permanências muito curtas sao cobradas com um valor minimo de uma hora. Estadias longas podem gerar descontos, e permanencias excessivas resultam em multa por ocupação prolongada da vaga.

Decisões que o sistema precisa tomar:

- Qual o tipo de veículo? Define a tarifa por hora.
- O tempo foi menor que 1 hora? Cobra-se o minimo de 1 hora.
- O tempo foi maior que 5 horas? Aplica-se desconto de 10%.
- O tempo foi maior que 10 horas? Aplica-se multa de R$ 20,00.

---

## Definicao das Variaveis

| Nome          | Tipo     | Finalidade                                              |
|---------------|----------|---------------------------------------------------------|
| placa         | char[]   | Armazena a placa do veiculo            |
| tipoVeiculo   | char[]   | Guarda exatamente o que o usuario digitou               |
| tipoNum       | int      | Tipo convertido para numero após leitura da entrada     |
| horas         | float    | Tempo de permanência do veiculo em horas                |
| tarifaPorHora | float    | Valor da hora conforme o tipo do veiculo                |
| valorBase     | float    | Valor calculado antes de aplicar desconto ou multa      |
| desconto      | float    | Valor do desconto a ser subtraído (se aplicável)        |
| multa         | float    | Valor da multa a ser somada (se aplicável)              |
| valorFinal    | float    | Valor total apos desconto e/ou multa                    |
| tipoTexto     | char[]   | Nome do tipo do veiculo por extenso para o recibo       |

---

## Regras de Negocio

Tipos de veiculo e tarifas:

| Codigo | Tipo        | Tarifa    |
|--------|-------------|-----------|
| 1      | Carro       | R$ 5,00/h |
| 2      | Moto        | R$ 3,00/h |
| 3      | Caminhonete | R$ 8,00/h |

Regras de tempo:

| Condição                      | Regra aplicada                    |
|-------------------------------|-----------------------------------|
| Permanencia menor que 1 hora  | Cobra-se o equivalente a 1 hora   |
| Permanencia maior que 5 horas | Desconto de 10% sobre o valor base|
| Permanencia maior que 10 horas| Multa adicional de R$ 20,00       |

Formula de calculo:

    valorBase  = tarifaPorHora x horas (minimo: 1 hora)
    desconto   = valorBase x 0,10  (se horas maior que 5)
    multa      = R$ 20,00          (se horas maior que 10)
    valorFinal = valorBase - desconto + multa

---

## Fluxograma

Inicio

    Ler placa, tipoVeiculo, horas

    Converter tipoVeiculo de texto para número com atoi:
        Se retornou 0, o usuario digitou por extenso:
            Se "carro", "Carro" ou "CARRO"       -> tipoNum = 1
            Se "moto", "Moto" ou "MOTO"           -> tipoNum = 2
            Se "caminhonete" ou variações         -> tipoNum = 3
            Caso contrario                        -> encerra com erro

    switch(tipoNum):
        Caso 1 -> tarifaPorHora = 5.0, atribui tipoTexto = "Carro" para puxar no recibo
        Caso 2 -> tarifaPorHora = 3.0, atribui tipoTexto = "Moto" para puxar no recibo
        Caso 3 -> tarifaPorHora = 8.0, atribui tipoTexto = "Caminhonete" para puxar no recibo
        Padrao -> encerra com erro

    Calculo do valor base:
        Se horas menor que 1.0 -> valorBase = tarifaPorHora
        Senao                  -> valorBase = tarifaPorHora x horas

    Desconto e multa:
        desconto = 0, multa = 0 por padrão
        Se horas maior que 10.0 -> multa = 20.0
        Senao se horas maior que 5.0 -> desconto = valorBase x 0.10

    valorFinal = valorBase - desconto + multa

    Exibir recibo

---

## Explicacao da Logica

No início do código incluo três bibliotecas: a stdio.h para entrada e saída de dados, a string.h para comparação de textos e a stdlib.h para converter texto em número. Na entrada de dados, o programa lê a placa, o tipo do veiculo e o tempo de permanência. O tipo é lido sempre como texto para aceitar tanto numeros quanto palavras por extenso. A funcao atoi converte o texto para numero; se retornar zero, significa que o usuario digitou por extenso, e o bloco if/else com strcmp faz a identificação e define o numero correspondente para tipoNum. Com o número em mãos, o switch-case define a tarifa e o nome do veiculo. Em seguida, um if/else calcula o valor base respeitando o minimo de uma hora. Outro if/else verifica as faixas de tempo para aplicar desconto ou multa. O valor final é calculado e exibido como recibo.

---

## Como Compilar e Executar

Pre-requisitos: GCC instalado.
No terminal:

Compilação:

    gcc main.c -o estacionamento

Execução:

    ./estacionamento.exe
