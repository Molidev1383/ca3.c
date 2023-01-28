#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "koamki.h"
typedef struct member karbar;
typedef struct Messages messages;
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
void deleter(messages *mhead, karbar*mored, int id){

    messages *prv = mhead;
    messages *feli = mhead;
    if (feli->next_massge == NULL)
    {
        printf("eshteba kardi!dobare emtehan kon\n");
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

}
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
    
}
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




