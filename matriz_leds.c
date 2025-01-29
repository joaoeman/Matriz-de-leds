#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "matriz_leds.h"

// Arquivo .pio para controle da matriz
#include "pio_matrix.pio.h"

// Pino que realizará a comunicação do microcontrolador com a matriz
#define OUT_PIN 7

Quadros ANIMACOES[10];
/*s
|   Declaração das animações
|   Cada tipo Quadro representa uma animação com 5 quadros 
*/
// PRIMEIRA ANIMAÇÃO
    Matriz_leds_config matriz = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz4 ={
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
   
void config_animacoes(){
    // PRIMEIRA ANIMAÇÃO
    ANIMACOES[0].n_quadros=5;
    ANIMACOES[0].desenhos[0]=&matriz;
    ANIMACOES[0].desenhos[1]=&matriz2;
    ANIMACOES[0].desenhos[2]=&matriz3;
    ANIMACOES[0].desenhos[3]=&matriz4;
    ANIMACOES[0].desenhos[4]=&matriz5;
    // SEGUNDA ANIMAÇÃO
}

//------------------------------------------------------------------------------------------------------------//
// Gera o binário que controla a cor de cada célula do LED
//rotina para definição da intensidade de cores do led
uint32_t gerar_binario_cor(double red, double green, double blue)
{
  unsigned char RED, GREEN, BLUE;
  RED = red * 255.0;
  GREEN = green * 255.0;
  BLUE = blue * 255.0;
  return (GREEN << 24) | (RED << 16) | (BLUE << 8);
}

uint configurar_matriz(PIO pio){
    bool ok;

    // Define o clock para 128 MHz, facilitando a divisão pelo clock
    ok = set_sys_clock_khz(128000, false);

    // Inicializa todos os códigos stdio padrão que estão ligados ao binário.
    stdio_init_all();

    printf("iniciando a transmissão PIO");
    if (ok) printf("clock set to %ld\n", clock_get_hz(clk_sys));

    //configurações da PIO
    uint offset = pio_add_program(pio, &pio_matrix_program);
    uint sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, OUT_PIN);

    return sm;
}

void imprimir_desenho(Matriz_leds_config configuracao, PIO pio, uint sm){
    for (int contadorLinha = 4; contadorLinha >= 0; contadorLinha--){
        if(contadorLinha % 2){
            for (int contadorColuna = 0; contadorColuna < 5; contadorColuna ++){
                uint32_t valor_cor_binario = gerar_binario_cor(
                    configuracao[contadorLinha][contadorColuna].red,
                    configuracao[contadorLinha][contadorColuna].green,
                    configuracao[contadorLinha][contadorColuna].blue
                );

                pio_sm_put_blocking(pio, sm, valor_cor_binario);
            }
        }else{
            for (int contadorColuna = 4; contadorColuna >= 0; contadorColuna --){
                uint32_t valor_cor_binario = gerar_binario_cor(
                    configuracao[contadorLinha][contadorColuna].red,
                    configuracao[contadorLinha][contadorColuna].green,
                    configuracao[contadorLinha][contadorColuna].blue
                );

                pio_sm_put_blocking(pio, sm, valor_cor_binario);
            }
        }
    }
}

RGB_cod obter_cor_por_parametro_RGB(int red, int green, int blue){
    RGB_cod cor_customizada = {red/255.0,green/255.0,blue/255.0};

    return cor_customizada;
}

void executar_animacao(int num_animacao,PIO pio, uint sm){
    // calcula o delay para quantidade de quadros por segundo
    int delay = (1000/ANIMACOES[num_animacao].n_quadros);
    // executa a animação
    printf("Tamanho do quadro:%d",ANIMACOES[num_animacao].n_quadros);
    for(int i=0;i<ANIMACOES[num_animacao].n_quadros;i++){
        imprimir_desenho(*(ANIMACOES[num_animacao].desenhos[i]),pio,sm);
        sleep_ms(delay);
    }
}
// funções da tarefa do embarcatech
#define tempo_frame 250
#define rows 4
#define cols 4

const uint8_t row_pins[rows] = {26,22,21,20};//R1 R2 R3 R4
const uint8_t col_pins[cols] = {19,18,17,16};//C1 C2 C3 C4

//mapamento teclado matricial
const char key_map[rows][cols] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'}
};

