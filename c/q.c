#include "q.h"

void warn(char* s)
{
	fprintf(stderr, "warning: %s\n", s);
}

int init_queue()
{
	int queue_id;

	if((queue_id = msgget(QKEY, IPC_CREAT | QPERM)) == -1)
		perror("msgget failed");

	return queue_id;
}

int enter(char *objname, int priority)
{
	int len, s_qid;;
	struct q_entry s_entry;

	if((len = strlen(objname)) > MAXOBN)
	{
		warn("name too long");
		return -1;
	}

	if(priority > MAXPRIOR || priority < 0)
	{
		warn("invalid priority level");
		return -1;
	}

	if((s_qid = init_queue()) == -1)
		return -1;

	s_entry.mtype =(long) priority;
	strncpy(s_entry.mtext, objname, MAXOBN);

	if(msgsnd(s_qid, &s_entry, len, 0) == -1)
	{
		perror("msgsnd failed");
		return 1;
	}
	else
		return 0;
}

void proc_obj(struct q_entry* q_entry)
{
	printf("\npriority %ld name: %s\n", q_entry->mtype, q_entry->mtext);
}

int serve()
{
	int mlen, r_qid;
	struct q_entry r_entry;

	if((r_qid = init_queue()) == -1)
		return -1;

	for(;;)
	{
		if((mlen = msgrcv(r_qid, &r_entry, MAXOBN, (-1 * MAXPRIOR), MSG_NOERROR)) == -1)
		{
			perror("msgrcv failed");
			return -1;
		}
		else
		{
			r_entry.mtext[mlen] = '\0';
			proc_obj(&r_entry);
		}
	}
}
