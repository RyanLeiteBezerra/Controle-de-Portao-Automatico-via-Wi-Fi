# Controle de Portão Automático via Wi-Fi com ESP32 e RF 433 MHz

Este projeto combina IoT, comunicação RF e automação para controlar um portão eletrônico remotamente utilizando um ESP32 e módulos RF de 433 MHz. O sistema permite a autenticação por senha e o acionamento do portão através de um navegador no celular, proporcionando segurança e praticidade.


### 🛠️ Funcionalidades

- Autenticação Segura: Acesso protegido por senha para evitar usos não autorizados.
- Controle via Wi-Fi: Interface web simples e acessível por qualquer dispositivo na mesma rede.
- Comunicação RF: Captação e envio do código do controle remoto original usando o protocolo RF 433 MHz.
- Personalização: Fácil adaptação para outros dispositivos ou controles que utilizem a mesma frequência.

### ⚙️ Componentes Utilizados no Circuito

- **ESP32:** Microcontrolador principal responsável pela lógica do sistema e pelo servidor web.
- **Módulo Receptor RF 433 MHz:** Para captar o código do controle remoto original.
- **Módulo Transmissor RF 433 MHz:** Para enviar o código do controle e acionar o portão.
- **Divisores de Tensão usando Resistores:** Para adaptar os níveis de tensão entre os componentes.

  1. Divisor de Tensão para o Receptor: Resistores de 1kΩ e 2kΩ
  2. Divisor de Tensão para o Transmissor: Resistores de 2kΩ e 510Ω

![Circuito](https://github.com/user-attachments/assets/635d8fbb-c83c-40f9-afac-c82411806f90)

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


### 🍎 Atalho no IPhone / Apple Watch:

1. **Abra o aplicativo "Atalhos" no iPhone**

2. **Crie um novo atalho:**
- Toque no botão "+" no canto superior direito para adicionar um novo atalho.
- Clique em **"Adicionar Ação"**.

3. **Escolha a ação "Expandir URL":**

- No campo de busca, digite **"URL"** e selecione a opção **"Expandir URL"**.
- Insira a URL para abrir o portão: http://<**IP exibido no Monitor Serial**>/abrir


4. **Adicione uma ação "Abrir URL":**

- Toque no botão "+" abaixo da primeira ação.
- Pesquise por **"Abrir URL"** e adicione.
- Certifique-se de que a URL expandida será aberta por essa ação.

5. **Renomeie o atalho:**

- Toque no ícone de três pontos no topo da tela.
- Digite o nome desejado, como **"Abrir Portão"**.
- Opcional: escolha um ícone ou cor para personalizar o atalho.
  
6. **Teste o atalho:**

- Toque no atalho criado para verificar se o portão é acionado corretamente.
-Se tudo estiver configurado corretamente, o portão será acionado automaticamente ao executar o atalho.

7. **Adicione o atalho ao Apple Watch (opcional):**

- Abra o aplicativo Atalhos no iPhone.
- Toque no atalho criado ("Abrir Portão").
- Toque nos três pontos no canto superior direito do atalho.
- Role para baixo até encontrar a opção "Mostrar no Apple Watch" e ative-a.
- Certifique-se de que o Apple Watch está sincronizado com o iPhone.

8. **Adicione o atalho à tela inicial (opcional):**

- Clique no ícone de três pontos no atalho.
- Selecione **"Adicionar à Tela de Início"** para criar um ícone diretamente acessível.
