#include <iostream>
#include <vector>
#include <time.h>
#include "raylib.h"
#include "mathLib.h"
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
	float health = 0;
	float multiplier = 0;
	float timer = 0;
	float multTimer = 0;
	gen randGen;
	randGen.seedRand(time(NULL));
	string text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
	vec2 position = { 100,100 };\

	for (int i = 0; i < text.length(); ++i)
	{
		if (isblank(text[i])) wordCount++;
	}

	InitWindow(screenWidth, screenHeight, "orbital");

	Texture2D ball = LoadTexture("ballshade_1.png");
	vector<Entity> ents;
	vector<Entity> balls;
	balls.push_back(Entity("yellowball.png", vec2{ 400,400 }, (float)randGen.rand(1, 3)));
	balls.push_back(Entity("redball.png", vec2{ 600,350 }, (float)randGen.rand(1, 3)));
	balls.push_back(Entity("brownball.png", vec2{ 100,100 }, (float)randGen.rand(1, 3)));

	float myRad = 2 * PI / 4;

	vector<vec2> waypoint;
	waypoint.push_back(vec2{ 400, 150 });
	waypoint.push_back(vec2{ 700, 80 });
	waypoint.push_back(vec2{ 50, 250 });
	waypoint.push_back(vec2{ 400, 400 });
	waypoint.push_back(vec2{ 600, 350 });
	waypoint.push_back(vec2{ 500, 200 });
	waypoint.push_back(vec2{ 100, 100 });
	waypoint.push_back(vec2{ 200, 300 });

	vector<vec2> yellowPath;
	vector<vec2> redPath;
	vector<vec2> brownPath;
	

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		multiplier = sin((float)multTimer) * 100;
		multTimer += GetFrameTime() * 20;
		timer+= GetFrameTime();
		for (int i = 0; i < balls.size(); ++i)
		{
			balls[i].move(waypoint);
			if (balls[i].pos == waypoint[balls[i].i])
			{
				int previousWaypoint = balls[i].i;
				balls[i].startPos = waypoint[balls[i].i];
				balls[i].elapsed = 0;
				balls[i].left = !balls[i].left;
				while (balls[i].i == previousWaypoint)
				{
					balls[i].i = randGen.rand(0, (int)waypoint.size());
					balls[i].duration = randGen.rand(1, 3);
					std::cout << balls[i].i << std::endl;
				}
			}
		}
		if (timer > 1 && counter < 6)
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
		for (int i = 0; i < ents.size(); ++i)
		{
			ents[i].update(50, balls[0].pos);
		}
		yellowPath.push_back(balls[0].pos);
		if (yellowPath.size() > 30)
		{
			yellowPath.erase(yellowPath.begin());
		}
		redPath.push_back(balls[1].pos);
		if (redPath.size() > 30)
		{
			redPath.erase(redPath.begin());
		}
		brownPath.push_back(balls[2].pos);
		if (brownPath.size() > 30)
		{
			brownPath.erase(brownPath.begin());
		}
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		//textLength = MeasureText(text.c_str(), 20);
		//DrawText(text.c_str(), 0, 0, 20, LIGHTGRAY);
		//DrawText(SubText(text.c_str(), 0, 30), 0, 50, 20, LIGHTGRAY);
		for (int i = 0; i < waypoint.size(); ++i)
		{
			DrawTexturePro(ball, Rectangle{ 0,0,32,32 }, Rectangle{ waypoint[i].x,waypoint[i].y,16,16 }, Vector2{ 8,8 }, 0, WHITE);
		}
		if (yellowPath.size() > 2)
		{
			for (int i = 0; i < yellowPath.size() - 1; ++i)
			{
				DrawLineEx(yellowPath[i], yellowPath[i + 1], i, YELLOW);
				//DrawCircleLines(yellowPath[i].x, yellowPath[i].y, 5, WHITE);
			}
		}
		if (redPath.size() > 2)
		{
			for (int i = 0; i < redPath.size() - 1; ++i)
			{
				DrawLineEx(redPath[i], redPath[i + 1], i-2, RED);
				//DrawCircleLines(redPath[i].x, redPath[i].y, 5, WHITE);
			}
		}
		if (brownPath.size() > 2)
		{
			for (int i = 0; i < brownPath.size() - 1; ++i)
			{
				DrawLineEx(brownPath[i], brownPath[i + 1], i-1, DARKBROWN);
				//DrawCircleLines(brownPath[i].x, brownPath[i].y, 5, WHITE);
			}
		}
		for (int i = 0; i < balls.size(); ++i)
			balls[i].draw();
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
