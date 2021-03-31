project('scribby', 'c',
  license : 'GPLv3',
  default_options : [
    'c_std=gnu18'
    ]
)

cc = meson.get_compiler('c')

subdir('src')

libyaml = cc.find_library('yaml', required : true)

executable('scribbyd', sources : scribbyd_sources, dependencies : libyaml)
