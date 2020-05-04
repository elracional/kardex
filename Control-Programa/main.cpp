#include <iostream>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>
#include <math.h>
#include<stdio.h>  
#include<conio.h>
#include <windows.h>

using namespace std;

void box(int x1,int y1,int x2,int y2, int relleno,int color);
void indicacion();
void indicacion1();
void menu();
void menu2();
void mueve2(int matri);
void general();
int automata (int cal);
void ini();
void q0();
void q1();
void q2();
void qError();

struct alumnos  
{
				char nombre[30];
                char cal1[50];
                char cal2[50];
                char cal3[50];
                int matricula;
                struct alumnos *sig;  
}; 
               
struct alumnos *inicio=NULL, *final=NULL, *temp=NULL, *temp2; 
int cont,t,win1,win2;
char cadena[50];
bool aceptado;

void agregar ()
{
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     indicacion();
     menu();
     box(10,130,125,180,1,BLACK);
     outtextxy(22,145,"AGREGAR");
     char num[5];
     int i=0;
     bool err=false;
     int n,k=0, a=0; //variables para los ciclos do, k para cuando se borra, a para el automara
     do 
     {
         i=0;
         outtextxy(150,100, "Alumnos a ingresar: ");
         box(350,100,450,130,1,BLACK);
         while (i<5)
         {
               num[i] = getch(); 
               if (num[i]=='\r') 
               {
                    i=5;
                    k=1;
               }
               else if (num[i]==8)
               {
                    k=0;
                    i=5;
               }
               else if (num[i]!='0' && num[i]!='1' && num[i]!='2' && num[i]!='3' && num[i]!='4' && num[i]!='5' && num[i]!='6' && num[i]!='7' && num[i]!='8' && num[i]!='9' )
               {
                    num[i+1] = '\0';
                    outtextxy(355,105,num);
                    i++;
                    win2 = initwindow(270,100,"Error",100,100);
                    setcurrentwindow(win2);
                    while(!kbhit())
                    {
                         outtextxy(50,20,"Numero invalido"); 
                         outtextxy(20,40,"Presione una tecla para continuar...");
                    }
                    closegraph(CURRENT_WINDOW);
                    setcurrentwindow(win1); 
                    i=5;
                    k=0;
               }
               else 
               {
                    num[i+1] = '\0';
                    outtextxy(355,105,num);
                    i++;
                    k=1;
               }
         }
     }while (k==0);
     n = atoi(num);
     for (int j=0;j<n;j++)
     {
         clearviewport();
         line(1,80,getmaxx(),80);
         line(135,1,135,getmaxy());
         indicacion();
         menu();
         box(10,130,125,180,1,BLACK);
         outtextxy(22,145,"AGREGAR");
         temp=(struct alumnos *) malloc(sizeof(struct alumnos)); 
         if (temp==NULL)
         {
              outtext("NO HAY MEMORIA DISPONIBLE");         
              exit(1);
         }
         char mat[10];
         k=0;
         do
         {
             i=0;
             outtextxy(170,150,"Matricula: ");
             box(300,150,400,180,1,BLACK);
             while (i<10)
             {
                   mat[i] = getch(); 
                   if (mat[0]=='\r')
                   {
                        win2 = initwindow(270,100,"Error",100,100);
                        setcurrentwindow(win2);
                        while(!kbhit())
                        {
                             outtextxy(20,20,"Favor de introducir una matricula"); 
                             outtextxy(20,40,"Presione una tecla para continuar...");
                        }
                        closegraph(CURRENT_WINDOW);
                        setcurrentwindow(win1); 
                        i=10;
                        k=0;
                   }
                   else if (mat[i]=='\r')
                   {
                        i=10;
                        k=1;
                   }
                   else if (mat[i]==8)
                   {
                        k=0;
                        i=10;
                   }
                   else if (mat[i]!='0' && mat[i]!='1' && mat[i]!='2' && mat[i]!='3' && mat[i]!='4' && mat[i]!='5' && mat[i]!='6' && mat[i]!='7' && mat[i]!='8' && mat[i]!='9' )
                   {
                        mat[i+1] = '\0';
                        outtextxy(305,155,mat);
                        i++;
                        win2 = initwindow(270,100,"Error",100,100);
                        setcurrentwindow(win2);
                        while(!kbhit())
                        {
                             outtextxy(50,20,"Numero invalido"); 
                             outtextxy(20,40,"Presione una tecla para continuar...");
                        }
                        closegraph(CURRENT_WINDOW);
                        setcurrentwindow(win1); 
                        i=10;
                        k=0;
                   } 
                   else
                   {
                       mat[i+1] = '\0';
                       outtextxy(305,155,mat);
                       i++;
                       k=1;
                   } 
             }
         }while (k==0);
         int ma = atoi(mat);
         temp2=inicio;   
         while((temp2!=NULL)&&(a==0))   
         {
              if(ma==temp2->matricula)  
              {
                   a=1; 
                   win2 = initwindow(270,100,"Error",100,100);
                   setcurrentwindow(win2);
                   while(!kbhit())
                   {
                        outtextxy(50,20,"MATRICULA YA REGISTRADA");
                        outtextxy(15,40,"Sera redireccionado al menu anterior"); 
                        outtextxy(20,60,"Presione una tecla para continuar..."); 
                   }
                   closegraph(CURRENT_WINDOW);
                   setcurrentwindow(win1);
              }
              temp2=temp2->sig;
              
              
         }
         if(a==0 && temp!=NULL)
         {
              temp->matricula=ma; 
              k=0;
              do
              {
                   i=0;
                   char nom[30];
                   outtextxy(170,185,"Nombre: "); 
                   box(300,185,500,215,1,BLACK);
                   while (i<30)
                   {
                         nom[i] = getch();
                         if (nom[0]=='\r')
                         {
                              win2 = initwindow(270,100,"Error",100,100);
                              setcurrentwindow(win2);
                              while(!kbhit())
                              {
                                   outtextxy(20,20,"Favor de introducir un nombre"); 
                                   outtextxy(20,40,"Presione una tecla para continuar...");
                              }
                              closegraph(CURRENT_WINDOW);
                              setcurrentwindow(win1); 
                              i=30;
                              k=0;
                         }
                         else if (nom[i]=='\r')
                         {
                              k=1;
                              i=30;
                         }
                         else if (nom[i]==8)
                         {
                              k=0;
                              i=30;
                         }
                         else
                         {
                              nom[i+1] = '\0';
                              outtextxy(305,190,nom);
                              temp->nombre[i]=nom[i];
                              temp->nombre[i+1] = '\0';
                              i++;
                              k=1;
                         } 
                   }
              }while (k==0);
              int au=0,autom=1, lg=0;
              k=0;
              do
              {
                  do 
                  {
                       lg=0;
                       outtextxy(170,220,"Calif 1: ");
                       box(300,220,400,250,1,BLACK);
                       char c1[50];
                       i=0;
                       while (i<50)
                       {
                             c1[i] = getch();
                             lg++;
                             if (c1[0]=='\r')
                             {
                                  win2 = initwindow(270,100,"Error",100,100);
                                  setcurrentwindow(win2);
                                  while(!kbhit())
                                  {
                                       outtextxy(20,20,"Favor de introducir una califiacion"); 
                                       outtextxy(20,40,"Presione una tecla para continuar...");
                                  }
                                  closegraph(CURRENT_WINDOW);
                                  setcurrentwindow(win1);
                                  k=0;
                                  i=50;
                                  autom=0;
                             }
                             else if (c1[i]=='\r')
                             {
                                  k=1;
                                  i=50;
                                  autom=1;
                             }
                             else if (c1[i]==8)
                             {
                                  k=0;
                                  i=50;
                                  autom=0;
                             }
                             else
                             {
                                 c1[i+1] = '\0';
                                 outtextxy(305,225,c1);
                                 temp->cal1[i]=c1[i];
                                 temp->cal1[i+1] = '\0';
                                 i++;
                                 k=1;
                                 autom=1;
                             } 
                       }
                       cadena[50] =' ';
                       strcpy(cadena,temp->cal1);
                       int aut;
                       if (autom==1)
                       {
                            aut =automata(lg-1);
                            if (aut==true)
                               au=0;
                            else au=1;       
                       }
                  }while (au==1);
              }while (k==0);
              
              au=0,autom=1, lg=0,k=0;
              do
              {
                    do
                    {
                         lg=0;
                         outtextxy(170,255,"Calif 2: ");
                         box(300,255,400,285,1,BLACK);
                         char c2[50];
                         i=0;
                         while (i<50)
                         {
                               c2[i] = getch();
                               lg++;
                               if (c2[0]=='\r')
                               {
                                    win2 = initwindow(270,100,"Error",100,100);
                                    setcurrentwindow(win2);
                                    while(!kbhit())
                                    {
                                         outtextxy(20,20,"Favor de introducir una calificacion"); 
                                         outtextxy(20,40,"Presione una tecla para continuar...");
                                    }
                                    closegraph(CURRENT_WINDOW);
                                    setcurrentwindow(win1);
                                    k=0;
                                    i=50;
                                    autom=0;
                               }
                               else if (c2[i]=='\r')
                               {
                                    k=1;
                                    i=50;
                                    autom=1;
                               }
                               else if (c2[i]==8)
                               {
                                    k=0;
                                    i=50;
                                    autom=0;
                               }
                               else
                               {
                                   c2[i+1] = '\0';
                                   outtextxy(305,260,c2);
                                   temp->cal2[i]=c2[i];
                                   temp->cal2[i+1] = '\0';
                                   i++;
                                   k=1;
                                   autom=1;
                               }
                         }
                         cadena[50] =' ';
                         strcpy(cadena,temp->cal2);
                         int aut;
                         if (autom==1)
                         {
                              aut =automata(lg-1);
                              if (aut==true)
                                 au=0;
                              else au=1;       
                         }
                    }while (au==1);
              }while (k==0);
              
              au=0,autom=1, lg=0,k=0;
              do
              {
                    do
                    {
                         lg=0;
                         outtextxy(170,290,"Calif 3: ");
                         box(300,290,400,320,1,BLACK);
                         char c3[50];
                         i=0;
                         while (i<50)
                         {
                               c3[i] = getch();
                               lg++;
                               if (c3[0]=='\r')
                               {
                                    win2 = initwindow(270,100,"Error",100,100);
                                    setcurrentwindow(win2);
                                    while(!kbhit())
                                    {
                                         outtextxy(20,20,"Favor de introducir una calificacion"); 
                                         outtextxy(20,40,"Presione una tecla para continuar...");
                                    }
                                    closegraph(CURRENT_WINDOW);
                                    setcurrentwindow(win1);
                                    k=0;
                                    i=50;
                                    autom=0;
                               }
                               else if (c3[i]=='\r')
                               {
                                    k=1;
                                    i=50;
                                    autom=1;
                               }
                               else if (c3[i]==8)
                               {
                                    k=0;
                                    i=50;
                                    autom=0;
                               }
                               else
                               {
                                   c3[i+1] = '\0';
                                   outtextxy(305,296,c3);
                                   temp->cal3[i]=c3[i];
                                   temp->cal3[i+1] = '\0';
                                   i++;
                                   k=1;
                                   autom=1;
                               }
                         }
                         cadena[50] =' ';
                         strcpy(cadena,temp->cal3);
                         int aut;
                         if (autom==1)
                         {
                              aut =automata(lg-1);
                              if (aut==true)
                                 au=0;
                              else au=1;       
                         }
                    }while (au==1);
              }while (k==0);
              
              temp->sig=NULL;  
              if (inicio==NULL) 
              {
                   inicio=temp;
                   final=inicio;
              }
              else
              {
                  final->sig=temp; 
                  final=temp;
              }
              win2 = initwindow(270,100,"Registro",100,100);
              setcurrentwindow(win2);
              while(!kbhit())
              {
                   outtextxy(50,20,"REGISTRO EXITOSO."); 
                   outtextxy(20,40,"Presione una tecla para continuar...");
              }
              closegraph(CURRENT_WINDOW);
              setcurrentwindow(win1);
         }
     }
     general();
}
void eliminar ()
{
     temp=inicio; 
     temp2=inicio;
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     menu();
     box(10,220,125,270,1,BLACK);
     outtextxy(25,235,"ELIMINAR");
     char mat[10];
     int i=0,k=0;
     do
     {
         outtextxy(145,100,"INGRESE LA MATRICULA: ");
         box (400,100,500,130,1,BLACK);
         i=0;
         while (i<10)
         {
               mat[i] = getch(); 
               if (mat[0]=='\r')
               {
                    win2 = initwindow(270,100,"Error",100,100);
                    setcurrentwindow(win2);
                    while(!kbhit())
                    {
                         outtextxy(20,20,"Favor de introducir una matricula"); 
                         outtextxy(20,40,"Presione una tecla para continuar...");
                    }
                    closegraph(CURRENT_WINDOW);
                    setcurrentwindow(win1); 
                    i=10;
                    k=0;        
               }
               else if (mat[i]=='\r')
               {
                    i=10; 
                    k=1; 
               }
               else if (mat[i]==8)
               {
                    k=0;
                    i=30;
               }
               else
               {
                   mat[i+1] = '\0';
                   outtextxy(405,105,mat);
                   i++;
                   k=1;
               } 
         }
     }while (k==0);     
     int ma = atoi(mat);
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     menu();
     box(10,220,125,270,1,BLACK);
     outtextxy(25,235,"ELIMINAR");
     int a=0; 
     system("cls");        
     while((temp!=NULL)&&(a==0))   
     {
          if(ma==temp->matricula)  
          {
               if(temp2==temp)
                  inicio=inicio->sig;
               else temp2->sig=temp->sig;
               free(temp); 
               a=1;  
               win2 = initwindow(270,100,"Modificacion",100,100);
               setcurrentwindow(win2);
               while(!kbhit())
               {
                    outtextxy(50,20,"ELIMINACION EXITOSA."); 
                    outtextxy(20,40,"Presione una tecla para continuar...");
               }
         }
         temp2=temp;
         temp=temp->sig;
     }
     if(temp==NULL && a==0)
     {
          win2 = initwindow(270,100,"Modificacion",100,100);
          setcurrentwindow(win2);
          while(!kbhit())
          {
               outtextxy(50,20,"ALUMNO NO ENCONTRADO");
               outtextxy(20,40,"Presione una tecla para continuar...");
          }
     }
     closegraph(CURRENT_WINDOW);
     setcurrentwindow(win1);
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     menu(); 
     general();
}

