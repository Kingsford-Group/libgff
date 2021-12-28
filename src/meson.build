###########
# sources #
###########

libgff_sources = files([
 'codons.cpp',
 'GArgs.cpp', 
 'GBase.cpp', 
 'gdna.cpp', 
 'GFaSeqGet.cpp', 
 'GFastaIndex.cpp', 
 'gff_utils.cpp',
 'gff.cpp', 
 'GStr.cpp',
 ])

 # install library if
# - either running as a proper project
# - or using shared libraries
libgff_lib_install = (not meson.is_subproject()) or (get_option('default_library') == 'shared')

libgff_lib = library(
  'libGFF',
  libgff_sources,
  soversion : meson.project_version(),
  version : meson.project_version(),
  install : libgff_lib_install,
  dependencies : libgff_lib_deps,
  include_directories : libgff_include_directories,
  cpp_args : libgff_cpp_args)


if not meson.is_subproject()
  executable(
    'TestGFFParse',
    files([
        'TestGFFParse.cpp',
    ]),
    install : true,
    dependencies : libgff_lib_deps,
    include_directories : libgff_include_directories,
    link_with : libgff_lib,
    cpp_args : libgff_cpp_args
  )
endif