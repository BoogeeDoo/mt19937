#include <random>

struct MyRand {
  std::mt19937 gen;
  std::uniform_int_distribution<int> dis;

  MyRand(int min, int max, int seed) : dis(min, max) { gen.seed(seed); }
};

extern "C" {

const int NUMERIC_LIMITS = std::numeric_limits<int>::max();

int ReturnNumericLimits() {
  return NUMERIC_LIMITS;
}

MyRand* CreateRand(int min = 0, int max = NUMERIC_LIMITS, int seed = 0) {
  MyRand* rand = new MyRand(min, max, seed);
  return rand;
}

int Generate(MyRand* rand) {
  return rand->dis(rand->gen);
}

void FreeRand(MyRand* rand) {
  delete rand;
}
}
