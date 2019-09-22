//Переменные
  String buff; 
  String command;
  String ID = "777";
  char flag_begin; 
  int ID_count;
  int buff_length;
  int buff_count;
  bool end_packet_enter;
  bool point; 
//  int timing = millis();
//  char flag_end;
//  int ID_status;
//  int buff_status;
//  int flag_begin_status;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
}

//Стартовое положение=================
void Setup(){
 
  command.reserve(1);
  buff.reserve(128);
  flag_begin = ':';
  Reset();
}

//Сброс string переменной buff
void Reset(){
 
  buff = "";
  Null_reset();
}

//Перезагрузка переменных, участвующих в функции Read()
void Null_reset(){
  
  command ="`";
  buff_length = 0;
  ID_count = -1;
  end_packet_enter = false;
  point = false;
  buff_count = 0;
//  flag_begin_status = 0;
//  flag_end = 'e'; 
//  buff_status = 0;
//  ID_status = 0;
}
//==================================

//Информация чтобы печатать и отправлять
void Send(String buff){

  Serial.print(flag_begin);
  Serial.write(buff.length());
  Serial.print(buff);
}

//Вызывается если что-то попадает в порт
void serialEvent(){
  Read();

  if(command != NULL){
    Command_start();
  } 
  
  Reset();
 
}

//Чтение пакета
void Read(){
while(Serial.available() && !end_packet_enter) //Пока не конец пакета
  {  
    char cbuff = Serial.read();//Читаем
    buff +=(char)cbuff; //Начинаем читать все после ":" 
    if(flag_begin != cbuff && point == false){ //Если нет ":" то частичная перезагрузка
       Null_reset();
     }else if(flag_begin == cbuff && point != true){ //Если точка не включена и встретилось двоеточие, переключаем точку 
     point = true;
     }else{            
      if(buff_length <= 0){ //Если длина пакета не установлена, то байт - начало длины пакета
        buff_length = cbuff;
       //===================================================================== 
      // Serial.println("b");
     //  if (buff_length < buff.length()){ 
    //    buff_length += char(cbuff);   
   //    }
  //========================================================================== 
         }else{ //Если длина установлена  
          ID_count++;   //Прибавляем количество байт        
          if(ID_count > String(ID).length()-1){ //Если равно количеству байт в ID    
            if(buff_count < command.length()){  
              command =(char)cbuff;    
              buff_count++;                                    
            }
  //=========================================================================   
              }else{ //Иначе        
                if (ID[ID_count] != cbuff){ //Проверяем символ ID     
                  Serial.println("Неправильный идентификатор(ID)"); //Если не тот - печатаем              
                  point = false; //Закрываем точку    
                  Null_reset();                         
               }
             }
           }
         }
       }
     }
            
//Выполнение команд 
void Command_start(){
  if(command == "4"){
    Serial.println(buff);
  }
}
