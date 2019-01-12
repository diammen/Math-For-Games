#include <iostream>
#include <vector>
#include <time.h>
#include "raylib.h"
#include "mathLib.h"
#include "GameObject.h"
using std::string;
using std::vector;
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;


	InitWindow(screenWidth, screenHeight, "demo");

	gameObject body("ballshade_14.png", { 100,400 }, 0, { 1,1 }, 3);
	gameObject turret("turret.png", { 0,0 }, 0, { 1,1 }, 3);
	body.transform.addChild(&turret.transform);

	vector<vec2> waypoint;
	waypoint.push_back(vec2{ 100, 325 });
	waypoint.push_back(vec2{ 700, 300 });
	waypoint.push_back(vec2{ 400, 375 });
	waypoint.push_back(vec2{ 200, 275 });
	waypoint.push_back(vec2{ 50, 350 });

	vector<vec2> yellowPath;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		body.move(waypoint);
		if (body.transform.localPos == waypoint[body.target])
		{
			body.startPos = waypoint[body.target];
			body.target++;
			if (body.target > 4) body.target = 0;
			body.elapsed = 0;
		}
		yellowPath.push_back(body.transform.localPos);
		if (yellowPath.size() > 30)
		{
			yellowPath.erase(yellowPath.begin());
		}
		if (IsKeyDown(KEY_A))
		{
			turret.transform.rotate(-6.0f * GetFrameTime());
		}
		if (IsKeyDown(KEY_D))
		{
			turret.transform.rotate(6.0f * GetFrameTime());
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		if (yellowPath.size() > 2)
		{
			for (int i = 0; i < yellowPath.size() - 1; ++i)
			{
				DrawLineEx(yellowPath[i], yellowPath[i + 1], i, YELLOW);
			}
		}

		body.draw();
		turret.draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
