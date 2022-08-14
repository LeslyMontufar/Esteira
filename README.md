# Esteira ![Language grade: C](https://img.shields.io/badge/language-C-blue)

Uso de conversor AD para mudar intensidade do led conforme a resistência de um potenciômetro.

## Índice 

* [Descrição](#descrição)
* [Desenvolvimento](#desenvolvimento)

## Descrição

1. Considere inicialmente a figura abaixo onde os objetos são carregados por uma esteira e a sua presença é detectada por um sensor, gerando um pulso para cada objeto detectado. Uma caixa armazena os objetos e a sua missão é construir uma aplicação capaz de contar quantos objetos estão sendo colocados na caixa e interromper a esteira quando esse limite for alcançado. 

2. Considere que um pino de saída poderá indicar quando a esteira for parada. Por exemplo, você pode utilizar o LED da placa para representar essa situação.

3. A esteira só reinicializará a contagem e voltará a funcionar quando um operador apertar um botão, indicando que a caixa foi esvaziada. Você pode usar um pino de entrada para representar essa ação do operador.

![esteira](https://github.com/LeslyMontufar/Esteira/blob/main/img/esteira.png)

A contagem dos objetos deve ser feita através de um timer configurado para contagem de pulsos. PA0 pode ser o botão do operador e PC13 a indicação de esteira parada.

## Desenvolvimento
1. 
