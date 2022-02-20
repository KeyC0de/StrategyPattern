#include "strategy.h"


int main()
{
	//Duck duck;
	Duck duck2{new GraphicalDisplay(), new SimpleQuack(), new ExtendedFly()};

	duck2.showcase();
	// change behavior at runtime
	duck2 = Duck( new TextDisplay(), new NoQuack(), new SimpleFly() );
	duck2.showcase();

#if defined _DEBUG && !defined NDEBUG
	while ( !getchar() );
#endif
	return EXIT_SUCCESS;
}