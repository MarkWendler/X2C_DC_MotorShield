from at.lcm.x2c.mplabscope.backend import ISymbolExternalInterface

from org.openide.util import Lookup


symbolInterface = Lookup.getDefault().lookup(ISymbolExternalInterface);
symbols = symbolInterface.getSymbols();
for symbol in symbols:
    print symbol
