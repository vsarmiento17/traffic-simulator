#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;
 
// Estructura de vehículo
struct Vehicle {
    string licensePlate;
    int speed;   // Velocidad en km/h
    bool stopped;  // Indica si el vehículo está detenido
    float distanceTravelled;  // Distancia total recorrida en km
 
    Vehicle(string plate, int s) : licensePlate(plate), speed(s), stopped(false), distanceTravelled(0.0) {}
};
 
// Función del Insertion Sort
void insertionSort(vector<Vehicle>& vehicles) {
    int n = vehicles.size();
    for (int i = 1; i < n; i++) {
        Vehicle key = vehicles[i];
        int j = i - 1;
        // Desplazar los vehículos con mayor prioridad a la derecha
        while (j >= 0 && vehicles[j].speed > key.speed) {
            vehicles[j + 1] = vehicles[j];
            j--;
        }
        // Colocar el vehículo clave en su posición correcta
        vehicles[j + 1] = key;
    }
}
 
// Función para mostrar cambios de velocidad
void displaySpeedChange(int oldSpeed, int newSpeed, const string& vehiclePlate) {
    if (newSpeed > oldSpeed) {
        cout << vehiclePlate << " incrementa su velocidad a " << newSpeed << " km/h." << endl;
    } else if (newSpeed < oldSpeed) {
        cout << vehiclePlate << " disminuye su velocidad a " << newSpeed << " km/h." << endl;
    }
}
 
// Función para mostrar la distancia total recorrida
void displayDistance(const Vehicle& vehicle) {
    cout << vehicle.licensePlate << " ha recorrido un total de " << vehicle.distanceTravelled << " km." << endl;
}
 
// Simula el comportamiento del vehículo
void simulateVehicleMovement(Vehicle& vehicle) {
    int initialSpeed = vehicle.speed; // Guardamos la velocidad inicial del vehículo
    cout << vehicle.licensePlate << " está comenzando a moverse a " << vehicle.speed << " km/h." << endl;
 
    // El vehículo se detiene por un semáforo o por un vehículo adelante
    if (rand() % 2 == 0) {  // 50% chance que el coche se detenga
        vehicle.stopped = true;
        vehicle.speed = 0;  // Detiene el vehículo
        cout << vehicle.licensePlate << " se detiene debido a un semáforo o carro adelante." << endl;
        displaySpeedChange(initialSpeed, vehicle.speed, vehicle.licensePlate);
    } else {
        // Si no se detuvo, el vehículo continúa
        int newSpeed = rand() % 50 + 30;  // Cambia su velocidad aleatoriamente entre 30 y 80 km/h
        displaySpeedChange(initialSpeed, newSpeed, vehicle.licensePlate);
        vehicle.speed = newSpeed;
    }
}
 
// Pregunta al usuario si quiere reanudar la marcha
bool askToResume(const Vehicle& vehicle) {
    char choice;
    cout << "\nEl vehículo " << vehicle.licensePlate << " está detenido.\n";
    cout << "¿Deseas que el vehículo reanude su marcha? (s/n): ";
    cin >> choice;
    if (choice == 's' || choice == 'S') {
        return true;
    }
    return false;
}
 
// Preguntar al usuario si quiere continuar manejando el vehículo
bool askIfWantsToDrive() {
    char choice;
    cout << "\n¿Quieres continuar manejando el vehículo? (s/n): ";
    cin >> choice;
    if (choice == 's' || choice == 'S') {
        return true;
    }
    return false;
}
 