void buscar ()
{
     temp=inicio; 
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     menu();
     box(10,310,125,360,1,BLACK);
     outtextxy(30,325,"BUSCAR");
     int i=0,k=0;
     char mat[10];
     do
     {
          outtextxy(145,100,"INGRESE LA MATRICULA: ");
          box (400,100,500,130,1,BLACK);
          i=0;
          while (i<10)
          {
                mat[i] = getch(); 
                if (mat[0]=='\r')
                {
                     win2 = initwindow(270,100,"Error",100,100);
                     setcurrentwindow(win2);
                     while(!kbhit())
                     {
                          outtextxy(20,20,"Favor de introducir una matricula"); 
                          outtextxy(20,40,"Presione una tecla para continuar...");
                     }
                     closegraph(CURRENT_WINDOW);
                     setcurrentwindow(win1); 
                     i=10;
                     k=0;
                }
                else if (mat[i]=='\r')
                {
                     i=10;
                     k=1;
                }
                else if (mat[i]==8)
                {
                     k=0;
                     i=10;
                }
                else
                {
                    mat[i+1] = '\0';
                    outtextxy(405,105,mat);
                    i++;
                    k=1;
                }
          }
     }while (k==0);     
     int ma = atoi(mat);
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     menu();
     box(10,310,125,360,1,BLACK);
     outtextxy(30,325,"BUSCAR");
     int a=0;
     int x1=380,y=170,x2=530; 
     while((temp!=NULL)&&(a==0))   
     {
          if(ma==temp->matricula)  
          {
               outtextxy(420,130,"CONSULTA");
               line (160,155,getmaxx()-30,155);
               outtextxy(x1,y,"Matricula:");
               outtextxy(x2,y,mat);
               y+=30;
               outtextxy(x1,y,"Nombre");
               outtextxy(x2,y,temp->nombre);
               y+=30;
               outtextxy(x1,y,"Calif. 1:");
               outtextxy(x2,y,temp->cal1);
               y+=30;
               outtextxy(x1,y,"Calif. 2:");
               outtextxy(x2,y,temp->cal1);
               y+=30;
               outtextxy(x1,y,"Calif. 3:");
               outtextxy(x2,y,temp->cal1);
               a=1;  
         }
         temp=temp->sig; 
     }     
     if(temp==NULL && a==0)
     {
          win2 = initwindow(270,100,"Modificacion",100,100);
          setcurrentwindow(win2);
          while(!kbhit())
          {
               outtextxy(50,20,"ALUMNO NO ENCONTRADO");
               outtextxy(20,40,"Presione una tecla para continuar...");
          }
          closegraph(CURRENT_WINDOW);
          setcurrentwindow(win1);
          clearviewport();
          line(1,80,getmaxx(),80);
          line(135,1,135,getmaxy());
          menu(); 
          general();
     }
}

