   case F_OPEN_:

        char* archivo = (char *)malloc(strlen((instruccion_actual())->parametros[0]) + 1); // asigno memoria
        strcpy(archivo, (instruccion_actual())->parametros[0]);//meto en el espacio de memoria que asigne
        if (corroborar_tablaglobal_archivos(archivo)){
        //agregar archivo a tabla de archivos abiertos del proceso
        //agregar_a_tablaArchivosP(archivo);
        //despues bloquear el proceso 
        agregar_a_procesosBlock(archivo);

        }
        else{
            //tengo que preguntar a fs si existe el archivo
            preguntar_fs_existenciaArch(archivo, id_pcb_actual());
            //no existe le pido al fs que me cree un nuevo archivo de tam 0 y sigue como existiera 
            //si existe lo agrego a la tabla global y tabla del proceso 

            enviar_contexto(pcb_exec->contexto_ejecucion, socket_cpu, CONTEXTO_EJECUCION);
        }
      
