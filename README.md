<h1 align="center"> Smart Home Berbasis Arduino Uno</h1>

<p align="center">
Sistem rumah pintar dengan fitur otomatis & manual berbasis mikrokontroler
</p>

<p align="center">
  <img width="1855" height="848" alt="banner" src="https://github.com/user-attachments/assets/6855e57a-1bf9-49e2-b522-e65283e1e226" />

</p>



## Anggota Kelompok 1
- Athaya Raihan Annafi — H1D023001  
- Ratu Naurah Calista — H1D023004  
- Ariza Nola Rufiana — H1D023005  
- Rafif Surya Murtadha — H1D023008  
- Revalina Fidiya Anugrah — H1D023011  



##  Deskripsi Project
Project ini merupakan sistem **Smart Home berbasis Arduino Uno** yang mampu mengontrol lampu, kipas, dan alarm secara otomatis maupun manual.

Sistem bekerja dengan membaca data dari sensor, kemudian diproses oleh Arduino untuk menghasilkan aksi seperti menyalakan lampu, mengaktifkan kipas, serta memberikan peringatan jika terdeteksi gas berbahaya.



## Struktur Repository

```
smart-home-arduino/
│
├── README.md
├── LICENSE (optional)
│
├── /code
│   └── smart_home.ino
│
├── /documentation
│   ├── laporan.pdf
│   ├── flowchart.png
│   ├── diagram_blok.png
│   ├── wiring_diagram.png
│
├── /simulation
│   └── link_tinkercad.txt
│
├── /media demonstrasi
│   ├── demo_video.mp4 
│   └── screenshot.png
```



##  Fitur Sistem

| Fitur | Deskripsi |
|------|----------|
| 💡 Lampu Otomatis | Menyala saat gelap (LDR) |
| 🌡️ Kipas Otomatis | Aktif saat suhu tinggi (TMP36) |
| 🚨 Alarm Gas | Buzzer aktif saat gas berbahaya |
| 🔄 Mode Manual | Kontrol via push button |
| 🖥️ LCD | Monitoring real-time |
| ⚡ Interrupt | Pergantian mode cepat |



## Konsep yang Digunakan

| Konsep | Implementasi |
|-------|-------------|
| Percabangan | if-else |
| Perulangan | loop() |
| GPIO | Input & Output |
| ADC | Sensor analog |
| PWM | Kontrol motor |
| I2C | LCD |
| Interrupt | Mode switch |


## Komponen
Arduino Uno, LDR, TMP36, Sensor Gas, LCD I2C, Motor DC, Buzzer, LED, Push Button, Transistor, Resistor.


## Cara Kerja
Sensor → Arduino → Output aktif sesuai kondisi → ditampilkan di LCD.



## 🔗 Link Simulasi
🔗Link : https://www.tinkercad.com/things/27LdxauL5ch-smartroom?sharecode=J2Z_Fh3xIrIaM04F8W9tuFMAYUTp43Jx52KVDvwXjVw

## 🎥 Video Demo
🔗Link : 



## Mata Kuliah
Pemrograman Sistem Tertanam - Kelas A
