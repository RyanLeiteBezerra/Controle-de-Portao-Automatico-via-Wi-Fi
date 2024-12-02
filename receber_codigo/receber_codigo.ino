#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch(); // Cria um objeto mySwitch da classe RCSwitch para controlar o transmissor/receptor RF.

void setup() {
	Serial.begin(9600); // Inicia a comunicação serial.
	mySwitch.enableReceive(14); // Ativa a recepção de dados no pino 14 da ESP32.
}

// Declaração de uma função estática para converter um número decimal em uma cadeia de caracteres binários.
static char * dec2bin(unsigned long Dec, unsigned int bitLength);

void loop() {
	// Verifica se há dados disponíveis para leitura pelo receptor RF.
	if (mySwitch.available()) {
		long receivedValue = mySwitch.getReceivedValue(); // Lê o valor recebido.
		long bitLength = mySwitch.getReceivedBitlength(); // Lê o número de bits do valor recebido.
		long pulseLength = mySwitch.getReceivedDelay(); // Lê o comprimento do pulso do sinal recebido.
		long protocol = mySwitch.getReceivedProtocol(); // Lê o protocolo do sinal recebido.
		const char* b = dec2bin(receivedValue, bitLength);  // Converte o valor recebido para binário usando a função dec2bin.
    
	    // Imprime no monitor serial as informações do sinal recebido.
	    Serial.print("Binário: ");
	    Serial.print(b);		
		Serial.print(" Comprimento do Pulso: ");
		Serial.print(pulseLength);
		Serial.print(" Valor recebido ");
		Serial.print(receivedValue);
		Serial.print("/ ");
		Serial.print(bitLength);
		Serial.print("bit ");
		Serial.print("Protocolo: ");
		Serial.println(protocol);
		mySwitch.resetAvailable(); // Limpa o status disponível para receber o próximo sinal.
	}
}

// Função que converte um número decimal em uma string binária preenchida com zeros até alcançar o comprimento de bits especificado.
static char * dec2bin(unsigned long Dec, unsigned int bitLength) {
	static char bin[64];  // Array estático para armazenar a string binária.
	unsigned int i = 0;  // Índice para construir a string binária.
	
	// Converte o número decimal em binário, armazenando de trás para frente.
	while (Dec > 0) {
		bin[32 + i++] = ((Dec & 1) > 0) ? '1' : '0';  // Adiciona '1' ou '0' ao array.
		Dec >>= 1;  // Desloca o número um bit para a direita.
	}
	
	// Preenche o restante da string binária com zeros até o comprimento especificado.
	for (unsigned int j = 0; j < bitLength; j++) {
		if (j >= bitLength - i) {
			bin[j] = bin[31 + i - (j - (bitLength - i))];  // Inverte a ordem dos bits já armazenados.
		} else {
			bin[j] = '0';  // Completa com zeros.
		}
	}
	
	bin[bitLength] = '\0';  // Adiciona o terminador de string.
	
	return bin;  // Retorna a string binária.
}