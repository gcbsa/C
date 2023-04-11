//Error code definitions
#define SUCCESS 0;
#define FAIL -1;
#define INVALID_POINTER -2;
#define OUT_OF_MEMORY -3;

//Type definition
typedef struct list List;

//Base operations
List * create();
int destroy(List * list);
int empty(List * list);

//Handle operations
int insert(List * list, int position, int element);
int alter(List * list, int position, int element);
int exclude(List * list, int position);
int reverse(List * list);
int sort(List * list); //todo

//Fetch operations
int retrieve(List * list, int position, int * element);
int search(List * list, int * position, int element);
int len(List * list);
int min(List * list, int * element);
int max(List * list, int * element);

//View operations
int print(List * list);
