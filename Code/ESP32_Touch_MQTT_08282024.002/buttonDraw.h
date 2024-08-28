
void drawInfo() {
    //Information
  tft.fillRect(BUTTON_6_X, BUTTON_6_Y + 70, 320, 30, TFT_WHITE);
  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(FONT_SIZE);
  tft.setTextDatum(MC_DATUM);
  
  String temp0(timeWeekDay);
  String temp1(timeMonth); 
  String temp2(timedate); 
  String temp3(timeHour); 
  String temp4(timeMin);  
  String timeTemp =  temp0 + "   " + temp1 + "-" + temp2 + "  " + temp3 + ":" + temp4;
  Serial.print("Time Fornmatted: ");
  Serial.println(timeTemp);
  tft.drawString(timeTemp, BUTTON_6_X + (320 / 2), BUTTON_6_Y + 70 + (30 / 2));
}


void drawButtonsScreenOne() {
  Serial.println("Screen 1");
  tft.fillScreen(TFT_BLACK);  //wypes screen black
  //Line 0
  tft.fillRect(LABEL_1_X, LABEL_1_Y, LABEL_1_W, LBL_FRAME_H, TFT_WHITE);
  tft.fillRect(LABEL_2_X, LABEL_2_Y, LABEL_2_W, LBL_FRAME_H, TFT_WHITE);
  tft.fillRect(LABEL_3_X, LABEL_3_Y, LABEL_3_W, LBL_FRAME_H, TFT_WHITE);
  tft.fillRect(LABEL_4_X, LABEL_4_Y, LABEL_4_W, LBL_FRAME_H, TFT_WHITE);
  tft.fillRect(LABEL_5_X, LABEL_5_Y, LABEL_5_W, LBL_FRAME_H, TFT_WHITE);

  //Line 1
  tft.fillRect(BUTTON_1_X, BUTTON_1_Y, BUTTON_1_W, 60, TFT_GREEN);
  tft.fillRect(BUTTON_2_X, BUTTON_2_Y, BUTTON_2_W, 60, TFT_GREEN);
  tft.fillRect(BUTTON_3_X, BUTTON_3_Y, BUTTON_3_W, 60, TFT_GREEN);
  tft.fillRect(BUTTON_4_X, BUTTON_4_Y, BUTTON_4_W, 60, TFT_GREEN);
  tft.fillRect(BUTTON_5_X, BUTTON_5_Y, BUTTON_5_W, 60, TFT_GREEN);

  //Line 2
  tft.fillRect(BUTTON_6_X, BUTTON_6_Y, BUTTON_6_W, 60, TFT_RED);
  tft.fillRect(BUTTON_7_X, BUTTON_7_Y, BUTTON_7_W, 60, TFT_RED);
  tft.fillRect(BUTTON_8_X, BUTTON_8_Y, BUTTON_8_W, 60, TFT_RED);
  tft.fillRect(BUTTON_9_X, BUTTON_9_Y, BUTTON_9_W, 60, TFT_RED);
  tft.fillRect(BUTTON_10_X, BUTTON_10_Y, BUTTON_10_W, 60, TFT_RED);

  //Information
 // tft.fillRect(BUTTON_6_X, BUTTON_6_Y + 70, 320, 30, TFT_WHITE);

  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(FONT_SIZE);
  tft.setTextDatum(MC_DATUM);


  //Line 0  Labels
  tft.drawString("1", LABEL_1_X + (LABEL_1_W / 2), LINE0_Y + (50 / 2));
  tft.drawString("2", LABEL_2_X + (LABEL_2_W / 2), LINE0_Y + (50 / 2));
  tft.drawString("3", LABEL_3_X + (LABEL_3_W / 2), LINE0_Y + (50 / 2));
  tft.drawString("4", LABEL_4_X + (LABEL_4_W / 2), LINE0_Y + (50 / 2));
  tft.drawString("5", LABEL_5_X + (LABEL_5_W / 2), LINE0_Y + (50 / 2));

  //Line 1
  tft.drawString("ON", BUTTON_1_X + (BUTTON_1_W / 2), BUTTON_1_Y + (60 / 2));
  tft.drawString("ON", BUTTON_2_X + (BUTTON_2_W / 2), BUTTON_2_Y + (60 / 2));
  tft.drawString("ON", BUTTON_3_X + (BUTTON_3_W / 2), BUTTON_3_Y + (60 / 2));
  tft.drawString("ON", BUTTON_4_X + (BUTTON_4_W / 2), BUTTON_4_Y + (60 / 2));
  tft.drawString("ON", BUTTON_5_X + (BUTTON_5_W / 2), BUTTON_5_Y + (60 / 2));

  //Line 2
  tft.drawString("OFF", BUTTON_6_X + (BUTTON_6_W / 2), BUTTON_6_Y + (60 / 2));
  tft.drawString("OFF", BUTTON_7_X + (BUTTON_7_W / 2), BUTTON_7_Y + (60 / 2));
  tft.drawString("OFF", BUTTON_8_X + (BUTTON_8_W / 2), BUTTON_8_Y + (60 / 2));
  tft.drawString("OFF", BUTTON_9_X + (BUTTON_9_W / 2), BUTTON_9_Y + (60 / 2));
  tft.drawString("OFF", BUTTON_10_X + (BUTTON_10_W / 2), BUTTON_10_Y + (60 / 2));

drawInfo();
}
