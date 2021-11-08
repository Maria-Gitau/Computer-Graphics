#include <windows.h>
#include <GL\glut.h>
#include <cmath>

void myInit(void)

{

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // sets background color to white

    // sets a point to be 4x4 pixels

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0.0, 500.0, 0.0, 400.0); // the display area in world coordinates.

}

void myDisplay(void)

{

    glClear(GL_COLOR_BUFFER_BIT); // clears the screen
    glColor3f(0.0f, 0.5f, 1.0f);// setsthe drawing colour

    glPointSize(4.0);

    //other door handle
    glBegin(GL_POLYGON);
    double radius = 3.5;
    double ori_x = 275.0;
    double ori_y = 100.0;
    double PI = 3.142;
    for (int i = 0; i <= 300; i++) {
        double angle = 2 * PI * i / 300;
        double x = cos(angle) * radius;
        double y = sin(angle) * radius;
        glVertex2d(ori_x + x, ori_y + y);
    }
    glEnd();

    //crescent moon
    glBegin(GL_POLYGON);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    float borderColor[] = { 0.0f, 0.5f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    double radius1 = 34;
    double orig_x = 410.0;
    double orig_y = 330.0;
    double M_PI = 3.142;
    for (int i = 0; i <= 300; i++) {
        double angle1 = 2 * M_PI * i / 300;
        double x1 = cos(angle1) * radius1;
        double y1 = sin(angle1) * radius1;
        glVertex2d(orig_x + x1, orig_y + y1);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    double radius2 = 38;
    double origi_x = 440.0;
    double origi_y = 330.0;
    double MY_PI = 3.142;
    for (int i = 0; i <= 300; i++) {
        double angle2 = 2 * MY_PI * i / 300;
        double x2 = cos(angle2) * radius2;
        double y2 = sin(angle2) * radius2;
        glVertex2d(origi_x + x2, origi_y + y2);
    }
    glEnd();

    float step = 4.0;
    float x = 125.0f;
    float y = 245.0f;
    double Radius= 5.5f;
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.5f, 1.0f);
    for (float angle = 0.0f; angle <= 280; angle += step)
    {
        float rad = 2 * angle / 180;
        x = x + (Radius * sin(rad));
        y = y + (Radius * cos(rad));
        glVertex3f(x, y, 0.0f);

    }

    glEnd();

    glBegin(GL_LINES);
    //bottom
    glVertex2i(100, 20);
    glVertex2i(400, 20);

    //topleft
    glVertex2i(100, 200);
    glVertex2i(50, 200);

    //topleftup
    glVertex2i(50, 200);
    glVertex2i(50, 250);

    //top
    glVertex2i(50, 250);
    glVertex2i(450, 250);

    //topright
    glVertex2i(400, 200);
    glVertex2i(450, 200);

    //toprightup
    glVertex2i(450, 200);
    glVertex2i(450, 250);

    //left
    glVertex2i(100, 200);
    glVertex2i(100, 20);

    //right
    glVertex2i(400, 200);
    glVertex2i(400, 20);

    //leftwindowgrillup
    glVertex2i(150, 175);
    glVertex2i(150, 125);

    //leftwindowgrillacross
    glVertex2i(125, 150);
    glVertex2i(175, 150);

    //rightwindowgrillup
    glVertex2i(350, 175);
    glVertex2i(350, 125);

    //rightwindowgrillacross
    glVertex2i(325, 150);
    glVertex2i(375, 150);

    //glVertex2i (10, -50);

    glEnd();

    //Right Window
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);

    //bottom
    glVertex2i(325, 125);
    glVertex2i(375, 125);

    //top
    glVertex2i(325, 175);
    glVertex2i(375, 175);

    //left
    glVertex2i(325, 125);
    glVertex2i(325, 175);

    //right
    glVertex2i(375, 125);
    glVertex2i(375, 175);

    //glVertex2i (10, -50);

    //Left Window

    //bottom
    glVertex2i(125, 125);
    glVertex2i(175, 125);

    //top
    glVertex2i(125, 175);
    glVertex2i(175, 175);

    //left
    glVertex2i(125, 125);
    glVertex2i(125, 175);

    //right
    glVertex2i(175, 125);
    glVertex2i(175, 175);

    //door
    //top
    glVertex2i(200, 175);
    glVertex2i(300, 175);

    //left
    glVertex2i(200, 20);
    glVertex2i(200, 175);

    //right
    glVertex2i(300, 20);
    glVertex2i(300, 175);


    glEnd();

    glFlush(); // sends all output to display;

}

int main(int argc, char** argv)
{

    glutInit(&argc, argv); // to initialize the toolkit;

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // sets the display mode

    glutInitWindowSize(640, 480); // sets the window size

    glutInitWindowPosition(10, 10); // sets the starting position for the window

    glutCreateWindow("My first OpenGL program!"); // creates the window and sets the title

    glutDisplayFunc(myDisplay);
    myInit(); // additional initializations as necessary
    glutMainLoop(); // go into a loop until event occurs
    return 0;
}