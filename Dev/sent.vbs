Set WshShell = WScript.CreateObject("WScript.Shell")
strName = wshShell.ExpandEnvironmentStrings( "%USERNAME%" )
WScript.sleep 200
        Wshshell.sendkeys"{enter}" 