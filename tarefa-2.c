#include <stdio.h>
#include <string.h>  // Incluído para usar a função strcmp
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/bootrom.h" 

void reiniciar_boot() {
    reset_usb_boot(0,0);
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