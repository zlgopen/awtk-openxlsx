import os
import platform
import scripts.app_helper as app

helper = app.Helper(ARGUMENTS);

helper.use_std_cxx(17)
helper.set_libs(['xlsx']).call(DefaultEnvironment)

CustomWidgetSConscriptFiles = []
SConscriptFiles = CustomWidgetSConscriptFiles + ['SConscript', 'demos/SConscript']
SConscript(SConscriptFiles)
