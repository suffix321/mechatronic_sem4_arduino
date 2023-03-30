#include <Pixy.h>

// Function to read data from the Pixy camera and send it to the computer over the serial port
void readPixyData() {
    // Read the number of blocks detected by the Pixy camera
    int blocks = Pixy.getBlocks();

    // If at least one block is detected, extract the position and size of the first block
    if (blocks) {
        int x = Pixy.blocks[0].x;
        int y = Pixy.blocks[0].y;
        int width = Pixy.blocks[0].width;
        int height = Pixy.blocks[0].height;
        int centerX = x + width / 2;
        int centerY = y + height / 2;

        // Send the position and size data to the computer over the serial port
        Serial.print("X: ");
        Serial.print(centerX);
        Serial.print(" Y: ");
        Serial.print(centerY);
        Serial.print(" Width: ");
        Serial.print(width);
        Serial.print(" Height: ");
        Serial.println(height);
    }
}

void setup() {
    // Initialize the serial port and the Pixy camera
    Serial.begin(9600);
    Pixy.init();
}

void loop() {
    // Call the readPixyData function to read data from the Pixy camera and send it to the computer
    readPixyData();
}
