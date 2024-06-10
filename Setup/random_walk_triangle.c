#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int N = 10000;
float x[]= {0.f, 1.f, 0.5f};
float y[]= {0.f, 0.f, 0.865f};

static void makePoints(void)
{
  int m = rand() % 2  + 0;
  float now[] = { x[m], y[m] };
  for(int i = 0;i<N;i++)
    {
      
      int n = rand() % 3 + 0;
      float new[] = { x[n], y[n] };
      now[0] =  (now[0]+new[0])/2;
      now[1] =  (now[1]+new[1])/2;
      // DisplayPoints
      glPointSize(5.f);
      glColor3f(1.f, 0.f, 0.f);
      glBegin(GL_POINTS);
      glVertex3f(now[0], now[1], 0.f);
      glEnd();
    }
}

static void display(void) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Repaint the background with the color 
    // specified by glClearColor()
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(5.f);

    // TODO
    //Triangles
     glColor3f(0.f, 1.f, 0.f);
     glBegin(GL_TRIANGLES);
     glVertex3f(0.f, 0.f, 0.f);
     glVertex3f(1.f, 0.f, 0.f);
     glVertex3f(0.5f, 0.865f, 0.f);
     glEnd();
     // DisplayPoints
    glPointSize(5.f);
    glColor3f(0.f, 1.f, 0.f);
    glBegin(GL_POINTS);
    glVertex3f(x[0], y[0], 0.f);
    glVertex3f(x[1], y[1], 0.f);
    glVertex3f(x[2], y[2], 0.f);
    glEnd();
    
    makePoints();
    


    glutSwapBuffers();
}


static void initGL(void) {
    // Set the color for painting the background (White)
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // Set an orthographic projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}


static void keyHandle(unsigned char key, int x, int y) {
    // Exit when ESC is pressed
    if (key == 27) exit(0);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Setup");

    initGL();
    
    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyHandle);
    glutMainLoop();
    return 0;
}
