int main_menu (int boutton) {
  lcd.setCursor(0, 0);
  lcd.print("Choix cuve");
  while (1)
  {
    delay(150);
    boutton = NONE;
    lcd.setCursor(0, 1);
    lcd.print(cuve_no);
    lcd.setCursor(0, 1);
    boutton = Current_Boutton();
    if (cuve_no > 1 && boutton == DOWN) {
      cuve_no --;
    }
    if (cuve_no < 3 && boutton == UP) {
      cuve_no ++;
    }
    if (boutton == SELECT) {
      boutton = NONE;
      etat_general = TEMP_SETUP;
      return 0;
    }
  }
  boutton = NONE;
}

void set_temp ()
{
  lcd.setCursor(0, 0);
  lcd.print("Temp. Consigne");
  temp_consigne = temperature;
  while (1) {
    if (temp_consigne == 9) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temp. Consigne");
      lcd.setCursor(13, 1);
      lcd.print(temp_consigne);
    }
    delay(150);
    int boutton;
    lcd.setCursor(0, 0);
    boutton = NONE;

    if (temp_consigne < 10) {
      lcd.setCursor(13, 1);
    }
    else {
      lcd.setCursor(12, 1);
    }
    lcd.print(temp_consigne);
    boutton = Current_Boutton();
    if (temp_consigne > 0 && boutton == DOWN) {
      temp_consigne --;
    }
    if (temp_consigne < 30 && boutton == UP) {
      temp_consigne ++;
    }
    if (boutton == SELECT) {
      boutton = NONE;
      etat_general = REGUL;
      lcd.clear();
      return 0;
    }
  }
}
