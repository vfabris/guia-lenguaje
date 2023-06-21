#ifndef _PETICIONES_FS_H_
#define _PETICIONES_FS_H_

#include <commons/collections/list.h>
#include <pcb/pcb.h>
#include <sockets/sockets.h>
#include <instrucciones_fs/instrucciones_fs.h>


typedef struct 
{
    char*nombre;
    int* puntero;
    t_list* procesos_block;
    int tamanio;

}t_archivo;

t_list* tabla_global_archivos_abiertos;
extern t_pcb* pcb_exec; 
extern int socket_fs; 
#endif
