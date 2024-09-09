#include <GL/glut.h>
#include <vector>
#include <iostream>
#include <cfloat> // for FLT_MAX

// Point structure
struct Point
{
    GLint x, y;
};

// Polyline structure
struct PolyLine
{
    std::vector<Point> points;
    bool closed = false;
};

std::vector<PolyLine> polylines;
PolyLine currentPolyline;
int selectedPoint = -1;
int selectedPolyline = -1;

// Function to create a house shape
void createHouseShape()
{
    PolyLine house;
    house.points = {
        {100, 100}, {200, 100}, {200, 200}, {100, 200}, // Square base
        {100, 200},
        {150, 300},
        {200, 200}, // Roof
    };
    house.closed = true;
    polylines.push_back(house);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw all polylines
    glColor3f(0.0, 0.0, 1.0); // Blue for polylines
    for (const auto &polyline : polylines)
    {
        glBegin(GL_LINE_STRIP);
        for (const auto &point : polyline.points)
        {
            glVertex2i(point.x, point.y);
        }
        if (polyline.closed)
        {
            glVertex2i(polyline.points.front().x, polyline.points.front().y); // Close the polyline
        }
        glEnd();
    }

    // Draw current polyline if it's being created
    if (!currentPolyline.points.empty())
    {
        glColor3f(1.0, 0.0, 0.0); // Red for the current polyline
        glBegin(GL_LINE_STRIP);
        for (const auto &point : currentPolyline.points)
        {
            glVertex2i(point.x, point.y);
        }
        glEnd();
    }

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
}

Point findClosestPoint(int x, int y, int &polylineIndex)
{
    float minDist = FLT_MAX;
    Point closestPoint;
    polylineIndex = -1;

    for (int i = 0; i < polylines.size(); ++i)
    {
        const auto &polyline = polylines[i];
        for (int j = 0; j < polyline.points.size(); ++j)
        {
            float dist = (polyline.points[j].x - x) * (polyline.points[j].x - x) +
                         (polyline.points[j].y - y) * (polyline.points[j].y - y);
            if (dist < minDist)
            {
                minDist = dist;
                closestPoint = polyline.points[j];
                polylineIndex = i;
                selectedPoint = j;
            }
        }
    }

    return closestPoint;
}

void mouse(int button, int state, int x, int y)
{
    y = glutGet(GLUT_WINDOW_HEIGHT) - y;
    std::cout << "Mouse click at (" << x << ", " << y << ")" << std::endl;

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (selectedPoint == -1)
        {
            // Add point to current polyline
            currentPolyline.points.push_back({x, y});
            std::cout << "Added point: (" << x << ", " << y << ")" << std::endl;
        }
        else
        {
            // Move selected point
            polylines[selectedPolyline].points[selectedPoint] = {x, y};
            selectedPoint = -1;
        }
        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    std::cout << "Key pressed: " << key << std::endl;
    switch (key)
    {
    case 'b': // Begin a new polyline
        if (!currentPolyline.points.empty())
        {
            polylines.push_back(currentPolyline);
            std::cout << "Added polyline with " << currentPolyline.points.size() << " points." << std::endl;
            currentPolyline.points.clear();
        }
        break;
    case 'd':
        if (selectedPolyline != -1)
        {
            auto &polyline = polylines[selectedPolyline];
            if (selectedPoint != -1 && selectedPoint >= 0 && selectedPoint < polyline.points.size())
            {
                // Delete the selected point
                polyline.points.erase(polyline.points.begin() + selectedPoint);
                std::cout << "Deleted selected point at index " << selectedPoint << " from polyline " << selectedPolyline << std::endl;
                selectedPoint = -1;
            }
            else if (!polyline.points.empty())
            {
                // Delete the last point if no specific point is selected
                polyline.points.pop_back();
                std::cout << "Deleted last point from polyline " << selectedPolyline << std::endl;
            }
            else
            {
                std::cerr << "Error: No points left to delete in polyline " << selectedPolyline << std::endl;
            }

            // Remove empty polyline if it becomes empty
            if (polyline.points.empty())
            {
                polylines.erase(polylines.begin() + selectedPolyline);
                std::cout << "Deleted empty polyline " << selectedPolyline << std::endl;
                selectedPolyline = -1;
            }
        }
        else
        {
            std::cerr << "Error: No polyline selected for deletion." << std::endl;
        }
        break;
    case 'm': // Select and move a point
    {
        int polylineIndex;
        findClosestPoint(x, y, polylineIndex);
        selectedPolyline = polylineIndex;
    }
    break;
    case 'r': // Refresh and redraw
        glutPostRedisplay();
        break;
    case 'q': // Quit the program
        exit(0);
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Polyline Editor");

    glClearColor(1.0, 1.0, 1.0, 1.0);

    createHouseShape(); // Initialize the house shape

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
