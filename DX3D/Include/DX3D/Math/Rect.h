#pragma once

#include <DX3D/Core/Core.h>

namespace dx3d {

	class Rect {

	public:
		Rect() = default;

		Rect(i32 width , i32 hight): 
			top(0),
			left(0),
			width(width),
			hight(hight)
		{
		}
		Rect(i32 top , i32 left, i32 width , i32 hight): 
			top(top),
			left(left),
			width(width),
			hight(hight)
		{
		}

	public:
		i32 top{}, left{}, width{}, hight{};
	};
}
