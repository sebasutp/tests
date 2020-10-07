/**
 * Finds how many prime numbers are there up to a certain value passed as
 * parameter
 */

#include <iostream>
#include <vector>
#include <boost/program_options.hpp>

uint64_t map_sieve_ix(uint64_t ix) {
  return (ix - 3) / 2;
}

struct Sieve {
  std::vector<bool> sieve;
  uint64_t limit;
  uint64_t N;

  bool is_prime(uint64_t x) const {
    return (x==2) || sieve[map_sieve_ix(x)];
  }

  uint64_t count() const {
    return N;
  }

  void add_prime(uint64_t x) {
    N++;
    //std::cout << x << std::endl;
    for (uint64_t i = x*x; i <= limit; i += 2*x) {
      sieve[map_sieve_ix(i)] = false; // all multiples are not prime
    }
  }

  Sieve(uint64_t limit) {
    this->limit = limit;
    if (limit < 2) {
      N = 0;
      return;
    }
    N = 1; // The number 2 is prime, check from 3 onwards
    if (N == 2) return;
    sieve = std::vector<bool>(map_sieve_ix(limit)+2, true);
    //std::cout << "17: " << is_prime(17) << std::endl;
    for (uint64_t p=3; p<=limit; p+=2) {
      if (is_prime(p)) {
        add_prime(p);
        //std::cout << "17: " << is_prime(17) << std::endl;
      }
    }
  }
};

using namespace std;

int main(int argc, char* argv[]) {
  try {
    namespace po = boost::program_options;
    po::options_description desc("Allowed options");
    desc.add_options()
      ("help,h", "print usage message")
      ("limit,l", po::value<uint64_t>(), "up to which number do we count primes");
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")){
      cout << desc << endl;
      return 1;
    }
    if (vm.count("limit") == 0) {
      cout << "you must pass a limit (use --limit, check help)" << endl;
      return 1;
    }

    uint64_t limit = vm["limit"].as<uint64_t>();
    Sieve s(limit);
    cout << s.count() << endl;
  } catch (std::exception& ex) {
    cerr << "Error: " << ex.what() << endl;
    return 1;
  }
}
