/*  ----------------------------------------------------------------
    www.prometec.net

    Leyendo la temperatura y humedad con un sensor DHT11
    y subir los valores a un sercidor mediante WiFi con el esp8266.
  --------------------------------------------------------------------
*/

#include <ESP8266WiFi.h>


const char* ssid     = "Hamana";
const char* password = "buenasnoches123";

const char* host = "prometecserver.ddns.net";

void setup()
{
  Serial.begin(9600);
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{


 void loop()
   {
       int err;
       float temp, hum;
       if((err = dht11.read(hum, temp)) == 0)    // Si devuelve 0 es que ha leido bien
          {
             Serial.print("Temperatura: ");
             Serial.print(temp);
             Serial.print(" Humedad: ");
             Serial.print(hum);
             Serial.println();
          }
       else
          {
             Serial.println();
             Serial.print("Error Num :");
             Serial.print(err);
             Serial.println();
          }
       delay(1000);            //Recordad que solo lee una vez por segundo
   }

   Serial.print("connecting to ");
   Serial.println(host);

 // Use WiFiClient class to create TCP connections
   WiFiClient client;
   const int httpPort = 80;
   if (!client.connect(host, httpPort)) {
     Serial.println("connection failed");
     return;
   }
  
   // We now create a URL for the request
   String url = "/dht11.php";
   String key = "?pass=1234";
   String dato1 = "&Temperatura=";
   String dato2 = "&Humedad=";
  
   Serial.print("Requesting URL: ");
   Serial.println(url);
  
   // This will send the request to the server
   client.print(String("GET ") + url + key + dato1 + temp + dato2 + hum + " HTTP/1.1\r\n" +
   "Host: " + host + "\r\n" +
   "Connection: close\r\n\r\n");
   unsigned long timeout = millis();
   
   while (client.available() == 0) {
    if (millis() - timeout > 5000) {
     Serial.println(">>> Client Timeout !");
     client.stop();
     return;
    }
   } // Read all the lines of the reply from server and print them to Serial
   
   while (client.available()) {
     String line = client.readStringUntil('\r');
     Serial.print(line);
   }
  
   Serial.println();
   Serial.println("closing connection");
  
   delay(60000);
}
