/*
 * CountryTime.h
 *
 * Created: 23/12/2021 09:37:31
 *  Author: a
 */ 


#ifndef COUNTRYTIME_H_
#define COUNTRYTIME_H_
 

 struct countryTime{
	 char city[15];
	 int utcOffset;
	 //Todo DaylightSavingtime offset dependent on date
	 //bool daylightsavingTime;
	 //int daylightsavingDate1;
	 //int daylightsavingDate2;
	 };

countryTime worldCountryTime[24] ={
	{"Amsterdam"       , 1  },  
	{"Anchorage"       ,-9  },
	{"Bangkok"         , 7  },
	{"Bern"            , 1  },
	{"Bruessel"        , 1  },
	{"Chicago"         ,-6  },
	{"Hongkong"        , 8  },
	{"Istanbul"        , 3  },
	{"Karachi"         , 5  },
	{"London"          , 0  },
	{"Los Angeles"     ,-8  },
	{"Miami"           ,-5  },
	{"Moscow"          , 3  },
	{"Muscat"          , 4  },
	{"New-York"        ,-5  },
	{"Paris"           , 1  },
	{"Perth"           , 8  },
	{"Rio De Janeiro"  ,-3  },
	{"Santiago"        ,-4  },
	{"Seoul"           , 9  },
	{"Singapur"        , 8  },
	{"Sydney"          , 11 },
	{"Tokyo"           , 9  },
	{"Washington"      ,-8  }   
}


#endif /* COUNTRYTIME_H_ */