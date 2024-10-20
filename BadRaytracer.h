#pragma once

#include <Windows.h> //all ready failed
#include <iostream>
#include <cmath>

namespace BadRaytracer {

	HWND myconsole = GetConsoleWindow();//google
	HDC mydc = GetDC(myconsole);

	int screenX = 250;
	int screenY = 250;

	bool running = true;

	int frame = 0;

	class Ray {

	public:

		float ox, oy, oz, dx, dy, dz;

		bool SphereIntersection(float sx, float sy, float sz, float r) { // i <3 google
			float a = dx * dx + dy * dy + dz * dz;
			float b = 2 * (ox * dx + oy * dy + oz * dz - sx * dx - sy * dy - sz * dz);
			float c = ox * ox + oy * oy + oz * oz - sx * sx - sy * sy - sz * sz + r * r;

			float discriminant = b * b - 4 * a * c;
			if (discriminant < 0) {
				return false; // no intersection
			}

			float t0 = (-b - sqrt(discriminant)) / (2 * a);
			float t1 = (-b + sqrt(discriminant)) / (2 * a);

			return true; // intersection
		}

	};

	void Start() {

		//i don't really need it but like :D

	}

	void Loop() {

		for (int y = 0; y < screenY; y = y + 1) {
			
			for (int x = 0; x < screenX; x = x + 1) {
				
				Ray ray;
	
				ray.ox = x - (screenX / 2);
				ray.oy = y - (screenY / 2);
				ray.oz = 0;

				ray.dx = 0;
				ray.dy = 0;
				ray.dz = -1;

				if (ray.SphereIntersection(0, 0, -6, 5)) {

					SetPixel(mydc, x, y, RGB(0, 255, 0));

				}
				else {

					SetPixel(mydc, x, y, RGB(0, 0, 0));

				}
			}
		}

		frame += 1;

	}

	void End() {

		ReleaseDC(myconsole, mydc);
		std::cin.ignore();

	}
}