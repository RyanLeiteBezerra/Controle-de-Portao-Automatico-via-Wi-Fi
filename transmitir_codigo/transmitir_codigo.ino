#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  Serial.begin(9600);

  // Configurar o pino de transmissão (substitua pelo pino correto)
  mySwitch.enableTransmit(12); // Transmissor conectado ao pino 12 do ESP32

  // Configurar a duração do pulso
  mySwitch.setPulseLength(508); // Comprimento do pulso capturado

  // Configurar o protocolo capturado
  mySwitch.setProtocol(6);

  Serial.println("Pronto para enviar o sinal. Pressione Enter para enviar.");
}

void loop() {
  if (Serial.available() > 0) { // Verifica se há entrada no Monitor Serial
    String input = Serial.readString(); // Lê a entrada do usuário
    if (input.length() > 0) { // Se houver algo digitado
      Serial.println("Enviando o sinal...");
      mySwitch.send(162020133, 28); // Envia o código decimal com 28 bits
      Serial.println("Sinal enviado com sucesso!");
    }
  }
}
