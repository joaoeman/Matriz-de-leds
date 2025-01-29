// Definição de tipo da estrutura que irá controlar a cor dos LED's
typedef struct {
    double red;
    double green;
    double blue;
}Led_config;

typedef Led_config RGB_cod;
// Definição de tipo da matriz de leds
typedef Led_config Matriz_leds_config[5][5]; 

typedef struct Quadros{
    Matriz_leds_config *desenhos[5];
    int n_quadros;
}Quadros;

uint32_t gerar_binario_cor(double red, double green, double blue);

uint configurar_matriz(PIO pio);

void imprimir_desenho(Matriz_leds_config configuracao, PIO pio, uint sm);
void executar_animacao(int num_animacao,PIO pio, uint sm);
void config_animacoes();
RGB_cod obter_cor_por_parametro_RGB(int red, int green, int blue);

//funções da tarefa
void keypad_init();
char read_keypad();
void animacao(PIO pio, uint sm);
void animacao_b(PIO pio, uint sm);
void animacao_c(PIO pio, uint sm);
void animacao_d(PIO pio, uint sm);
void anima_05(PIO pio, uint sm);
void branco(PIO pio, uint sm);
void jogo_da_cobrinha(PIO pio, uint sm);
void animacao_g(PIO pio, uint sm);
void tecla_A(PIO pio, uint sm);
void tecla_B(PIO pio, uint sm);
void tecla_C(PIO pio, uint sm);
void tecla_D(PIO pio, uint sm);
void animacao_onda(PIO pio, uint sm);