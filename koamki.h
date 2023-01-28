#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef struct member karbar;
typedef struct Messages messages;
struct Messages
{
    int id;
    int like;
    char *matn;
    char *m_shenase;
    messages*next_massge;
} ;
  struct member
{
    char *shenase;
    char *ramz;
    int tedadpayam;
    karbar *karbarbadi;
};
karbar* karbarfinder(karbar *khead, char cshenase[]);
char* dynamicstring(char *stringp);
void karbarezefekon (karbar* khead);
void massagegozari(messages *mhead, karbar*morednazar);
void printer(karbar *you, messages *phead);
void deleter(messages *mhead, karbar*mored, int id);
karbar* karbaryabande(karbar *karbarvaredshode,char*shenasevaredshode,char* ramzvaredshode);
void liker(messages *mhed, char* sahebpayam, int p_id);