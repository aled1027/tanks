#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <boost/test/unit_test.hpp>
#include "../Entity.h"

// to compile: g++ test.cpp -lboost_unit_test_framework -o test
 
int add(int i, int j)
{
    return i + j;
}

BOOST_AUTO_TEST_CASE(universeInOrder) {
    // seven ways to detect and report the same error:
    BOOST_CHECK( add( 2,2 ) == 4 );        // #1 continues on error
            
    BOOST_REQUIRE( add( 2,2 ) == 4 );      // #2 throws on error
            
    if( add( 2,2 ) != 4 )
        BOOST_ERROR( "Ouch..." );            // #3 continues on error
            
    if( add( 2,2 ) != 4 )
        BOOST_FAIL( "Ouch..." );             // #4 throws on error
            
    if( add( 2,2 ) != 4 ) throw "Ouch..."; // #5 throws on error
            
    BOOST_CHECK_MESSAGE( add( 2,2 ) == 4,  // #6 continues on error
                            "add(..) result: " << add( 2,2 ) );
            
    BOOST_CHECK_EQUAL( add( 2,2 ), 4 );  // #7 continues on error
}

BOOST_AUTO_TEST_CASE( point_test ) {
    Point p(1.0,2.0);
    std::pair<float,float> pair = std::make_pair(2.0,2.0);
    std::pair<float,float> pair_ = p.getPair();
    BOOST_CHECK( pair == pair_);

    // BOOST_CHECK_EQUAL( p.getPair(), std::make_pair(1.0,2.0) ); // doesn't work with pairs -- see stackoverflow
}

BOOST_AUTO_TEST_CASE( entity_test) {
    Point p(-1.0,-2.0);
    Entity ent_def();
    Entity ent_norm(p,1.0,2.0,3.0,4.0,5.0);
    // BOOST_CHECK(ent_norm
}
