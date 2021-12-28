#########
# tests #
#########


libgff_test_cram_sources = files([
    'cram/can_read.t',
])

test(
  'libgff quick local cram tests',
  libgff_cram_script,
  args : [
    '--xunit-file=' + join_paths(meson.project_build_root(), 'pbaa-short-cram-ccs.xml'),
    '--keep-tmpdir',
    '--verbose'] +
   libgff_test_cram_sources,
  env : [
    'BIN_DIR=' + join_paths(meson.project_build_root(), 'src'),
    'PROJECT_DIR=' + join_paths([meson.current_source_dir(), '..'])],
  timeout : 36000) # with '-O0 -g' tests can be *very* slow