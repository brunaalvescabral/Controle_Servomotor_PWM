#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definições
#define PINO_SERVO 22       // GPIO 22 para o servo
#define PERIODO_PWM 20000   // Período de 20ms (50Hz)

// Função para configurar o PWM
void configurar_pwm(uint pino) {
    gpio_set_function(pino, GPIO_FUNC_PWM); // Configura o pino para função PWM
    uint slice_num = pwm_gpio_to_slice_num(pino); // Obtém o slice do PWM
    pwm_set_clkdiv(slice_num, 125.0f); // Divide o clock para 1MHz (125MHz / 125 = 1MHz)
    pwm_set_wrap(slice_num, PERIODO_PWM); // Define o período do PWM (20ms)
    pwm_set_enabled(slice_num, true); // Habilita o PWM
}

// Função para definir a posição do servo em microssegundos
void definir_posicao_servo(uint pino, uint microssegundos) {
    uint slice_num = pwm_gpio_to_slice_num(pino);
    uint canal = pwm_gpio_to_channel(pino);
    pwm_set_chan_level(slice_num, canal, microssegundos); // Define o ciclo ativo
}

int main() {
    stdio_init_all(); // Inicializa a comunicação serial (para debug)

    // Configura o PWM para o servo
    configurar_pwm(PINO_SERVO);

    // 2) Posiciona o servo em 180 graus (2400µs)
    definir_posicao_servo(PINO_SERVO, 2400);
    sleep_ms(5000);

    // 3) Posiciona o servo em 90 graus (1470µs)
    definir_posicao_servo(PINO_SERVO, 1470);
    sleep_ms(5000);

    // 4) Posiciona o servo em 0 graus (500µs)
    definir_posicao_servo(PINO_SERVO, 500);
    sleep_ms(5000);

    // 5) Movimentação periódica do servo entre 0 e 180 graus
    while (true) {
        // Move de 0° a 180°
        for (uint us = 500; us <= 2400; us += 5) {
            definir_posicao_servo(PINO_SERVO, us);
            sleep_ms(10); // Atraso para movimentação suave
        }

        // Move de 180° a 0°
        for (uint us = 2400; us >= 500; us -= 5) {
            definir_posicao_servo(PINO_SERVO, us);
            sleep_ms(10); // Atraso para movimentação suave
        }
    }

    return 0;
}