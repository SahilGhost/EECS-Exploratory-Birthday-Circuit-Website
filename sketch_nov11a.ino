void setup() {
  Serial.begin(9600);
  // Set the pins for the switches as inputs
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);

  // Set the pins for the 7-segment display as outputs
  pinMode(2, OUTPUT); // Segment a
  pinMode(3, OUTPUT); // Segment b
  pinMode(4, OUTPUT); // Segment c
  pinMode(5, OUTPUT); // Segment d
  pinMode(6, OUTPUT); // Segment e
  pinMode(7, OUTPUT); // Segment f
  pinMode(8, OUTPUT); // Segment g
}

void loop() {
  // Reading inputs from switches
  int X = digitalRead(12);
  int Y = digitalRead(11);
  int Z = digitalRead(10);

  // Boolean expressions for each segment
  int a = (!X && !Y && !Z) || (X && Y && Z); // a = X'Y'Z' + XYZ
  int b = (!X && !Y) || (!Y && Z) || (X && Y) || (Y && Z); // b = X'Y' + Y'Z + XY + YZ
  int c = b; // c has the same expression as b
  int d = a; // d has the same expression as a
  int e = a; // e has the same expression as a
  int f = a; // f has the same expression as a
  int g = (!X && Z) || (X && !Y && Z); // g = X'Z + XY'Z

  // Setting the display based on the calculated expressions
  digitalWrite(2, a); // Segment a
  digitalWrite(3, b); // Segment b
  digitalWrite(4, c); // Segment c
  digitalWrite(5, d); // Segment d
  digitalWrite(6, e); // Segment e
  digitalWrite(7, f); // Segment f
  digitalWrite(8, g); // Segment g
}