void keypad_init(){
    for(int i = 0; i< rows;i++){
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i],false);
    }
    for(int i = 0; i< cols;i++){
        gpio_init(col_pins[i]);
        gpio_set_dir(col_pins[i], GPIO_IN);
        gpio_pull_down(col_pins[i]);
    }
}
char read_keypad(){
    for(int row = 0;row<rows;row++){
        gpio_put(row_pins[row], 1);

        for(int col = 0; col<cols;col++){

            if(gpio_get(col_pins[col])){
                gpio_put(row_pins[row],0);
                sleep_ms(20);
                return key_map[row][col];
            }
        }
        gpio_put(row_pins[row], 0);
    }
    return '\0';
}

void animacao(PIO pio, uint sm)
{
    Matriz_leds_config matriz = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    
    Matriz_leds_config matriz2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    
    Matriz_leds_config matriz3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    
    Matriz_leds_config matriz4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
   
    Matriz_leds_config matriz5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    
    imprimir_desenho(matriz, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz2, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz3, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz4, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz5, pio, sm);
    sleep_ms(tempo_frame);
}

void animacao_b(PIO pio, uint sm)
{
    Matriz_leds_config matriz_b = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 0
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 1
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 2
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 3
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 4
    };
    Matriz_leds_config matriz_b2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_b3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_b4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 1.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.5, 0.0}, {0.0, 0.0, 1.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 1.0}, {0.5, 0.5, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 1.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_b5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}}, // Linha 0
        {{0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 1.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}}, // Linha 1
        {{0.5, 0.5, 0.0}, {0.0, 0.0, 1.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 1.0}, {0.5, 0.5, 0.0}}, // Linha 2
        {{0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 1.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}}, // Linha 3
        {{0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config *matrizes_b[] = {
        &matriz_b, &matriz_b2, &matriz_b3, &matriz_b4, &matriz_b5}; // Colocando as matrizes na array

    int num_matrizes_b = sizeof(matrizes_b) / sizeof(matrizes_b[0]); // Número de matrizes

    for (int i = 0; i < num_matrizes_b; i++)
    {
        imprimir_desenho(*matrizes_b[i], pio, sm); // Passa cada matriz por referência
        sleep_ms(tempo_frame);
    }
}

void animacao_c(PIO pio, uint sm)
{
    Matriz_leds_config matriz_c = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_c2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_c3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 4
    };
    Matriz_leds_config matriz_c4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 4
    };
    Matriz_leds_config matriz_c5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 4
    };
    Matriz_leds_config matriz_c6 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 1
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 4
    };
    Matriz_leds_config matriz_c7 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 0
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 1
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 4
    };
    Matriz_leds_config matriz_c8 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 0
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 1
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}}, // Linha 4
    };
    Matriz_leds_config matriz_c9 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 0
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 1
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_c10 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 0
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 1
        {{0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_c11 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 0
        {{0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_c12 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config* matrizes_c[] = {
        &matriz_c, &matriz_c2, &matriz_c3, &matriz_c4, &matriz_c5, &matriz_c6, 
        &matriz_c7, &matriz_c8, &matriz_c9, &matriz_c10, &matriz_c11, &matriz_c12
    }; // Colocando as matrizes na array

    int num_matrizes_c = sizeof(matrizes_c) / sizeof(matrizes_c[0]); // Número de matrizes

    for (int i = 0; i < num_matrizes_c; i++)
    {
        imprimir_desenho(*matrizes_c[i], pio, sm); // Passa cada matriz por referência
        sleep_ms(tempo_frame);
    }
}

void animacao_d(PIO pio, uint sm)
{
    Matriz_leds_config matriz_d = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_d2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_d3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_d4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_d5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}}, // Linha 4
    };

    Matriz_leds_config *matrizes_d[] = {
        &matriz_d, &matriz_d2, &matriz_d3, &matriz_d4, &matriz_d5}; // Colocando as matrizes na array

    int num_matrizes_d = sizeof(matrizes_d) / sizeof(matrizes_d[0]); // Número de matrizes

    for (int i = 0; i < num_matrizes_d; i++)
    {
        imprimir_desenho(*matrizes_d[i], pio, sm); // Passa cada matriz por referência
        sleep_ms(tempo_frame);
    }
}

