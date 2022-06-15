#pragma once
struct Point
{
	float x;
	float y;
};
struct Rect
{
	int x0;
	int y0;
	int x1;
	int y1;
};
enum Bonus {
	SECOND_BALL,
	WIDEN,
	NOTHING
};