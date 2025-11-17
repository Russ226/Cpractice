#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

void test(){
    printf("this is a test \n");
}

struct Registery{
    char* name;
    void *function;
    struct Registery *next;
};

struct RegisteryList{
    struct Registery *head;
    struct Registery *tail;

}

//if you want to create an empty registry node both name and func have to empty 
struct Registery *create_registery_node(char *n, void *f){
    if(!((n == NULL && f == NULL) || (n != NULL && f != NULL))){
        printf("Error function name and function pointer must either not null or both null\n");
        return NULL;
    }
    struct Registery ret_item = malloc(sizeof(struct Registery));
    if(ret_item == NULL){
        printf("Error unable to allocate memory to create a new entry in the funcs list\n");
        return NULL;
    }

    if(n != NULL && f != NULL){
        ret_item->name = n;
        ret_item->function = f;
    }else{
        ret_item->name = NULL;
        ret_item->function = NULL;
    }

    ret_item->next = NULL;
    return ret_item;
}

struct RegisteryList *create_function_registery(struct Registery *head){
    struct RegisteryList *ret_item = malloc(sizeof(struct RegisteryList));
     if(funcs = NULL){
        printf("Error unable to allocate new memory to create function registry list\n");
        return NULL;
    }
    ret_item->head = ret_item->tail = head;
    return ret_item;
}

void *dl_handler = NULL;
struct RegisteryList *funcs = NULL;

int function_table_init(char *lib_path){
    if(dl_handler != NULL){
        printf("Warning dl_handler no null clearing it\n");
        dlclose(dl_handler);
    }

    dl_handler = dlopen(lib_path, RTLD_LAZY);

    if(dl_handler == NULL){
        printf("Error failed to open %s", path);
        return -1;
    }

    return 0;
}

int add_function(char *func_name){
    if(dl_handler == NULL){
        printf("Error please call the init function first!\n");
        return -1;
    }
    
    if(func_name == NULL){
        printf("Error function look up name is null\n");
        return -1;
    }

    void *look_up_func = dlsym(dl_handler, func_name);
    if(look_up_func == NULL){
        printf("Error can not find function with name %s", func_name);
        return -1;
    }

    if(funcs == NULL){
        
        if(funcs = NULL){
            printf("Error unable create function registry\n");
            return -1;
        }
        
        struct Registery *new_node = create_registery_node(func_name, look_up_func);
        
        if(new_node == NULL){
            printf("Error unable create function registry while creating node\n");
            return -1;
        }
        
        funcs = create_function_registery(new_node);

        
    }else{
        struct Registery *new_node = create_registery_node(func_name, look_up_func);

        if(new_node == NULL){
            printf("Error unable to add new function to registery with name %s\n", func_name);
            return -1;
        }

        funcs->tail->next = new_node;
        funcs->tail = new_node;
    }

    return 0;

}

void destory_registery(){
    if(funcs != NULL){
        struct Registery cur = funcs->head;
        struct Registery next = funcs->head->next;

        if(next != NULL){
            while(next != NULL){
                free(cur->name);
                free(cur->function);
                free(cur);
                cur = next;
                next = cur->next;
            }
        }

        free(cur->name);
        free(cur->function);
        free(cur);
        free(funcs);
    }

    if(dl_handler != null){
        dlclose(dl_handler);
    }
}


int main(){
    struct Registery *t = malloc(sizeof(struct Registery));
    t->name = "testff";
    
    t->function = &test;

    ((void (*)(void))t->function)();
    return 0;
}