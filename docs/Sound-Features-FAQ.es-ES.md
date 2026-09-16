# Funciones de audio: preguntas y respuestas

Complemento de la [guía de uso](README.es-ES.html). No se necesita clave API.

## ¿Qué herramienta conviene usar?

La **consola de volumen** regula ganancia, monitorización y salida de programa. **Audible Meter** emite avisos y lee mediciones. **Sound Doctor** realiza una sesión y propone filtros. Los dos últimos no pueden funcionar simultáneamente.

Todos trabajan localmente con estadísticas de tamaño limitado en memoria. No graban ni transmiten audio ni guardan historial de mediciones o informes. Sí conservan preferencias y exclusiones de entrada.

## ¿Qué significan los valores?

Los dB de la consola son la ganancia del control: 0 dB no altera el nivel; valores negativos lo reducen. No son una medición de sonoridad.

Los picos describen máximos breves. RMS representa la energía del audio y sirve para niveles típicos y variación dinámica. En dBFS, cuanto más cerca de 0, mayor nivel. Pre-fader significa antes del control OBS; post-fader, después. Bajar ese control no repara distorsión ya presente en la entrada.

## ¿Por qué JAWS dice el volumen anterior?

Su gestión de flechas puede leer el número antiguo antes de que el complemento anuncie el resultado correcto con «dB». En la prueba comunicada, Insert+3 seguido de la flecha eliminó el anuncio antiguo. El ajuste funciona correctamente. El problema se remite a Vispero; la confirmación explícita sigue disponible para JAWS y NVDA.

## ¿Cuándo suenan los tonos?

Los avisos automáticos de salida dependen del tiempo acumulado sobre un umbral. Valores predeterminados: 1,5 segundos y el límite rojo OBS, −9 dBFS con pico de muestra o −2 dBFS con pico real. Bajadas inferiores a un segundo no reinician completamente la exposición; un segundo bajo el umbral prepara un nuevo aviso.

Con Audible Meter activo, la consola responde al instante: tono medio en amarillo y agudo en rojo. Límites amarillo/rojo: −20/−9 dBFS con pico de muestra; −13/−2 dBFS con pico real. Verde, falta de señal o fuente y foco fuera de sus controles no producen tono.

El tono grave guía una corrección de entrada aceptada mientras el audio sigue rojo antes del control. Fuente multimedia y Fuente de vídeo VLC no generan avisos pre-fader.

## ¿Puedo silenciar avisos y seguir midiendo?

Sí. I alterna avisos de entrada y salida mientras Audible Meter está activo. Reactivarlos inicia un nuevo cómputo de exposición. Los tonos de consola y H/J/K/L continúan disponibles. Estas letras nunca se interceptan en campos de edición.

H anuncia nivel y zona actuales de la fuente elegida; J, la más fuerte ahora. K da el RMS activo típico de la elegida durante la sesión; L identifica la fuente con mayor nivel típico. La selección corresponde a la última fuente enfocada en la consola.

## ¿Cómo funciona la reducción solicitada?

Pulse Mayús+I durante un aviso de salida. Para cada fuente responsable, el objetivo es el umbral menos el margen. Se usa el mayor pico observado en el incidente, se redondea la reducción hacia arriba a pasos de 0,5 dB y se limita al máximo configurado. Nunca aumenta ganancia ni actúa solo por un aviso pre-fader.

Los valores iniciales son margen de 3 dB y reducción máxima de 12 dB. Protege picos, pero no equilibra por usted voz, música y efectos.

Ctrl+Mayús+I restaura solo controles que aún coinciden con el valor corregido. Iniciar o detener Audible Meter, cambiar de colección de escenas o guardar ajustes del medidor borra ese único nivel de restauración.

## ¿Por qué tiene prioridad la guía de entrada?

La distorsión anterior al control debe corregirse en el origen. El primer diálogo es silencioso. Sí inicia la guía; No o Escape guarda una exclusión para esa fuente sin cambios. Una señal activa sana mantenida resuelve el incidente. Cambiar identidad o ajustes provoca una evaluación nueva.

