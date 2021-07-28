require "peng_dp/version"
require "sample_callbacks"

module PengDp
  class Error < StandardError; end
  
  def dp_sum(column_name, epsilon = 1.0, privacy_budget = 10)
    if column_name.nil?
      raise ArgumentError, "Column name can not be nil."
    end
    cb = CallbackHolder.new
    cb.sum(self.pluck(column_name), epsilon, privacy_budget)
  end

  def dp_average(column_name, epsilon = 1.0, privacy_budget = 10)
    if column_name.nil?
      raise ArgumentError, "Column name can not be nil."
    end
    cb = CallbackHolder.new
    cb.mean(self.pluck(column_name), epsilon, privacy_budget)
  end

  def dp_count_above(column_name, limit = 0, epsilon = 1.0, privacy_budget = 10)
    if column_name.nil?
      raise ArgumentError, "Column name can not be nil."
    end
    cb = CallbackHolder.new
    cb.count_above(self.pluck(column_name), limit, epsilon, privacy_budget)
  end

  def dp_count(column_name = :id, epsilon = 1.0, privacy_budget = 10)
    if column_name.nil?
      raise ArgumentError, "Column name can not be nil."
    end
    cb = CallbackHolder.new
    cb.count(self.pluck(column_name), epsilon, privacy_budget)
  end

  def dp_maximum(column_name, epsilon = 1.0, privacy_budget = 10)
    if column_name.nil?
      raise ArgumentError, "Column name can not be nil."
    end
    cb = CallbackHolder.new
    cb.max(self.pluck(column_name), epsilon, privacy_budget)
  end

end

# Include functions into ActiveRecord
class ApplicationRecord < ActiveRecord::Base
  self.abstract_class = true
  extend PengDp
end

# class String
#   include PengDp
# end

# class Array
#   include PengDp
# end
