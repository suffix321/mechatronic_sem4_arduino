#include <Pixy.h>

Pixy2 pixy;

// Color signatures
const uint16_t yellowSignature = 1;
const uint16_t redSignature = 2;

// Target color
uint16_t targetColor = yellowSignature;

// Ball position
int ballX, ballY;


// Function to read data from the Pixy camera and send it to the computer over the serial port
void readPixyData() {
    // Get block data for target color
    pixy.ccc.getBlocks();
    int numBlocks = pixy.ccc.numBlocks;

    // If no blocks detected, return
    if (numBlocks == 0) {
        return;
    }

    // Search for target color
    for (int i = 0; i < numBlocks; i++) {
        if (pixy.ccc.blocks[i].signature == targetColor) {
            ballX = pixy.ccc.blocks[i].x;
            ballY = pixy.ccc.blocks[i].y;
            break;
        }
    }

    // If target color not found, return
    if (ballX == 0 && ballY == 0) {
        Serial.print("target Color not found")
        return;
    }

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
