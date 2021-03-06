require_relative 'lib/peng_dp/version'

Gem::Specification.new do |spec|
  spec.name          = "peng_dp"
  spec.version       = PengDp::VERSION
  spec.authors       = ["Kavin Hertwig", "Zaeem Athar", "Philip Groneberg"]
  spec.email         = ["p.groneberg@campus.tu-berlin.de"]

  spec.summary       = %q{A gem that implements basic differential privacy functions into ActiveRecords.}
  spec.description   = %q{The gem implements the basic functionality of the google differential privacy library to be used through ActiveRecords.}
  # spec.homepage      = "Put your gem's website or public repo URL here."
  spec.license       = "MIT"
  spec.required_ruby_version = Gem::Requirement.new(">= 2.3.0")

  # spec.metadata["allowed_push_host"] = "TODO: Set to 'http://mygemserver.com'"

  # spec.metadata["homepage_uri"] = spec.homepage
  # spec.metadata["source_code_uri"] = "https://github.com/philip-groneberg/PENG-DP"
  # spec.metadata["changelog_uri"] = "TODO: Put your gem's CHANGELOG.md URL here."

  # Specify which files should be added to the gem when it is released.
  # The `git ls-files -z` loads the files in the RubyGem that have been added into git.
  spec.files         = Dir.chdir(File.expand_path('..', __FILE__)) do
    `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^(test|spec|features)/}) }
  end
  spec.bindir        = "exe"
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }
  spec.require_paths = ["lib"]

  spec.add_dependency 'rice', '~> 4.0', '>= 4.0.2'
  spec.extensions = %w[lib/extconf.rb]
end
