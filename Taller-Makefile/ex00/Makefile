# Crear una variable
VARIABLE = Hola!
# Crear una regla para que ejecute un hello world
printf:
	echo $(VARIABLE)
# Crear un directorio y un archivo
makeff:
	mkdir folder 
	touch folder/file
# Establecer el contenido de un archivo (sobreescribir)
write:
	echo "Hello World!" > folder/file
# Añadir contenido a un archivo (sin sobreescribir)
append:
	echo "Hello World!" >> folder/file
# Mostrar el contenido de un archivo
show:
	cat folder/file
# Limpiar los archivos y directorios creados
rm:
	rm -rf folder
# Ejecutar clean y luego create
re: rm  makeff
# Declarar PHONY
.PHONY: printf makeff write append show rm re