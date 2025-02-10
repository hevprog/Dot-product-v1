
#include <raylib.h>

#include <raymath.h>


float dot1(Vector2 a,Vector2 b);
float dot2(Vector2 a, Vector2 b);
int main(){
    SetTargetFPS(60);
    InitWindow(1080,780,"Dot product visualizer");
    Vector2 mouse,touch;
    Vector2 center,v1,v2,dot;
    center = {1080/2,780/2};
    v1 = center;
    v2 = center;
    v1.y -= 80;



    while(!WindowShouldClose()){
        BeginDrawing();

        //Condition
        if(CheckCollisionCircles(mouse,2,v1,30))
            v1 = IsMouseButtonDown(MOUSE_LEFT_BUTTON)?mouse:v1;
        if(CheckCollisionCircles(mouse,2,v2,30))
            v2 = IsMouseButtonDown(MOUSE_LEFT_BUTTON)?mouse:v2;
        if(IsKeyPressed(KEY_SPACE)){
            center = {1080/2,780/2};
            v1 = center;
            v2 = center;
            v1.y -= 80;

        }

        //process
        mouse = GetMousePosition();

        
        Vector2 noCenterv2 = Vector2Subtract(v2,center);
        Vector2 noCenterv1 = Vector2Subtract(v1,center);
        float dot = dot1(Vector2Normalize(noCenterv1),Vector2Normalize(noCenterv2));
        Vector2 projection = Vector2Scale(noCenterv1,dot);
        projection = Vector2Add(projection,center);
       
        //same function just in one line
        //projection = Vector2Add(center,Vector2Scale(noCenterv1,dot1(Vector2Normalize(noCenterv2),Vector2Normalize(noCenterv1))));
        //Draw funcs
        DrawCircleLinesV(center,Vector2Distance(center,v1),WHITE);
        
        DrawCircleV(mouse,(IsMouseButtonDown(MOUSE_LEFT_BUTTON))? 6:2,(IsMouseButtonDown(MOUSE_LEFT_BUTTON))? RED:WHITE);

        DrawLineV(v1,projection,PINK);
        DrawLineV(center,v1,YELLOW);
        DrawLineV(v2,projection,GREEN);

        
        //DrawCircleV({dot1(Vector2Subtract(v1,center),Vector2Subtract(v2,center)),v1.y},10,GREEN);
        DrawCircleV(v1,10,VIOLET);
        DrawCircleV(v2,10,PURPLE);
        DrawCircleV(projection,10,GREEN);

        DrawCircleV({300,200},20,(dot>0)? ORANGE:WHITE);
        EndDrawing();
        ClearBackground(BLACK);
    }
    CloseWindow();
}

float dot1(Vector2 a,Vector2 b){
    return (a.x*b.x)+(a.y*b.y);
};


float dot2(Vector2 a,Vector2 centerA, Vector2 b, Vector2 centerB){
    //UNDER DEVELOPMENT, NEED TO STUDY FURTHER
    // Dot = product of magnitude of two vectors and the cosine of theta
    float angle;
    float magA = (sqrtf((a.x-centerA.x)*(a.x-centerA.x)+(a.y-centerA.y)*(a.y-centerA.y)));
    float magB = (sqrtf((b.x-centerB.x)*(b.x-centerB.x)+(b.y-centerB.y)*(b.y-centerB.y)));
    return magA*magB*cos(angle); //How to deal with an angle here?
};