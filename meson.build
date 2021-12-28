project(
  'libgff',
  ['cpp', 'c'],
  version : '1.0.1',
  default_options : [
    'buildtype=release',
    'warning_level=3',
    'cpp_std=c++14',
    'c_std=c11',
    'b_ndebug=if-release'],
  license : 'MIT',
  meson_version : '>= 0.57.0')

cxxflag = [
  '-Wduplicated-cond',
  '-Wduplicated-branches',
  '-Wlogical-op',
  '-Wrestrict',
  '-Wnull-dereference',
  '-Wuseless-cast',
  '-Wdouble-promotion',
  '-Wshadow',
  '-Wformat=1',
]

cpp = meson.get_compiler('cpp')

libgff_cpp_args = []

foreach cf : cxxflag
  if cpp.has_argument(cf)
    libgff_cpp_args += cf
  endif
endforeach

################
# dependencies #
################

libgff_lib_deps = []

###########
# headers #
###########

subdir('include')

#####################
# sources + library #
#####################

subdir('src')

##########
# extras #
##########

if not meson.is_subproject()
  # tests
  if get_option('tests')
    libgff_cram_script = find_program('cram', required : false)
    if not libgff_cram_script.found()
      warning('Using bundled cram script')
      libgff_cram_script = find_program('scripts/cram', required : true)
    endif

    subdir('tests')
  endif
endif