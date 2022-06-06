int Current_Boutton() {
  int bouton_presse = NONE;
  int u_boutton;
  u_boutton = analogRead (0);
  if (u_boutton < 60) {
    bouton_presse = RIGHT;
  }
  else if (u_boutton < 200) {//analog voltage 145
    bouton_presse = UP;

  }
  else if (u_boutton < 400) {//analog voltage 329
    bouton_presse = DOWN;
  }
  else if (u_boutton < 600) { //analog voltage 585
    bouton_presse = LEFT;
  }
  else if (u_boutton < 800) {
    bouton_presse = SELECT;
  }
  
  return bouton_presse;
}
