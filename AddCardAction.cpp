#include "AddCardAction.h"
#include"Ladder.h"
#include"Snake.h"
#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include "CardFive.h"
#include "CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTwelve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"


AddCardAction::AddCardAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddCardAction::~AddCardAction()
{
}

void AddCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input *pIn=pGrid->GetInput();
	Output *pOut=pGrid->GetOutput();
	// 2- Read the "cardNumber" parameter and set its data member
	pOut->PrintMessage("Please enter card number");
	cardNumber = pIn->GetInteger(pOut);
	// 3- Read the "cardPosition" parameter (its cell position) and set its data member
	pOut->PrintMessage("Please click on card cell");
	cardPosition = pIn->GetCellClicked();
	// 4- Make the needed validations on the read parameters
	while (cardNumber<1 || cardNumber>14)
	{
		pOut->PrintMessage("Please Re-Enter a valid card number");
		cardNumber = pIn->GetInteger(pOut);
	}
	while (cardPosition.IsValidCell()==false)
	{
		pOut->PrintMessage("Please Re-Enter a valid Cell");
		cardPosition=pIn->GetCellClicked();
	}

	//gadallah:Valditaing that a card is not placed in the start of a ladder or snake
	Ladder* lFlag = dynamic_cast<Ladder*>(pGrid->getGameObject(cardPosition));
	Snake* sFlag = dynamic_cast<Snake*>(pGrid->getGameObject(cardPosition));


	while (lFlag != NULL || sFlag != NULL)
	{
		pOut->PrintMessage("invalid card cell,please enter a new cell ");
			cardPosition = pIn->GetCellClicked();
		 lFlag = dynamic_cast<Ladder*>(pGrid->getGameObject(cardPosition));
		 sFlag = dynamic_cast<Snake*>(pGrid->getGameObject(cardPosition));
	}

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddCardAction::Execute() 
{

	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	AddCardAction::ReadActionParameters();
	// 2- Switch case on cardNumber data member and create the appropriate card object type
	Card * pCard = NULL; // will point to the card object type
	switch (cardNumber)
	{
	case 1:
		pCard = new CardOne(cardPosition);
		break;

		// A- Add the remaining cases
															
	case 2:
		pCard = new CardTwo(cardPosition);
		break;
		
	case 3:
		pCard = new CardThree(cardPosition);
		break;

	case 4:
		pCard = new CardFour(cardPosition);
		break;
		
	case 5:
		pCard = new CardFive(cardPosition);
		break;

	case 6:
		pCard = new CardSix(cardPosition);
		break;
	
	case 7:
		pCard = new CardSeven(cardPosition);
		break;

	case 8:
		pCard = new CardEight(cardPosition);
		break;

	case 9:
		pCard = new CardNine(cardPosition);
		break;

	case 10:
		pCard = new CardTen(cardPosition);
		break;

	case 11:
		pCard = new CardEleven(cardPosition);
		break;

	case 12:
		pCard = new CardTwelve(cardPosition);
		break;

	case 13:
		pCard = new CardThirteen(cardPosition);
		break;

	case 14:
		pCard = new CardFourteen(cardPosition);
		break;

		
	}

	// 3- if pCard is correctly set in the switch case (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		// A- We get a pointer to the Grid from the ApplicationManager
		Grid* pGrid = pManager->GetGrid();
		// B- Make the "pCard" reads its card parameters: ReadCardParameters(), It is virtual and depends on the card type
		pCard->ReadCardParameters(pGrid);
		// C- Add the card object to the GameObject of its Cell:
		bool added = pGrid->AddObjectToCell(pCard);
		// D- if the GameObject cannot be added in the Cell, Print the appropriate error message on statusbar
		if (!added)
		{
			pGrid->PrintErrorMessage("Error: Cell already has an object, can't add card! Click to continue ...");
		}
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}
