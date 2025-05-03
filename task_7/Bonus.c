#include <stdio.h>
#include <string.h>

union SensorValue {
    int temperature;
    float pressure;
    char status;
};

typedef struct {
    int sensorID;
    char *sensorType;
    union SensorValue data;
} SensorData;

void printSensorData(SensorData sensor) {
    printf("Sensor ID: %d\n", sensor.sensorID);
    printf("Sensor Type: %s\n", sensor.sensorType);
    if (strcmp(sensor.sensorType, "Temperature") == 0) {
        printf("Temperature: %d\n", sensor.data.temperature);
    } else if (strcmp(sensor.sensorType, "Pressure") == 0) {
        printf("Pressure: %f\n", sensor.data.pressure);
    } else if (strcmp(sensor.sensorType, "Displacement") == 0) {
        printf("Status: %c\n", sensor.data.status);
    } else {
        printf("Invalid sensor type.\n");
    }
}

int main(){
    SensorData sd;
    sd.sensorID = 1;
    sd.sensorType = "Temperature";
    sd.data.temperature = 25;
    printSensorData(sd);
}