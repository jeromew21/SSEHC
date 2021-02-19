#include <iostream>
#include <chrono>

#include "game/chessboard.hpp"
#include "uci/strings.hpp"
#include "uci/interface.hpp"
#include "tests/tests.hpp"
#include "tests/benchmarks.hpp"
#include "misc/version.hpp"

const int random_seed = 39132644;

bool verbose = false;

void verbose_info(const std::string &text)
{
  if (verbose)
    std::cout << "info string " << text << std::endl;
}

void init()
{
  seedRand(random_seed);
  init_bits();
  move_maps::init();
}

/*! \mainpage SSEHC
 * Main page
 */
int main(int argc, char *argv[])
{
  // parse args
  for (int i = 1; i < argc; i++)
  {
    std::string arg = std::string(argv[i]);
    if (arg == "--verbose")
    {
      verbose = true;
    }
    else if (arg == "--version")
    {
      std::cout << version_major << "." << version_minor << std::endl;
      exit(0);
    }
  }

  init();

  for (int i = 1; i < argc; i++)
  {
    std::string arg = std::string(argv[i]);
    if (arg == "--test")
    {
      run_tests();
      exit(0);
    }
  }
  
  for (int i = 1; i < argc; i++)
  {
    std::string arg = std::string(argv[i]);
    if (arg == "--benchmark")
    {
      run_benchmarks();
      exit(0);
    }
  }

  uci::listen();

  return 0;
}
