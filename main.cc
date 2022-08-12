// -*- coding: utf-8 -*-

#define EIGEN_DONT_PARALLELIZE // parallel off

#include <iostream>
//#include <ostream>
//#include <fstream>
//#include <vector>
//#include <Eigen/Dense>
//#include <chrono>
#include <cmath>

int main(){
  std::cout.precision(10); // Show 10 digits
  std::cout << std::scientific << std::endl;
//  constexpr double pi = std::acos(-1.0);

  double tt = 0.006; // tickness of plate
  double tw = 0.005; // tickness of waher
  double tb = 0.0115*0.6; // average tickness of bolt and nat
  double rr = 0.0075; // width (radius direction) of equal plate
  double rw = 0.007; // width (radius direction) of waher
  double rb = 0.012; // width (radius direction) of bolt or nat
  double neux; // neutral axis from bottom of plate
  double te; // equal tickness in washer area

  constexpr double ot = 1.0/3.0;

  // all stracture
  std::cout << "all stracture "  << std::endl;

  neux = (2.0*tt*rr*0.5*tt + 2.0*tw*rw*(tt + 0.5*tw) + 2.0*tb*rb*(tt + tw + 0.5*tb))/(2.0*tt*rr + 2.0*tw*rw + 2.0*tb*rb);

  std::cout << "neutral axis " << neux << std::endl;

  //  te = std::cbrt((ot*rw*std::pow(neux - tt, 3.0) + ot*rr*(std::pow(neux, 3.0) - std::pow(neux - tt, 3.0)) + ot*rw*std::pow(tw + tt - neux, 3.0) + ot*rb*(std::pow(tb + tw + tt - neux, 3.0) - std::pow(tw + tt - neux, 3.0)))/rr*12.0);

  //  std::cout << "equal tickness " << te << std::endl;

  // only upper stracture
  std::cout << "only upper stracture "  << std::endl;

  neux = (2.0*tw*rw*(0.5*tw) + 2.0*tb*rb*(tw + 0.5*tb))/(2.0*tw*rw + 2.0*tb*rb);

  //  std::cout << "areas # dbug " << 2.0*tw*rw + 2.0*tb*rb << std::endl;

  std::cout << "neutral axis " << neux << std::endl;

  double original_2nd_moment = (ot*2.0*rb*(std::pow(tb + tw - neux, 3.0) + std::pow(neux - tw, 3.0)) + ot*2.0*rw*(-std::pow(neux - tw, 3.0) + std::pow(neux, 3.0)));

  te = std::cbrt(original_2nd_moment/(2.0*rr)*12.0); // note rr

  std::cout << "equal tickness " << te << std::endl;

  std::cout << "equal section second moment " << 2.0*rr*std::pow(te, 3.0)/12.0 << std::endl;
  std::cout << "original section second moment " << original_2nd_moment << std::endl;
  std::cout << "equal section area " << 2.0*rr*te << std::endl;
  std::cout << "original section area " << 2.0*tw*rw + 2.0*tb*rb << std::endl;
  std::cout << "ratio of equal section area to original section area " << (2.0*rr*te)/(2.0*tw*rw + 2.0*tb*rb) << std::endl;
}
