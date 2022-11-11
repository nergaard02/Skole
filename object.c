#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "drawline.h"
#include "triangle.h"
#include "object.h"


/*
 * Return a newly created object based on the arguments provided.
 */
object_t *create_object(SDL_Surface *surface, triangle_t *model, int numtriangles)
{
    object_t *ball = malloc(sizeof(object_t));

    if (ball == NULL){
        free(ball);
    }



    ball->numtriangles = numtriangles;
    ball->scale = model->scale;
    ball->rotation = 2;
    ball->tx = 80;
    ball->ty = 80;
    ball->speedx = 3;
    ball->speedy = 2;
    ball->ttl = 70;
    ball->numtriangles = numtriangles;
    ball->model = model;
    ball->surface = surface;

    return ball;
}

/*
 * Destroy the object, freeing the memory.
 */
void destroy_object(object_t *object)
{
    /* Implement me */
    free(object);
}

/*
 * Draw the object on its surface.
 */
void draw_object(object_t *object)
{
    
    for (int k = 0; k < 478; k++){
        object->model[k].tx = object->tx;
        object->model[k].ty = object->ty;
        object->model[k].rotation += object->speedx;
        
        
        draw_triangle(object->surface, &object->model[k]);
    }
    /* Implement me */
} 
