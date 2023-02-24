#include <random>

namespace xstl {
/// The structs: RandomGeneratorFunctionFactory, QuickRandomGenerator,
/// RandomContainerGenerator, XSTLRandomGenerator
/// TODO will create c-wrappers for these generators
struct RandomGenerator {
  // TODO
  // More sophisticated random value generator, with more added on customization
  // Its more general and customizable; it is a wrapper of the all other
  // generators
};

struct RandomGeneratorFunctionFactory {
  // TODO
  // group here: CreateRandom[T]GeneratorFunction() and its utils
  // Where T is a type to generate
};

struct QuickRandomGenerator {
  // TODO
  // group here: set_random_test_value() overloads
  // these functions generates a value of type T, where T is a primitive type
  // it does this with the least possible customization
  // s.t. the only parameter needed is the variable that stores the randomly
  // generated value
};

template <typename Container> struct RandomContainerGenerator {
  // TODO
  // This generator is used to generate dummy objects, where you pass in the
  // container type as a template paramert, you may also need to pass the
  // constructor of that `Container`, and the methods that the random generator
  // will use to push values to that container. For starters this maybe only
  // limited to container objects.
};

} // namespace xstl

template <typename RandomEngine = std::default_random_engine,
          typename Distrubution = std::uniform_int_distribution<int>,
          typename Generator = std::mt19937>
auto CreateRandomIntegerGeneratorFunction(int from = INT32_MIN,
                                          int to = INT32_MAX)
    -> decltype(std::bind(Distrubution(), Generator())) {
  RandomEngine engine;
  Generator generator(engine());
  Distrubution distribution(from, to);
  auto generate = std::bind(distribution, generator);

  return generate;
}
