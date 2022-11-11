#include<iostream>
using namespace std;
 
char gato[3][3];
bool bandera=true;
//===PROTOTIPOS===
void imprimegato();
void cambiaturno(char &t);
void introduce(char t, char corden);
short evalua(char t);
int main()
{
imprimegato();
char t='X';
char posicion;
 
 while(bandera==true)
 {
   cout << "Es el turno de "<<t<<" introduzca posicion: ";
   cin >> posicion;
   posicion=toupper(posicion);
   introduce(t,posicion);
 
  // comprueba(turno);
evalua(t);
cambiaturno(t);
   imprimegato();
  }
 
system("pause");
}//fin main
//====INTRODUCE=====
void introduce(char t, char corden)
{
 switch(corden)
 {
   case 'A':
     if(gato[0][0]!='X' && gato[0][0]!='O')
     {
       gato[0][0]=t;
//       cambiaturno(t);
     }
     else{cout<<"\n=Posicion ocupada=\n";}
     break;
   case 'B':
     if(gato[0][1]!='X' && gato[0][1]!='O')
     {
       gato[0][1]=t;
//       cambiaturno(t);
     }
     else{cout<<"\n=Posicion ocupada=\n";}
     break;
 case 'C':
     if(gato[0][2]!='X' && gato[0][2]!='O')
     {
       gato[0][2]=t;
//       cambiaturno(t);
     }
     else{cout<<"\n=Posicion ocupada=\n";}
     break;
   case 'D':
     if(gato[1][0]!='X' && gato[1][0]!='O')
     {
       gato[1][0]=t;
//       cambiaturno(t);
     }
     else{cout<<"\n=Posicion ocupada=\n";}
     break;
   case 'E':
     if(gato[1][1]!='X' && gato[1][1]!='O')
     {
       gato[1][1]=t;
 //      cambiaturno(t);
     }
     else{cout<<"\n=Posicion ocupada=\n";}
     break;
   case 'F':
     if(gato[1][2]!='X' && gato[1][2]!='O')
     {
       gato[1][2]=t;
//       cambiaturno(t);
     }
     else{cout<<"\n=Posicion ocupada=\n";}
     break;
 case 'G':
     if(gato[2][0]!='X' && gato[2][0]!='O')
     {
       gato[2][0]=t;
//       cambiaturno(t);
     }
     else{cout<<"\n=Posicion ocupada=\n";}
     break;
   case 'H':
     if(gato[2][1]!='X' && gato[2][1]!='O')
     {
       gato[2][1]=t;
//       cambiaturno(t);
     }
     else{cout<<"\n=Posicion ocupada=\n";}
     break;
   case 'I':
     if(gato[2][2]!='X' && gato[2][2]!='O')
     {
       gato[2][2]=t;
//       cambiaturno(t);
     }
     else{cout<<"\n=Posicion ocupada=\n";}
     break;
   default:
      cout<<"\nIntroduzca una posicion valida.\n";
 }//fin switch
}//fin introduce
//====CAMBIATURNO===
void cambiaturno(char &t)
{
if (t=='X'){t='O';}
else{t='X';}
//cout<<t
//return t;
}//fin cambiaturno
 
