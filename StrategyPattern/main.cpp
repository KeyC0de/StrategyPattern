#include "strategy.h"

int main()
{
	//Duck duck;
	Duck duck2{new GraphicalDisplay(), new SimpleQuack(), new ExtendedFly()};

	duck2.showcaseObject();
	// change behavior at runtime
	duck2 = Duck( new TextDisplay(), new NoQuack(), new SimpleFly() );
	duck2.showcaseObject();

	std::system( "pause" );
	return 0;
}