# TAREFA 2 - MICROCONTROLADORES - EMBARCATECH

Resolução da Tarefa 2 proposta na Unidade 4-Microcontroladores- do EmbarcaTech. Este projeto apresenta, através do uso da ferramenta educacional BitDogLab, o controle de pinos GPIO e o acionamento de periféricos como LEDs RGB e Buzzer, uma forma de interação entre o usuário e o sistema por meio de comandos interpretados pelo microcontrolador da Raspberry Pi Pico W, o RP2040.

## FUNCIONALIDADES

O programa funciona da seguinte maneira: o sistema ofertará a possibilidade, através de comandos, onde o usuário pode selecionar ligar ou desligar um LED vermelho, um LED azul, um LED verde, um LED branco ou um Buzzer. Por meio da escolha de um caractere, este usuário determinará a resposta do sistema. A interação realizada pode ser monitorada através do serial monitor, que emitirá a resposta do sistema oriunda da escolha do usuário. Por fim, o sistema dará um reboot ao final da experiência do usuário.

## DIVISÃO DAS ATIVIDADES

As atividades foram divididas em  tópicos, sendo realizadas segundo as instruções e detalhamentos fornecidos pelo Líder do repositório, Guilherme. A divisão consistiu em:

1. **Construir diagrama.json no simulador Wokwi** *(Realizado por Vitória)*  
   Diagrama construído no simulador online Wokwi, contendo:  
   - 01 Raspberry Pi Pico W;  
   - 03 LEDs com as cores vermelho, verde e azul;  
   - 01 Buzzer.  

2. **Configurar Buzzer e LEDs** *(Realizado por Marcos)*  
   Configurações do Buzzer e LEDs, criação de macros para os pinos, criação de funções para a inicialização e utilização de comandos.

3. **Realizar a leitura através do terminal serial** *(Realizado por Camila)*  
   Realização da leitura de um buffer de caracteres utilizando a biblioteca de entrada e saída padrão da linguagem C (`scanf()`).

4. **Mapear as instruções para ligar, desligar os LEDs e os Buffers, assim como para chamar a função para fazer reboot na placa** *(Realizado por Enzo)*  
   Mapeamento das instruções do programa e função de reboot seguindo a lógica de que deve ser dado um determinado input do teclado, consequentemente realizar a ação da função acionada pelo comando.

5. **Escrever o README.md e produzir o vídeo explicativo do projeto** *(Realizado por Camila)*  
   Escrita do arquivo README.md, o qual contém as atividades realizadas, descrição do projeto e detalhamento da atividade realizada. Produção do vídeo demonstrativo do projeto.

Enquanto o líder ficou responsável pela gestão do repositório e equipe de desenvolvedores.

## COMPONENTES E FERRAMENTAS UTILIZADOS

- Placa de desenvolvimento BitDogLab;  
- Cabo de conexão USB-A;  
- Computador pessoal;  
- Visual Studio Code;
- Wokwi.

## LÓGICA UTILIZADA NA REALIZAÇÃO DA TAREFA

A realização da tarefa seguiu a estratégia de possuir um líder que tornou-se responsável por auxiliar e monitorar as atividades realizadas pelos desenvolvedores, enquanto os mesmos assumiram tarefas a serem feitas para que o sistema fosse completado.  

A primeira etapa foi a criação do `diagram.json` no Wokwi. Posteriormente, o ambiente de desenvolvimento passou a ser o VS Code para realização dos códigos. GPIOs e funções foram declaradas e integradas à `main`, bem como o monitoramento via serial monitor, possibilitado por funções presentes no código. Assim, foram realizados testes para a conclusão do projeto.

## Linguagem utilizada
- **C**
## Equipe

- **Líder**: Guilherme Emetério  
- **Desenvolvedores**:  
  - Enzo Andrade  
  - Camila Ramos
  - Vitória Freire  
  - Mateus Moreira  
  - Marcus Vinicius  

## VÍDEO EXPLICATIVO
[Link do vídeo explicativo](#)
