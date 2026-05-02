#ifndef __EMPLEADO_H
#define __EMPLEADO_H
typedef struct empleados {
 char apellidos[30];
 char nombre[15];
  int matricula;
  char bufferRelleno[5];
 } tipoEmpleado;
 
 
 tipoEmpleado *crearVectorRegistros(int numEmpleados, int *errNum){
   if(numEmpleados<=0){
      *errNum=-1;
      return NULL;
   } 
   int tamRegistro;
   
   tamRegistro= sizeof(tipoEmpleado)*numEmpleados;
   tipoEmpleado *tamRegistroTemp= malloc(tamRegistro);
   if(tamRegistroTemp==NULL){
   *errNum=-2;
   return NULL;
   }
   else *errNum=0;
   return tamRegistroTemp;
   }


 
 
int cargarRegistrosAleatorios(tipoEmpleado * empleados, int numEmpleados)
{
    if(empleados==NULL || numEmpleados<=0)
        return -1;
    int i;
    static char apellidos [][15] = {"ALONSO","ALVAREZ","ARBESU",
        "DOMINGUEZ","FERNANDEZ","FLORIANO",
        "GONZALEZ","GOMEZ","GUTIERREZ",
        "MARTIN", "MORO", "PEREZ","TURRION",
        "ZAMBRANO", "PALACIOS", "MONTERO"};
    static char nombres [][15] = {"ALVARO","ARSENIO","DOMINGO",
        "FELIPE","FATIMA","FABIAN",
        "GONZALO","PEDRO","PATRICIA",
        "TOMAS", "ZOILO", "LUCIA", "RODRIGO"};
    int numApellidos = sizeof(apellidos)/15;
    int numNombres = sizeof(nombres)/15;
    char buffer[5];
   
        srand(time(NULL));
        for (i = 0; i < numEmpleados; i++) {
        sprintf(empleados[i].apellidos,"%s %s",apellidos[rand() % numApellidos],
            apellidos[rand() % numApellidos]);
        sprintf(empleados[i].nombre,"%s",nombres[rand() % numNombres]);
        sprintf(buffer,"%c%c%c%c",(char)('0' + rand() % 10),
            (char)('0' + rand() % 10),
            (char)('0' + rand() % 10),
            (char)('0' + rand() % 10));
        empleados[i].matricula = atoi(buffer);
      }
    return 0;
}

 
 tipoEmpleado **crearRegistrosRef(int numEmpleados, int *errNum){

   if(numEmpleados<=0){
      *errNum=-1;
      return NULL;
   }

   tipoEmpleado **vectorRefEmpleados;
   vectorRefEmpleados=malloc(sizeof(tipoEmpleado *)*numEmpleados);
   if(vectorRefEmpleados==NULL){
      *errNum=-2;
      return NULL;
   }
   for(int i=0; i<numEmpleados;i++){
      vectorRefEmpleados[i]=malloc(sizeof(tipoEmpleado));
      if(vectorRefEmpleados[i]==NULL){
          for(int j=i-1; j>=0;j--){
            free(vectorRefEmpleados[j]);
         }
      free(vectorRefEmpleados);
         *errNum=-3;
         return NULL;
      }
   }
   
   *errNum=0;
   return vectorRefEmpleados;
 }
 
 
 int liberarMemRegistrosRef(tipoEmpleado **empleadosRef, size_t numEmpleados){
   if(empleadosRef==NULL) return -1;
   for(int i=0; i<numEmpleados; i++){
      free(empleadosRef[i]);
   }
   free(empleadosRef);
   return 0;
 }
 
 
 
 int cargarRegistrosAleatoriosRef(tipoEmpleado **empleados, int numEmpleados){

    if(empleados==NULL || numEmpleados<=0)
        return -1;
    int i;
    static char apellidos [][15] = {"ALONSO","ALVAREZ","ARBESU",
        "DOMINGUEZ","FERNANDEZ","FLORIANO",
        "GONZALEZ","GOMEZ","GUTIERREZ",
        "MARTIN", "MORO", "PEREZ","TURRION",
        "ZAMBRANO", "PALACIOS"};
    static char nombres [][15] = {"ALVARO","ARSENIO","DOMINGO",
        "FELIPE","FATIMA","FABIAN",
        "GONZALO","PEDRO","PATRICIA",
        "TOMAS", "ZOILO", "LUCIA"};
    int numApellidos = sizeof(apellidos)/15;
    int numNombres = sizeof(nombres)/15;
    char buffer[5];
   
        srand(time(NULL));
        for (i = 0; i < numEmpleados; i++) {
        sprintf(empleados[i]->apellidos,"%s %s",apellidos[rand() % numApellidos],
            apellidos[rand() % numApellidos]);
        sprintf(empleados[i]->nombre,"%s",nombres[rand() % numNombres]);
        sprintf(buffer,"%c%c%c%c",(char)('0' + rand() % 10),
            (char)('0' + rand() % 10),
            (char)('0' + rand() % 10),
            (char)('0' + rand() % 10));
        empleados[i]->matricula = atoi(buffer);


   }

return 0;
 }
 
 
 void cargarUnRegistro(tipoEmpleado * empleado){
   
    printf("\nIntroduce el apellido del empleado: ");
    scanf("%s", empleado->apellidos);
    printf("\nIntroduce el nombre del empleado: ");
    scanf("%s", empleado->nombre);
    printf("\nIntroduce la matrícula del empleado: "); 
    scanf("%d", &empleado->matricula);

 }
 
 
void mostrarRegistro(tipoEmpleado empleado){
   
    puts(empleado.apellidos);
    puts(empleado.nombre); 
    printf("%d\n", empleado.matricula);

}


void mostrarRegistrosRef(tipoEmpleado ** refsEmpleados, int numEmpleados){
    for (int i = 0; i < numEmpleados; i++) {
        printf("%s %s - Matricula: %d\n", refsEmpleados[i]->nombre, refsEmpleados[i]->apellidos, refsEmpleados[i]->matricula);
    }
}


void mostrarRegistros(tipoEmpleado * empleados, int numEmpleados){
     for (int i = 0; i < numEmpleados; i++) {
        printf("%s %s - Matricula: %d\n", empleados[i].nombre, empleados[i].apellidos, empleados[i].matricula);
    }
   
}


void ordenarRegistrosRefApellido(tipoEmpleado ** refsEmpleados, int numEmpleados){
int i, j;
    tipoEmpleado *temp; 
    
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados - 1; j > i; j--) {
            if ((strcmp(refsEmpleados[j]->apellidos, refsEmpleados[j - 1]->apellidos)) < 0) {

                temp = refsEmpleados[j];
                refsEmpleados[j] = refsEmpleados[j - 1];
                refsEmpleados[j - 1] = temp;
            }
        }
    }
}


void ordenarRegistrosApellido(tipoEmpleado * empleados, int numEmpleados){
    int i,j;
    tipoEmpleado temp;
   
    for (i = 0; i < numEmpleados - 1 ; i++) {
        for (j = numEmpleados-1; j > i; j--) {
            if ((strcmp(empleados[j].apellidos, empleados[j - 1].apellidos)) < 0) {
                temp = empleados[j];
                empleados[j] = empleados[j - 1];
                empleados[j - 1] = temp;
            }
        }
    }
}


#endif