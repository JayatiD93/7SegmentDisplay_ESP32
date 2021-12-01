#define CH2 14
#define CH4 15

void glow(int G, int H, int I, int J)
  {
    if(G==0 && H==0 && I==0 && J==0)
    {
      digitalWrite(21,0);
      Serial.println("Balanced");
    }
    else
{
      digitalWrite(21,1);
}
    digitalWrite(16,G);
    digitalWrite(17,H);
    digitalWrite(18,I);
    digitalWrite(19,J);
  }

int T=0,B=0,L=0,R=0;

int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, 1, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

void setup(){
  Serial.begin(115200);
  pinMode(CH2, INPUT);
  pinMode(CH4, INPUT);
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
  pinMode(21,OUTPUT);
}

int ch2Value,ch4Value;

void loop() {
  ch2Value = readChannel(CH2, -100, 100, 0);
  ch4Value = readChannel(CH4, -100, 100, 0);

//  Serial.print(" Top|Bottom: ");
//  Serial.print(ch2Value);
//  Serial.print("    Left|Right: ");
//  Serial.println(ch4Value);
  delay(500);
  if(ch2Value > 45)
  {
    T = 0;
    Serial.println("Top");
  }
  else
  {
   T = 1; 
  }
    if(ch2Value < -45)
  {
    B = 0;
    Serial.println("Bottom");
  }
  else
  {
   B = 1; 
  }
  if(ch4Value < -45)
  {
    L = 0;
    Serial.println("Left");
  }
  else
  {
   L = 1; 
  }
  if(ch4Value > 45)
  {
    R = 0;
    Serial.println("Right");
  }
  else
  {
   R = 1; 
  }
  glow(T,B,L,R);
}
