# Librería Arduino GammaCorrection
La librería GammaCorrection implementa funciones para realizar la corrección gamma. La relación entre la intensidad aplicada mediante un PWM a un LED y la iluminación percibida es no lineal. Con la librería GammaCorrection podemos corregir los valores para que el comportamiento sea correcto.

Más información https://www.luisllamas.es/libreria-arduino-GammaCorrection/

## Instrucciones de uso

La librería GammaCorrection contiene funciones estáticas para la corrección gamma. Por tanto, no es necesario instanciar un objeto, simplemente llamamos a las funciones necesarias.

Se dispone de dos métodos. Correct8 usa una fórmula con aritmética de enteros para aproximar el resultado. La función CorrectTable8 emplea una tabla para la corrección. Por tanto, el método Correct8 ocupa menos memoria en de programa, mientras que la función CorrectTable8 es ligeramente más rápida y precisa. Por defecto, se recomienda emplear la función Correct8 salvo que sea necesario realizar una gran cantidad de cálculos.

Para su uso, indicamos el valor deseado de iluminación percibida, y la librería nos devuelve el PWM necesario. Por ejemplo, para bajar la intensidad un 80% introduciríamos 204 (255 * 0.8) en las funciones de corrección, y GammaCorrection nos devolvería el valor a introducir en el PWM (aprox. 137 en este ejemplo).

### Uso de GammaCorrection
```c++
	static uint8_t Correct8(uint8_t value);
	static uint8_t CorrectTable8(uint8_t value);
```

## Ejemplos
La librería GammaCorrection incluye los siguientes ejemplos para ilustrar su uso.

* GammaCorrection: Ejemplo que muestra el uso de Correct8.
```c++
#include "GammaCorrectionLib.h"

void setup() 
{
	Serial.begin(115200);
	pinMode(9, OUTPUT);

	auto value = 0;
	for (auto index = 0; index <= 255; index++)
	{
		value = GammaCorrection::Correct8(index);
		analogWrite(9, value);
		Serial.print(index);
		Serial.print("  ");
		Serial.println(value);
	}
}

void loop() 
{
}
```

* GammaCorrectionTable: Ejemplo que muestra el uso de CorrectTable8.
```c++
#include "GammaCorrectionLib.h"

void setup() 
{
	Serial.begin(115200);
	pinMode(9, OUTPUT);

	auto value = 0;
	for (auto index = 0; index <= 255; index++)
	{
		value = GammaCorrection::CorrectTable8(index);
		analogWrite(9, value);
		Serial.print(index);
		Serial.print("  ");
		Serial.println(value);
	}
}

void loop() 
{
}
```
