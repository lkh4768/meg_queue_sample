#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#define QKEY		(key_t)0105
#define QPERM		0660
#define MAXOBN		50
#define MAXPRIOR	10

struct q_entry
{
	long mtype;
	char mtext [MAXOBN - 1];
};

extern void warn(char*);
extern int init_queue();
extern int enter(char*, int);
extern void proc_obj(struct q_entry*);
extern int serve();
