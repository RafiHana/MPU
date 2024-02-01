String dataIn;
String dt[10];
int i;
boolean parsing=false;

void setup() 
{
   Serial.begin(9600);
   dataIn="";
}

void loop() 
{
    if(Serial.available()>0)
    {
          char inChar = (char)Serial.read();
          dataIn += inChar;
          if (inChar == '\n') {parsing = true;}
    }
    if(parsing)
    {
          parsingData();
          parsing=false;
          dataIn="";
    }
}

void parsingData()
{
     int j=0;

     Serial.print("data masuk : ");
     Serial.print(dataIn);
     Serial.print("\n");
     
     dt[j]="";
     for(i=1;i<dataIn.length();i++)
     {
            if ((dataIn[i] == '#') || (dataIn[i] == ','))
            {
                  j++;
                 dt[j]=""; 
            }
            else
            {
                 dt[j] = dt[j] + dataIn[i];
            }
     }
         int yaw = data[0].toInt();
         int pitch = data[1].toInt();
         int roll = data[2].toInt();
         
         Serial.print(yaw);
         Serial.print(" ");
         Serial.print(pitch);
         Serial.print(" ");
         Serial.println(roll);

}


     
