#include <stdio.h>
#include <string.h>  // Incluído para usar a função strcmp
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/bootrom.h" 

// Definição dos pinos dos LEDs
#define LED_VERDE_PIN 11
#define LED_AZUL_PIN 12
#define LED_VERMELHO_PIN 13
#define LED_BRANCO_PIN 14 

// Definição do pino do buzzer
#define BUZZER_PIN 21

void reiniciar_boot() {
    reset_usb_boot(0,0);
}

void inicializar_componentes() {
    // Inicializar os LEDs
    gpio_init(LED_VERDE_PIN);
    gpio_set_dir(LED_VERDE_PIN, GPIO_OUT);
    
    gpio_init(LED_AZUL_PIN);
    gpio_set_dir(LED_AZUL_PIN, GPIO_OUT);
    
    gpio_init(LED_VERMELHO_PIN);
    gpio_set_dir(LED_VERMELHO_PIN, GPIO_OUT);
    
    gpio_init(LED_BRANCO_PIN);
    gpio_set_dir(LED_BRANCO_PIN, GPIO_OUT);

    // Inicializar o Buzzer
    gpio_init(BUZZER_PIN);
    gpio_set_dir(BUZZER_PIN, GPIO_OUT);
}

void ligar_led_verde() {
    gpio_put(LED_VERDE_PIN, 1);  // Acende o LED verde
    gpio_put(LED_AZUL_PIN, 0);   // Desliga os outros LEDs
    gpio_put(LED_VERMELHO_PIN, 0);
    gpio_put(LED_BRANCO_PIN, 0);
}

void ligar_led_azul() {
    gpio_put(LED_AZUL_PIN, 1);   // Acende o LED azul
    gpio_put(LED_VERDE_PIN, 0);  // Desliga os outros LEDs
    gpio_put(LED_VERMELHO_PIN, 0);
    gpio_put(LED_BRANCO_PIN, 0);
}

void ligar_led_vermelho() {
    gpio_put(LED_VERMELHO_PIN, 1);  // Acende o LED vermelho
    gpio_put(LED_VERDE_PIN, 0);     // Desliga os outros LEDs
    gpio_put(LED_AZUL_PIN, 0);
    gpio_put(LED_BRANCO_PIN, 0);
}

void ligar_leds_branco() {
    gpio_put(LED_BRANCO_PIN, 1);   // Acende o LED branco
    gpio_put(LED_VERDE_PIN, 0);    // Desliga os outros LEDs
    gpio_put(LED_AZUL_PIN, 0);
    gpio_put(LED_VERMELHO_PIN, 0);
}

void desligar_leds() {
    gpio_put(LED_VERDE_PIN, 0);    // Desliga o LED verde
    gpio_put(LED_AZUL_PIN, 0);     // Desliga o LED azul
    gpio_put(LED_VERMELHO_PIN, 0); // Desliga o LED vermelho
    gpio_put(LED_BRANCO_PIN, 0);   // Desliga o LED branco
}

void acionar_buzzer() {
    gpio_put(BUZZER_PIN, 1);  // Liga o buzzer
    sleep_ms(500);            // Aguarda 500ms
    gpio_put(BUZZER_PIN, 0);  // Desliga o buzzer
}


int main() {
    char comando[10];
    stdio_init_all();

    /*
        ToDo
        Recerber o comando do usuário
    */
    
    while (1) {
        
        // Interpretando os comandos
        if (strcmp(comando, "verde") == 0) {
            ligar_led_verde();
        } else if (strcmp(comando, "azul") == 0) {
            ligar_led_azul();
        } else if (strcmp(comando, "vermelho") == 0) {
            ligar_led_vermelho();
        } else if (strcmp(comando, "branco") == 0) {
            ligar_leds_branco();
        } else if (strcmp(comando, "desligar") == 0) {
            desligar_leds();
        } else if (strcmp(comando, "buzzer") == 0) {
            acionar_buzzer();
        } else if (strcmp(comando, "reboot") == 0) {
            reiniciar_boot();
        } else {
            printf("Comando não reconhecido!\n");
        }
    }

    return 0;
}