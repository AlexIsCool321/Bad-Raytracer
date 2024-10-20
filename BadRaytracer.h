#pragma once

#include <Windows.h>
#include <iostream>
#include <cmath>

namespace BadRaytracer {

	HWND myconsole = GetConsoleWindow();
	HDC mydc = GetDC(myconsole);

	int screenX = 250;
	int screenY = 250;

	bool running = true;

	class Ray {

	public:

		float ox, oy, oz, dx, dy, dz;

		bool SphereIntersection(float sx, float sy, float sz, float r) {
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

		//idk dont really need it but like :D

	}

	void Loop() {

		for (int y = 0; y < screenY; y = y + 1) {
			
			for (int x = 0; x < screenX; x = x + 1) {
				
				Ray r;
	
				r.ox = x - (screenX / 2);
				r.oy = y - (screenY / 2);
				r.oz = 0;

				r.dx = 0;
				r.dy = 0;
				r.dz = -1;

				if (r.SphereIntersection(0, 0, -6, 5)) {

					SetPixel(mydc, x, y, RGB(255, 255, 255));

				}
				else {

					SetPixel(mydc, x, y, RGB(0, 0, 0));

				}
				
			}
			
		}
	}

	void End() {

		ReleaseDC(myconsole, mydc);
		std::cin.ignore();

	}

}