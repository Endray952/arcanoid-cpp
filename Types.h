#pragma once
struct Point
{
	float x;
	float y;
};
struct Rect
{
	Point LeftTop;
	Point RighBottom;
};
enum Bonus {
	SECOND_BALL,
	WIDEN,
	NOTHING
};