# Accessible Studio: guía de uso

Accessible Studio añade navegación por teclado, avisos hablados, herramientas de audio y análisis visual opcional a OBS Studio en Windows. Está pensado para personas ciegas que utilizan JAWS o NVDA. Las [preguntas sobre audio](Sound-Features-FAQ.es-ES.html) explican las mediciones y los filtros.

## Instalar, actualizar y desinstalar

Se necesitan Windows 10 u 11 y OBS Studio 32.x, ambos de 64 bits. Solo el análisis visual y de compatibilidad requiere una clave API de OpenAI. El audio y los atajos funcionan sin ella.

1. Instale OBS desde su [página oficial](https://obsproject.com/download).
2. Cierre OBS y ejecute el instalador de la versión de Accessible Studio que haya recibido.
3. Siga las indicaciones. Si faltan WebView2 o el entorno de ejecución de Visual C++, se descargarán de Microsoft; para ello hace falta Internet.
4. Abra OBS y vaya a **Herramientas > Accessible Studio**.

El instalador se detiene si OBS no está instalado, está dañado o es anterior a 32.0. Con OBS 33 o posterior, advierte de posibles incompatibilidades y ofrece la [versión más reciente del complemento](https://github.com/tifloinfo/accessible-studio/releases/latest). Instalar de todos modos no garantiza compatibilidad. El instalador pide cerrar OBS; no lo termina por la fuerza.

Los archivos se guardan en `C:\ProgramData\obs-studio\plugins\accessible-studio`. No se sustituyen archivos de OBS o Qt ni se crean accesos directos en el escritorio. La última página permite abrir el manual.

**Migración desde Accessible OBS Studio 1.0:** se elimina el complemento antiguo con sus ajustes propios, atajos, caché y clave API. El resto de ajustes y contenidos de OBS se conserva. Las actualizaciones dentro de Accessible Studio 1.1.x mantienen los ajustes y la clave.

Para desinstalar, cierre OBS y quite Accessible Studio desde las aplicaciones instaladas de Windows. Los ajustes y la clave se conservan. Si quiere borrar la clave, hágalo antes desde su administración en el complemento.

## Encontrar comandos y ayuda

En **Herramientas > Accessible Studio**, las herramientas de audio incluyen la consola de volumen, Audible Meter, Sound Doctor y los ajustes avanzados de audio. Las herramientas de vídeo incluyen descripciones, lectura de texto, personas y fondos, comprobación visual y administración de claves API.

También encontrará el editor de atajos y el manual. El manual se abre en el navegador en el idioma de OBS, si está disponible; de lo contrario, en inglés.

## Atajos predeterminados

Los conflictos existentes o sus propias asignaciones pueden cambiar estos atajos.

### Navegación

- F6 / Mayús+F6: área principal siguiente / anterior.
- Ctrl+0: vista previa de vídeo.
- Ctrl+1: escenas.
- Ctrl+2: fuentes.
- Ctrl+3: mezclador de audio.
- Ctrl+4: transiciones de escena.
- Ctrl+5: controles.
- Ctrl+M: controles multimedia visibles.
- Alt+1 a Alt+9: primeras nueve escenas en el orden mostrado; Alt+0: décima escena.

Cuando NVDA es el único lector detectado, se añade un anuncio con el nombre del área. El mezclador nativo conserva el comportamiento habitual de OBS.

### Salidas y audio

- F5: iniciar o detener la transmisión.
- F7: iniciar o detener la grabación, aunque esté en pausa.
- Alt+F7: pausar o reanudar si la configuración de OBS lo permite.
- F8: iniciar o detener la cámara virtual.
- Alt+F2: estado de salidas y modo Estudio; Intro o Escape cierra la ventana.
- Ctrl+Grave: consola de volumen. Se refiere a la tecla física justo debajo de Escape, independientemente de su símbolo.
- Ctrl+I: activar o desactivar Audible Meter.
- Ctrl+Mayús+D: iniciar o interrumpir Sound Doctor.

Se anuncian los cambios de estado completados y la desconexión y recuperación de la transmisión.

### Imagen

Estos comandos necesitan clave API e Internet. No es necesario enfocar la vista previa.

- F3: descripción breve, de hasta 80 caracteres.
- Mayús+F3: descripción detallada.
- Alt+F3: texto visible, sin traducción ni comentarios.
- Ctrl+F3: personas visibles y su entorno inmediato.
- F4: comprobación de composición y calidad visual.

## Cambiar atajos

Abra el editor, busque un comando y selecciónelo con las flechas. Intro o Añadir o editar abre la asignación. Pulse la combinación deseada y añada otras si las necesita. Confirme y elija **Aceptar en el editor principal** para guardar.

Si hay un conflicto, se identifica el comando y se pregunta si desea reasignar. Supr o Eliminar en la lista principal borra todas las asignaciones del comando seleccionado. Al cerrar con cambios pendientes puede guardar, descartar o volver. Las teclas de navegación y combinaciones reservadas del sistema no se capturan.

Si cambia el perfil, la colección de escenas o alguna asignación relevante mientras edita, el guardado puede rechazarse. Vuelva a abrir el editor.

De forma predeterminada, los atajos de OBS solo funcionan cuando OBS es la aplicación activa. Active y guarde la opción que permite a OBS gestionar los atajos fuera de la aplicación para usar su propio ajuste de foco.

Al iniciar o cambiar de perfil, un diálogo puede ofrecer conservar las asignaciones existentes o sustituir únicamente las combinaciones en conflicto. Conservarlas deja sin asignar los atajos predeterminados afectados. Recordar la decisión la aplica a todos los perfiles de esa compilación. La migración de valores predeterminados conserva las asignaciones personalizadas no vacías. El comando que abre directamente el menú del complemento no tiene atajo predeterminado.

## Ajustar volumen y escucha local

Ctrl+Grave abre la consola accesible. Los cambios son inmediatos.

- Izquierda / Derecha: fuente anterior / siguiente.
- Arriba / Abajo: subir / bajar 1 dB el control enfocado.
- Inicio: establecer 0 dB.
- 1 a 9 y después 0: seleccionar fuentes 1 a 10.
- Espacio: alternar juntas la monitorización y la salida de programa.
- Ctrl+Espacio: alternar solo la monitorización.
- Mayús+Espacio: alternar solo la salida de programa.
- Escape: cerrar y volver al control anterior de OBS.

La monitorización es la escucha local. La salida de programa llega a la transmisión o grabación. También hay botones independientes para ambas funciones.

Al principio se muestran fuentes activas del programa, no las exclusivas de la vista previa en modo Estudio. Active **Mostrar todas las fuentes** con Intro, no con Espacio, para incluir las inactivas. Izquierda y Derecha recorren todas, incluso después de la décima. La lista y los valores se actualizan dos veces por segundo.

El rango normal termina en 0 dB. Si otro control de OBS ya estableció ganancia positiva, se conserva ese rango. Desde OBS 32.2, silencio y monitorización son independientes; las versiones anteriores compatibles usan los estados antiguos de monitorización.

Tras Arriba o Abajo se anuncia el valor resultante en dB, incluso en los límites. Las pulsaciones rápidas agrupan anuncios pendientes; salir del control cancela los restantes.

**JAWS:** puede decir primero el número anterior y luego el complemento anuncia el correcto con «dB». El volumen cambia en la dirección correcta. En la prueba comunicada, Insert+3 seguido de la flecha evitó el anuncio antiguo. El problema se traslada a Vispero; la confirmación explícita en dB se mantiene para JAWS y NVDA.

## Audible Meter

Ctrl+I alterna un único modo sin ventana. Vigila fuentes activas incluso sin transmitir ni grabar. Empieza con avisos automáticos activados, no abre la consola por sí solo ni cambia filtros.

- I: alternar avisos automáticos de entrada y salida.
- H: nivel y zona actuales de la última fuente elegida en la consola.
- J: fuente más fuerte en este momento y su nivel.
- K: nivel activo típico de la fuente elegida durante la sesión.
- L: fuente con el mayor nivel activo típico.
- Mayús+I: durante un aviso de salida, solicitar una reducción prudente de las fuentes responsables.
- Ctrl+Mayús+I: restaurar la última reducción, excepto fuentes ajustadas después.

Las letras no se interceptan en campos de edición. H y K avisan si no se ha seleccionado una fuente.

### Interpretar los tonos

El **tono grave** indica que una entrada sigue demasiado alta antes del control OBS, después de aceptar corregirla. Baje la ganancia del dispositivo, la entrada de Windows o la aplicación de origen. El **tono medio** indica amarillo en la fuente enfocada de la consola. El **tono agudo** indica rojo en esa fuente o un aviso automático de salida. Verde, silencio, fuente no disponible o foco fuera de sus controles no producen tono.

Los tonos de la consola son inmediatos. Los avisos automáticos requieren un tiempo de exposición. I no desactiva los tonos de medición de la consola.

Un aviso de entrada abre primero un diálogo silencioso. Sí inicia la guía; No o Escape guarda una exclusión para esa fuente sin cambios. El silencio no demuestra recuperación: se anuncia la falta de señal y después se pregunta si desea continuar. Una señal activa sana mantenida termina la guía. Confirme el mensaje de éxito para reanudar otros avisos.

En la consola se pausa el tiempo de avisos de salida y se dejan pendientes los problemas de entrada. Al cerrarla se presentan los aún vigentes. Si intenta abrirla durante la guía de entrada, se pregunta si desea continuar; No guarda la exclusión y abre la consola.

Los ajustes avanzados permiten cambiar umbral, exposición, margen, reducción máxima y exclusiones. No cambian las zonas de la consola ni H/J/K/L. No hay modos adicionales, ventanas de historial ni archivos de informe.

## Sound Doctor

No puede funcionar al mismo tiempo que Audible Meter.

1. Pulse Ctrl+Mayús+D y confirme el inicio.
2. Produzca audio representativo durante al menos dos minutos. Cada fuente necesita 45 segundos de señal activa para recibir propuestas de filtros.
3. Detenga transmisión y grabación para ver los resultados. Hasta entonces la medición puede continuar.
4. Lea las propuestas y marque solo las deseadas; inicialmente ninguna está seleccionada.
5. Finalizar aplica lo seleccionado; Escape cierra sin cambios.

Un compresor puede reducir grandes variaciones en una entrada probablemente en directo. Un limitador protege contra picos futuros. El programa mide niveles, no comprende palabras ni distingue con fiabilidad música de voz. Seleccione compresión para música solo si desea ese efecto.

Antes de aplicar, se vuelven a comprobar fuentes y filtros. Las fuentes modificadas se omiten y no se duplica procesamiento existente. Un compresor nuevo sigue a los filtros existentes y precede al nuevo limitador final. Los filtros llevan nombres de Sound Doctor y admiten Deshacer y Rehacer de OBS.

Ctrl+Mayús+D vuelve a solicitar interrumpir y descartar la sesión. No o Escape continúa. Puede guardar la preferencia de omitir esa confirmación. Si el informe ya está abierto, el comando vuelve a él. El informe se oculta durante transmisión o grabación.

Los ajustes de Sound Doctor controlan las recomendaciones. Aplicar guarda; Aceptar guarda y cierra; Cancelar descarta cambios desde el último Aplicar. Consulte las [preguntas de audio](Sound-Features-FAQ.es-ES.html) para los valores.

## Desplazarse por archivos multimedia

Ctrl+M enfoca los controles visibles de una fuente reproducible. Izquierda/Derecha retrocede/avanza 5 segundos; Mayús+Izquierda/Derecha, un minuto; Re Pág/Av Pág, 5 minutos. Fuera de esos controles no se cambia el funcionamiento de las teclas.

## Describir y corregir imágenes

Guarde una clave en las herramientas de vídeo. Tras validarla, se almacena para su cuenta en el Administrador de credenciales de Windows. Nunca se muestra; un reemplazo fallido conserva la anterior. Borrarla requiere confirmación.

Un comando visual captura la imagen renderizada por OBS. Un clic confirma la solicitud. Los resultados aparecen en una ventana WebView2 accesible; cada respuesta nueva se anuncia una vez. Copiar el último resultado copia solo esa respuesta. Al cerrar se restaura el foco cuando corresponde.

Las preguntas relacionadas con la imagen y las descripciones ofrecidas reutilizan la conversación. Cerrar o iniciar una captura nueva la termina. Comprobar de nuevo envía una imagen nueva para comparar.

La comprobación visual analiza luz, encuadre, tamaño, desenfoque, ruido, capturas vacías y obstrucciones. No juzga contenido, opiniones ni ortografía. El texto se evalúa solo por su presentación visual. Los bordes y controles habituales de Zoom no bastan para afirmar que está en modo ventana.

Las correcciones propuestas permiten elegir una fuente de vídeo y una transformación con su riesgo. Con una sola fuente se omite su selección. Usted aprueba una corrección cada vez. No se ofrece estirar a pantalla completa ni controlar audio, salidas, credenciales, comandos arbitrarios o borrado de escenas.

Tras ajustar al lienzo, una comprobación adicional puede evaluar la calidad. Si es mala o incierta, solo se restauran las transformaciones guardadas y se centra la fuente cuando la escena y su estado siguen coincidiendo. No se ejecuta un Deshacer general que borre cambios hechos durante la espera. En modo Estudio se omite esta comprobación en línea porque vista previa y programa pueden diferir.

## Privacidad y compatibilidad

El análisis visual envía a OpenAI imagen, idioma de OBS, instrucciones y preguntas. El de compatibilidad envía versiones, dependencias y descripción de funciones. La clave autentica las solicitudes; no es contenido del análisis. Su propietario asume los costes API.

Con una versión principal de OBS posterior a las probadas, puede cancelar, continuar o analizar compatibilidad. La estimación combina comprobaciones locales de solo lectura e información oficial OBS a través de OpenAI; no garantiza compatibilidad. Un informe correcto se conserva para las versiones y arquitectura exactas y se copia al portapapeles.

Las herramientas de audio trabajan localmente sin grabar o transmitir audio ni guardar historial de mediciones. Conservan preferencias y exclusiones. No hay publicidad ni telemetría.

## Solución de problemas y licencia

Si falta el complemento, compruebe OBS de 64 bits y ciérrelo antes de reinstalar. Si falla un atajo, revise asignaciones, conflictos y foco. Los controles multimedia requieren una fuente reproducible. Repare WebView2 o reinstale con Internet si no se abren los resultados.

Accessible Studio es independiente: no está desarrollado, patrocinado ni respaldado por el proyecto OBS o sus colaboradores. OBS y OBS Studio son marcas registradas de Wizards of OBS LLC.

© 2026 [Tiflo.Info](https://tiflo.info). GNU GPL versión 2 o posterior; véase la [licencia](../LICENSE.txt). Nombres y logotipos tienen protección independiente. [English](README.en-US.html).
