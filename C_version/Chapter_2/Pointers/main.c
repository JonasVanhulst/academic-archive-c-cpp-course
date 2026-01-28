#include <stdio.h>

struct point3D {
    float x, y, z;
};

struct triangle {
    struct point3D *p1;
    struct point3D *p2;
    struct point3D *p3;
};

void addPoints(struct point3D *points, int numberOfPoints);
void linkPointsToTriangles(struct point3D *points, struct triangle *triangles, int numberOfTriangles);
void printResults(struct triangle *triangles, int numberOfTriangles);

int main(void) {
    struct point3D points[15];
    struct triangle triangles[5];

    addPoints(points, sizeof(points) / sizeof(points[0]));
    linkPointsToTriangles(points, triangles, sizeof(triangles) / sizeof(triangles[0]));
    printResults(triangles, sizeof(triangles) / sizeof(struct triangle));

    return 0;
}

void addPoints(struct point3D *points, int numberOfPoints)
{
    for (int i = 0; i < numberOfPoints; i++)
    {
        printf("Give the coordinates of point %d = ", i);
        struct point3D tmpPoint;
        (void)scanf("%f %f %f", &tmpPoint.x, &tmpPoint.y, &tmpPoint.z);
        points[i] = tmpPoint;
    }
}

void linkPointsToTriangles(struct point3D *points, struct triangle *triangles, int numberOfTriangles)
{
    for (int i = 0; i < numberOfTriangles; i++)
    {
        triangles[i].p1 = &points[i * 3];
        triangles[i].p2 = &points[i * 3 + 1];
        triangles[i].p3 = &points[i * 3 + 2];
    }
}

void printResults(struct triangle *triangles, int numberOfTriangles)
{
    for (int i = 0; i < numberOfTriangles; i++)
    {
        printf("Triangle %d:\n", i + 1);
        printf("Point 1: (%.2f, %.2f, %.2f)\n", triangles[i].p1->x, triangles[i].p1->y, triangles[i].p1->z);
        printf("Point 2: (%.2f, %.2f, %.2f)\n", triangles[i].p2->x, triangles[i].p2->y, triangles[i].p2->z);
        printf("Point 3: (%.2f, %.2f, %.2f)\n", triangles[i].p3->x, triangles[i].p3->y, triangles[i].p3->z);
    }
}