void branco(PIO pio, uint sm){
Matriz_leds_config matriz_branco = {
    //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
    // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
    {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 0
    {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 1
    {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 2
    {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 3
    {{0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}, {0.2, 0.2, 0.2}}, // Linha 4
    };
    imprimir_desenho(matriz_branco, pio, sm);
}

void anima_05(PIO pio, uint sm){
    Matriz_leds_config matriz_f1 =  {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_f2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.2, 0.4, 0.2}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_f3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.2, 0.4, 0.2}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.7, 0.5, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}, {0.0, 0.0, 0.8}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_f4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.4, 0.2, 0.1}, {0.2, 0.4, 0.2}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_f5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.2, 0.4, 0.2}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_f6 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.7, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.2, 0.4, 0.2}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.7, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_f7 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.8, 0.8, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.7, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.4, 0.2, 0.1}, {0.2, 0.4, 0.2}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.7, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.7, 0.5, 0.3}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.8, 0.8, 0.0}}, // Linha 4
    };
    imprimir_desenho(matriz_f1, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_f2, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_f3, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_f4, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_f5, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_f6, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz_f7, pio, sm);
    sleep_ms(1000);
}

void jogo_da_cobrinha(PIO pio, uint sm)
{
    Matriz_leds_config frame1 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame6 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame7 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame8 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame9 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame10 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 4
    };

    Matriz_leds_config frame11 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 4
    };

    Matriz_leds_config frame12 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame13 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 4
    };

    Matriz_leds_config frame14 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame15 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 4
    };

    Matriz_leds_config *frames[] = {&frame1, &frame2, &frame3, &frame4, &frame5, &frame6, &frame7, &frame8, &frame9, &frame10, &frame11, &frame12, &frame13, &frame14, &frame15};
    int num_frames = sizeof(frames) / sizeof(frames[0]);

    for (int i = 0; i < num_frames; i++)
    {
        imprimir_desenho(*frames[i], pio, sm);
        sleep_ms(tempo_frame * 2);
    }
}

void animacao_g(PIO pio, uint sm)
{
    Matriz_leds_config matriz_g = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_g2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_g3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_g4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 0.5}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.5}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_g5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.5, 0.5, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config matriz_g6 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.5, 0.5, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config matriz_g7 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.5, 0.5, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config matriz_g8 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config matriz_g9 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config matriz_g10 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 1.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {0.0, 0.0, 1.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 1.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config *matrizes_g[] = {
        &matriz_g, &matriz_g2, &matriz_g3, &matriz_g4, &matriz_g5, &matriz_g6, &matriz_g7, &matriz_g8, &matriz_g9, &matriz_g10}; // Colocando as matrizes na array

    int num_matrizes_g = sizeof(matrizes_g) / sizeof(matrizes_g[0]); // Número de matrizes

    for (int i = 0; i < num_matrizes_g; i++)
    {
        imprimir_desenho(*matrizes_g[i], pio, sm); // Passa cada matriz por referência
        sleep_ms(tempo_frame * 2);
    }
}

void tecla_A(PIO pio, uint sm)
{
    Matriz_leds_config matriz = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    imprimir_desenho(matriz, pio, sm);
    sleep_ms(tempo_frame);
}

void tecla_B(PIO pio, uint sm)
{
    Matriz_leds_config matriz = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}}, // Linha 0
        {{0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}}, // Linha 1
        {{0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}}, // Linha 2
        {{0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}}, // Linha 3
        {{0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}}, // Linha 4
    };

    imprimir_desenho(matriz, pio, sm);
    sleep_ms(tempo_frame);
}

void tecla_C(PIO pio, uint sm)
{
    Matriz_leds_config frame1 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}}, // Linha 0
        {{0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}}, // Linha 1
        {{0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}}, // Linha 2
        {{0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}}, // Linha 3
        {{0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}}, // Linha 4
    };

    imprimir_desenho(frame1, pio, sm);
    sleep_ms(tempo_frame);
}

void tecla_D(PIO pio, uint sm)
{
    Matriz_leds_config frame1 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}}, // Linha 0
        {{0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}}, // Linha 1
        {{0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}}, // Linha 2
        {{0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}}, // Linha 3
        {{0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}}, // Linha 4
    };

    imprimir_desenho(frame1, pio, sm);
    sleep_ms(tempo_frame);
}

void animacao_onda(PIO pio, uint sm)
{
    Matriz_leds_config onda1 = {
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config onda2 = {
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config onda3 = {
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    // Exibir a onda no pio
    imprimir_desenho(onda1, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(onda2, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(onda3, pio, sm);
    sleep_ms(tempo_frame);
}
