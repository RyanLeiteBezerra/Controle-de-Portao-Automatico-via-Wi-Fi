# Controle de Portão Automático via Wi-Fi com ESP32 e RF 433 MHz

Este projeto combina IoT, comunicação RF e automação para controlar um portão eletrônico remotamente utilizando um ESP32 e módulos RF de 433 MHz. O sistema permite a autenticação por senha e o acionamento do portão através de um navegador no celular, proporcionando segurança e praticidade.


### 🛠️ Funcionalidades

- Autenticação Segura: Acesso protegido por senha para evitar usos não autorizados.
- Controle via Wi-Fi: Interface web simples e acessível por qualquer dispositivo na mesma rede.
- Comunicação RF: Captação e envio do código do controle remoto original usando o protocolo RF 433 MHz.
- Personalização: Fácil adaptação para outros dispositivos ou controles que utilizem a mesma frequência.

### ⚙️ Componentes Utilizados

- ESP32: Microcontrolador principal responsável pela lógica do sistema e pelo servidor web.
- Módulo Receptor RF 433 MHz: Para captar o código do controle remoto original.
- Módulo Transmissor RF 433 MHz: Para enviar o código do controle e acionar o portão.
- Resistores e Divisor de Tensão: Para adaptar os níveis de tensão entre os componentes.

![Esquema do circuito](https://github.com/user-attachments/assets/16d6d56b-c266-4331-ae3f-e09edd78a1dd)

### 🖥️ Como Funciona:

1. O sistema capta o código do controle remoto original e o armazena.
2. O ESP32 hospeda uma página web onde é necessário inserir uma senha para autenticação.
3. Após a autenticação, o usuário pode acionar o portão clicando em um botão na interface web.
4. O módulo transmissor RF envia o código captado, simulando o controle remoto.


### 🧩 Requisitos:

- Arduino IDE configurado para ESP32.
- Biblioteca RCSwitch.
- Acesso a uma rede Wi-Fi.


### 🚀 Como Usar:

1. **Clone este repositório**

2. **Configure o ESP32 como receptor RF para capturar o sinal do controle remoto:**

- Conecte o módulo receptor RF 433 MHz ao ESP32 conforme o esquema elétrico.
- Carregue o código receptor no ESP32 utilizando a Arduino IDE.
- Pressione o botão do controle remoto próximo ao receptor RF.
- Observe no Monitor Serial o código capturado, o comprimento do pulso e o protocolo.

3. **Atualize o código do transmissor com as informações capturadas:**

- Abra o arquivo principal do projeto na Arduino IDE.
- Substitua as variáveis code, length e protocol pelas informações capturadas.

- Exemplo:

  mySwitch.send(162020133, 28); // Substitua pelos seus valores
  
  mySwitch.setPulseLength(508); // Substitua pelo comprimento de pulso capturado
  
  mySwitch.setProtocol(6); // Substitua pelo protocolo capturado

4. **Configure o Wi-Fi:**

- No mesmo código do transmissor, insira o SSID e a senha da sua rede Wi-Fi.
- Exemplo:

  const char* ssid = "NOME_DA_SUA_REDE";
   
  const char* password = "SENHA_DA_SUA_REDE";
  
5. **Carregue o código no ESP32:**

- Certifique-se de que o módulo transmissor RF está conectado corretamente ao ESP32.
- Envie o código atualizado para o ESP32.

6. **Acesse a interface web:**

- Conecte seu celular ou computador à mesma rede Wi-Fi do ESP32.
- No navegador, insira o endereço IP exibido no Monitor Serial.
- Digite a senha configurada para acessar a interface e controlar o portão.

### 📹 Demonstração:
https://github.com/user-attachments/assets/cfdc385f-300b-4ace-ab6a-f54b02e6c981
