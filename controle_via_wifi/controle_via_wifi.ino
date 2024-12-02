#include <WiFi.h>
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

// Configurações da rede Wi-Fi
const char* ssid = "NOME_DA_SUA_REDE";  
const char* password = "SENHA_DA_SUA_REDE";  

// Configuração do servidor web
WiFiServer server(80);

// Senha para acessar o controle do portão
const String accessPassword = "Magnun13666";

void setup() {
  Serial.begin(9600);

  // Configurar o transmissor RF
  mySwitch.enableTransmit(12); // Substitua pelo pino correto
  mySwitch.setPulseLength(508);
  mySwitch.setProtocol(6);

  // Conectar ao Wi-Fi
  Serial.print("Conectando ao Wi-Fi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConectado ao Wi-Fi!");
  Serial.print("IP do ESP32: ");
  Serial.println(WiFi.localIP());

  // Iniciar o servidor
  server.begin();
  Serial.println("Servidor iniciado.");
}

void loop() {
  // Verifica conexões de clientes
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Cliente conectado.");
    String request = client.readStringUntil('\r');
    client.flush();

    Serial.println("Requisição recebida: ");
    Serial.println(request);

    // Verifica se a senha foi enviada
    if (request.indexOf("GET /?password=") != -1) {
      int passwordStart = request.indexOf("password=") + 9; // Posição da senha
      int passwordEnd = request.indexOf(' ', passwordStart); // Fim da senha
      String receivedPassword = request.substring(passwordStart, passwordEnd);
      receivedPassword.trim(); // Remove espaços extras

      Serial.print("Senha recebida: ");
      Serial.println(receivedPassword);

      if (receivedPassword == accessPassword) {
        // Página principal com controle do portão
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println();
        client.println("<html>");
        client.println("<body>");
        client.println("<h1>Controle do Portão</h1>");
        client.println("<button id=\"btnAbrir\">Abrir Portão</button>");
        client.println("<p id=\"status\"></p>");
        client.println("<script>");
        client.println("document.getElementById('btnAbrir').addEventListener('click', function() {");
        client.println("  fetch('/abrir').then(response => response.text()).then(data => {");
        client.println("    document.getElementById('status').innerText = 'Portão acionado!';");
        client.println("    setTimeout(() => document.getElementById('status').innerText = '', 2000);");
        client.println("  }).catch(error => console.log(error));");
        client.println("});");
        client.println("</script>");
        client.println("</body>");
        client.println("</html>");
      } else {
        // Resposta para senha incorreta
        client.println("HTTP/1.1 401 Unauthorized");
        client.println("Content-Type: text/html");
        client.println();
        client.println("<html><body><h1>Senha incorreta!</h1></body></html>");
      }
    } else if (request.indexOf("/abrir") != -1) {
      Serial.println("Enviando sinal para abrir o portão...");
      mySwitch.send(162020133, 28);
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/plain");
      client.println();
      client.println("OK");
    } else {
      // Página de login
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println();
      client.println("<html>");
      client.println("<body>");
      client.println("<h1>Acesso ao Controle do Portão</h1>");
      client.println("<form action=\"/\" method=\"GET\">");
      client.println("<label>Senha: </label>");
      client.println("<input type=\"password\" name=\"password\">");
      client.println("<button type=\"submit\">Entrar</button>");
      client.println("</form>");
      client.println("</body>");
      client.println("</html>");
    }
    client.stop();
    Serial.println("Cliente desconectado.");
  }
}
