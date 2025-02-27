# Medidor

Monitoramento de Temperatura com DHT11, LED e Buzzer

Descrição

Este projeto utiliza um sensor DHT11 para medir a temperatura ambiente. Caso a temperatura ultrapasse 30°C, um LED e um buzzer são ativados para emitir um alerta. As leituras são realizadas a cada 2 segundos e exibidas no monitor serial.

Componentes Utilizados

Microcontrolador (Ex: Arduino)

Sensor DHT11 (Temperatura e Umidade)

LED (Indicador visual de alerta)

Buzzer (Alerta sonoro)

Resistores e Jumpers (Conexão dos componentes)

Bibliotecas Necessárias Para compilar e executar este código, as seguintes bibliotecas devem estar instaladas:

BitDogLab.h

DHT.h

Pinos Utilizados

DHT11: Pino 5

LED: Pino 13

Buzzer: Pino 12

Funcionamento do Código

Configura os pinos do LED e buzzer como saída.

Inicializa o sensor DHT11.

A cada 2 segundos, realiza uma leitura da temperatura.

Caso a temperatura seja maior que 30°C, aciona o LED e o buzzer.

Exibe a temperatura no Monitor Serial.

Como Usar

Conecte os componentes conforme os pinos especificados.

Compile e carregue o código no microcontrolador.

Abra o Monitor Serial (9600 baud) para visualizar as leituras.

Observe os alertas caso a temperatura exceda 30°C.

Exemplo de Saída no Monitor Serial

Temperatura: 28.5 °C
Temperatura: 29.2 °C
Temperatura: 30.5 °C
ALERTA: Temperatura alta!
Temperatura: 31.0 °C
ALERTA: Temperatura alta!

Possíveis Melhorias

Adicionar um sensor de umidade para monitoramento adicional.

Integrar um display LCD para exibir as informações sem necessidade do Monitor Serial.

Implementar um sistema de envio de alertas via Wi-Fi ou Bluetooth.

Descrição Projeto documento: https://drive.google.com/file/d/1vcTK69qe6A14bOx2vPEFfS4qodb-jNyK/view?usp=sharing