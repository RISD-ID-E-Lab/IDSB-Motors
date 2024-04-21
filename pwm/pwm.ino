int speed = 255;
String inputStr = "";
bool clean = false;

void setup() {
  inputStr.reserve(200);
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);

  digitalWrite(5, 1);
  digitalWrite(6, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (clean) {
    analogWrite(9, inputStr.toInt());
    Serial.println(inputStr.toInt());
    // clear the string:
    inputStr = "";
    clean = false;
  }
  
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      clean = true;
    }
    else {
      // add it to the inputString:
      inputStr += inChar;
    }
  }
}