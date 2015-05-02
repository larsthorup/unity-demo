typedef struct CounterStruct *Counter;

void Counter_Create(Counter);

void Counter_Increment(Counter);

long Counter_Exchange(Counter, long);

