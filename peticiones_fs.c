#include <peticiones_fs.h>

void inicializar_tabladearchivos_globales(){

    tabla_global_archivos_abiertos=list_create();

}
bool corroborar_tablaglobal_archivos(char*archivo){
    
    for (int i=0; i<list_size(tabla_global_archivos_abiertos);i++){
        t_archivo* archivoActual = list_get(tabla_global_archivos_abiertos, i);
        if(strcmp(archivoActual->nombre ,archivo)) return true;
    }
   
    return false;
}

void agregar_a_tablaArchivosP(char* archivo){
    t_archivo* archivoActual = archivo_asociado(archivo);
    list_add(pcb_exec->tabla_de_archivos,archivoActual);
        
    }

t_archivo* archivo_asociado(char* archivo){
   for (int i=0; i<list_size(tabla_global_archivos_abiertos);i++){
        t_archivo* archivoActual = list_get(tabla_global_archivos_abiertos, i);
         if(strcmp(archivoActual->nombre ,archivo)){
            
           return archivoActual;
         } 
}
}
void agregar_a_procesosBlock(char* archivo){
    t_archivo* archivo_abierto= archivo_asociado(archivo);
    list_add(archivo_abierto->procesos_block,pcb_exec);
}

bool preguntar_fs_existenciaArch(char* archivo, int pid){

    t_paquete* paquete= crear_paquete(INSTRUCCIONES_FS);

    id_instruccion_fs codigo = ABRIR;
    t_archivo* archivoBuscado = archivoBuscado;
    int tamanio = archivoBuscado->tamanio ;
    agregar_a_paquete(paquete, &codigo, sizeof(id_instruccion_fs));
    agregar_a_paquete(paquete, &pid, sizeof(pcb_exec->contexto_ejecucion->id));
    agregar_a_paquete(paquete, &tamanio, sizeof(int));
    enviar_paquete(paquete, socket_fs);

    

    /*
    codigo instrucc->id_instruccion_fs
    pid del proceso que se esta ejecutando-> lo saco del contexto
    longitud ->tamaño archivo 
    id_archivo-> nombre archivo
    */
}
