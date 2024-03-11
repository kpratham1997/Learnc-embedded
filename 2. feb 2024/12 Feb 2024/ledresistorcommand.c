#include <stdio.h>

int main() {
    float forwardVoltage, forwardCurrent, supplyVoltage, resistorValue;
    int numLEDs;
    
    // Input values
    printf("Enter LED Forward Voltage (V): ");
    scanf("%f", &forwardVoltage);
    
    printf("Enter LED Forward Current (mA): ");
    scanf("%f", &forwardCurrent);
    
    printf("Enter Supply Voltage (V): ");
    scanf("%f", &supplyVoltage);

    printf("Enter Number of LEDs: ");
    scanf("%d", &numLEDs);
    
    // Calculate resistor value
    resistorValue = (supplyVoltage - (forwardVoltage * numLEDs)) / (forwardCurrent / 1000); // Convert current from mA to A
    
    // Display result
    printf("Resistor Value (ohms): %.2f\n", resistorValue);
    
    return 0;
}
