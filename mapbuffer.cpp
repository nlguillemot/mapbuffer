#define JUSTGL_IMPLEMENTATION
#include "justgl.h"

void ConfigGL(WindowConfig* pConfig)
{
    pConfig->WindowTitle = "MapBuffer test";
    pConfig->ClientWidth = 1;
    pConfig->ClientHeight = 1;
}

void InitGL()
{
    GLuint buf0, buf1;
    glGenBuffers(1, &buf0);
    glGenBuffers(1, &buf1);

    GLuint data[] = { 0, 1, 2 };

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf0);
    glBufferStorage(GL_ELEMENT_ARRAY_BUFFER, sizeof(data), data, GL_MAP_READ_BIT | GL_MAP_WRITE_BIT);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf1);
    glBufferStorage(GL_ELEMENT_ARRAY_BUFFER, sizeof(data), data, GL_MAP_READ_BIT | GL_MAP_WRITE_BIT);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf0);
    GLuint* mapped0 = (GLuint*)glMapBufferRange(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(data), GL_MAP_READ_BIT);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf1);
    GLuint* mapped1 = (GLuint*)glMapBufferRange(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(data), GL_MAP_READ_BIT);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    printf("buffer 0:\n");
    for (int i = 0; i < 3; i++)
        printf("%d ", mapped0[i]);
    printf("\n");

    printf("buffer 1:\n");
    for (int i = 0; i < 3; i++)
        printf("%d ", mapped1[i]);
    printf("\n");

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf0);
    glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buf1);
    glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    GLenum err = glGetError();
    if (err == GL_NO_ERROR)
        printf("There were no GL errors.\n");
    else
        printf("There was a GL error.\n");

    system("pause");
}

void ResizeGL(int width, int height)
{
}

int PaintGL()
{
    return 1;
}