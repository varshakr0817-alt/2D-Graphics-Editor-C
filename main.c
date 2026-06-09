#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 30
#define COLS 60
#define MAX_OBJECTS 100

char canvas[ROWS][COLS];

typedef struct
{
    int id;
    int type; // 1-Line 2-Rectangle 3-Triangle 4-Circle

    int x1, y1;
    int x2, y2;

    int width, height;
    int radius;

} Object;

Object objects[MAX_OBJECTS];
int count = 0;
int nextID = 1;

/* ---------------- Canvas Functions ---------------- */

void initCanvas()
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    printf("\n");

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}

/* ---------------- Drawing Functions ---------------- */

void drawLineCanvas(int x1, int y1, int x2, int y2)
{
    if(y1 == y2)
    {
        if(x1 > x2)
        {
            int t = x1;
            x1 = x2;
            x2 = t;
        }

        for(int i = x1; i <= x2; i++)
        {
            if(y1 >= 0 && y1 < ROWS && i >= 0 && i < COLS)
                canvas[y1][i] = '*';
        }
    }

    else if(x1 == x2)
    {
        if(y1 > y2)
        {
            int t = y1;
            y1 = y2;
            y2 = t;
        }

        for(int i = y1; i <= y2; i++)
        {
            if(i >= 0 && i < ROWS && x1 >= 0 && x1 < COLS)
                canvas[i][x1] = '*';
        }
    }
}

void drawRectangleCanvas(int x, int y, int width, int height)
{
    for(int i = y; i < y + height; i++)
    {
        for(int j = x; j < x + width; j++)
        {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS)
                canvas[i][j] = '*';
        }
    }
}

void drawTriangleCanvas(int x, int y, int height)
{
    for(int i = 0; i < height; i++)
    {
        for(int j = x - i; j <= x + i; j++)
        {
            if(y + i >= 0 && y + i < ROWS &&
               j >= 0 && j < COLS)
            {
                canvas[y + i][j] = '*';
            }
        }
    }
}

void drawCircleCanvas(int cx, int cy, int r)
{
    for(int y = 0; y < ROWS; y++)
    {
        for(int x = 0; x < COLS; x++)
        {
            int d = (x - cx)*(x - cx) + (y - cy)*(y - cy);

            if(d <= r*r)
                canvas[y][x] = '*';
        }
    }
}

/* ---------------- Redraw ---------------- */

void redrawAll()
{
    initCanvas();

    for(int i = 0; i < count; i++)
    {
        switch(objects[i].type)
        {
            case 1:
                drawLineCanvas(
                    objects[i].x1,
                    objects[i].y1,
                    objects[i].x2,
                    objects[i].y2
                );
                break;

            case 2:
                drawRectangleCanvas(
                    objects[i].x1,
                    objects[i].y1,
                    objects[i].width,
                    objects[i].height
                );
                break;

            case 3:
                drawTriangleCanvas(
                    objects[i].x1,
                    objects[i].y1,
                    objects[i].height
                );
                break;

            case 4:
                drawCircleCanvas(
                    objects[i].x1,
                    objects[i].y1,
                    objects[i].radius
                );
                break;
        }
    }
}

/* ---------------- Add Objects ---------------- */

void addLine()
{
    Object obj;

    obj.id = nextID++;
    obj.type = 1;

    printf("Enter x1 y1: ");
    scanf("%d%d", &obj.x1, &obj.y1);

    printf("Enter x2 y2: ");
    scanf("%d%d", &obj.x2, &obj.y2);

    objects[count++] = obj;

    redrawAll();

    printf("Line Added. ID = %d\n", obj.id);
}

void addRectangle()
{
    Object obj;

    obj.id = nextID++;
    obj.type = 2;

    printf("Enter x y: ");
    scanf("%d%d", &obj.x1, &obj.y1);

    printf("Enter width height: ");
    scanf("%d%d", &obj.width, &obj.height);

    objects[count++] = obj;

    redrawAll();

    printf("Rectangle Added. ID = %d\n", obj.id);
}

void addTriangle()
{
    Object obj;

    obj.id = nextID++;
    obj.type = 3;

    printf("Enter center x y: ");
    scanf("%d%d", &obj.x1, &obj.y1);

    printf("Enter height: ");
    scanf("%d", &obj.height);

    objects[count++] = obj;

    redrawAll();

    printf("Triangle Added. ID = %d\n", obj.id);
}

void addCircle()
{
    Object obj;

    obj.id = nextID++;
    obj.type = 4;

    printf("Enter center x y: ");
    scanf("%d%d", &obj.x1, &obj.y1);

    printf("Enter radius: ");
    scanf("%d", &obj.radius);

    objects[count++] = obj;

    redrawAll();

    printf("Circle Added. ID = %d\n", obj.id);
}

/* ---------------- Delete Object ---------------- */

void deleteObject()
{
    int id;
    int pos = -1;

    printf("Enter Object ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(objects[i].id == id)
        {
            pos = i;
            break;
        }
    }

    if(pos == -1)
    {
        printf("Object Not Found!\n");
        return;
    }

    for(int i = pos; i < count - 1; i++)
    {
        objects[i] = objects[i + 1];
    }

    count--;

    redrawAll();

    printf("Object Deleted Successfully.\n");
}

/* ---------------- Modify Object ---------------- */

void modifyObject()
{
    int id;

    printf("Enter Object ID to modify: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(objects[i].id == id)
        {
            int type = objects[i].type;

            if(type == 1)
            {
                printf("Enter new x1 y1: ");
                scanf("%d%d", &objects[i].x1, &objects[i].y1);

                printf("Enter new x2 y2: ");
                scanf("%d%d", &objects[i].x2, &objects[i].y2);
            }

            else if(type == 2)
            {
                printf("Enter new x y: ");
                scanf("%d%d", &objects[i].x1, &objects[i].y1);

                printf("Enter new width height: ");
                scanf("%d%d",
                      &objects[i].width,
                      &objects[i].height);
            }

            else if(type == 3)
            {
                printf("Enter new center x y: ");
                scanf("%d%d",
                      &objects[i].x1,
                      &objects[i].y1);

                printf("Enter new height: ");
                scanf("%d",
                      &objects[i].height);
            }

            else if(type == 4)
            {
                printf("Enter new center x y: ");
                scanf("%d%d",
                      &objects[i].x1,
                      &objects[i].y1);

                printf("Enter new radius: ");
                scanf("%d",
                      &objects[i].radius);
            }

            redrawAll();

            printf("Object Modified Successfully.\n");
            return;
        }
    }

    printf("Object Not Found!\n");
}

/* ---------------- Show Object List ---------------- */

void showObjects()
{
    printf("\nStored Objects:\n");

    for(int i = 0; i < count; i++)
    {
        printf("ID = %d   Type = %d\n",
               objects[i].id,
               objects[i].type);
    }

    if(count == 0)
        printf("No Objects Available.\n");
}

/* ---------------- Main ---------------- */

int main()
{
    int choice;

    initCanvas();

    do
    {
        printf("\n========== 2D GRAPHICS EDITOR ==========\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Object\n");
        printf("6. Modify Object\n");
        printf("7. Display Canvas\n");
        printf("8. Show Object List\n");
        printf("9. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addLine();
                break;

            case 2:
                addRectangle();
                break;

            case 3:
                addTriangle();
                break;

            case 4:
                addCircle();
                break;

            case 5:
                deleteObject();
                break;

            case 6:
                modifyObject();
                break;

            case 7:
                displayCanvas();
                break;

            case 8:
                showObjects();
                break;

            case 9:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 9);

    return 0;
}
