#include <WiFi.h>
#include <HTTPClient.h>

#define SENSOR_PIN 13
#define ONBOARD_LED 26

const char* ssid = "SSID";         // Ganti dengan SSID Wi-Fi kamu
const char* password = "PASSWORD"; // Ganti dengan password Wi-Fi kamu
const char* server = "http://api.thingspeak.com/update"; // URL API Thingspeak

String apiKey = "WRITE_APIKEY";  // Ganti dengan Write API Key Thingspeak kamu

WiFiClient client;

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(ONBOARD_LED, OUTPUT);

  // Koneksi ke Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(10);
    Serial.println("Menghubungkan ke WiFi...");
  }
  Serial.println("Terhubung ke WiFi!");
}

void loop() {
  if (digitalRead(SENSOR_PIN)) {
    // Jika ada gerakan (sensor mendeteksi)
    digitalWrite(ONBOARD_LED, HIGH);

    // Kirim data ke Thingspeak
    sendToThingspeak(1);  // 1 untuk gerakan terdeteksi
    delay(10); // Tunggu sebentar sebelum mengirim data lagi
    loop();
  } else {
    // Jika tidak ada gerakan
    digitalWrite(ONBOARD_LED, LOW);

    // Kirim data ke Thingspeak
    sendToThingspeak(0);  // 0 untuk tidak ada gerakan
    loop();
  }
}

void sendToThingspeak(int motionDetected) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Membuat URL untuk mengirim data
    String url = String(server) + "?api_key=" + apiKey + "&field2=" + String(motionDetected); // listening di field 2, tergantung menggunakan field berapa

    http.begin(url);  // Inisialisasi HTTP request
    int httpResponseCode = http.GET();  // Kirim GET request

    if (httpResponseCode > 0) {
      Serial.print("Data terkirim, kode respons: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Gagal mengirim data, kode error: ");
      Serial.println(httpResponseCode);
    }

    http.end();  // Menutup koneksi HTTP
  } else {
    Serial.println("Tidak ada koneksi Wi-Fi");
  }
}