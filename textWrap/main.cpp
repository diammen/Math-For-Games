#include <iostream>
#include <vector>
#include "raylib.h"
#include "utils.h"
#include "Entity.h"
using std::string;
using std::vector;
int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	int textLength = 0;
	int wordCount = 1;
	int size = 5;
	int counter = 0;
	float multiplier = 0;
	float timer = 0;
	float multTimer = 0;
	string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
	vec2 position = { 100,100 };

	for (int i = 0; i < text.length(); ++i)
	{
		if (isblank(text[i])) wordCount++;
	}

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	Texture2D ball = LoadTexture("ballshade_1.png");
	vector<Entity> ents;
	Entity centerBall("yellowball.png", vec2{(float)screenWidth / 2, (float)screenHeight / 2});
	float myRad = 2 * PI / 4;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		multiplier = sin((float)multTimer) * 100;
		multTimer += GetFrameTime() * 2;
		timer+= GetFrameTime();
		for (int i = 0; i < ents.size(); ++i)
		{
			ents[i].update(multiplier);
		}
		if (timer > 1)
		{
			Entity temp;
			temp.offset = counter;
			temp.rec.x = 50 * sin(myRad *counter + 1);
			temp.rec.y = 50 * cos(myRad *counter + 1);
			ents.push_back(temp);
			counter++;
			timer = 0;
			myRad = 2 * PI / 4;
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		textLength = MeasureText(text.c_str(), 20);
		DrawText(text.c_str(), 0, 0, 20, LIGHTGRAY);
		DrawText(SubText(text.c_str(), 0, 30), 0, 50, 20, LIGHTGRAY);
		centerBall.draw();
		for (int i = 0; i < ents.size(); ++i)
		{
			ents[i].draw();
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
						  //--------------------------------------------------------------------------------------

	return 0;
}
