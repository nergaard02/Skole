//
//  main.c
//  oblig
//
//  Created by Andreas Nergård on 31/08/2022.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void compare_values (int x, int y){                  //deklarerer funksjon med x og y som parametere
    if (x > y){                                      //sjekker om x har større verdi enn y
        printf("x-verdien er størst med %d\n", x);   //printer ut x-veriden dersom if-statement betingelsen oppfylles
    } else if (y > x){                               //sjekker om y har større verdi enn x
        printf("y-verdien er størst med %d\n", y);   //printer ut y-verdien dersom else if betingelsen oppfylles
    } else{                                          //dersom ingen av de tidligere betingelsene oppfylles
        printf("x-verdien og y-verdien er lik\n");     //forteller at x og y må ha samme verdi
    }
}

   
void myTriangles(int numlines){                    //deklarerer funksjon med numlines som parameter
    for (int i = 0; i < numlines; i++){            //loop som går fra 0 til numlines
        for (int k = i; k >= 0; k--){              //nested loop som teller ned fra i til 0
            printf("*");                           //gjør slik at trekanten blir representert med "*"
        }
        printf("\n");                              //lager ny linje for hver gjennomgang av ytterste loop
    }
}

int myPrimefactor (int number, int primefactor){    //deklarerer funksjon med number og primefactor som parametere
    if (number % primefactor == 0){                 //sjekker om number/primefactor gir rest
        return 1;                                   //dersom det ikke er noe rest, returner 1
    } else{
        return 0;                                   //dersom det er rest, returner 0
    }
}

void myNumbers (int startnum, int endnum){                           //deklarerer funksjon med startnum og endnum som parametere
    for (int i = startnum; i <= endnum; i++){                        //loop som går igjennom alle tall fra startnum til endnum

        if (myPrimefactor (i, 5) && i % 2 == 0){            //bruker myPrimefactor funksjonen for å sjekke om 5 er en primfaktor
            printf("%d er et partall og 5 er en primfaktor\n", i);   //dersom 5 er en primfaktor av i og i er et partall
        }
        else if (!myPrimefactor (i, 5)  && i % 2 == 0){              //dersom 5 ikke er en primfaktor, men i er et partall
            printf("%d er et partall og 5 er ikke en primfaktor\n", i);
        }
        else if (myPrimefactor (i, 5)  && i % 2 != 0){                //dersom 5 er en primfaktor, og i er et oddetall
            printf("%d er et oddetall og 5 er en primfaktor\n", i);
        }
        else if (!myPrimefactor (i, 5)  && i % 2 != 0){               //dersom 5 ikke er en primfaktor, og i er et oddetall
            printf("%d er et oddetall og 5 er ikke en primfaktor\n", i);
        }
    }
}

int myLog2(unsigned int n){              //deklarerer funksjon med unsigned int n som parameter
    for (int i = 0; 1; ++i){             //vil gå så lenge vi ikke går over et tall større enn 32-bit
        if (n == 0) return 0;            //dersom brukeren putter inn 0, returnerer vi 0 med en gang
        if (n >> i == 1)                 //bit-shifter til høyre helt til n = 1
            return i;
    }
}

void reverse(char *string){                //deklarerer funksjon med en array som parameter, som vi også peker til
    int i, totalchar;                      //deklarerer i og totalchar
    totalchar = 0;                         //initialiserer totalchar
    for (i = 0; string[i] != '\0'; i++){   //Så lenge lenge stringen ikke inneholder nullkarakter, fortsett å gå igjennom array
        if (string[i] != ' ')              //for å ikke telle med mellomrom
            totalchar++;                   //når de to betingelsene over er oppfyllt, øker totalchar
    }
    
    int middle = totalchar / 2;                  //finner midtpunktet på arrayen

    char temp;                                   //midlertidig variabel

    for (int r = 0; r < middle; r++){            //går fra 0 til midten i arrayen, skal representere indexposisjonen
        temp = string [r];                       //setter temp lik den bokstaven som tilhører indexposisjonen vi er på
        string [r] = string [totalchar - r - 1]; //finner motsatt indexposisjon på arrayen
        string [totalchar - r - 1] = temp;       //setter bokstaven til den nye indexposisjonen
    }
}