// Función para simular el paso de los vehículos por el cruce
void simulateTraffic(queue<Vehicle>& vehicleQueue) {
    vector<Vehicle> vehicles;
    // Transferir los vehículos de la cola al vector para ordenarlos
    while (!vehicleQueue.empty()) {
        vehicles.push_back(vehicleQueue.front());
        vehicleQueue.pop();
    }
    // Ordenar los vehículos por velocidad usando el Insertion Sort
    insertionSort(vehicles);
    // Mostrar los vehículos ordenados por velocidad
    cout << "\nVehículos ordenados por velocidad de salida:" << endl;
    for (const auto& v : vehicles) {
        cout << "Placa: " << v.licensePlate << ", Velocidad: " << v.speed << " km/h" << endl;
    }
    // Simulando el movimiento y detención del vehículo
    cout << "\nSimulando salida del vehículo..." << endl;
    for (auto& v : vehicles) {
        simulateVehicleMovement(v);
        // Si el vehículo se detuvo, preguntamos al usuario si lo quiere hacer continuar
        while (v.stopped) {
            if (askToResume(v)) {
                v.stopped = false;
                v.speed = rand() % 50 + 30; // Asignamos una nueva velocidad aleatoria
                displaySpeedChange(0, v.speed, v.licensePlate);
                break;
            } else {
                // Si el usuario no desea continuar, el vehículo sigue detenido
                cout << v.licensePlate << " permanece detenido." << endl;
                this_thread::sleep_for(chrono::seconds(1));  // Espera de 1 segundo
            }
        }
 
        // Mostrar la distancia recorrida
        v.distanceTravelled += v.speed / 60.0;  // Calculamos la distancia (en km) en 1 minuto
        displayDistance(v);
        // Preguntamos si el usuario quiere seguir manejando
        if (askIfWantsToDrive()) {
            cout << v.licensePlate << " continúa manejando." << endl;
        } else {
            cout << v.licensePlate << " se detiene por decisión del usuario." << endl;
            break;  // El vehículo se detiene si el usuario decide no continuar
        }
 
        // Simulamos el paso del tiempo para que el programa no imprima de inmediato
        this_thread::sleep_for(chrono::seconds(1));  // Espera de 1 segundo entre cada acción
    }
}
 
void simulateTrafficLight(stack<Vehicle>& vehicleStack) {
    if (!vehicleStack.empty()) {
        Vehicle vehicle = vehicleStack.top();
        // Simulamos el estado del semáforo
        string lightState = (rand() % 2 == 0) ? "rojo" : "verde";
        cout << "El semáforo está en " << lightState << ".\n";
 
        // Si el semáforo está en rojo, el vehículo se detiene
        if (lightState == "rojo") {
            vehicle.stopped = true;
            vehicle.speed = 0;  // Detiene el vehículo
            cout << vehicle.licensePlate << " se detiene debido al semáforo en rojo.\n";
        } else {
            // Si el semáforo está en verde, el vehículo sigue
            vehicle.stopped = false;
            vehicle.speed = rand() % 50 + 30; // Asignamos una nueva velocidad aleatoria
            cout << vehicle.licensePlate << " sigue moviéndose.\n";
        }
 
        // Mostrar cuando el semáforo se vuelve verde
        if (lightState == "verde") {
            cout << "El semáforo se vuelve verde, el vehículo puede continuar su marcha.\n";
        }
    }
}
int main() {
    srand(time(0));  // Inicializar la semilla para números aleatorios
 
    queue<Vehicle> vehicleQueue;  // Cola para almacenar los vehículos
    stack<Vehicle> vehicleStack;  // Pila para simular el comportamiento de los vehículos
    // Agregar un vehículo a la cola
    vehicleQueue.push(Vehicle("LXY290", 60));
 
    // Mostrar los vehículos en la cola antes de la simulación
    cout << "Vehículos en la cola:" << endl;
    queue<Vehicle> tempQueue = vehicleQueue;
    while (!tempQueue.empty()) {
        Vehicle v = tempQueue.front();
        cout << "Placa: " << v.licensePlate << ", Velocidad: " << v.speed << " km/h" << endl;
        tempQueue.pop();
    }
    // Simular el paso de los vehículos por el cruce
    simulateTraffic(vehicleQueue);
 
    // Transferir el vehículo de la cola a la pila para simular un cruce
    while (!vehicleQueue.empty()) {
        vehicleStack.push(vehicleQueue.front());
        vehicleQueue.pop();
    }
    // Simular el cruce con semáforo
    simulateTrafficLight(vehicleStack);
    return 0;
}
