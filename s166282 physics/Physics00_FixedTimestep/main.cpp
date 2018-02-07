#include "Physics00_FixedTimestepApp.h"

int main() {
	
	// allocation
	auto app = new Physics00_FixedTimestepApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}