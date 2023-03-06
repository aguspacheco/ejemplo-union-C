#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
typedef enum {ALUM =0 ,PROFE=1}TParticipante;
typedef struct profesor{
	short legajo; long sueldo; char nomap[MAX];
}t_profesor;
typedef struct alumno{
	int matricula;	char nomap[MAX];
}t_alumno;
typedef struct participantes{
  	TParticipante tipo;// discriminador de tipo de contenido
  	union t_uparticipante{
  		t_alumno a;
  		t_profesor p;
	  } u;
}t_participante;
int main(int argc, char *argv[]) {
	t_participante p1;// cargamos datos de un alumno
	p1.tipo = ALUM;
	p1.u.a.matricula = 1000;
	strcpy(p1.u.a.nomap ,"Jose");
	
	//....
	
	if(p1.tipo==ALUM)
	{
	   printf("Alumno: %d, %s\n",p1.u.a.matricula,p1.u.a.nomap);	
	}
	else
	   printf("Profesor: %d, %s\n", p1.u.p.legajo,p1.u.p.nomap);
	
	printf("leg.Prof.%d: sueldo:%d \n", p1.u.p.legajo,p1.u.p.sueldo);
	
	return 0;
}
