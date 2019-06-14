
#include <DHT.h>
#include <ESP8266WiFi.h>
 
    //Nombre de la red
    const char* nombre = "IZI-0674";
     
    //Password
    const char* password = "F82DC00F0674";
     
    //Puerto (dejar en 80 por defecto)
    WiFiServer server(80);
    
const int data=2;


DHT dht(data,DHT11);



void setup() 
{
   dht.begin();
   Serial.begin(9600);

   delay(50); //Hay que dejar un margen de tiempo
 
  
  // Conectar a la red WiFi
  WiFi.begin(nombre, password);
  while (WiFi.status() != WL_CONNECTED)
    delay(100); //aqui tambien hay que dejar un margen de tiempo
  Serial.println("Conectado a la red WiFi");
  
  // Iniciar el servidor
  server.begin();
  Serial.println("Se ha iniciado el servidor");
  
  // Escribir la direccion IP
  Serial.print("IP: ");
  Serial.print(WiFi.localIP());
  Serial.println("");
 
}

void loop() 
{
  
  float hum = dht.readHumidity();
  float temp=dht.readTemperature();
    
    Serial.print("Temperatura: ");
    Serial.print(temp);
    Serial.println(" C");
    Serial.print("Humedad:     ");
    Serial.print(hum);
    Serial.println(" %");
    Serial.println();
    delay(1000);    

// Comprobar si se ha conectado algun cliente
  WiFiClient client = server.available();
   
  if (client) {
    Serial.println("Nueva conexion");
    
    // Escribir las cabeceras HTML
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
   
    //Escribir el contenido que vamos a visualizar
    client.println("<html>");
    client.print("Temperatura: ");
    client.print(temp);
    client.println(" C");
    client.print("Humedad:     ");
    client.print(hum);
    client.println(" %");
    client.println("</html>");    
  }
}