void visualizar ()
{
     temp=inicio;          
     int i=1;
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     menu();
     box(10,130,125,180,1,BLACK);
     outtextxy(14,415,"VISUALIZAR");
     int x1=200,y=125,x2=300;
     int a=0;
     while (temp!=NULL) 
     {
           settextstyle(3,0,1);
           a=1;
           outtextxy(420,90,"ALUMNOS");
           line (160,110,getmaxx()-30,110);
           for (int ci=0; ci<5;ci++)
           {
               outtextxy(x1,y,"Matricula: ");
               char ma[5];
               itoa(temp->matricula,ma,10);
               outtextxy(x2,y,ma);
               y+=20;
               outtextxy(x1,y,"Nombre: ");
               outtextxy(x2,y,temp->nombre);
               y+=20;
               outtextxy(x1,y,"Calif. 1: ");
               outtextxy(x2,y,temp->cal1);
               y+=20;
               outtextxy(x1,y,"Calif. 2: ");
               outtextxy(x2,y,temp->cal2);
               y+=20;
               outtextxy(x1,y,"Calif. 3: ");
               outtextxy(x2,y,temp->cal3);
               y+=30;
               temp=temp->sig; 
               if (temp==NULL)
                  break;
           }
           x1+=200;
           x2+=200;
           y=125;
           
     }
     if(temp==NULL && a==0)
     {
          win2 = initwindow(270,100,"Modificacion",100,100);
          setcurrentwindow(win2);
          while(!kbhit())
          {
               outtextxy(50,20,"NO HAY REGISTRO");
               outtextxy(20,40,"Presione una tecla para continuar...");
          }
          closegraph(CURRENT_WINDOW);
          setcurrentwindow(win1);
          clearviewport();
          line(1,80,getmaxx(),80);
          line(135,1,135,getmaxy());
          menu(); 
          general();
     }
}

