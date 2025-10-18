#ifndef UIBEHAVIOR_H
#define UIBEHAVIOR_H

class UIBehavior {
public:
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual ~UIBehavior() = default;
};

#endif