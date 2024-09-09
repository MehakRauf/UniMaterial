#include <GL/glut.h>
#include <cmath>

// Structure to represent a point
struct Point2 {
    float x, y;
    Point2(float x, float y) : x(x), y(y) {}
};

// Function to draw an arc
void drawArc(Point2 center, float radius, float startAngle, float sweep) {
    const int n = 30; // number of intermediate segments in the arc
    float angle = startAngle * M_PI / 180.0f; // initial angle in radians
    float angleInc = sweep * M_PI / (180.0f * n); // angle increment
    float cx = center.x, cy = center.y;

    glBegin(GL_LINE_STRIP); // Begin drawing the arc
    for (int k = 0; k <= n; k++, angle += angleInc) {
        glVertex2f(cx + radius * cos(angle), cy + radius * sin(angle));
    }
    glEnd(); // End drawing the arc
}

// Function to draw a line
void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Function to draw horizontal lines
void drawHorizontalLines(float y, int numLines, float lineWidth) {
    glBegin(GL_LINES);
    for (int i = 0; i < numLines; i++) {
        float xStart = -47.0f;
        glVertex2f(xStart, y);
        glVertex2f(xStart + lineWidth, y);
        y +=45.0f; // Adjust y-coordinate for each horizontal line
    }
    glEnd();
}

// Display function
void display() {
    // Clear the screen with a white background
    glClear(GL_COLOR_BUFFER_BIT);

    // Set  color 
    glColor3f(0.0, 1.0, 1.0);
    // Draw an arc centered at (0, 0) with a radius of 50
    drawArc(Point2(0.0f, 0.0f), 50.0f, 20.0f, 140.0f); // Start at 20 degrees, sweep 140 degrees

    // Calculate points on the arc for vertical lines
    float endX = 50.0f * cos((20.0f + 140.0f) * M_PI / 180.0f);
    float endY = 50.0f * sin((20.0f + 140.0f) * M_PI / 180.0f);

    float startX = 50.0f * cos(20.0f * M_PI / 180.0f);
    float startY = 50.0f * sin(20.0f * M_PI / 180.0f);

    float midX = 50.0f * cos(90.0f * M_PI / 180.0f);
    float midY = 50.0f * sin(90.0f * M_PI / 180.0f);

    // Set line color
    glColor3f(0.0, 1.0, 1.0);
    // Draw vertical lines from points on the arc
    drawLine(endX, endY, endX, -50.0f);
    drawLine(startX, startY, startX, -50.0f);
    drawLine(midX, midY, midX, -50.0f);

    // Draw horizontal lines starting at the midX position
    drawHorizontalLines(-50.0f, 2, 94.0f); // Adjust the y-position and number of lines as needed

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
    glutCreateWindow("Draw Horizontal Arc"); // Create the window with a title

    // Call the initialization function
    init();

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the GLUT main loop
    glutMainLoop();
    return 0;
}
