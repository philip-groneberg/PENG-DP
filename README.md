# PengDp

Peng_dp is a gem that provides an easy to integrate solution of differential privacy to your Rails project by extending ActiveRecord helper functions like `count`, `average`, `sum` (and more), with the equivilent differential private function `dp_count`, `dp_average`, `dp_sum` (and more).

The differential privacy functionality is provided through the use of the https://github.com/google/differential-privacy building blocks.

**IMPORTANT**: Through some unsolved dependency issues does the current version (0.1.3) not provide actual differential private results (see Section Development). When these issues are resolved and differential private results can be guaranteed, the gem version will be updated to version 1.0.0.

## Installation

Add this line to your application's Gemfile:

```ruby
gem 'peng_dp'
```

And then execute:

    $ bundle install

Or install it yourself as:

    $ gem install peng_dp

## Usage

To use the gem replace the currently used ActiveRecord helper function with it's differential private equivalent.

| ActiveRecord function            | peng_dp equivalent           |
| :------------------------------- | :--------------------------: |
| sum(:column_name)                | dp_sum(:column_name)         |
| average(:column_name)            | dp_average(:column_name)     |
| count(:column_name)              | dp_count(:column_name)       |
| ---                              | dp_count_above(:column_name, limit) |
| maximum(:column_name)            | dp_maximum(:column_name)     |

To change the used `epsilon` value (default = 1) add them to the function call.

```ruby
# changes the epsilon value to 4
.dp_count(:column_name, 4)
```

The gem also provides a basic check for the remaining privacy budget that can also be provided as an additional value to the function call.

```ruby
# raises an error if remaining_privacy_budget is equal or smaller than 0
.dp_count(:column_name, 4, remaining_privacy_budget)
```

(For more information regarding `epsilon` and the `privacy budget` see https://github.com/google/differential-privacy)

An example project is available here: https://github.com/philip-groneberg/PENG-DP-example.

## Development

After checking out the repo, run `bin/setup` to install dependencies.

To install this gem onto your local machine, run `bundle exec rake install`. To release a new version, update the version number in `version.rb`, and then run `bundle exec rake release`, which will create a git tag for the version, push git commits and tags, and push the `.gem` file to [rubygems.org](https://rubygems.org).

To build and install the gem locally you need to create a shared object for the `C++` Code integration using [Rice](https://github.com/jasonroelofs/rice).

	$ ruby extconf.rb
	$ make

To then build the gem use:

	$ gem build peng_dp.gemspec

And to install the gem locally use (with the current version):

	$ gem install peng_dp-0.1.0.gem

### Debugging

Should there be missing path variables for the ruby development environment use:

	$ ridk enable

In case of a locked packman database remove `db.lck` file with:

	$ ridk exec rm /var/lib/pacman/db.lck

### Dependency issues

Currently there is an dependeny issue with the https://github.com/google/differential-privacy and it's integration through [Bazel](https://bazel.build/). Resulting from this all google differential private functions inside [lib/sample_callbacks.cpp](https://github.com/philip-groneberg/PENG-DP/blob/master/lib/sample_callbacks.cpp) are currently commented out and replaced by normal function behavior. 

When the dependency issue is resolved, uncomment the google differential private functions and delete the marked replacement code.

## Contributing

Bug reports and pull requests are welcome on GitHub at https://github.com/philip-groneberg/PENG-DP.


## License

The gem is available as open source under the terms of the [MIT License](https://opensource.org/licenses/MIT).
