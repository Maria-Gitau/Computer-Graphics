#include<iostream>
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<math.h>
#include<cmath>
using namespace std;

int main() {
	glfwInit(); //initialize window

	GLFWwindow* window = glfwCreateWindow(800, 800, "House Task", NULL, NULL); // h, w, window_title, full_screen/not
	if (window == NULL) { //Checks if window was created
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window); //Make window part of current context

	//gladLoadGL(); //Load needed configs for OGL

	glViewport(0, 0, 800, 800); //area that should be rendered by OGL

	while (!glfwWindowShouldClose(window)) // window should only be closed when close button is closed/ directed by function
	{
		glClearColor(1,1,1,1); // prep to clear color of buffer and set new color
		//last arg is alpha. Dicates the transparensy of the window. 1-Opaque
		glClear(GL_COLOR_BUFFER_BIT);
		
		//Top Rectangle
		glColor3f(0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex2f(-0.8f, 0.35f);
		glVertex2f(-0.8f, 0.6f);
		glVertex2f(0.8f, 0.6f);
		glVertex2f(0.8f, 0.35f);
		glEnd();

		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(-0.8f, 0.35F);
		glVertex2f(-0.6f, 0.35f);
		glEnd();

		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex2f(0.8f, 0.35F);
		glVertex2f(0.6f, 0.35f);
		glEnd();

		//Base Rectangle
		glColor3f(0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex2f(-0.6f, 0.35f);
		glVertex2f(-0.6f, -0.35f);
		glVertex2f(0.6f, -0.35f);
		glVertex2f(0.6f, 0.35f);
		glEnd();

		//Door
		glColor3f(0, 1, 0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(-0.15f, 0.25f);
		glVertex2f(-0.15f, -0.35f);
		glVertex2f(0.15f, -0.35f);
		glVertex2f(0.15f, 0.25f);
		glEnd();

		glColor3f(0, 0, 1);
		glBegin(GL_POLYGON);                        // Middle circle - Door knob
		double radius = 0.015;
		double ori_x = 0.11;                         // the origin or center of circle
		double ori_y = -0.05;
		double PI = 3.142;
		for (int i = 0; i <= 300; i++) {
			double angle = 2 * PI * i / 300;
			double x = cos(angle) * radius;
			double y = sin(angle) * radius;
			glVertex2d(ori_x + x, ori_y + y);
		}
		glEnd();

		//Window-Left
		glColor3f(0, 1, 0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(-0.52f, 0.25f);
		glVertex2f(-0.52f, 0.0f);
		glVertex2f(-0.27f, 0.0f);
		glVertex2f(-0.27f, 0.25f);
		glEnd();

		glColor3f(0, 0, 1);  //Diagonal Grill
		glBegin(GL_LINES);
		glVertex2f(-0.395f, 0.25F);
		glVertex2f(-0.395f, 0.0f);
		glEnd();

		glColor3f(0, 0, 1);  //Horizontal Grill
		glBegin(GL_LINES);
		glVertex2f(-0.52f, 0.125F);
		glVertex2f(-0.27f, 0.125f);
		glEnd();

		//Window-Right
		glColor3f(0, 1, 0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(0.52f, 0.25f);
		glVertex2f(0.52f, 0.0f);
		glVertex2f(0.27f, 0.0f);
		glVertex2f(0.27f, 0.25f);
		glEnd();

		glColor3f(0, 0, 1);  //Diagonal Grill
		glBegin(GL_LINES);
		glVertex2f(0.395f, 0.25F);
		glVertex2f(0.395f, 0.0f);
		glEnd();

		glColor3f(0, 0, 1);  //Horizontal Grill
		glBegin(GL_LINES);
		glVertex2f(0.52f, 0.125F);
		glVertex2f(0.27f, 0.125f);
		glEnd();
				
		//Moon - 1
		int i;
		GLfloat x1 = 0.85f; GLfloat y1 = 0.85f; GLfloat radius1 = 0.1f;
		int triangleAmount = 60;
		GLfloat twicePi = 2.0f * 3.142;
		glBegin(GL_TRIANGLE_FAN);
		glColor3ub(255, 217, 51);
		glVertex2f(x1, y1);
		for (i = 0; i <= triangleAmount; i++)
		{
			glVertex2f(
				x1 + (radius1 * cos(i * twicePi / triangleAmount)),
				y1 + (radius1 * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();

		//Moon - 1
		//int i;
		GLfloat x2 = 0.9; GLfloat y2 = 0.9f; GLfloat radius2 = 0.1f;
		//int triangleAmount = 60;
		//GLfloat twicePi = 2.0f * 3.142;
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 1, 1);
		glVertex2f(x2, y2);
		for (i = 0; i <= triangleAmount; i++)
		{
			glVertex2f(
				x2 + (radius2 * cos(i * twicePi / triangleAmount)),
				y2 + (radius2 * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();

		//Top-arc
		float step = 4.0;
		float x = -0.45f;
		float y = 0.585f;
		float Radius = 0.02f;
		glBegin(GL_LINE_STRIP);
		glColor3f(0, 0, 1);
		for (float angle = 0.0f; angle <= 280; angle += step)
		{
			float rad = 2 * angle / 180;
			x = x +( Radius * sin(rad));
			y = y + ( Radius * cos(rad));
			glVertex3f(x, y, 0.0f);

		}


		glEnd();

		glfwSwapBuffers(window);  //display color we want by swapping front buffer

		glfwPollEvents(); // process polled events such as resizing window
	}

	glfwDestroyWindow(window);  //delete once done with window
	glfwTerminate(); //Terminate window before the function ends
	return 0;
}
