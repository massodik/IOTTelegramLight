// Support kami dengan cara subscribe, comment, like, share dan jangan lupa klik juga tombol loncengnya agar selalu mendapatkan notifikasi dan update video terbaru dari channel WFH 2020

// Link Subscribe WFH 2020 : https://www.youtube.com/channel/UCk6P7JEtpBXxMzTr_HGFQhA?sub_confirmation=1

// Gunakanlah sketch kode ini dengan bijak. Semoga bermanfaat dan memberikan inspirasi kepada teman-teman semua. Wassalamualaikum WR. WB

// Made by : Gilang Lenardo

#include "CTBot.h"
CTBot myBot;
CTBotReplyKeyboard Tbl;
CTBotInlineKeyboard TbLp1on, TbLp2on, TbLp1off, TbLp2off, TbLpAllon, TbLpAlloff;

#define Lampu1 D1
#define Lampu2 D2


#define LAMPU_1_ON  "Lampu_1_ON"
#define LAMPU_1_OFF  "Lampu_1_OFF"
#define LAMPU_2_ON  "Lampu_2_ON"
#define LAMPU_2_OFF  "Lampu_2_OFF"

#define SEMUA_LAMPU_ON  "Semua_Lampu_ON"
#define SEMUA_LAMPU_OFF  "Semua_Lampu_OFF"
#define TIDAK  "Tidak"

 String Status_Lampu_1;
 String Status_Lampu_2;

  
 int Lampu_1 = HIGH;
 int Lampu_2 = HIGH;


 bool TampilkanTombol;
              
 String ssid = "qicol";
 String pass = "12345678";
 String token = "6109506075:AAFNmUK5-TgRSpUjItjxzNCtZnoDmPusUMc";

void setup() {
  
Serial.begin(115200);                           
	Serial.println("Memulai Koneksi...");

	 myBot.wifiConnect(ssid, pass);       
	  myBot.setTelegramToken(token);      

    if (myBot.testConnection())   
	      Serial.println("\nKoneksi Ke Telegram BOT Berhasil!"); 
	  else 
	      Serial.println("\nTidak Terkoneksi Ke Telegram BOT"); 
	
	      pinMode(Lampu1, OUTPUT);     
        pinMode(Lampu2, OUTPUT);      
           
	      digitalWrite(Lampu1, HIGH);  
        digitalWrite(Lampu2, HIGH);         

           Tbl.addButton("Lampu 1");
           Tbl.addButton("Lampu 2");
           Tbl.addRow();
           Tbl.addButton("Semua Lampu ON");
           Tbl.addButton("Semua Lampu OFF");
           Tbl.addRow();
           Tbl.addButton("Cek Status");
           Tbl.enableResize();
           TampilkanTombol = false;
           
           TbLp1on.addButton("✅ Ya", LAMPU_1_ON, CTBotKeyboardButtonQuery);
           TbLp1on.addButton("❌ Tidak", TIDAK, CTBotKeyboardButtonQuery);
           
           TbLp2on.addButton("✅ Ya", LAMPU_2_ON, CTBotKeyboardButtonQuery);
           TbLp2on.addButton("❌ Tidak", TIDAK, CTBotKeyboardButtonQuery);


           TbLp1off.addButton("✅ Ya", LAMPU_1_OFF, CTBotKeyboardButtonQuery);
           TbLp1off.addButton("❌ Tidak", TIDAK, CTBotKeyboardButtonQuery);
           
           TbLp2off.addButton("✅ Ya", LAMPU_2_OFF, CTBotKeyboardButtonQuery);
           TbLp2off.addButton("❌ Tidak", TIDAK, CTBotKeyboardButtonQuery);

           
           TbLpAllon.addButton("✅ Ya", SEMUA_LAMPU_ON, CTBotKeyboardButtonQuery);
           TbLpAllon.addButton("❌ Tidak", TIDAK, CTBotKeyboardButtonQuery);

           TbLpAlloff.addButton("✅ Ya", SEMUA_LAMPU_OFF, CTBotKeyboardButtonQuery);
           TbLpAlloff.addButton("❌ Tidak", TIDAK, CTBotKeyboardButtonQuery);
}

