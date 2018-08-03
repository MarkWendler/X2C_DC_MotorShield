from com.microchip.mplab.nbide.embedded.makeproject import HotProject
from org.netbeans.api.project import ProjectUtils

from at.lcm.x2c.mplabscope.backend import ISymbolExternalInterface
from at.lcm.x2c.mplabscope.backend import Backend
import at.lcm.x2c.mplabscope 
from org.openide.windows import TopComponent

from org.openide.modules import Modules

from org.openide.windows import WindowManager


from org.openide.util import Lookup


print Lookup.getDefault().lookup(ISymbolExternalInterface);

hotproject = HotProject.getProject();
if hotproject is None:
	print "#ERROR: cannot get current project"
else:
	print "Selected project:",ProjectUtils.getInformation(hotproject).getDisplayName()

assemblyProvider =  hotproject.getLookup()
print assemblyProvider

componentlooker = WindowManager.getDefault()
print componentlooker.getRegistry()
componentregistry = componentlooker.getRegistry()
components = componentregistry.getOpened()
for component in components:
  print component



moduleManager = Modules.getDefault()
print moduleManager
modules = moduleManager.getEnabledModules()
for module in modules:
  print module.getCodeName()
  
#scope = moduleManager.get("at.lcm.x2c.mplabscope")
scope = moduleManager.getModuleLookup()
#print scope



myLookup = Lookup.getDefault()
#print myLookup
scope = myLookup.lookup(mplabscope)
print scope