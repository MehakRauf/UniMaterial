#include <GL/glut.h>
#include <cmath>

// Control points for the Bézier curve
float ctrlPoints[4][2] = {
    { -80.0f, -80.0f }, // Start point
    { -30.0f, 100.0f }, // Control point 1
    { 30.0f, -100.0f }, // Control point 2
    { 80.0f, 80.0f }    // End point
};

// Function to calculate the Bézier curve point at a given t using De Casteljau’s algorithm
void calculateBezierPoint(float t, float& x, float& y) {
    float u = 1 - t;
    float tt = t * t;
    float uu = u * u;
    float uuu = uu * u;
    float ttt = tt * t;

    x = uuu * ctrlPoints[0][0]  // (1 - t)^3 * P0
        + 3 * uu * t * ctrlPoints[1][0] // 3 * (1 - t)^2 * t * P1
        + 3 * u * tt * ctrlPoints[2][0] // 3 * (1 - t) * t^2 * P2
        + ttt * ctrlPoints[3][0]; // t^3 * P3

    y = uuu * ctrlPoints[0][1]
        + 3 * uu * t * ctrlPoints[1][1]
        + 3 * u * tt * ctrlPoints[2][1]
        + ttt * ctrlPoints[3][1];
}

// Function to draw the Bézier curve
void drawBezierCurve() {
    glBegin(GL_LINE_STRIP); // Use GL_LINE_STRIP to draw a continuous curve

    for (float t = 0.0f; t <= 1.0f; t += 0.01f) {
        float x, y;
        calculateBezierPoint(t, x, y);
        glVertex2f(x, y);
    }

    glEnd();
}

// Function to draw the control points and the connecting lines
void drawControlPoints() {
    // Draw lines connecting control points
    glColor3f(0.8f, 0.8f, 0.8f); // Gray color
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 4; i++) {
        glVertex2f(ctrlPoints[i][0], ctrlPoints[i][1]);
    }
    glEnd();

    // Draw control points as small squares
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < 4; i++) {
        glVertex2f(ctrlPoints[i][0], ctrlPoints[i][1]);
    }
    glEnd();
}

// Display function
void display() {
    // Clear the screen with a white background
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the control points and the lines connecting them
    drawControlPoints();

    // Draw the Bézier curve in blue
    glColor3f(0.0f, 0.0f, 1.0f);
    drawBezierCurve();

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
    gluOrtho2D(-100.0, 100.0, -100.0, 100.0); // Set the visible area

    // Switch to model view matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Set the window size
    glutCreateWindow("Bezier Curve"); // Create the window with a title

    // Call the initialization function
    init();

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the GLUT main loop
    glutMainLoop();
    return 0;
}