void modificar ()
{
     temp=inicio; 
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     menu();
     box(10,490,125,540,1,BLACK);
     outtextxy(17,505,"MODIFICAR");
     int i=0,k=0;
     char mat[10];
     do
     {
          outtextxy(145,100,"INGRESE LA MATRICULA: ");
          box (400,100,500,130,1,BLACK);
          i=0;
          while (i<10)
          {
                mat[i] = getch();
                if (mat[0]=='\r')
                {
                     win2 = initwindow(270,100,"Error",100,100);
                     setcurrentwindow(win2);
                     while(!kbhit())
                     {
                          outtextxy(20,20,"Favor de introducir una matricula"); 
                          outtextxy(20,40,"Presione una tecla para continuar...");
                     }
                     closegraph(CURRENT_WINDOW);
                     setcurrentwindow(win1); 
                     i=10;
                     k=0;
                } 
                else if (mat[i]=='\r')
                {
                     i=10;
                     k=1;
                }
                else if (mat[i]==8)
                {
                     k=0;
                     i=30;
                }
                else if (mat[i]!='0' && mat[i]!='1' && mat[i]!='2' && mat[i]!='3' && mat[i]!='4' && mat[i]!='5' && mat[i]!='6' && mat[i]!='7' && mat[i]!='8' && mat[i]!='9' )
                {
                     mat[i+1] = '\0';
                     outtextxy(405,105,mat);
                     i++;
                     win2 = initwindow(270,100,"Error",100,100);
                     setcurrentwindow(win2);
                     while(!kbhit())
                     {
                          outtextxy(50,20,"Numero invalido"); 
                          outtextxy(20,40,"Presione una tecla para continuar...");
                     }
                     closegraph(CURRENT_WINDOW);
                     setcurrentwindow(win1); 
                     i=10;
                     k=0;
                } 
                else
                {
                    mat[i+1] = '\0';
                    outtextxy(405,105,mat);
                    i++;
                    k=1;
                }       
          }
     }while(k==0);    
     int ma = atoi(mat);
     int a=0,o=0;
     while((temp!=NULL)&&(a==0))   
     {
          if(ma==temp->matricula)  
          {
               a=1;
               o=1;
          }
          temp=temp->sig; 
     }
     if ((temp==NULL) && (a==0))
     {
          win2 = initwindow(270,100,"Modificacion",100,100);
          setcurrentwindow(win2);
          while(!kbhit())
          {
               outtextxy(50,20,"REGISTRO INEXISTENTE."); 
               outtextxy(20,40,"Presione una tecla para continuar...");
          }
          closegraph(CURRENT_WINDOW);
          setcurrentwindow(win1);
          clearviewport();
          line(1,80,getmaxx(),80);
          line(135,1,135,getmaxy());
          menu(); 
          general();
     } 
     if (o==1)
     {
          clearviewport();
          line(1,80,getmaxx(),80);
          line(135,1,135,getmaxy());
          outtextxy(300,300,"MENU DE MODIFICACION");
          outtextxy(500,665,"Presione ESC para regresar");
          mueve2(ma);
     } 
}