int main ()
{
    printf(" a. Sammenlign verdier\n b. Triangel\n c. Primfaktor\n d. Intervall med tall\n e. Mest signifikante bit\n f. Reverser string\n Velg hvilken funksjon du ønsker å starte: "); //bruker velger funksjon å kjøre
    char str = getchar();       //en-karakter input
    getchar();                 //fjerner ny linje tegn (\n)
    
    
    switch (str){              //lager en switch case for alle funksjonene
        case 'a':
        {
            int x, y;                           //deklarerer x og y
            printf("Velg en verdi for x: ");    //ber om input
            scanf("%d", &x);                    //bruker scanf for å registerere input
            printf("Velg en verdi for y: ");    //ber om input
            scanf("%d", &y);                    //bruker scanf for å registrere input
            compare_values(x, y);               //kaller på funksjonen compare_values med x og y som argumenter
            break;                              //avslutter casen
        }
    
        case 'b':
        {
            int numlines;                                            //deklarerer numlines
            printf("Velg hvor mange linjer triangelet skal være: "); //ber om input fra brukeren
            scanf("%d", &numlines);                                  //registrerer input
            myTriangles(numlines);                                   //kaller på funksjon myTriangles med numlines som argument
            break;                                                   //avslutter casen
        }
    
       case 'c':
        {
           int number, primefactor;                                   //deklarerer number og primefactor
           printf("Velg et tall: ");                                  //ber om input fra brukeren
           scanf("%d", &number);                                      //registrerer input
           printf("Velg en primfaktor: ");                            //ber om input
           scanf("%d", &primefactor);                                 //registrerer input
           myPrimefactor(number, primefactor);       //kaller på funksjon myPrimefactor med number og primefactor som argumenter
            if (myPrimefactor(number, primefactor)){ //dersom vi får returnert 1 som verdi
                printf("%d er en primfaktor av %d\n", primefactor, number);
            }else{
                printf("%d er ikke en primfaktor av %d\n", primefactor, number); //dersom vi får returnert 0 som verdi
            }
           break;                                                                //avslutter casen
        }
        
    
      case 'd':
        {
          int startnum;                             //deklarerer startnum
          printf("Velg et tall å starte med: ");    //ber om input fra brukeren
          scanf("%d", &startnum);                   //registrerer input
          int endnum;                               //deklarerer endnum
          printf("Velg et tall å slutte med: ");    //ber om input fra brukeren
          scanf("%d", &endnum);                     //registrerer input
          
          myNumbers(startnum, endnum);              //kaller på funksjon med startnum og endnum som argumenter
          break;                                    //avslutter case
        }
            
            
      case 'e':
        {
          int n;                                   //deklarerer n
          printf("Velg et tilfeldig tall: ");      //ber om input fra brukeren
          scanf("%d", &n);                         //registrer input
          int i = myLog2(n);                       //setter i lik det vi får i verdi fra funksjon myLog med n som argument
          printf("Den mest signifikante bitten er: %d\n", i);   //Printer resultatet
          break;                                                //avslutter case
        }
            
            
        case 'f':
        {
            char string[100];
            printf("Skriv en setning på mindre enn 100 bokstaver: ");  //ber om input fra brukeren
            fgets(string, 100, stdin);       //vi lagrer input fra terminalen inn i en string ved hjelp av stdin
            reverse(string);                 //kaller på funksjonen med string som argument
            printf("Setnigen reversert er: %s\n", string);     //printer ut resultatet
            return 0;
            break;           //avslutter case
        }
    }
    
}
    
    
    
    



    
        
        
        
    
    
    
    
    



   

    
    

    
    
    
   
        
      
        
        

    

    
    

    
    

        
    

    

    
    

    