El silencio no equivale a éxito. Se avisa a los 2 y 12 segundos sin señal y se pregunta a los 22. Continuar espera señal sin repetir esa secuencia. Confirme el mensaje de éxito antes de reanudar otros avisos.

La consola pausa el tiempo de avisos de salida y deja pendientes los de entrada. Audio activo sano elimina un problema ya resuelto; el silencio lo conserva. Cerrar la consola presenta primero los problemas de entrada vigentes.

## ¿Qué se puede configurar en Audible Meter?

En **Herramientas de audio > Ajustes avanzados de audio > Audible Meter**:

- Umbral de salida: −30 a 0 dBFS; el valor inicial depende del modo de pico OBS.
- Exposición: 0,1–30 segundos; inicial 1,5 segundos.
- Margen: 0–12 dB; inicial 3 dB.
- Reducción máxima: 0,5–30 dB; inicial 12 dB.
- Exclusiones pre-fader: eliminar una para volver a comprobar esa entrada.

No cambian las zonas de consola, H/J/K/L ni el límite rojo de entrada. Solo hay un modo sin ventana. Aplicar guarda; Aceptar guarda y cierra; Cancelar descarta desde el último Aplicar.

## ¿Cuánto necesita Sound Doctor?

Al menos 120 segundos, con 45 segundos de audio activo por fuente para recomendar procesamiento. Son duraciones fijas. La medición puede continuar mientras se transmite o graba; los resultados esperan a que ambas actividades terminen. Use sonidos representativos. El programa no comprende palabras ni distingue con fiabilidad música y voz.

## ¿Cuándo recomienda compresión?

La fuente debe ser una probable entrada en directo, tener suficiente audio activo, no haber cambiado y no contener compresor ni limitador, aunque estén desactivados. La diferencia dinámica debe alcanzar el mínimo configurado, inicialmente 8 dB.

La diferencia se calcula entre mediana RMS activa y percentil 95. El RMS se corrige según la ganancia del control OBS. El compresor nuevo sigue al procesamiento existente y precede a un limitador nuevo seleccionado.

El umbral es mediana más 5 dB, redondeado y limitado entre −24 y −10 dB. Ataque: 6 ms; liberación: 100 ms; ganancia de salida: 0 dB. Relación: 2:1 con diferencia inferior a 10 dB, 2,5:1 desde 10 hasta menos de 14 dB, y después el máximo configurado. Comprima música solo si desea ese efecto.

## ¿Cuándo recomienda un limitador?

Por defecto, en probables entradas en directo suficientemente activas, sin cambios y sin limitador. No exige saturación observada: es preventivo. El nuevo limitador cierra la cadena con techo inicial de −3 dBFS y liberación de 60 ms. No repara distorsión anterior ni garantiza que la mezcla total no se sobrecargue.

El alcance puede incluir todas las fuentes activas; un medio ya masterizado quizá no lo necesite. Ambas recomendaciones son independientes. El informe también explica filtros existentes, limitadores no situados al final, picos de entrada repetidos próximos a saturación y datos insuficientes o caducados.

## ¿Qué ajustes tiene Sound Doctor?

- Diferencia dinámica mínima: 6–15 dB; inicial 8 dB.
- Relación máxima: 2,5:1, 3:1 o 3,5:1; inicial 3:1. Puede recomendar valores menores.
- Alcance del limitador: probables entradas en directo o todas las fuentes activas.
- Techo: −12 a −1 dBFS; inicial −3 dBFS.

## ¿Puede cambiar algo sin aprobación?

No. Ninguna recomendación empieza marcada. Finalizar aplica solo las elegidas tras revisar fuente, volumen y filtros. Omite fuentes modificadas. Escape cierra sin cambios. Los filtros nuevos permiten Deshacer y Rehacer de OBS.

Ctrl+Mayús+D puede interrumpir y descartar la medición tras confirmar. No o Escape continúa. La opción de recordar puede suprimir esa confirmación.
