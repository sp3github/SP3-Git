#pragma once
class UI
{
public:
	enum StateType{
	PAUSE = 0,
	LEVEL,
	STARTSCREEN,
	ITEM,
	VICTORY,
	DEFEAT,
	WINLEVEL,
	BET
	};

	UI(void);
	~UI(void);

	void RenderUI(StateType States);

	int DetermineState(int choice);

	void Click(void);
};

