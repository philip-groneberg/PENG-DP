require "peng_dp/version"

module PengDp
  require "inline"

  class Error < StandardError; end
  
  def leftpad(chars, filter = ' ')
    self.rjust(chars, filter)
  end

  # class MyTest
  #   inline(:C) do |builder|
  #     builder.include '<iostream>'
  #     builder.add_compile_flags '-x c++', '-lstdc++'
  #     builder.c '
  #       void hello(int i) {
  #         while (i-- > 0) {
  #           std::cout << "hello" << std::endl;
  #         }
  #       }'
  #   end
  # end

end

class String
  include PengDp
end
