# Motion Detector PRD Project

Repositori ini dibuat untuk dokumentasi Tugas Besar PRD bertemakan IoT oleh kelompok 5 PRD kelas 44 beranggotakan:
- Made Krisna Kusuma Wijaya	  18224091
- Jacko Luciano	              18224101
- Laurensius Dani Rendragaha  18224107
- Daniel Arrigo Manurung	    18224031
- Kenneth Moses Saragih	      18224093

## Deskripsi

Proyek ini bertujuan untuk mengimplementasikan sistem otomatisasi penyalaan lampu berbasis IoT yang menggunakan deteksi gerakan. Ketika sensor mendeteksi gerakan, sistem akan mengirimkan status ke Thingspeak untuk dipantau secara real-time melalui halaman web.

Sistem ini menggunakan **ESP32/ESP8266** sebagai mikrokontroler, dengan sensor PIR/sensor doppler untuk mendeteksi gerakan, dan **Thingspeak** untuk menyimpan dan memantau data status gerakan secara langsung.

## Fitur
- **Deteksi Gerakan Otomatis**: Sensor PIR yang terhubung ke mikrokontroler ESP32/ESP8266 mendeteksi gerakan dan mengirimkan status ke Thingspeak.
- **Monitoring Status Gerakan**: Data status gerakan (terdeteksi atau tidak) dipantau dan ditampilkan di halaman web.
- **Tampilan Web Interaktif**: Halaman web yang menyajikan tombol untuk memulai monitoring dan menampilkan status deteksi gerakan.
- **Penghematan Energi**: Otomatisasi lampu dengan IoT yang dapat menyalakan atau mematikan lampu berdasarkan deteksi gerakan.

## Struktur Proyek

### 1. **Frontend (HTML/CSS/JavaScript)**

- **index.html**: Halaman web yang digunakan untuk memonitor status deteksi gerakan dan menghubungkan ke Thingspeak melalui API.
  - Fitur interaktif dengan tombol untuk memulai monitoring dan menampilkan status gerakan terbaru.
  - Menampilkan tim pengembang di bagian "About Us".

### 2. **Backend (ESP32/ESP8266 - Arduino C++ Code)**

- **Firmware untuk ESP32/ESP8266**: Kode yang dijalankan pada perangkat mikrokontroler untuk menghubungkan ke Wi-Fi, membaca status sensor PIR, dan mengirimkan data ke Thingspeak.
  - Menggunakan library `WiFi.h` dan `HTTPClient.h` untuk menghubungkan ke Wi-Fi dan mengirim data ke Thingspeak.
  - LED onboard menyala jika gerakan terdeteksi dan mematikan jika tidak ada gerakan.

## Instalasi

### 1. **Frontend (Web)**
- Pastikan Anda sudah mengunduh atau meng-clone repositori ini.
- Buka file `index.html` di browser untuk melihat tampilan halaman web.

### 2. **Backend (Firmware ESP32/ESP8266)**

- **Persyaratan**:
  - Mikrokontroler **ESP32** atau **ESP8266**.
  - Sensor PIR (Passive Infrared Sensor)/Sensor Doppler.
  - Koneksi Wi-Fi yang stabil.
  - Akun **Thingspeak** untuk mendapatkan API Key.

- **Langkah-langkah**:
  1. **Unduh dan Instal Arduino IDE**: [Arduino IDE](https://www.arduino.cc/en/software).
  2. **Instal Library**:
     - `WiFi.h`
     - `HTTPClient.h`
  3. **Koneksi Wi-Fi**:
     - Gantilah `ssid` dan `password` pada kode dengan informasi Wi-Fi Anda.
  4. **API Key**:
     - Dapatkan **Write API Key** dari akun Thingspeak Anda dan masukkan ke dalam kode pada bagian `apiKey`.
  5. **Upload Firmware**:
     - Pilih **ESP32** atau **ESP8266** sesuai perangkat Anda, lalu upload kode ke perangkat menggunakan Arduino IDE.

### 3. **Menghubungkan Thingspeak**
- Buat saluran baru di Thingspeak dan perhatikan **Channel ID** dan **API Key**.
- Pastikan untuk menyambungkan perangkat ESP32/ESP8266 dengan Thingspeak untuk mengirim data ke **field2** (status gerakan).

## Penggunaan

1. **Menggunakan Web Interface**:
   - Buka halaman `index.html` di browser.
   - Masukkan **Channel ID** dan **API Key** dari Thingspeak.
   - Klik tombol "Mulai Monitoring" untuk memulai monitoring status deteksi gerakan.
   - Status deteksi gerakan akan diperbarui setiap 10 detik.

2. **Menjalankan Firmware di Mikrokontroler**:
   - Setelah meng-upload kode ke ESP32/ESP8266, pastikan perangkat terhubung ke Wi-Fi.
   - Sensor PIR akan mendeteksi gerakan dan mengirimkan status ke Thingspeak, yang bisa dipantau di web.

## Lisensi

Proyek ini dilisensikan di bawah **MIT License** - lihat file [LICENSE](LICENSE) untuk detail.