void m_mat(int matricula_m)
{
     temp=inicio; 
     temp2=inicio;
     int a=0;
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     menu2();
     box(10,130,125,180,1,BLACK);
     outtextxy(15,145,"MATRICULA");
     char mat[10];
     int i=0,k=0;
     while((temp!=NULL)&&(a==0))
     {
          if(matricula_m==temp->matricula)
          {
               do
               {
                    outtextxy(145,100,"NUEVA MATRICULA: ");
                    box (400,100,500,130,1,BLACK);
                    i=0;
                    while (i<10)
                    {
                          mat[i] = getch();
                          if (mat[0]=='\r')
                          {
                               win2 = initwindow(270,100,"Error",100,100);
                               setcurrentwindow(win2);
                               while(!kbhit())
                               {
                                    outtextxy(20,20,"Favor de introducir una matricula"); 
                                    outtextxy(20,40,"Presione una tecla para continuar...");
                               }
                               closegraph(CURRENT_WINDOW);
                               setcurrentwindow(win1); 
                               i=10;
                               k=0;
                          } 
                          else if (mat[i]=='\r')
                          {
                               i=10;
                               k=1;
                          }
                          else if (mat[i]==8)
                          {
                               k=0;
                               i=10;
                          }
                          else if (mat[i]!='0' && mat[i]!='1' && mat[i]!='2' && mat[i]!='3' && mat[i]!='4' && mat[i]!='5' && mat[i]!='6' && mat[i]!='7' && mat[i]!='8' && mat[i]!='9' )
                          {
                               mat[i+1] = '\0';
                               outtextxy(405,105,mat);
                               i++;
                               win2 = initwindow(270,100,"Error",100,100);
                               setcurrentwindow(win2);
                               while(!kbhit())
                               {
                                    outtextxy(50,20,"Numero invalido"); 
                                    outtextxy(20,40,"Presione una tecla para continuar...");
                               }
                               closegraph(CURRENT_WINDOW);
                               setcurrentwindow(win1); 
                               i=10;
                               k=0;
                          } 
                          else
                          {
                              mat[i+1] = '\0';
                              outtextxy(405,105,mat);
                              i++;
                              k=1;
                          } 
                    }
               }while (k==0);     
               int ma = atoi(mat);
               while((temp2!=NULL)&&(a==0))   
               {
                    if(ma==temp2->matricula)  
                    {
                         a=1; 
                         win2 = initwindow(270,100,"Error",100,100);
                         setcurrentwindow(win2);
                         while(!kbhit())
                         {
                              outtextxy(50,20,"MATRICULA YA REGISTRADA");
                              outtextxy(15,40,"Sera redireccionado al menu principal"); 
                              outtextxy(20,60,"Presione una tecla para continuar...");   
                         }
                         closegraph(CURRENT_WINDOW);
                         setcurrentwindow(win1);
                    }
                    else 
                    {
                         win2 = initwindow(270,100,"Modificacion",100,100);
                         setcurrentwindow(win2);
                         while(!kbhit())
                         {
                              outtextxy(50,20,"MODIFICACION EXITOSA."); 
                              outtextxy(20,40,"Presione una tecla para continuar...");
                         }
                         closegraph(CURRENT_WINDOW);
                         setcurrentwindow(win1);
                         clearviewport();
                         line(1,80,getmaxx(),80);
                         line(135,1,135,getmaxy());
                         menu();
                         temp->matricula=ma;
                         a=1;
                    }
                    temp2=temp2->sig; 
              }
          }
          temp=temp->sig; 
     }
}

void m_nom(int matricula_m)
{
     temp=inicio; 
     temp2=inicio;
     int a=0;
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     menu2();
     box(10,220,125,270,1,BLACK);
     outtextxy(25,235,"NOMBRE");
     while((temp!=NULL)&&(a==0))
     {
          if(matricula_m==temp->matricula)
          {
               int i=0,k=0;
               do
               {
                   outtextxy(145,100,"NUEVO NOMBRE: ");
                   box (400,100,500,130,1,BLACK);
                   char nom[30];
                   i=0;
                   while (i<30)
                   {
                         nom[i] = getch();
                         if (nom[0]=='\r')
                         {
                              win2 = initwindow(270,100,"Error",100,100);
                              setcurrentwindow(win2);
                              while(!kbhit())
                              {
                                   outtextxy(20,20,"Favor de introducir un nombre"); 
                                   outtextxy(20,40,"Presione una tecla para continuar...");
                              }
                              closegraph(CURRENT_WINDOW);
                              setcurrentwindow(win1); 
                              i=30;
                              k=0;
                         }
                         else if (nom[i]=='\r')
                         {
                              i=30;
                              k=1;
                         }
                         else if (nom[i]==8)
                         {
                              k=0;
                              i=30;
                         }
                         else
                         {
                             nom[i+1] = '\0';
                             outtextxy(405,105,nom);
                             temp->nombre[i]=nom[i];
                             temp->nombre[i+1] = '\0';
                             i++;
                             k=1;
                         } 
                   }
               }while (k==0);
               a=1;
          }
          temp=temp->sig; 
     }
     win2 = initwindow(270,100,"Modificacion",100,100);
     setcurrentwindow(win2);
     while(!kbhit())
     {
          outtextxy(50,20,"MODIFICACION EXITOSA."); 
          outtextxy(20,40,"Presione una tecla para continuar...");
     }
     closegraph(CURRENT_WINDOW);
     setcurrentwindow(win1);
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     menu();
}

