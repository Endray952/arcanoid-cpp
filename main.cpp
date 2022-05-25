#include <GL/glut.h>
#include <math.h>
#include "Game.h"
#include <iostream>


#define FPS 60
float WinWidth = 600.0;
float WinHeight = 600.0;


float r_x = 50.0, r_y = 290.0, r_w = 80, r_h = 8.0;
int mouse_x;

Game *game;

void Initialize(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    Game::window_width = glutGet(GLUT_WINDOW_WIDTH);
    Game::window_height = glutGet(GLUT_WINDOW_HEIGHT);
    Game* g = new Game;
    game = g;
}

void ReshapeWindow(int w, int h) {
    Game::window_width = glutGet(GLUT_WINDOW_WIDTH);
    Game::window_height = glutGet(GLUT_WINDOW_HEIGHT);
    if (game) {
        game->HandleWindowReshape();
    }
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, w, 0.0, h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void TimerCallback(int) {
    if (game) {
        game->Update();
    }
  
    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, TimerCallback, 0);
}


void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double w = glutGet(GLUT_WINDOW_WIDTH);
    double h = glutGet(GLUT_WINDOW_HEIGHT);
    glOrtho(0, w, h, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //menu.Render();
    //glColor3f(0.2, 0.8, 0.1);
    //glRectf(r_x, r_y, r_x + r_w, r_y + r_h);
    game->Draw();
    glutSwapBuffers();
}


void KeyboardCallback(int key, int, int) {
    switch (key)
    {
    case GLUT_KEY_UP:
        break;
    case GLUT_KEY_DOWN:
        break;
    case GLUT_KEY_LEFT:
        break;
    case GLUT_KEY_RIGHT:
        break;
    default:
        break;
    }
}


void MouseCallback(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        switch (button) {
        case GLUT_LEFT_BUTTON:
            //menu.HandleClick();
            if (game) {
                game->isActive = !game->isActive;
            }       
            break;
        default:
            break;
        }
    }
}


void MouseRoutine(int x, int y) {
    //menu.FindFocus(x, y);
    //std::cout << x << " "
    game->MouseMove(x);
    //mouse_x = x;
    //r_x = mouse_x;
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(WinWidth, WinHeight);

    glutInitWindowPosition(0, 0);

    glutCreateWindow("Menu app");

    glutReshapeFunc(ReshapeWindow);

    glutSpecialFunc(KeyboardCallback);
    glutMouseFunc(MouseCallback);
    glutPassiveMotionFunc(MouseRoutine);

    glutTimerFunc(0, TimerCallback, 0);
    glutDisplayFunc(Display);

    Initialize();
    glutMainLoop();

}