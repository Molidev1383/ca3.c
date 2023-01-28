#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
# include"koamki.h"
# define right 1
/*dar in kod ma sai mikonim ta ba estefade az linked list ha va arraye haie dynamic yek payam resan ra piade sazi konim
payam ha linked list marbot be khod ra darand va karbar ha linked list marbot be khodeshan vali mozoe inast ke chegjori bnhayat argukent string ma begirad
 dar in kar ma majborim dono done az karbar realloc konim va chek konim ke che charecterii ast ke agar be an karekter haie ke marbot be zadan enter 
 ast beresi konad agar taraf ba zadan enter charcter marbot ra vared karde bashad digar realloc nemikonad */
typedef struct member karbar;
typedef struct Messages messages;
/*in tabe dar asl haman tabeist ke done done realloc mikonad va character ra gharar midahad baraye hameie tvae i ke az karbar vorodi migirand az khorojie
in tabe estefade mikonim*/
char* dynamicstring(char *stringp){
    stringp= malloc(sizeof(char));

    if (!stringp)
        return NULL;

    char c;
    char *reallocStr;
    size_t len = 0;
    size_t buf = 1;

    

    while ((c = getchar()) != '\n' && c != EOF) {
        if (len == buf) {
            buf *= 2;

            reallocStr = realloc(stringp, buf * sizeof(char));

            if (!reallocStr)
                return NULL;

            stringp = reallocStr;
        }

        stringp[len++] = c;
    }

    stringp[len] = '\0';
    return stringp;
}
/*dar asl nodde jadid misazad va ezafe mikonad*/
void karbarezefekon (karbar* khead){
    karbar *current = khead;
    karbar *jadid = malloc(sizeof(karbar));
    while (current->karbarbadi != NULL)
    {
        current = current->karbarbadi;
    }
    current->karbarbadi = jadid;
    jadid->karbarbadi = NULL;
    jadid->tedadpayam = 0;
    jadid->shenase = dynamicstring(jadid->shenase);
    jadid->ramz = dynamicstring(jadid->ramz);
    printf("karbar ezafe shod");
    
}/*dar as dar in ja payam hara az karbar marbote migirim*/
void massagegozari(messages *mhead, karbar*morednazar){
    messages *temp = mhead;
    messages *jadid = malloc(sizeof(messages));
    while (temp->next_massge != NULL)
    {
        temp = temp->next_massge;
    }

    temp->next_massge = jadid;
    jadid->next_massge = NULL;

    jadid->matn = dynamicstring(jadid->matn);
    jadid->m_shenase = dynamicstring(jadid->m_shenase);
    jadid->m_shenase = morednazar->shenase;
    jadid->like = 0;
    morednazar->tedadpayam ++;
    jadid->id = morednazar->tedadpayam;
    printf("post shoma sabt shod");

}/*in tabe baraye neshan dadan payam ha tarahi shode ast*/
void printer(karbar *you, messages *phead)
    {
    messages *payamfeli;
    payamfeli = phead;
    while (payamfeli->next_massge != NULL)
    {
        payamfeli= payamfeli->next_massge;
        if (strcmp(payamfeli->m_shenase, you->shenase) == 0)
        {
            printf("karbar: %s\nmassage_id: %d\nlike: %d\nmassage: %s\n\n", payamfeli->m_shenase, payamfeli->id, payamfeli->like, payamfeli->matn);
        }
    }
}
void deleter(messages *mhead, karbar*mored, int id){

    messages *feli = mhead;
    messages *prv = mhead;
    if (feli->next_massge == NULL)
    {
        printf("eshteba kardi dobare emtehan kon\n");
        return;
    }
    while (feli->next_massge != NULL)
    {
        prv = feli;
        feli = feli->next_massge;
        if ((feli->next_massge == NULL) && (strcmp(mored->shenase, feli->m_shenase) == 0) && (feli->id == id))
        {
            prv->next_massge = NULL;
            feli = NULL;
            printf("pakkardam");
            free(feli); 
            return; 
        }
        if ((strcmp(mored->shenase, feli->m_shenase) == 0) && (feli->id == id))
        {
            prv->next_massge = feli->next_massge;
            feli = NULL;
            printf("pak kardam");
            free(feli);
            return;
        }
    }
    printf("post mored nazaraeto nayaftam\n");
}
karbar* karbaryabande(karbar *karbarvaredshode,char*shenasevaredshode,char* ramzvaredshode){
    karbar *temp  = malloc(sizeof(karbar));
    temp = karbarvaredshode;
    while (temp->karbarbadi != NULL)
    {
        temp = temp->karbarbadi;
        if ((strcmp(temp->shenase, shenasevaredshode) == 0) && (strcmp(temp->ramz,ramzvaredshode) == 0))
        {
            return temp;
        }
        
    }

    return NULL;
}
void liker(messages *mhed, char* sahebpayam, int p_id)
{
    messages*feli= mhed;
    while (feli->next_massge != NULL)
    {
        feli = feli->next_massge;
        if ((strcmp(sahebpayam, feli->m_shenase) == 0) && (p_id == feli->id))
        {
            feli->like++;
            printf("like kardam");
            return;
        } 
    }
    printf("post mored nazar yaftft nashod\n");
}
karbar* karbarfinder(karbar *khead, char cshenase[])
{
    karbar *feli =khead;
    while (feli->karbarbadi != NULL)
    {
       feli = feli->karbarbadi;
        if (strcmp(feli->shenase , cshenase) == 0)
        {
           return feli;
        }
    }
    printf("hatman yeja soti dadi\n");
    return NULL;
}
int main(){/*baraye piadesazi in ke kodemon hamishe run she tabiatan be yek loop binahayat niaz darim va 
barye tashkhis dastor ha tavsot computer az strcmp estefade mikonim  va dar sorat tadid yeki az tabe hara faramikhani*/
/*srae list karbar ha*/
    karbar *khead = malloc(sizeof(karbar));
    khead->karbarbadi = NULL;
    /*sar list payama*/
    messages *mhead = malloc(sizeof(messages));
    mhead->next_massge = NULL;
    karbar *morednazar = malloc(sizeof(karbar));
    while (right)
    {printf("chikar mikhay bokoni\n");
        char *whattodo=dynamicstring(whattodo);
        char login[] = "login";
        if (strcmp(whattodo, login) == 0)
        {
             char *shenaseChecker=dynamicstring(shenaseChecker);
             char *ramzChecker=dynamicstring(ramzChecker);
            morednazar = karbaryabande(khead, shenaseChecker, ramzChecker);
            printf("shomavaredshodi");
            if (morednazar == NULL)
            {
                printf("yeja dar vared kardan shenase ya ramz sooti dadi\n");
            }
        }
        char  logout[] ="logout";
        if ((strcmp(whattodo, logout) == 0) && (morednazar != NULL))
        {
             morednazar = NULL;
             printf("to kharej shodi az hesabet\n");
        }
         char signup[] = "signup";
        if (strcmp(whattodo, signup) == 0)
        {
             karbarezefekon(khead);
        }
         char info[] = "info";
        if ((strcmp(whattodo, info) == 0) &&(morednazar != NULL))
        {
            printer(morednazar,mhead);
        }
        char post[] = "post";
        if ((strcmp(whattodo, post) == 0) && (morednazar != NULL))
        {
            massagegozari(mhead, morednazar);
        }
         char like[] = "like";
        if ((strcmp(whattodo, like) == 0) && (morednazar != NULL))
        {
            char *sahebpayam=dynamicstring(sahebpayam);
            int id;
            scanf("%d",&id);
            liker(mhead, sahebpayam, id);
        }
         char find_user[] = "find_user";
        if (strcmp(whattodo, find_user) == 0)
        {
            char *fshenase=dynamicstring(fshenase);
            
            if(karbarfinder(khead, fshenase) != NULL)
            {
                printer(karbarfinder(khead, fshenase), mhead);
            }
        }
        char delete[] =  "delete";
        if ((strcmp(whattodo, delete) == 0) && (morednazar->shenase != NULL))
        {
             int id;
             scanf("%d", &id);
             deleter(mhead, morednazar, id);
        }
         if ((strcmp(whattodo, like) != 0) && (strcmp(whattodo,find_user) != 0) && (strcmp(whattodo, delete) != 0) && (strcmp(whattodo, post) != 0) && (strcmp(whattodo, info) != 0) && (strcmp(whattodo, login) != 0) && (strcmp(whattodo, signup) != 0) &&(strcmp(whattodo, logout) != 0))
        {
         printf("hamchindastori nadarim\n");
        }
        char *alaki=dynamicstring(alaki);
        printf("varedkon ta pak she\n");
        getch();
        system("cls");
        
    }

    


}

