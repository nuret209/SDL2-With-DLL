/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

#include "src/Window.h"
int main(int argc, char *args[])
{
	// The window we'll be rendering to
	Window w(800, 600 , "baslik");
	w.init();
	while (!w.getQuit())
	{
		w.handleCloseEvent();
	}
	

	return 0;
}