void loop() {
TBMessage msg;

	if (myBot.getNewMessage(msg)) {                                                           
    if (msg.text.equalsIgnoreCase("/start")) {                                         
          myBot.sendMessage(msg.sender.id, "Bismillah");
          myBot.sendMessage(msg.sender.id, "Halo...\nSelamat Datang Di IOT Kelompok 1.\n\nGunakan tombol dibawah untuk mengontrol lampu 👇", Tbl);
          Serial.println("\nUser memulai Bot \n");
          TampilkanTombol = true;
    } else if (msg.text.equalsIgnoreCase("Lampu 1")) {
        if (Lampu_1 == LOW) {
            myBot.sendMessage(msg.sender.id, "Saat ini Lampu 1 dalam keadaan ON\nApakah anda ingin mematikan Lampu 1?", TbLp1off);
            Serial.println("\nUser mengirim perintah 'Lampu 1' \nSaat ini Lampu 1 dalam keadaan ON \n");
        } else {
            myBot.sendMessage(msg.sender.id, "Saat ini Lampu 1 dalam keadaan OFF\nApakah anda ingin menyalakan Lampu 1?", TbLp1on);
            Serial.println("\nUser mengirim perintah 'Lampu 1' \nSaat ini Lampu 1 dalam keadaan OFF \n");            
        }
      } else if (msg.text.equalsIgnoreCase("Lampu 2")) {
        if (Lampu_2 == LOW) {
            myBot.sendMessage(msg.sender.id, "Saat ini Lampu 2 dalam keadaan ON\nApakah anda ingin mematikan Lampu 2?", TbLp2off);
            Serial.println("\nUser mengirim perintah 'Lampu 2' \nSaat ini Lampu 2 dalam keadaan ON \n");
        } else {
            myBot.sendMessage(msg.sender.id, "Saat ini Lampu 2 dalam keadaan OFF\nApakah anda ingin menyalakan Lampu 2?", TbLp2on);
            Serial.println("\nUser mengirim perintah 'Lampu 2' \nSaat ini Lampu 2 dalam keadaan OFF \n");            
        }
      } else if (msg.text.equalsIgnoreCase("Semua Lampu ON")) {
            myBot.sendMessage(msg.sender.id, "Apakah anda ingin menyalakan Semua Lampu?", TbLpAllon);
            Serial.println("\nUser ingin menyalakan semua lampu\n");
      } else if (msg.text.equalsIgnoreCase("Semua Lampu OFF")) {
            myBot.sendMessage(msg.sender.id, "Apakah anda ingin mematikan Semua Lampu?", TbLpAlloff);
            Serial.println("\nUser ingin mematikan semua lampu\n");
      } else if (msg.text.equalsIgnoreCase("Cek Status")) {
            if (Lampu_1 == LOW) {
              Status_Lampu_1 = "Lampu 1 ON";
            } else {
              Status_Lampu_1 = "Lampu 1 OFF";
            }
            if (Lampu_2 == LOW) {
              Status_Lampu_2 = "Lampu 2 ON";
            } else {
              Status_Lampu_2 = "Lampu 2 OFF";
            }
            
        Serial.println("\nUser mengirim perintah 'Cek Status'\n");
        myBot.sendMessage(msg.sender.id, "Status saat ini : \n\n👉 " + Status_Lampu_1 + "\n\n👉 " + Status_Lampu_2 + "\n\n👉 " + "\n\nGunakan tombol dibawah untuk mengontrol lampu 👇", Tbl);
        Serial.println("\nStatus saat ini : \n\n👉 " + Status_Lampu_1 + "\n👉 " + Status_Lampu_2 + "\n👉 " + "\n");
      } else if (msg.messageType == CTBotMessageQuery) {
          if (msg.callbackQueryData.equals(LAMPU_1_ON)) {
              digitalWrite(Lampu1, LOW);
              Lampu_1 = LOW;
              myBot.sendMessage(msg.sender.id, "💡 Lampu 1 Telah Dinyalakan");
              Serial.println("\nUser menyalakan Lampu 1\n");
          } else if (msg.callbackQueryData.equals(LAMPU_1_OFF)) {
              digitalWrite(Lampu1, HIGH);
              Lampu_1 = HIGH;
              myBot.sendMessage(msg.sender.id, "🚫 Lampu 1 Telah Dimatikan");
              Serial.println("\nUser mematikan Lampu 1\n");
          } else if (msg.callbackQueryData.equals(LAMPU_2_ON)) {
              digitalWrite(Lampu2, LOW);
              Lampu_2 = LOW;
              myBot.sendMessage(msg.sender.id, "💡 Lampu 2 Telah Dinyalakan");
              Serial.println("\nUser menyalakan Lampu 2\n");
          } else if (msg.callbackQueryData.equals(LAMPU_2_OFF)) {
              digitalWrite(Lampu2, HIGH);
              Lampu_2 = HIGH;
              myBot.sendMessage(msg.sender.id, "🚫 Lampu 2 Telah Dimatikan");
              Serial.println("\nUser mematikan Lampu 2\n");
          } else if (msg.callbackQueryData.equals(SEMUA_LAMPU_ON)) {
              digitalWrite(Lampu1, LOW);
              digitalWrite(Lampu2, LOW);

              Lampu_1 = LOW;
              Lampu_2 = LOW;

              myBot.sendMessage(msg.sender.id, "Semua 💡💡💡💡 Lampu Telah Dinyalakan");
              Serial.println("\nUser telah menyalakan Semua Lampu\n");
          } else if (msg.callbackQueryData.equals(SEMUA_LAMPU_OFF)) {
              digitalWrite(Lampu1, HIGH);
              digitalWrite(Lampu2, HIGH);

              Lampu_1 = HIGH;
              Lampu_2 = HIGH;

              myBot.sendMessage(msg.sender.id, "🚫 Semua Lampu Telah Dimatikan");
              Serial.println("\nUser telah mematikan Semua Lampu\n");
          } else if (msg.callbackQueryData.equals(TIDAK)) {
              myBot.sendMessage(msg.sender.id, "❌ Perintah Telah Dibatalkan!!!");
              Serial.println("\nUser telah membatalkan perintah\n");
          }
        } else {   
			        myBot.sendMessage(msg.sender.id, "⛔️ ERROR: Perintah tidak dikenal?!\n\nGunakan tombol dibawah untuk mengontrol lampu 👇", Tbl);
              Serial.println("\nUser mengirim perintah yang tidak dikenal\n");
		    }
	   }
	delay(500);
}
