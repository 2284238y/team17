#include "catch.hpp"
#include<iostream>
#include<wiringPi.h>
#include<unistd.h>
#include"Sensor/sensor.h"
#include<cmath>

#define CATCH_CONFIG_MAIN

#define PIR   0
#define motor 3

#define MAX_TIME 100
#define DHT11PIN 7
#define ATTEMPTS 5

sensor s1;


TEST_CASE( "Base on the Humidity and Tem to calculate if it will snow  ", "[argument]" ) {
    
    SECTION( "Set the humidity and temperature to test" ) {
        s1.setTemp(10.5);
	s1.setHum(20.5);   
        s1.snowCal();
        REQUIRE( s1.getSnowPro() ==  );
    }
    SECTION( "Reset the humidity and temperature to test " ) {
	s1.setTemp(4.5);
	s1.setHum(60.5);   
        s1.snowCal();
        REQUIRE( s1.getSnowPro() ==  );
    }
    SECTION( "Reset the humidity and temperature to test" ) {
        s1.setTemp(1.0);
	s1.setHum(70);   
        s1.snowCal();
        REQUIRE( s1.getSnowPro() ==  );
    }
    SECTION( "Reset the humidity and temperature to test" ) {
        s1.setTemp(1.0);
	s1.setHum(70);   
        s1.snowCal();
        REQUIRE( s1.getSnowPro() ==  );
    }

}

TEST_CASE("Test Humidity and Temperature sensor"){
	s1.readTempHumSensor();	
        REQUIRE( s1.getHum()<=100);
	REQUIRE( s1.getTemp()>=-20);
}

TEST_CASE("Test PIR sensor"){
	s1.readIrSensor();	
        REQUIRE( s1.getIr()==0);
}


