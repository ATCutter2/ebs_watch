/*
 * UI.cpp
 *
 * Created: 29/12/2021 11:38:05
 *  Author: Adrian Schnyder
 */ 
#include "UI.h"
View::View(){
			Top       =nullptr ;
			Deeper    =nullptr ;
			next      =nullptr ;
			previous  =nullptr ;
			id	      =0 ;	
}

View::View(
		View* TopScreen     ,
		View* DeeperScreen  ,
		View* nextScreen    ,
		View* previousScreen,
		unsigned int identifier
	){
		Top       =TopScreen      ;
		Deeper    =DeeperScreen   ;
		next      =nextScreen     ;
		previous  =previousScreen ;
		id	      = identifier    ;
	}
//////////////////////////////////////////////////////////////////////////
// Setup the Functions to be executed according to view here
void workingsMainView				   (){
	//TODO Update the following with current values
	//viewchanes are to be executed in in userInput thread
	/*
	MainView.topString   	=            ;
	MainView.lowerString 	=            ;
	*/
}
void workingsMainViewSettings		   (){
	//TODO Update the following with current values
	//viewchanes are to be executed in in userInput thread
	/*
	MainViewSettings.topString   	=            ;
	MainViewSettings.lowerString 	=            ;
	*/
}
void workingsTimeSettingsTimeZone	   (){
	//TODO Update the following with current values
	//viewchanes are to be executed in in userInput thread
	/*
	TimeSettingsTimeZone.topString   	=            ;
	TimeSettingsTimeZone.lowerString 	=            ;
	*/
}
void workingsTimeSettingsTime		   (){
	//TODO Update the following with current values
	//viewchanes are to be executed in in userInput thread
	/*
	TimeSettingsTime.topString   	=            ;
	TimeSettingsTime.lowerString 	=            ;
	*/
}
void workingsTimeSettingsTimeformat	   (){
	//TODO Update the following with current values
	//viewchanes are to be executed in in userInput thread
	/*
	TimeSettingsTimeformat.topString   	=            ;
	TimeSettingsTimeformat.lowerString 	=            ;
	*/
}

void workingsMainViewSettingsSetUhrwerk(){
	//TODO Update the following with current values
	//viewchanes are to be executed in in userInput thread
	/*
	MainViewSettingsSetUhrwerk.topString   	=            ;
	MainViewSettingsSetUhrwerk.lowerString 	=            ;
	*/
}

void workingsClockSettings			   (){
	//TODO Update the following with current values
	//viewchanes are to be executed in in userInput thread
	/*
	ClockSettings.topString   	=            ;
	ClockSettings.lowerString 	=            ;
	*/
	}


void workingsWeckerView				   (){
	//TODO Update the following with current values
	//viewchanes are to be executed in in userInput thread
	/*
	WeckerView.topString   	=            ;
	WeckerView.lowerString 	=            ;
	*/
}

void workingsWeckerViewSettings		   (){
	//TODO Update the following with current values
	//viewchanes are to be executed in in userInput thread
	/*
	WeckerViewSettings.topString   	=            ;
	WeckerViewSettings.lowerString 	=            ;
	*/
}

void workingsWeltStadtView			   (){
	//TODO Update the following with current values
	//viewchanes are to be executed in in userInput thread
	/*
	WeltStadtView.topString   	=            ;
	WeltStadtView.lowerString 	=            ;
	*/
	}

void workingsWeltStadtViewSettings	   (){
	//TODO Update the following with current values
	//viewchanes are to be executed in in userInput thread
	/*
	WeltStadtViewSettings.topString   	=            ;
	WeltStadtViewSettings.lowerString 	=            ;
	*/
}

//////////////////////////////////////////////////////////////////////////
//Loop Function
static void viewLoop(){
	switch(Global_selectedView->id){
		case 1:   workingsMainView				     (); break;
		case 2:   workingsMainViewSettings		     (); break;
		case 3:   workingsTimeSettingsTimeZone	     (); break;
		case 4:   workingsTimeSettingsTime			 (); break;
		case 5:   workingsTimeSettingsTimeformat	 (); break;
		case 6:   workingsMainViewSettingsSetUhrwerk (); break;
		case 7:   workingsClockSettings			     (); break;
		case 8:   workingsWeckerView				 (); break;
		case 9:   workingsWeckerViewSettings		 (); break;
		case 10:  workingsWeltStadtView			     (); break;
		case 11:  workingsWeltStadtViewSettings	     (); break;
		default:  workingsMainView		             ();
	}											    
}

//////////////////////////////////////////////////////////////////////////
//Setup (initialize) Views according to HMI
void setupViews(void){
	//Global address of View is given to View class (hence &)
	//setup:
	//"view name" = View(View when Touch long   ,View when Touch short, View when Encoder clockwise, View when Encoder counterclockwise)
	//when no change of View insert "view name"
	MainView        = View(&MainView,&MainViewSettings,&MainViewSettingsSetUhrwerk,&MainViewSettingsSetUhrwerk,1);
		MainViewSettings       =  View(&MainView ,&TimeSettingsTimeZone   ,&TimeSettingsTimeZone   ,&TimeSettingsTimeformat ,2 );
		TimeSettingsTimeZone   =  View(&MainView ,&TimeSettingsTime       ,&TimeSettingsTimeZone   ,&TimeSettingsTimeZone   ,3 );
		TimeSettingsTime       =  View(&MainView ,&TimeSettingsTimeformat ,&TimeSettingsTime       ,&TimeSettingsTime       ,4 );
		TimeSettingsTimeformat =  View(&MainView ,&MainView               ,&TimeSettingsTimeformat ,&TimeSettingsTimeformat ,5 );

		MainViewSettingsSetUhrwerk = View(&MainViewSettingsSetUhrwerk ,&ClockSettings   ,&MainViewSettings ,&MainViewSettings,6 );	
		ClockSettings              = View(&ClockSettings              ,&MainView        ,&ClockSettings    ,&ClockSettings   ,7);	

	WeckerView      = View(&MainView,&WeckerViewSettings,&MainView,&WeltStadtView ,8);
		WeckerViewSettings = View(&MainView  ,&WeckerViewSettings  ,&WeckerViewSettings ,&WeckerViewSettings,9);

	WeltStadtView   = View(&MainView,&MainViewSettings,&MainView,&WeckerView,10);
		WeltStadtViewSettings = View(&MainView ,&WeltStadtViewSettings ,&WeltStadtViewSettings ,&WeltStadtViewSettings,11); //TODO Test if walking trough settings works
	

	Global_selectedView = &MainView;
}



