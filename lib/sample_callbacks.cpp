#include <rice/rice.hpp>
#include <rice/stl.hpp>
// #include "cc/algorithms/count.h"

using namespace Rice;

namespace
{

  class CallbackHolder
  {
    public:

    int64_t Sum(const std::vector<double>& values, double epsilon, double privacy_budget) {
      int sum = 0;
      for (double value : values) {
        sum += value;
      }
      // add epsilon for demonstration purposes
      return sum + epsilon;
    }

    int64_t Mean(const std::vector<double>& values, double epsilon, double privacy_budget) {
      int sum = 0;
      for (double value : values) {
        sum += value;
      }
      // add epsilon for demonstration purposes
      return (static_cast<double>(sum) / values.size()) + epsilon;
    }

    int64_t CountAbove(const std::vector<double>& values, double limit, double epsilon, double privacy_budget) {
      int count = 0;
      for (double value : values) {
        if (value > limit) {
          ++count;
        }
      }
      // add epsilon for demonstration purposes
      return count + epsilon;
    }

    // Epsilon is a configurable parameter. A lower value means more privacy but
    // less accuracy.
    int64_t Count(const std::vector<double>& values, double epsilon, double privacy_budget) {
      // Construct the Count object to run on double inputs.
      // std::unique_ptr<differential_privacy::Count<double>> count =
      //    differential_privacy::Count<double>::Builder().SetEpsilon(epsilon)
      //                                                  .Build()
      //                                                  .ValueOrDie();

      // Compute the count and get the result.
      // base::StatusOr<differential_privacy::Output> result =
      //    count->Result(values.begin(), values.end());
      // if (!result.ok()) {
        // return 0;
      // }

      // GetValue can be used to extract the value from an Output protobuf. For
      // count, this is always an int64_t value.
      // return differential_privacy::GetValue<int64_t>(result.ValueOrDie());
      // return differential_privacy::GetValue<int64_t>((count->Result(values.begin(), values.end())).ValueOrDie());
      int count = 0;
      for (double value : values) {
        ++count;
      }
      // add epsilon for demonstration purposes
      return count + epsilon;
    }

    int64_t Max(const std::vector<double>& values, double epsilon, double privacy_budget) {
      int max = 0;
      for (double value : values) {
        if (value > max) {
          max = value;
        }
      }
      // add epsilon for demonstration purposes
      return max + epsilon;
    }


    Rice::Object callback_;
  };

} // namespace

extern "C"
void Init_sample_callbacks()
{
    define_class<CallbackHolder>("CallbackHolder")
      .define_constructor(Constructor<CallbackHolder>())
      .define_method("sum", &CallbackHolder::Sum)
      .define_method("mean", &CallbackHolder::Mean)
      .define_method("count_above", &CallbackHolder::CountAbove)
      .define_method("count", &CallbackHolder::Count)
      .define_method("max", &CallbackHolder::Max);
}

