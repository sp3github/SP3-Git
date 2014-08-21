#include "UI.h"

UI::UI(void)
{
}


UI::~UI(void)
{
}

void UI::RenderUI(StateType States)
{
	switch(States)
	{
	case PAUSE:
		break;
	case LEVEL:
		break;
	case STARTSCREEN:
		break;
	case ITEM:
		break;
	case VICTORY:
		break;
	case DEFEAT:
		break;
	case WINLEVEL:
		break;
	case BET:
		break;
	default:
		break;
	}
}

int UI::DetermineState(int choice)
{
	return 0;
}

void UI::Click(void)
{
}
