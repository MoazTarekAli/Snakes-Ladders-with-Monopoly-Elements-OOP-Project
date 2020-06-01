#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (add more as needed)
{
	//  [1] Actions of Design Mode

	ADD_LADDER,		// Add Ladder Action
	ADD_SNAKE,
	DELETE_OBJECT,// Add Snake Action	
	ADD_CARD,
// Add Card Action 
    COPY_CARD,
    CUT_CARD,
	PASTE_CARD,
	EDIT_CARD,	///Gadallah:el options el zyada 
	SAVE_GRID,
	OPEN_GRID,
	EXIT,			// Exit Application
	TO_PLAY_MODE,	// Go to Play Mode

	///TODO: Add more action types of Design Mode

	//  [2] Actions of Play Mode

	ROLL_DICE,	
    ADD_DICE_VALUE,
	NEW_GAME,
	EXIT2,
	TO_DESIGN_MODE,	// Go to Design Mode

	///TODO: Add more action types of Play Mode

	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

#endif