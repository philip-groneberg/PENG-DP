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
      // if (privacy_budget <= 0) {
      //   return absl::InvalidArgumentError("Not enough privacy budget.");
      // }
      // ASSIGN_OR_RETURN(std::unique_ptr<BoundedSum<int>> sum_algorithm,
      //                  BoundedSum<int>::Builder()
      //                      .SetEpsilon(epsilon)
      //                      .SetLower(0)
      //                      .SetUpper(150)
      //                      .Build());
      // for (double values : values) {
      //   sum_algorithm->AddEntry(values);
      // }
      // return sum_algorithm->PartialResult(privacy_budget);
      // ------------------------ Testing functionality code --------------------------
      // Uncomment code above and delete code below when dependency issues are resolved
      int sum = 0;
      for (double value : values) {
        sum += value;
      }
      // add epsilon for demonstration purposes
      return sum + epsilon;
    }

    int64_t Mean(const std::vector<double>& values, double epsilon, double privacy_budget) {
      // if (privacy_budget <= 0) {
      //   return absl::InvalidArgumentError("Not enough privacy budget.");
      // }
      // ASSIGN_OR_RETURN(std::unique_ptr<BoundedMean<int>> mean_algorithm,
      //                  BoundedMean<int>::Builder().SetEpsilon(epsilon).Build());
      // for (double value : values) {
      //   mean_algorithm->AddEntry(value);
      // }
      // return mean_algorithm->PartialResult(privacy_budget);
      // ------------------------ Testing functionality code --------------------------
      // Uncomment code above and delete code below when dependency issues are resolved
      int sum = 0;
      for (double value : values) {
        sum += value;
      }
      // add epsilon for demonstration purposes
      return (static_cast<double>(sum) / values.size()) + epsilon;
    }

    int64_t CountAbove(const std::vector<double>& values, double limit, double epsilon, double privacy_budget) {
      // if (privacy_budget <= 0) {
      //   return absl::InvalidArgumentError("Not enough privacy budget.");
      // }
      // ASSIGN_OR_RETURN(std::unique_ptr<Count<std::string>> count_algorithm,
      //                  Count<std::string>::Builder().SetEpsilon(epsilon).Build());

      // for (double value : values) {
      //   if (value > limit) {
      //     count_algorithm->AddEntry(value);
      //   }
      // }
      // return count_algorithm->PartialResult(privacy_budget);
      // ------------------------ Testing functionality code --------------------------
      // Uncomment code above and delete code below when dependency issues are resolved
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
      // if (privacy_budget <= 0) {
      //   return absl::InvalidArgumentError("Not enough privacy budget.");
      // }
      // ASSIGN_OR_RETURN(std::unique_ptr<Count<std::string>> count_algorithm,
      //                  Count<std::string>::Builder().SetEpsilon(epsilon).Build());

      // for (double value : values) {
      //     count_algorithm->AddEntry(value);
      // }
      // return count_algorithm->PartialResult(privacy_budget);
      // ------------------------ Testing functionality code --------------------------
      // Uncomment code above and delete code below when dependency issues are resolved
      int count = 0;
      for (double value : values) {
        ++count;
      }
      // add epsilon for demonstration purposes
      return count + epsilon;
    }

    int64_t Max(const std::vector<double>& values, double epsilon, double privacy_budget) {
      // ASSIGN_OR_RETURN(std::unique_ptr<continuous::Max<int>> max_algorithm,
      //                  continuous::Max<int>::Builder()
      //                      .SetEpsilon(epsilon)
      //                      .SetLower(0)
      //                      .SetUpper(150)
      //                      .Build());
      // for (double value : values) {
      //   max_algorithm->AddEntry(value);
      // }
      // return max_algorithm->PartialResult(privacy_budget);
      // ------------------------ Testing functionality code --------------------------
      // Uncomment code above and delete code below when dependency issues are resolved
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

