<h1 align="center"> Smart Room Berbasis Arduino Uno </h1>

<p align="center">
Sistem ruangan pintar dengan fitur otomatis & manual berbasis mikrokontroler
</p>

<p align="center">
<img width="1536" height="1024" alt="banner" src="https://github.com/user-attachments/assets/5a3afa29-be77-4a7a-9358-78228a6674d7" />

</p>



## Anggota Kelompok 1
- Athaya Raihan Annafi — H1D023001  
- Ratu Naurah Calista — H1D023004  
- Ariza Nola Rufiana — H1D023005  
- Rafif Surya Murtadha — H1D023008  
- Revalina Fidiya Anugrah — H1D023011  



##  Deskripsi Project
Project ini merupakan sistem **Smart Room berbasis Arduino Uno** yang mampu mengontrol lampu, kipas, dan alarm secara otomatis maupun manual. Terdapat dua versi implementasi:

1. **Versi UTS (smart_home.ino)** - Menggunakan sensor suhu TMP36 untuk kontrol kipas motor DC
2. **Versi Implementasi Hardware (implementasi hardware-projectpst.ino)** - Menggunakan servo untuk kontrol kipas

Sistem bekerja dengan membaca data dari sensor, kemudian diproses oleh Arduino untuk menghasilkan aksi seperti menyalakan lampu, mengaktifkan kipas, serta memberikan peringatan jika terdeteksi gas berbahaya.



## Struktur Repository

```
smart-room-arduino/
│
├── README.md
│
├── /code
│   ├── smart_home.ino
│   └── implementasi hardware-projectpst.ino
│
├── /documentation
│   ├── /uts
│   │   ├── laporan.pdf
│   │   ├── Component List.csv
│   │   ├── Schematic View Kelompok 1_Smart Room.pdf
│   │   ├── banner.png
│   │   └── wiring_diagram.png
│   │
│   └── /implementasi hardware
│       └── banner implementasi hardware.png
│
├── /simulation
│   ├── link_tinkercad.txt
│   ├── link_youtube.txt
│   └── link_youtube implementasi hardware.txt
│
```



##  Fitur Sistem - Versi UTS (smart_home.ino)

| Fitur | Deskripsi | Sensor/Aktuator |
|------|----------|-----------------|
| 💡 Lampu Otomatis | Menyala saat gelap | LDR |
| 🌡️ Kipas Otomatis | Aktif saat suhu tinggi | TMP36 + Motor DC |
| 🚨 Alarm Gas | Buzzer aktif saat gas berbahaya | MQ-135 / Gas Sensor |
| 🔄 Mode Manual | Kontrol via push button | Push Button |
| 🖥️ LCD | Monitoring real-time | LCD I2C |
| ⚡ Interrupt | Pergantian mode cepat | Interrupt Pin |



##  Fitur Sistem - Versi Implementasi Hardware (implementasi hardware-projectpst.ino)

| Fitur | Deskripsi | Sensor/Aktuator |
|------|----------|-----------------|
| 💡 Lampu Otomatis | Menyala saat gelap | LDR |
| 🔄 Kipas Servo | Gerak otomatis servo | Servo Motor |
| 🚨 Alarm Gas | Buzzer aktif saat gas berbahaya | MQ-135 / Gas Sensor |
| 🔄 Mode Manual | Kontrol via push button | Push Button |
| 🖥️ LCD | Monitoring real-time | LCD I2C |
| ⚡ Interrupt | Pergantian mode cepat | Interrupt Pin |



## Konsep yang Digunakan

| Konsep | Implementasi |
|-------|-------------|
| Percabangan | if-else |
| Perulangan | loop() |
| GPIO | Input & Output |
| ADC | Sensor analog |
| PWM | Kontrol motor DC & Servo |
| I2C | LCD |
| Interrupt | Mode switch |


## Komponen

### Versi UTS (smart_home.ino)
- Arduino Uno
- LDR (Light Dependent Resistor)
- TMP36 (Temperature Sensor)
- Sensor Gas (MQ-135)
- LCD 16x2 I2C
- Motor DC
- Buzzer
- LED (Hijau, Biru, Merah)
- Push Button
- Transistor
- Resistor

### Versi Implementasi Hardware (implementasi hardware-projectpst.ino)
- Arduino Uno
- LDR (Light Dependent Resistor)
- Sensor Gas (MQ-135)
- LCD 16x2 I2C
- Servo Motor
- Buzzer
- LED (Hijau, Biru, Merah)
- Push Button
- Resistor


## Cara Kerja
Sensor → Arduino → Output aktif sesuai kondisi → ditampilkan di LCD.



## 🔗 Link Simulasi
🔗Link : https://www.tinkercad.com/things/27LdxauL5ch-smartroom?sharecode=J2Z_Fh3xIrIaM04F8W9tuFMAYUTp43Jx52KVDvwXjVw

## 🎥 Video Demo
🔗Link UTS: https://youtu.be/fzk8j-MujXI
🔗Link Implementasi Hardware: https://youtu.be/...



## Mata Kuliah
Pemrograman Sistem Tertanam - Kelas A
