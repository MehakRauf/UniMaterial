#include <GL/glut.h>
#include <cmath>

// Coefficients for each polynomial equation
// Degree 1: y = ax + b
float a1 = 0.5f;
float b1 = -2.0f;

// Degree 2: y = ax^2 + bx + c
float a2 = 0.01f;
float b2 = -0.1f;
float c2 = -1.0f;

// Degree 3: y = ax^3 + bx^2 + cx + d
float a3 = 0.001f;
float b3 = 0.02f;
float c3 = -0.1f;
float d3 = 0.5f;

// Function to calculate the y-value for a linear polynomial
float linearPolynomial(float x) {
    return a1 * x + b1;
}

// Function to calculate the y-value for a quadratic polynomial
float quadraticPolynomial(float x) {
    return a2 * x * x + b2 * x + c2;
}

// Function to calculate the y-value for a cubic polynomial
float cubicPolynomial(float x) {
    return a3 * x * x * x + b3 * x * x + c3 * x + d3;
}

// Function to draw the polynomial curve
void drawPolynomialCurve(float (*polynomialFunction)(float)) {
    glBegin(GL_LINE_STRIP); // Use GL_LINE_STRIP to draw a continuous curve

    for (float x = -10.0f; x <= 10.0f; x += 0.1f) {
        float y = polynomialFunction(x);
        glVertex2f(x, y);
    }

    glEnd();
}

// Function to draw reference lines (horizontal and vertical axes)
void drawReferenceLines() {
    glBegin(GL_LINES);

    // Draw horizontal line (x-axis)
    glVertex2f(-10.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);

    // Draw vertical line (y-axis)
    glVertex2f(0.0f, -10.0f);
    glVertex2f(0.0f, 10.0f);

    glEnd();
}

// Display function
void display() {
    // Clear the screen with a white background
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw reference lines (axes) in black
    glColor3f(0.0, 0.0, 0.0);
    drawReferenceLines();

    // Draw the Degree 1 (Linear) curve in lime green
    glColor3f(0.0, 1.0, 0.0);
    drawPolynomialCurve(linearPolynomial);

    // Draw the Degree 2 (Quadratic) curve in orange
    glColor3f(1.0, 0.5, 0.0);
    drawPolynomialCurve(quadraticPolynomial);

    // Draw the Degree 3 (Cubic) curve in sky blue
    glColor3f(0.0, 0.5, 1.0);
    drawPolynomialCurve(cubicPolynomial);

    // Flush the drawing to the screen
    glFlush();
}

// Initialization function
void init() {
    // Set the background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // Set up the projection (orthographic projection in this case)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0); // Smaller visible area for a compact view

    // Switch to model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Set the window size
    glutCreateWindow("Polynomial Curves with Reference Lines"); // Create the window with a title

    // Call the initialization function
    init();

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the GLUT main loop
    glutMainLoop();
    return 0;
}
