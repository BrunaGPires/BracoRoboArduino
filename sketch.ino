#include <Servo.h>

#define angulo_inicial_motor 90

//mapeamento joystick 1
#define joystick1X A0
#define joystick1Y A1
//mapeamento joystick 2
#define joystick2X A2
#define joystick2Y A3

//mapeamento servos motores
Servo motorBase;
Servo motorBraco1;
Servo motorBraco2;
Servo motorGarra;

void setup() {
  mapearPinosMotores();
	inicializaAngulosMotores();
	mapearPinosJoystick();
}

void loop() {
  moverBase();
  moverBraco1();
  moverBraco2();
  moverGarra();
  delay(100);	
}

//funções
//mapeia pinos dos servos motores
void mapearPinosMotores(){
	motorBase.attach(5);
	motorBraco1.attach(6);
	motorBraco2.attach(9);
	motorGarra.attach(10);
}

//inicializa angulos dos servor motores
void inicializaAngulosMotores(){
	motorBase.write(angulo_inicial_motor);
	motorBraco1.write(angulo_inicial_motor);
	motorBraco2.write(angulo_inicial_motor);
	motorGarra.write(angulo_inicial_motor);
}

//mapeia pinos do joystick como input
void mapearPinosJoystick(){
	pinMode(joystick1X, INPUT);
	pinMode(joystick1Y, INPUT);
	
	pinMode(joystick2X, INPUT);
	pinMode(joystick2Y, INPUT);
}

//mapeia joystick motor
// move base
void moverBase(){
	int pos1X = analogRead(joystick1X);
	pos1X = map(pos1X, 0, 1023, 0, 180); //mapeamento da entrada analogica para o servo motor
	motorBase.write(pos1X);
	delay(100);
}


// move braço 1
void moverBraco1(){
	int pos1Y = analogRead(joystick1Y);
	pos1Y = map(pos1Y, 0, 1023, 45, 135);
	motorBraco1.write(pos1Y);
	delay(100);
}

// move braço 2
void moverBraco2(){
	int pos2X = analogRead(joystick2X);
	pos2X = map(pos2X, 0, 1023, 50, 90);
	motorBraco2.write(pos2X);
	delay(100);
}

// mover garra
void moverGarra(){
	int pos2Y = analogRead(joystick2Y);
	pos2Y = map(pos2Y, 0, 1023, 90, 130);
	motorGarra.write(pos2Y);
	delay(100);
}