//=======IMPRIMEGATO=====
void imprimegato()
{
cout<<"\n     ######GATO#######\n\n";
 
cout<<"\t  "<<gato[0][0]<<" | "<<gato[0][1]<<" | "<<gato[0][2]<<"         a | b | c"<<endl;
cout<<"\t----------"<<"      -----------\n";
cout<<"\t  "<<gato[1][0]<<" | "<<gato[1][1]<<" | "<<gato[1][2]<<"         d | e | f"<<endl;
cout<<"\t----------"<<"      -----------\n";
cout<<"\t  "<<gato[2][0]<<" | "<<gato[2][1]<<" | "<<gato[2][2]<<"         g | h | i"<<endl;
 
cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 
}//fin imrpimegato
short evalua(char t)
{
cout<<t;
short px=0;
short po=0;
short evaluacion=0;
 
cout<<"\n[0][i]\n";
for(short i=0;i<3;i++)
   {
   if(((gato[0][i]=='X')||gato[0][i]=='\0')&&((gato[1][i]=='X')||gato[1][i]=='\0')&&((gato[2][i]=='X')||gato[2][i]=='\0'))
      {px++;}
if(gato[0][0]=='O'||gato[0][1]=='O'||gato[0][2]=='O'||gato[1][0]=='O'||gato[1][1]=='O'||gato[1][2]=='O'||gato[2][0]=='O'||gato[2][1]=='O'||gato[2][2]=='O')
 {
   if(((gato[0][i]=='O')||gato[0][i]=='\0')&&((gato[1][i]=='O')||gato[1][i]=='\0')&&((gato[2][i]=='O')||gato[2][i]=='\0'))
      {po++;}
  }
      //else {po++;}
cout<<"\npo="<<po;
cout<<"\npx="<<px;
 
   }
 
for(short i=0;i<3;i++)
   {
 if(((gato[i][0]=='X')||gato[i][0]=='\0')&&((gato[i][1]=='X')||gato[i][1]=='\0')&&((gato[i][2]=='X')||gato[i][2]=='\0'))
      {px++;}
if(gato[0][0]=='O'||gato[0][1]=='O'||gato[0][2]=='O'||gato[1][0]=='O'||gato[1][1]=='O'||gato[1][2]=='O'||gato[2][0]=='O'||gato[2][1]=='O'||gato[2][2]=='O')
 {
 if(((gato[i][0]=='O')||gato[i][0]=='\0')&&((gato[i][1]=='O')||gato[i][1]=='\0')&&((gato[i][2]=='O')||gato[i][2]=='\0'))
      {po++;}
  }
 
//else{po++;}
 
cout<<"\npo="<<po;
cout<<"\npx="<<px;
    }//fin for      
 
//Diagonales
cout<<"\ndiagonales\n";
 if(((gato[0][0]=='X')||gato[0][0]=='\0')&&((gato[1][1]=='X')||gato[1][1]=='\0')&&((gato[2][2]=='X')||gato[2][2]=='\0'))
     {px++;}
if(gato[0][0]=='O'||gato[0][1]=='O'||gato[0][2]=='O'||gato[1][0]=='O'||gato[1][1]=='O'||gato[1][2]=='O'||gato[2][0]=='O'||gato[2][1]=='O'||gato[2][2]=='O')
{
 if(((gato[0][0]=='O')||gato[0][0]=='\0')&&((gato[1][1]=='O')||gato[1][1]=='\0')&&((gato[2][2]=='O')||gato[2][2]=='\0'))
     {po++;}
 }
 
      //else{po++;}cout<<"\n1.diagonal\n";
cout<<"\npo="<<po;
cout<<"\npx="<<px;
 
 
  if(((gato[2][0]=='X')||gato[2][0]=='\0')&&((gato[1][1]=='X')||gato[1][1]=='\0')&&((gato[0][2]=='X')||gato[0][2]=='\0'))
     {px++;}
 
if(gato[0][0]=='O'||gato[0][1]=='O'||gato[0][2]=='O'||gato[1][0]=='O'||gato[1][1]=='O'||gato[1][2]=='O'||gato[2][0]=='O'||gato[2][1]=='O'||gato[2][2]=='O')
 {
  if(((gato[2][0]=='O')||gato[2][0]=='\0')&&((gato[1][1]=='O')||gato[1][1]=='\0')&&((gato[0][2]=='O')||gato[0][2]=='\0'))
     {po++;}
  }
    //else{po++;}cout<<"\n2.diagonal\n";
cout<<"\npo="<<po;
cout<<"\npx="<<px;
 
 
if (t=='X'){evaluacion=px-po;}
else{evaluacion=po-px;}
cout<<"\n\nfinales";
cout<<"\npo="<<po;
cout<<"\npx="<<px;
//return evaluacion;
cout<<"\n\nEvaluacion es: "<<evaluacion<<endl;
}//fin evalua