void m_c1(int matricula_m)
{
     temp=inicio; 
     temp2=inicio;
     int a=0,au=0, lg=0,autom=1;
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     indicacion();
     menu2();
     box(10,310,125,360,1,BLACK);
     outtextxy(30,325,"CALIF. 1");
     while((temp!=NULL)&&(a==0))
     {
          if(matricula_m==temp->matricula)
          {
               int i=0, k=0;
               do
              {
                  do 
                  {
                       lg=0;
                       outtextxy(145,100,"NUEVA CALIF 1: ");
                       box (400,100,500,130,1,BLACK);
                       char c1[50];
                       i=0;
                       while (i<50)
                       {
                             c1[i] = getch();
                             lg++;
                             if (c1[0]=='\r')
                             {
                                  win2 = initwindow(270,100,"Error",100,100);
                                  setcurrentwindow(win2);
                                  while(!kbhit())
                                  {
                                       outtextxy(20,20,"Favor de introducir una califiacion"); 
                                       outtextxy(20,40,"Presione una tecla para continuar...");
                                  }
                                  closegraph(CURRENT_WINDOW);
                                  setcurrentwindow(win1);
                                  k=0;
                                  i=50;
                                  autom=0;
                             }
                             else if (c1[i]=='\r')
                             {
                                  k=1;
                                  i=50;
                                  autom=1;
                             }
                             else if (c1[i]==8)
                             {
                                  k=0;
                                  i=50;
                                  autom=0;
                             }
                             else
                             {
                                 c1[i+1] = '\0';
                                 outtextxy(405,105,c1);
                                 temp->cal1[i]=c1[i];
                                 temp->cal1[i+1] = '\0';
                                 i++;
                                 k=1;
                                 autom=1;
                             } 
                       }
                       cadena[50] =' ';
                       strcpy(cadena,temp->cal1);
                       int aut;
                       if (autom==1)
                       {
                            aut =automata(lg-1);
                            if (aut==true)
                               au=0;
                            else au=1;       
                       }
                  }while (au==1);
              }while (k==0);
              a=1;
          }
          temp=temp->sig; 
     }
     win2 = initwindow(270,100,"Modificacion",100,100);
     setcurrentwindow(win2);
     while(!kbhit())
     {
         outtextxy(50,20,"MODIFICACION EXITOSA."); 
         outtextxy(20,40,"Presione una tecla para continuar...");
     }
     closegraph(CURRENT_WINDOW);
     setcurrentwindow(win1);
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     menu(); 
}

void m_c2(int matricula_m)
{
     temp=inicio; 
     temp2=inicio;
     int a=0,au=0, lg=0,autom=1;
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     indicacion();
     menu2();
     box(10,400,125,450,1,BLACK);
     outtextxy(30,415,"CALIF. 2");
     while((temp!=NULL)&&(a==0))
     {
          if(matricula_m==temp->matricula)
          {
               int i=0, k=0;
               do
              {
                  do 
                  {
                       lg=0;
                       outtextxy(145,100,"NUEVA CALIF 2: ");
                       box (400,100,500,130,1,BLACK);
                       char c2[50];
                       i=0;
                       while (i<50)
                       {
                             c2[i] = getch();
                             lg++;
                             if (c2[0]=='\r')
                             {
                                  win2 = initwindow(270,100,"Error",100,100);
                                  setcurrentwindow(win2);
                                  while(!kbhit())
                                  {
                                       outtextxy(20,20,"Favor de introducir una califiacion"); 
                                       outtextxy(20,40,"Presione una tecla para continuar...");
                                  }
                                  closegraph(CURRENT_WINDOW);
                                  setcurrentwindow(win1);
                                  k=0;
                                  i=50;
                                  autom=0;
                             }
                             else if (c2[i]=='\r')
                             {
                                  k=1;
                                  i=50;
                                  autom=1;
                             }
                             else if (c2[i]==8)
                             {
                                  k=0;
                                  i=50;
                                  autom=0;
                             }
                             else
                             {
                                 c2[i+1] = '\0';
                                 outtextxy(405,105,c2);
                                 temp->cal2[i]=c2[i];
                                 temp->cal2[i+1] = '\0';
                                 i++;
                                 k=1;
                                 autom=1;
                             } 
                       }
                       cadena[50] =' ';
                       strcpy(cadena,temp->cal2);
                       int aut;
                       if (autom==1)
                       {
                            aut =automata(lg-1);
                            if (aut==true)
                               au=0;
                            else au=1;       
                       }
                  }while (au==1);
              }while (k==0);
              a=1;
          }
          temp=temp->sig; 
     }
     win2 = initwindow(270,100,"Modificacion",100,100);
     setcurrentwindow(win2);
     while(!kbhit())
     {
         outtextxy(50,20,"MODIFICACION EXITOSA."); 
         outtextxy(20,40,"Presione una tecla para continuar...");
     }
     closegraph(CURRENT_WINDOW);
     setcurrentwindow(win1);
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     menu(); 
}

void m_c3(int matricula_m)
{
     temp=inicio; 
     temp2=inicio;
     int a=0,au=0, lg=0,autom=1;
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     indicacion();
     menu2();
     box(10,490,125,540,1,BLACK);
     outtextxy(30,505,"CALIF. 3");
     while((temp!=NULL)&&(a==0))
     {
          if(matricula_m==temp->matricula)
          {
               int i=0, k=0;
               do
              {
                  do 
                  {
                       lg=0;
                       outtextxy(145,100,"NUEVA CALIF 3: ");
                       box (400,100,500,130,1,BLACK);
                       char c3[50];
                       i=0;
                       while (i<50)
                       {
                             c3[i] = getch();
                             lg++;
                             if (c3[0]=='\r')
                             {
                                  win2 = initwindow(270,100,"Error",100,100);
                                  setcurrentwindow(win2);
                                  while(!kbhit())
                                  {
                                       outtextxy(20,20,"Favor de introducir una califiacion"); 
                                       outtextxy(20,40,"Presione una tecla para continuar...");
                                  }
                                  closegraph(CURRENT_WINDOW);
                                  setcurrentwindow(win1);
                                  k=0;
                                  i=50;
                                  autom=0;
                             }
                             else if (c3[i]=='\r')
                             {
                                  k=1;
                                  i=50;
                                  autom=1;
                             }
                             else if (c3[i]==8)
                             {
                                  k=0;
                                  i=50;
                                  autom=0;
                             }
                             else
                             {
                                 c3[i+1] = '\0';
                                 outtextxy(405,105,c3);
                                 temp->cal3[i]=c3[i];
                                 temp->cal3[i+1] = '\0';
                                 i++;
                                 k=1;
                                 autom=1;
                             } 
                       }
                       cadena[50] =' ';
                       strcpy(cadena,temp->cal3);
                       int aut;
                       if (autom==1)
                       {
                            aut =automata(lg-1);
                            if (aut==true)
                               au=0;
                            else au=1;       
                       }
                  }while (au==1);
              }while (k==0);
              a=1;
          }
          temp=temp->sig; 
     }
     win2 = initwindow(270,100,"Modificacion",100,100);
     setcurrentwindow(win2);
     while(!kbhit())
     {
         outtextxy(50,20,"MODIFICACION EXITOSA."); 
         outtextxy(20,40,"Presione una tecla para continuar...");
     }
     closegraph(CURRENT_WINDOW);
     setcurrentwindow(win1);
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy());
     menu(); 
}

