#include <iostream>
#include "strategy.h"


IQuackBehavior::IQuackBehavior()
{
	std::cout << "Quack behavior support\n";
}

IQuackBehavior::~IQuackBehavior() noexcept
{
	std::cout << "Quack behavior terminated\n";
}

IFlyBehavior::IFlyBehavior()
{
	std::cout << "Fly behavior support\n";
}

IFlyBehavior::~IFlyBehavior() noexcept
{
	std::cout << "Fly behavior terminated\n";
}

IDisplayBehavior::IDisplayBehavior()
{
	std::cout << "Display behavior support\n";
}

IDisplayBehavior::~IDisplayBehavior() noexcept
{
	std::cout << "Display behavior terminated\n";
}

void SimpleFly::fly()
{
	std::cout << "Simply fly\n";
}

void ExtendedFly::fly()
{
	std::cout << "Flying for an extended amount of time.\n";
}

void SimpleQuack::quack()
{
	std::cout << "Simply quacking\n";
}

void NoQuack::quack()
{
	std::cout << "This duck does no quack.\n";
}

void TextDisplay::display()
{
	std::cout << "Simple text displaying of the duck.\n";
}

void GraphicalDisplay::display()
{
	std::cout << "Graphical displaying of ducks! The DUCK@!\n";
}

Duck::Duck( IDisplayBehavior* disp,
	IQuackBehavior* quack,
	IFlyBehavior* fly )
	:
	m_pDisplay{disp},
	m_pQuack{quack},
	m_pFly{fly},
	m_weight(4)
{
	std::cout << "Duck created.\n";
}

Duck::~Duck()
{
	std::cout << "The duck is gone!\n";
}

//Duck::Duck( Duck&& rhs ) noexcept
//	:
//	m_pDisplay{std::move( rhs.m_pDisplay )},
//	m_pQuack{std::move( rhs.m_pQuack )},
//	m_pFly{std::move( rhs.m_pFly )},
//	m_weight(rhs.m_weight)
//{
//
//}
// or delete to the maop:
Duck::Duck( Duck&& rhs ) noexcept
{
	*this = std::move( rhs );
}

Duck& Duck::operator=( Duck&& rhs ) noexcept
{
	std::swap( this->m_pDisplay, rhs.m_pDisplay );
	std::swap( this->m_pQuack, rhs.m_pQuack );
	std::swap( this->m_pFly, rhs.m_pFly );
	this->m_weight = rhs.m_weight;
	return *this;
}

void Duck::showcase() const
{
	m_pDisplay->display();
	m_pQuack->quack();
	m_pFly->fly();
}