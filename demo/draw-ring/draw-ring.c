

/*******************************************************************************************
*
*   raylib [shapes] example - draw ring (with gui options)
*
*   Example originally created with raylib 2.5, last time updated with raylib 2.5
*
*   Example contributed by Vlad Adrian (@demizdor) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2018-2022 Vlad Adrian (@demizdor) and Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "math.h"
#include "stddef.h"
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"                 // Required for GUI controls

#include "uiinabox/uiBox.h"
#include "uiinabox/draw.h"

/*******************************************************************************
 circle content
*******************************************************************************/

struct ringData
{
   float innerRadius;
   float outerRadius;
   float startAngle;
   float endAngle;
   Color color;
   int32_t segments;
};
typedef struct ringData ringData;


static uiSize ring_size( uiStyle const* style, uiContent const* cnt )
{
//   must_be_c_( cnt->type == &RingContent );
   ringData const* ring = cnt->data;
   int32_t diameter = ( ring->outerRadius > ring->innerRadius )
      ? ring->outerRadius * 2
      : ring->innerRadius * 2;
   return size_ui_( diameter, diameter );
}

static void draw_ring( uiStyle const* style, uiContent const* cnt, uiRect where, uiRect what )
{
//    must_be_c_( cnt->type == &RingContent );
    ringData const* ring = cnt->data;
    float x = float_c_( where.topLeft.x ) + float_c_( where.size.w ) / 2.0;
    float y = float_c_( where.topLeft.y ) + float_c_( where.size.h ) / 2.0;
    Vector2 center = { .x=x, .y=y };
    DrawRing( center, ring->innerRadius, ring->outerRadius, ring->startAngle, ring->endAngle, ring->segments, ring->color );
}
static uiContentType const RingContent = {
    .desc = stringify_c_( RingContent ),
    .size = &ring_size,
    .draw = &draw_ring
};

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(800, 450, "raylib [shapes] example - draw ring");

    int const monitorId = GetCurrentMonitor();
    int const maxHeight = GetMonitorHeight( monitorId );
    int const maxWeight = GetMonitorWidth( monitorId );
    SetWindowSize( maxWeight / 2, maxHeight/2 );

    Vector2 center = {(GetScreenWidth() - 300)/2.0f, GetScreenHeight()/2.0f };

    bool drawRing = true;

    ringData ring = {
        .innerRadius=80.0f,
        .outerRadius=190.0f,
        .startAngle=0.0f,
        .endAngle=360.0f,
        .segments=0,
        .color=Fade( MAROON, 0.3f )
    };
    uiContent cnt = { .type=&RingContent, .data=&ring };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // NOTE: All variables update happens inside GUI control functions
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawLine(500, 0, 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.6f));
            DrawRectangle(500, 0, GetScreenWidth() - 500, GetScreenHeight(), Fade(LIGHTGRAY, 0.3f));

            //if (drawRing) DrawRing(center, innerRadius, outerRadius, startAngle, endAngle, segments, Fade(MAROON, 0.3f));

            // Draw GUI controls
            //------------------------------------------------------------------------------
            ring.startAngle = GuiSliderBar((Rectangle){ 600, 40, 120, 20 }, "StartAngle", NULL, ring.startAngle, -450, 450);
            ring.endAngle = GuiSliderBar((Rectangle){ 600, 70, 120, 20 }, "EndAngle", NULL, ring.endAngle, -450, 450);

            ring.innerRadius = GuiSliderBar((Rectangle){ 600, 140, 120, 20 }, "InnerRadius", NULL, ring.innerRadius, 0, 100);
            ring.outerRadius = GuiSliderBar((Rectangle){ 600, 170, 120, 20 }, "OuterRadius", NULL, ring.outerRadius, 0, 200);

            ring.segments = (int)GuiSliderBar((Rectangle){ 600, 240, 120, 20 }, "Segments", NULL, (float)ring.segments, 0, 100);

            //drawRing = GuiCheckBox((Rectangle){ 600, 320, 20, 20 }, "Draw Ring", drawRing);

            char text[80];
            GuiTextBox( (Rectangle){ 600, 450, 120, 20 }, text, 80, true );
            //------------------------------------------------------------------------------

            //int minSegments = (int)ceilf((endAngle - startAngle)/90);
            //DrawText(TextFormat("MODE: %s", (segments >= minSegments)? "MANUAL" : "AUTO"), 600, 270, 10, (segments >= minSegments)? MAROON : DARKGRAY);

            uiRect where = make_rect_ui_( 0, 0, 450, 450 );
            uiRect what = rect_ui_( top_left_corner_ui_(), cnt.type->size( NULL, &cnt ) );
            cnt.type->draw( NULL, &cnt, where, what );

            Vector2 pos = { .x=600, .y=300 };
            Vector2 origin = { .x=0, .y=100 };
//            DrawTextPro( GetFontDefault(), "some ä text", pos, origin, 0.0f, 24.0f, 1.0f, BLACK );
            DrawTextEx( GetFontDefault(), "some ä text\nand more", pos, 24, 1, BLACK );
            uiFont font = {
                .typeFace = GetFontDefault(),
                .letterSpacing = 1,
                .size = 24,
                .color = BLACK
            };
            draw_text_ui( c_c( "some ä text\nand more" ), point_ui_( 600, 350 ), &font );

            DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
