priority message queue

- position important

-> incorrect
struct q_entry
{
  char mtext[50];
  long mtype;
}

-> correct
struct q_entry
{
  long mtype;
  char mtext[50];
}
