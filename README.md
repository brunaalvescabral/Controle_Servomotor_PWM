# Controle de Servo Motor com PWM no Wokwi

Este projeto demonstra como controlar um servo motor usando **PWM (Modulação por Largura de Pulso)** no Raspberry Pi Pico (RP2040) no simulador **Wokwi**. O código faz o servo se mover para três posições diferentes (0°, 90° e 180°) e, em seguida, realiza uma movimentação suave entre esses ângulos em um loop contínuo, utilizando PWM para controlar a posição do servo.

O projeto já está configurado com o arquivo `diagram.json`, que define as conexões e componentes no Wokwi. Basta abrir o projeto no simulador e executar o código.

---

## Como Funciona

### Componentes no Wokwi

1. **Raspberry Pi Pico W**:
   - Microcontrolador RP2040 simulado no Wokwi.
   - Utilizado para gerar o sinal PWM que controla o servo.

2. **Servo Motor**:
   - Conectado ao GPIO 22 do Pico W para receber o sinal PWM.
   - Alimentado pelo pino 3.3V do Pico W (no simulador, isso é seguro).

3. **Conexões**:
   - **GPIO 22**: Sinal PWM para o servo.
   - **3.3V**: Alimentação do servo.
   - **GND**: Conexão de terra.

> **Nota:** No simulador Wokwi, é seguro alimentar o servo diretamente do pino 3.3V do Pico W.

---

## Funcionamento do Código com PWM

O código utiliza **PWM** para controlar o servo motor. O PWM é configurado com uma frequência de 50Hz (período de 20ms), que é o padrão para servos. A posição do servo é determinada pela largura do pulso (ciclo ativo) enviado ao motor.

### Etapas do Código:

1. **Configuração do PWM**:
   - O pino GPIO 22 é configurado para gerar um sinal PWM com frequência de 50Hz (período de 20ms).

2. **Posicionamento do Servo**:
   - O servo é movido para três posições:
     - 180° (ciclo ativo de 2400µs).
     - 90° (ciclo ativo de 1470µs).
     - 0° (ciclo ativo de 500µs).
   - Em cada posição, o servo aguarda 5 segundos.

3. **Movimentação Suave com PWM**:
   - Após posicionar o servo nas três posições, o código entra em um loop onde o servo se move suavemente entre 0° e 180°.
   - A movimentação é feita em incrementos de 5µs, com um atraso de 10ms entre cada passo, ajustando o ciclo ativo do PWM.

---

### Funções Principais

1. **`configurar_pwm(uint pino)`**:
   - Configura o pino especificado para gerar um sinal PWM com período de 20ms.

2. **`definir_posicao_servo(uint pino, uint microssegundos)`**:
   - Define a posição do servo com base no ciclo ativo (em microssegundos) do PWM.

3. **`main()`**:
   - Função principal que executa a sequência de movimentos do servo utilizando PWM.

---

### Variáveis

- **`PINO_SERVO`**: Define o pino GPIO usado para controlar o servo (GPIO 22).
- **`PERIODO_PWM`**: Define o período do PWM como 20000 (20ms para 50Hz).

---

## Conclusão

Este projeto demonstra de forma prática como utilizar **PWM** para controlar um servo motor com o Raspberry Pi Pico no simulador Wokwi. Através da modulação por largura de pulso, é possível posicionar o servo em ângulos específicos e realizar movimentos suaves e precisos. O uso do Wokwi permite testar e validar o código de maneira rápida e eficiente, sem a necessidade de hardware físico.

Esse exemplo pode ser expandido para aplicações mais complexas, como o controle de múltiplos servos, integração com sensores ou criação de projetos de robótica. O PWM é uma técnica essencial para o controle de dispositivos que exigem precisão, como motores, LEDs e outros componentes eletrônicos.

---