void box (int x1,int y1,int x2,int y2, int relleno,int color)
{
     int poly [8];
     poly [0]=x1;
     poly [1]=y1;
     poly [2]=x2;
     poly [3]=y1;
     poly [4]=x2;
     poly [5]=y2;
     poly [6]=x1;
     poly [7]=y2;
     setfillstyle (relleno,color);
     fillpoly (4,poly);
}

void indicacion()
{    //SANS_SERIF_FONT , 3
     settextstyle(3,0,1);
     outtextxy(140,5,"Calificaciones Aceptadas (elementos en mayusculas, basado en sist. Ingles)");
     outtextxy(140,30,"     Aprobatorias:   A+, A, A-, B+, B, B-, C+, C, C-, D+, D, D-");
     outtextxy(140,55,"     Reprobatoria:   F");
}

void indicacion1()
{    
     settextstyle(3,0,1);
     outtextxy(140,5,"Para seleccionar alguna opcion mueva las flechas en su teclado (arriba, abajo)");
     outtextxy(140,30,"Presione ENTER para seleccionar un campo");
     outtextxy(140,55,"Presione BORRAR para limpiar un campo");
}

void menu()
{    
     settextstyle(3,0,2);
     box(10,130,125,180,1,LIGHTGRAY);
     outtextxy(22,145,"AGREGAR");
     box(10,220,125,270,1,LIGHTGRAY);
     outtextxy(25,235,"ELIMINAR");
     box(10,310,125,360,1,LIGHTGRAY);
     outtextxy(30,325,"BUSCAR");
     box(10,400,125,450,1,LIGHTGRAY);
     outtextxy(15,415,"VISUALIZAR");
     box(10,490,125,540,1,LIGHTGRAY);
     outtextxy(17,505,"MODIFICAR");
     box(10,580,125,630,1,LIGHTGRAY);
     outtextxy(40,595,"SALIR");
}

void menu2()
{    
     settextstyle(3,0,2);
     box(10,130,125,180,1,LIGHTGRAY);
     outtextxy(15,145,"MATRICULA");
     box(10,220,125,270,1,LIGHTGRAY);
     outtextxy(25,235,"NOMBRE");
     box(10,310,125,360,1,LIGHTGRAY);
     outtextxy(30,325,"CALIF. 1");
     box(10,400,125,450,1,LIGHTGRAY);
     outtextxy(30,415,"CALIF. 2");
     box(10,490,125,540,1,LIGHTGRAY);
     outtextxy(30,505,"CALIF. 3");
     box(10,580,125,630,1,LIGHTGRAY);
     outtextxy(17,595,"REGRESAR");
}

