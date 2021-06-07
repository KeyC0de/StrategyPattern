#pragma once

#include <iostream>
#include <memory>
#include <utility>

// family of related algorithms as interfaces
class IQuackBehavior
{
public:
	IQuackBehavior()
	{
		std::cout << "Quack behavior support" << '\n';
	}
	virtual ~IQuackBehavior() noexcept
	{
		std::cout << "Quack behavior terminated" << '\n';
	}
	virtual void quack() = 0;
};

class IFlyBehavior
{
public:
	IFlyBehavior()
	{
		std::cout << "Fly behavior support" << '\n';
	}
	virtual ~IFlyBehavior() noexcept
	{
		std::cout << "Fly behavior terminated" << '\n';
	}
	virtual void fly() = 0;
};

class IDisplayBehavior
{
public:
	IDisplayBehavior()
	{
		std::cout << "Display behavior support" << '\n';
	}
	virtual ~IDisplayBehavior() noexcept
	{
		std::cout << "Display behavior terminated" << '\n';
	}
	virtual void display() = 0;
};

// implementations of the interfaces
class SimpleFly
	: public IFlyBehavior
{
public:
	void fly() override
	{
		std::cout << "Simply fly\n";
	}
};
class ExtendedFly
	: public IFlyBehavior
{
public:
	void fly() override
	{
		std::cout << "Flying for an extended amount of time.\n";
	}
};

class SimpleQuack
	: public IQuackBehavior
{
public:
	void quack() override
	{
		std::cout << "Simply quacking\n";
	}
};
class NoQuack
	: public IQuackBehavior
{
public:
	void quack() override
	{
		std::cout << "This duck does no quack.\n";
	}
};

class TextDisplay
	: public IDisplayBehavior
{
public: 
	void display() override
	{
		std::cout << "Simple text displaying of the duck.\n";
	}
};
class GraphicalDisplay
	: public IDisplayBehavior
{
public: 
	void display() override {
		std::cout << "Graphical displaying of ducks! The DUCK@!\n";
	}
};


// the "Strategy" object
// regular classes use the algorithms they need and can vary them at runtime 
class Duck
{
	// this object supports the following behavioral algorithms:
	std::unique_ptr<IDisplayBehavior> m_disp;
	std::unique_ptr<IQuackBehavior> m_quack;
	std::unique_ptr<IFlyBehavior> m_fly;
	unsigned m_weight;
public:
	Duck() = delete;
	explicit Duck( IDisplayBehavior* disp,
		IQuackBehavior* quack,
		IFlyBehavior* fly )
		:
		m_disp{disp},
		m_quack{quack},
		m_fly{fly},
		m_weight{4}
	{
		std::cout << "Duck created.\n";
	}
	~Duck()
	{
		std::cout << "The duck is gone!\n";
	}

	Duck( Duck&& rhs ) noexcept
		:
		m_disp{ std::move( rhs.m_disp ) },
		m_quack{ std::move( rhs.m_quack ) },
		m_fly{ std::move( rhs.m_fly ) },
		m_weight{ rhs.m_weight }
	{}
	
	Duck& operator=( Duck&& rhs ) noexcept
	{
		if ( this != &rhs )
		{
			Duck temp( std::move( rhs ) );
			std::swap( this->m_disp, temp.m_disp );
			std::swap( this->m_quack, temp.m_quack );
			std::swap( this->m_fly, temp.m_fly );
			this->m_weight = temp.m_weight;
		}
		return *this;
	}

	void showcaseObject() const
	{
		m_disp->display();
		m_quack->quack();
		m_fly->fly();
	}
};
