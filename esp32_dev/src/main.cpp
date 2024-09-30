#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Bourgogne28";
const char* password = "trentalaud";

WebServer server(80);  // Web server on port 80

const int ledPin = 2;   // GPIO where the LED is connected
bool ledState = false;  // LED state (true = ON, false = OFF)

void handleRoot() {
    String html = "<html><head>";
    html += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"; // Responsive design
    html += "<style>";
    html += "body { font-family: Arial, sans-serif; text-align: center; background-color: #f4f4f4; margin: 0; padding: 20px; }";
    html += "button { font-size: 20px; padding: 15px 30px; color: #fff; background-color: #007BFF; border: none; border-radius: 5px; cursor: pointer; transition: background-color 0.3s; }";
    html += "button:hover { background-color: #0056b3; }";
    html += "</style>";
    html += "<script>";
    html += "function toggleLED() {";
    html += "  var xhttp = new XMLHttpRequest();";
    html += "  xhttp.onreadystatechange = function() {";
    html += "    if (this.readyState == 4 && this.status == 200) {";
    html += "      document.getElementById('ledButton').innerHTML = this.responseText;";
    html += "    }";
    html += "  };";
    html += "  xhttp.open('GET', '/toggle', true);";
    html += "  xhttp.send();";
    html += "}";
    html += "function updateButton() {";
    html += "  var xhttp = new XMLHttpRequest();";
    html += "  xhttp.onreadystatechange = function() {";
    html += "    if (this.readyState == 4 && this.status == 200) {";
    html += "      document.getElementById('ledButton').innerHTML = this.responseText;";
    html += "    }";
    html += "  };";
    html += "  xhttp.open('GET', '/status', true);";
    html += "  xhttp.send();";
    html += "}";
    html += "setInterval(updateButton, 1000);";  // Check every second
    html += "</script></head><body>";
    html += "<h1>ESP32 LED Control</h1>";
    html += "<button id='ledButton' onclick='toggleLED()'>Loading...</button>";  // Button starts loading
    html += "</body></html>";
    server.send(200, "text/html", html);
}

void handleToggle() {
    ledState = !ledState;  // Toggle LED state
    digitalWrite(ledPin, ledState ? HIGH : LOW);
    server.send(200, "text/plain", ledState ? "Turn OFF" : "Turn ON");  // Send the updated button label
}

void handleStatus() {
    server.send(200, "text/plain", ledState ? "Turn OFF" : "Turn ON");  // Send the current button label based on LED state
}

void setup() {
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);  // Ensure the LED is off initially

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    // Define web routes
    server.on("/", handleRoot);
    server.on("/toggle", handleToggle);
    server.on("/status", handleStatus);

    server.begin();
    Serial.println("Web server started");
    Serial.println(WiFi.localIP());  // Print the IP address
}

void loop() {
    server.handleClient();
}