void mueve()
{
     char tecla;
     int i=1;
     menu();
     do
     {
            switch(i)
            {
                     case 1:
                          box(10,130,125,180,1,BLACK);
                          outtextxy(22,145,"AGREGAR");
                          break;
                     case 2: 
                          box(10,220,125,270,1,BLACK);
                          outtextxy(25,235,"ELIMINAR");
                          break;
                     case 3: 
                          box(10,310,125,360,1,BLACK);
                          outtextxy(30,325,"BUSCAR");
                          break;
                     case 4: 
                          box(10,400,125,450,1,BLACK);
                          outtextxy(15,415,"VISUALIZAR");
                          break;
                     case 5: 
                          box(10,490,125,540,1,BLACK);
                          outtextxy(17,505,"MODIFICAR");
                          break;
                     case 6: 
                          box(10,580,125,630,1,BLACK);
                          outtextxy(40,595,"SALIR");
                          break;
            }//fin del swith dark
            tecla=getch();
            
            switch(i)
            {
                     case 1:  
                          box(10,130,125,180,1,LIGHTGRAY);
                          outtextxy(22,145,"AGREGAR");
                          break;
                     case 2: 
                          box(10,220,125,270,1,LIGHTGRAY);
                          outtextxy(25,235,"ELIMINAR");
                          break;
                     case 3: 
                          box(10,310,125,360,1,LIGHTGRAY);
                          outtextxy(30,325,"BUSCAR");
                          break;
                     case 4: 
                          box(10,400,125,450,1,LIGHTGRAY);
                          outtextxy(15,415,"VISUALIZAR");
                          break;
                     case 5: 
                          box(10,490,125,540,1,LIGHTGRAY);
                          outtextxy(17,505,"MODIFICAR");
                          break;
                     case 6: 
                          box(10,580,125,630,1,LIGHTGRAY);
                          outtextxy(40,595,"SALIR");
                          break;
            }//fin del swith light
            
            switch(tecla)
            {
            case 0: 
                 tecla=getch();
                 
                 switch (tecla)
                 {
                        case 72:
                             i--;
                             break;
                        case 80:
                             i++;
                             break;
                 }
                 if(i>6)
                        i=1;
                 if(i<1)
                        i=6;
                 break;//fin case cero
            
            case 13: 
                 switch(i)
                 {
                          case 1:
                               agregar();
                               break;
	                      case 2:
                               eliminar();
                               break;
	                      case 3:
                               buscar();
                               break;
                          case 4:
                               visualizar();
                               break;
	                      case 5:
                               modificar();
                               break;
	                      case 6:
                               tecla=27;
                               break;
                 }
                 if (i!=6)
                    menu();
	             break;

            }
            //fin enter
       } 
       while(tecla!=27);
}
void mueve2(int matri)
{
     temp=inicio; 
     int a=0; 
     char tecla;
     int i=1;
     menu2();
     do
     {
            switch(i)
            {
                     case 1:
                          box(10,130,125,180,1,BLACK);
                          outtextxy(15,145,"MATRICULA");
                          break;
                     case 2: 
                          box(10,220,125,270,1,BLACK);
                          outtextxy(25,235,"NOMBRE");
                          break;
                     case 3: 
                          box(10,310,125,360,1,BLACK);
                          outtextxy(30,325,"CALIF. 1");
                          break;
                     case 4: 
                          box(10,400,125,450,1,BLACK);
                          outtextxy(30,415,"CALIF. 2");
                          break;
                     case 5: 
                          box(10,490,125,540,1,BLACK);
                          outtextxy(30,505,"CALIF. 3");
                          break;
                     case 6: 
                          box(10,580,125,630,1,BLACK);
                          outtextxy(17,595,"REGRESAR");
                          break;
            }//fin del swith dark
            tecla=getch();
            
            switch(i)
            {
                     case 1:  
                          box(10,130,125,180,1,LIGHTGRAY);
                          outtextxy(15,145,"MATRICULA");
                          break;
                     case 2: 
                          box(10,220,125,270,1,LIGHTGRAY);
                          outtextxy(25,235,"NOMBRE");
                          break;
                     case 3: 
                          box(10,310,125,360,1,LIGHTGRAY);
                          outtextxy(30,325,"CALIF. 1");
                          break;
                     case 4: 
                          box(10,400,125,450,1,LIGHTGRAY);
                          outtextxy(30,415,"CALIF. 2");
                          break;
                     case 5: 
                          box(10,490,125,540,1,LIGHTGRAY);
                          outtextxy(30,505,"CALIF. 3");
                          break;
                     case 6: 
                          box(10,580,125,630,1,LIGHTGRAY);
                          outtextxy(17,595,"REGRESAR");
                          break;
            }//fin del swith light
            
            switch(tecla)
            {
            case 0: 
                 tecla=getch();
                 
                 switch (tecla)
                 {
                        case 72:
                             i--;
                             break;
                        case 80:
                             i++;
                             break;
                 }
                 if(i>6)
                        i=1;
                 if(i<1)
                        i=6;
                 break;//fin case cero

            case 13: 
                 switch(i)
                 {
                          case 1:
                               m_mat(matri);
                               tecla=27;
                               break;
	                      case 2:
                               m_nom(matri);
                               tecla=27;
                               break;
	                      case 3:
                               m_c1(matri);
                               tecla=27;
                               break;
                          case 4:
                               m_c2(matri);
                               tecla=27;
                               break;
	                      case 5:
                               m_c3(matri);
                               tecla=27;
                               break;
	                      case 6:
                               clearviewport();
                               line(1,80,getmaxx(),80);
                               line(135,1,135,getmaxy());
                               menu();
                               general();
                               tecla=27;
                               break;
                 }
                 if (i!=6)
                    menu2();
	             break;

            }
            //fin enter
       } 
       while(tecla!=27);
       if (tecla==27)
       {
       clearviewport();
                               line(1,80,getmaxx(),80);
                               line(135,1,135,getmaxy());
                               menu();
                               general();
                               }
}
int main()
{
    win1 =initwindow(800,700);
    general();
    mueve();
}

void general ()
{
     clearviewport();
     line(1,80,getmaxx(),80);
     line(135,1,135,getmaxy()); 
     indicacion1();
     outtextxy(194,590,"Hecho por: ");
     outtextxy(225,615,"Andrea Mireles Diaz");
     outtextxy(225,640,"Marisol Garcia Cadena");
     outtextxy(225,665,"Marybel Vargas Lara");
     outtextxy(500,665,"Presione ESC para salir");
     settextstyle(4, 0, 0 );
     outtextxy(300,300," CONTROL DE");
     outtextxy(300,400,"CALIFICACIONES");
     settextstyle(3, 0,2);
 }
 
int automata (int cal)
{
    t=cal;
    printf("\nCADENA: %s",cadena);
    ini();
    if (aceptado)
       return(true);
    else return(false);
    getche();
}

void ini()
{
     cont =0;
     aceptado = false;
     q0();
}

void q0()
{
     printf("\nEn q0");
                if (cadena[cont]==32)
                {
                    cont++;
                    q0();
                }
                else if (cadena[cont]=='A' || cadena[cont]=='B' || cadena[cont]=='C' || cadena[cont]=='D')
                {
                     cont++;
                     q1();
                }
                else if (cadena[cont]=='F')
                {
                     cont++;
                     q2();
                }
                else qError();
}

void q1()
{
     printf("\nEn q1");
     if (cont==t)
            aceptado = true;     
     else 
     {
                if (cadena[cont]=='+' || cadena[cont]=='-' || cadena[cont]==32 )
                {
                     cont++;
                     q2();
                }
                else qError();
     }
}

void q2()
{
     printf("\nEn q2");
     if (cadena[cont]==32)
     {
         cont++;
         q2();
     }
     else if (cont==t)
          aceptado = true;     
     else qError();
}


void qError()
{
     printf("\nERROR");
     aceptado = false; 
     win2 = initwindow(270,100,"Error",100,100);
     setcurrentwindow(win2);
     while(!kbhit())
     {
          outtextxy(50,20,"CALIFICACION INVALIDA."); 
          outtextxy(20,40,"Favor de leer las instrucciones");
          outtextxy(20,60,"Presione una tecla para continuar...");
     }
     closegraph(CURRENT_WINDOW);
     setcurrentwindow(win1);   
     return;
}



