# traffic-simulator

Este es el proyecto asignado para la materia de Estructura de Datos I (II SEMESTRE).
Para empezar este proyecto, se importan las librerías que se utiizarán para este código. (Líneas 1 - 9)
Siguiente a esto,  se crea la estructura con los datos del vehículo: la placa (licensePlate), velocidad (speed), una variable para indicar si el vehículo se detuvo (stopped) y la distancia total recorrida (distanceTravelled). (Líneas 13 - 19)

Empezando por los métodos dentro del programa, se tiene el método de ordenamiento por inserción (insertionSort) que va a ingresar la cantidad de vehículos que se van a mover. En este caso, sólo se está trabajando con un (1) vehículo, entonces sólo se va a insertar éste dentro de la lista. Si llegase a introducir más de uno, con la variable local 'key' ordenará la lista en el orden correcto. (Líneas 23 - 37)
Lo que sigue es la función 'displaySpeedChange' para mostrar el cambio de velocidad. Aquí hay tres parámetros, dos de velocidad para comparar si sube o baja, y el puntero de la placa del carro. Se utilizan los métodos 'if' y 'else' para verificar si la velocidad sube o baja y mostrar un mnesaje dependiendo de la situación. (Líneas 40 - 46)

Sigue una función que muestra distancia recorrida del auto.(Lineas 49 - 51)
Viene la función que simula el movimiento del vehículo llamada 'simulateVehicleMovement.' Ésta usará los datos del vehículo como parámetros.  Se crea una variable local 'initialSpeed' usando como referencia la velocidad ingresada del struct de Vehicle. Luego, entra dos métodos: el 'if' para mostrar que el vehículo se detuvo y muestra un mensaje indicando que se detuvo en un semáforo; el 'else' para seguir avanzando y mostrará una nueva velocidad. (Líneas 54 - 70)
Esta es una función booleana para preguntar al usuario si quiere continuar. Si (if) el usuario decide continuar, ingresando "S" o "s", sigue el vehículo en marcha. (Líneas 73 - 84)

Esta es otra función booleana para continuar manejando el vehículo, similar a la anterior. La diferencia es que está cierra el programa. (Líneas 87 - 97)
Esta función llamada 'simulateTraffic' se encarga de ordenar los vehículos de manera correcta. De ahí muestra, como mensaje, los datos del carro introducido. Luego asigna una velocidad aleatoria en el 'if.' De lo contrario ('else'), el carro se detiene, y luego muestra la cantidad recorrida de ese tramo. (Líneas 100 - 152)
Sigue la función para mostrar el comportamiento de las luces. (Líneas 154 - 179)

Ahora, el main. En el main, se inicializa una semilla para asignar números aleatorios. Hay una pila, que sirve para simular el comportamiento del vehículo, y una cola para almacenar el vehículo. Se agrega el vehículo a la cola y se muestra la información del auto. Lo que seguiría serían las funciones que se explicaron anteriormente.
