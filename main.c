#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <SDL.h>
#include "drawline.h"
#include "triangle.h"
#include "list.h"
#include "teapot_data.h"
#include "sphere_data.h"
#include "object.h"

/* Two macro's that find the lesser or greater of two values */
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)

/*
 * Clear the surface by filling it with 0x00000000(black).
 */
void clear_screen(SDL_Surface *surface)
{
    if(SDL_FillRect(surface, NULL, 0x00000000) < 0){
        fprintf(stderr, "Unable to clear the surface. Error returned: %s\n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}

/*
 * Accelerate the object; altering its speed based on the boost given.
 */
void accelerate_object(object_t *a, float boost, float maxspeed)
{
    float s;
    float news;
    
    /* Calculate lenght of speed vector */
    s = sqrtf(a->speedx * a->speedx + a->speedy * a->speedy);

    /* Boost speed */
    news = s * boost;
    if (news < 0.0)
        news = 0.0;
    if (news > maxspeed)
        news = maxspeed;    
    a->speedx *= news/s;
    a->speedy *= news/s;
}



/*
 * Animate bouncing balls on the screen.
 */
void bouncing_balls(SDL_Window *window)
{
    
    
}
    /* Implement me */
    
    
    

//}
    
    int main(void)
    {
        const size_t bufsize = 100;
        
        /* Change the screen width and height to your own liking */
        const int screen_w = 1600;
        const int screen_h = 900;
        
        char errmsg[bufsize];
        int done;
        SDL_Window *window;
        SDL_Surface *surface;
        SDL_Event event;
        
        /* Initialize SDL */
        if (SDL_Init(SDL_INIT_VIDEO) < -1) {
            snprintf(errmsg, bufsize, "Unable to initialize SDL.");
            goto error;
        }
        
        /* Create a 1600x900 window */
        window = SDL_CreateWindow("The Amazing Bouncing Balls",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  screen_w, screen_h,
                                  0);
        if(!window) {
            snprintf(errmsg, bufsize, "Unable to get video surface.");
            goto error;
        }
        
        surface = SDL_GetWindowSurface(window);
        if (!surface){
            snprintf(errmsg, bufsize, "unable to create surface.");
            goto error;
        }
        

        object_t *ball = create_object(surface, sphere_model, SPHERE_NUMTRIANGLES);
        
        
      
        
        
        done = 0;
        while (!done) {
            
            
            SDL_UpdateWindowSurface(window);
            clear_screen(surface);
            draw_object(ball);


            
            

            
            float gravity = 0.2;
            float bounce = 0.9;
            float friction = 0.01;
            
            ball->speedy += gravity;
            
            
            ball->tx += ball->speedx;
            ball->ty += ball->speedy;

            if (ball->tx + 50 > 1600 || ball->tx - 50 < 0){
                ball->speedx *= -1;
            }
        
            if (ball->ty + 50  > 900){
                ball->ty = 900 - 50;
        
                ball->speedy *= -bounce;
        
                if (ball->speedy < 0 && ball->speedy > -2.1){
                    ball->speedy = 0;
        
                }
            }
            
                    if (ball->ty + 50 == 900){
                        
                        if (ball->speedx < 0){
                            ball->speedx += friction;
                        }
                        
                        else if (ball->speedx > 0){
                            ball->speedx -= friction;
                        }
                        
                }
          
            
    
         
            
            while (SDL_PollEvent(&event)){
                switch(event.type) {
                    case SDL_QUIT:
                        done = 1;
                        break;
                        
                    case SDL_WINDOWEVENT:
                        if(event.window.event == SDL_WINDOWEVENT_SHOWN)
                            SDL_SetWindowPosition(window, 50, 50);
                        break;
                }
            }
        }
        
        
        /* Shut down SDL */
        SDL_Quit();
        
        /* Wait a little bit jic something went wrong (so that printfs can be read) */
        SDL_Delay(5000);
        
        return 0;
        
        /* Upon an error, print message and quit properly */
    error:
        fprintf(stderr, "%s Error returned: %s\n", errmsg, SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }


