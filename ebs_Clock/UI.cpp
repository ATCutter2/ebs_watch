/*
 * UI.cpp
 *
 * Created: 29/12/2021 11:38:05
 *  Author: Adrian Schnyder
 */ 
#include "UI.h"


View::View(
		View* TopScreen     ,
		View* DeeperScreen  ,
		View* nextScreen    ,
		View* previousScreen
	){
		Top       =TopScreen      ;
		Deeper    =DeeperScreen   ;
		next      =nextScreen     ;
		previous  =previousScreen ;
	}
//////////////////////////////////////////////////////////////////////////
// Setup the Functions to be executed according to view here
void workingsMainView				   (){
	
}
void workingsMainViewSettings		   (){
	
	
}
void workingsTimeSettingsTimeZone	   (){
	
	
}
void workingsTimeSettingsTime		   (){
	
}
void workingsTimeSettingsTimeformat	   (){
	
}

void workingsMainViewSettingsSetUhrwerk(){
}

void workingsClockSettings			   (){
}


void workingsWeckerView				   (){
}

void workingsWeckerViewSettings		   (){
}

void workingsWeltStadtView			   (){
}

void workingsWeltStadtViewSettings	   (){
}


//////////////////////////////////////////////////////////////////////////
//Setup (initialize) Views according to HMI
void setupViews(void){
	//Global address of View is given to View class (hence &)
	//setup:
	//"view name" = View(View when Touch long   ,View when Touch short, View when Encoder clockwise, View when Encoder counterclockwise)
	//when no change of View insert "view name"
	MainView        = View(&MainView,&MainViewSettings,&MainViewSettingsSetUhrwerk,&MainViewSettingsSetUhrwerk);
		MainViewSettings       =  View(&MainView ,&TimeSettingsTimeZone   ,&TimeSettingsTimeZone   ,&TimeSettingsTimeformat  );		
		TimeSettingsTimeZone   =  View(&MainView ,&TimeSettingsTime       ,&TimeSettingsTimeZone   ,&TimeSettingsTimeZone    );		
		TimeSettingsTime       =  View(&MainView ,&TimeSettingsTimeformat ,&TimeSettingsTime       ,&TimeSettingsTime        );		
		TimeSettingsTimeformat =  View(&MainView ,&MainView               ,&TimeSettingsTimeformat ,&TimeSettingsTimeformat  );

		MainViewSettingsSetUhrwerk = View(&MainViewSettingsSetUhrwerk ,&ClockSettings   ,&MainViewSettings ,&MainViewSettings  );	
		ClockSettings              = View(&ClockSettings              ,&MainView        ,&ClockSettings    ,&ClockSettings     );	

	WeckerView      = View(&MainView,&WeckerViewSettings,&MainView,&WeltStadtView);
		WeckerViewSettings = View(&MainView  ,&WeckerViewSettings  ,&WeckerViewSettings ,&WeckerViewSettings);

	WeltStadtView   = View(&MainView,&MainViewSettings,&MainView,&WeckerView);
		WeltStadtViewSettings = View(&MainView ,&WeltStadtViewSettings ,&WeltStadtViewSettings ,&WeltStadtViewSettings); //TODO Test if walking trough settings works
	
		MainView					.executeFunction  = workingsMainView				   ; //giving a specific View a function
		MainViewSettings			.executeFunction  = workingsMainViewSettings		   ; 
		TimeSettingsTimeZone		.executeFunction  = workingsTimeSettingsTimeZone	   ; 
		TimeSettingsTime			.executeFunction  = workingsTimeSettingsTime		   ; 
		TimeSettingsTimeformat		.executeFunction  = workingsTimeSettingsTimeformat	   ; 
		
		MainViewSettingsSetUhrwerk	.executeFunction  = workingsMainViewSettingsSetUhrwerk ; 
		ClockSettings				.executeFunction  = workingsClockSettings			   ; 

		WeckerView					.executeFunction  = workingsWeckerView				   ; 
		WeckerViewSettings			.executeFunction  = workingsWeckerViewSettings		   ; 
		WeltStadtView				.executeFunction  = workingsWeltStadtView			   ; 
		WeltStadtViewSettings		.executeFunction  = workingsWeltStadtViewSettings	   ; 

}



