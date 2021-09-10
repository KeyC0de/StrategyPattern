#pragma once

#include <memory>


// family of related algorithms as interfaces
class IQuackBehavior
{
public:
	IQuackBehavior();
	virtual ~IQuackBehavior() noexcept;

	virtual void quack() = 0;
};

class IFlyBehavior
{
public:
	IFlyBehavior();
	virtual ~IFlyBehavior() noexcept;

	virtual void fly() = 0;
};

class IDisplayBehavior
{
public:
	IDisplayBehavior();
	virtual ~IDisplayBehavior() noexcept;

	virtual void display() = 0;
};

// implementations of the interfaces
class SimpleFly
	: public IFlyBehavior
{
public:
	void fly() override;
};

class ExtendedFly
	: public IFlyBehavior
{
public:
	void fly() override;
};


class SimpleQuack
	: public IQuackBehavior
{
public:
	void quack() override;
};

class NoQuack
	: public IQuackBehavior
{
public:
	void quack() override;
};


class TextDisplay
	: public IDisplayBehavior
{
public: 
	void display() override;
};

class GraphicalDisplay
	: public IDisplayBehavior
{
public: 
	void display() override;
};


// the "Strategy" object
// it uses the algorithms it needs and can switch between them at runtime 
class Duck
{
	// this object supports the following behavioral algorithms:
	std::unique_ptr<IDisplayBehavior> m_pDisplay;
	std::unique_ptr<IQuackBehavior> m_pQuack;
	std::unique_ptr<IFlyBehavior> m_pFly;
	unsigned m_weight;
public:
	Duck() = delete;
	explicit Duck( IDisplayBehavior* disp, IQuackBehavior* quack, IFlyBehavior* fly );
	~Duck();

	Duck( Duck&& rhs ) noexcept;
	Duck& operator=( Duck&& rhs ) noexcept;

	void showcase() const;
};
