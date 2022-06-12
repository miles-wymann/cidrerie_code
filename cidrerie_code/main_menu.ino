/*Affiche le menu et permet de choisir la cuve a reguler
   recoit la valeur du bouton press
   retourne une valeur non utilisee (sinon warnimg au return 0)

*/

int main_menu (int boutton) {
  lcd.setCursor(0, 0);
  lcd.print("Choix cuve");
  while (1)
  {
    delay(150);     //evite les rebonds
    boutton = NONE;
    lcd.setCursor(0, 1);
    lcd.print(cuve_no);   //affiche la cuve choisie
    lcd.setCursor(0, 1);
    boutton = Current_Boutton();
    if (cuve_no > 1 && boutton == DOWN) {
      cuve_no --;
    }
    if (cuve_no < 3 && boutton == UP) {
      cuve_no ++;
    }
    //permet de sortir de l'etat
    if (boutton == SELECT) {
      boutton = NONE;
      etat_general = TEMP_SETUP;
      return 0;
    }
  }
  boutton = NONE;
}

/**********************************
   permet de choisir la valeur de la temérature de consigne
   retourne la temperature de consigen choisie
*/
int set_temp ()
{
  lcd.setCursor(0, 0);
  lcd.print("Temp. Consigne");
  temperature = readTemp(); // lecture de temperature par NTC
  temp_consigne = temperature;  //permet davoir la temperature de consigne a la meme valeur de la temperature mesurée
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
    //permet de regler un probleme de decalcage
    if (temp_consigne < 10) {
      lcd.setCursor(13, 1);
    }
    else {
      lcd.setCursor(12, 1);
    }
    lcd.print(temp_consigne);
    boutton = Current_Boutton();
    if (temp_consigne > TEMP_MIN && boutton == DOWN) {
      temp_consigne --;
    }
    if (temp_consigne < TEMP_MAX && boutton == UP) {
      temp_consigne ++;
    }
    if (boutton == SELECT) {
      boutton = NONE;
      etat_general = REGUL;
      lcd.clear();
      return temp_consigne;//fait sortir de la boucle
    }
  }
}
