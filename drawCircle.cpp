#include <GL/glut.h>

int* drawCircle(float radius, float centerPoint){
	/*int vertexX[] = {centerPoint,centerPoint+0.5,centerPoint};
	int vertexY[] = {centerPoint+radius,centerPoint+radius,centerPoint};*/
	int vertices[] = {centerPoint,centerPoint+radius,centerPoint+0.5,centerPoint+radius,centerPoint,centerPoint};

	return vertices;
}