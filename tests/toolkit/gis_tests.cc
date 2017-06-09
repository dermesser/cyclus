#include <gtest/gtest.h>

#include <iostream>
#include <iostream>
#include <string>
#include "toolkit/gis.h"
using namespace std;

using cyclus::toolkit::GIS;

namespace cyclus {

class GISTest : public ::testing::Test {
 protected:
  GIS eiffel_, museum_, amsterdam_, barcelona_, urbana_, newyork_, bloomington_,
      sydney_, saopaulo_;
  virtual void SetUp() {
    /// Longitude and Lattitude of all objects were obtained from GeoHack :
    /// 'https://tools.wmflabs.org/geohack/'
    eiffel_.latitude(48.858222);
    eiffel_.longitude(2.2945);
    museum_.latitude(48.861111);
    museum_.longitude(2.336389);
    amsterdam_.latitude(52.37305);
    amsterdam_.longitude(4.892222);
    barcelona_.latitude(41.383333);
    barcelona_.longitude(2.183333);
    urbana_.latitude(40.109665);
    urbana_.longitude(-88.204247);
    newyork_.latitude(40.7127);
    newyork_.longitude(-74.0059);
    bloomington_.latitude(40.484167);
    bloomington_.longitude(-88.993611);
    sydney_.latitude(-33.865);
    sydney_.longitude(151.209444);
    saopaulo_.latitude(-23.55);
    saopaulo_.longitude(-46.633333);
  }
  virtual void TearDown(){};
};

/// Tests distance between two GIS objects or facilities in kilometers (KM)
/// Distances were obtained from:
/// 'https://www.freemaptools.com/how-far-is-it-between.htm'
TEST_F(GISTest, Distance) {
  EXPECT_NEAR(eiffel_.Distance(museum_), 3.188, 3.188 * 0.05)
      << "eiffel vs museum failed";
  EXPECT_NEAR(eiffel_.Distance(amsterdam_), 432.126, 432.126 * 0.01)
      << "eiffel vs amsterdam failed";
  EXPECT_NEAR(amsterdam_.Distance(barcelona_), 1240.110, 1240.110 * 0.01)
      << "amsterdam vs barcelona failed";
  EXPECT_NEAR(amsterdam_.Distance(newyork_), 5868.701, 5868.701 * 0.01)
      << "amsterdam vs newyork failed";
  EXPECT_NEAR(newyork_.Distance(urbana_), 1204.246, 1204.246 * 0.01)
      << "newyork vs urbana failed";
  EXPECT_NEAR(bloomington_.Distance(urbana_), 78.663, 78.663 * 0.01)
      << "bloomington vs urbana failed";
}

TEST_F(GISTest, ToStringD) {
  string ams_str = amsterdam_.ToString(GIS::StringFormat::D);
  string syd_str = sydney_.ToString(GIS::StringFormat::D);
  string sao_str = saopaulo_.ToString(GIS::StringFormat::D);
  string urb_str = urbana_.ToString(GIS::StringFormat::D);
  ASSERT_TRUE(ams_str == "+52.37305+004.892222/");
  ASSERT_TRUE(syd_str == "-33.865+151.2094/");
  ASSERT_TRUE(sao_str == "-23.55-046.63334/");
  ASSERT_TRUE(urb_str == "+40.10966-088.20425/");
}

TEST_F(GISTest, ToStringDM) {
  string ams_str = amsterdam_.ToString(GIS::StringFormat::DM);
  string syd_str = sydney_.ToString(GIS::StringFormat::DM);
  string sao_str = saopaulo_.ToString(GIS::StringFormat::DM);
  string urb_str = urbana_.ToString(GIS::StringFormat::DM);
  ASSERT_TRUE(ams_str == "+5222.383+00453.533/");
  ASSERT_TRUE(syd_str == "-3351.9+15112.567/");
  ASSERT_TRUE(sao_str == "-2333-04638/");
  ASSERT_TRUE(urb_str == "+4006.5799-08812.255/");
}

TEST_F(GISTest, ToStringDMS) {
  string ams_str = amsterdam_.ToString(GIS::StringFormat::DMS);
  string syd_str = sydney_.ToString(GIS::StringFormat::DMS);
  string sao_str = saopaulo_.ToString(GIS::StringFormat::DMS);
  string urb_str = urbana_.ToString(GIS::StringFormat::DMS);
  ASSERT_TRUE(ams_str == "+522223.0+0045332.0/");
  ASSERT_TRUE(syd_str == "-335154.0+1511234.0/");
  ASSERT_TRUE(sao_str == "-233260.0-0463800.0/");
  ASSERT_TRUE(urb_str == "+400634.8-0881215.3/");
  ASSERT_LE(ams_str.length(), 20);
  ASSERT_LE(syd_str.length(), 20);
  ASSERT_LE(sao_str.length(), 20);
  ASSERT_LE(urb_str.length(), 20);
}

}  // namespace cyclus
