#include <Pixy.h>

// Function to read data from the Pixy camera and send it to the computer over the serial port
void readPixyData() {
    // Read the number of blocks detected by the Pixy camera
    int blocks = Pixy.getBlocks();

    // If at least one block is detected, extract the position and size of the first block
    if (blocks) {
        int width = Pixy.blocks[0].width;
        int height = Pixy.blocks[0].height;
        int centerX_ball = Pixy.blocks[0].x + Pixy.blocks[0].width / 2;
        int centerY_ball = Pixy.blocks[0].y + Pixy.blocks[0].height / 2;
        float angle = calculateAngle(centerX_ball, centerY_ball);
        int distance = caltulateDistance(centerY_ball, centerY_ball)

        // Send the position and size data to the computer over the serial port
        Serial.print("X: ");
        Serial.print(centerX_ball);
        Serial.print(" Y: ");
        Serial.print(centerY_ball);
        Serial.print(" Width: ");
        Serial.print(width);
        Serial.print(" Height: ");
        Serial.println(height);
    }
}
int calculateDistance(int centerX_ball, int centerY_ball) {
    int x_diff = centerX_ball - centerX_image;
    int y_diff = centerY_ball - centerY_image;
    int distance = sqrt(x_diff*x_diff + y_diff*y_diff);
    return distance;
}

float calculateAngle(int centerX_ball, int centerY_ball) {
    int x_diff = centerX_ball - centerX_image;
    int y_diff = centerY_ball - centerY_image;
    float angle = atan2(y_diff, x_diff) * 180.0 / PI;
    return angle;
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
