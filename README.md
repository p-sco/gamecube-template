# gamecube-template
A template for a devkitPro PowerPC environment in VS Code, suitable for Wii or Gamecube Homebrew development.

Using 'Terminal' -> 'Run Task', there are options to run make tasks to create debug or release builds which will be named after the current workspace as .dol and .elf files.
You can run 'clean' to get rid of the previously created builds.
You can choose to run Dolphin_run to execute the build in normal emulation mode, or you can run Dolphin_debug to execute the build in Dolphin Debug mode.

 Requires devkitPro installation. Make sure all paths are pointed correctly in .vscode files depending on your project structure. 
 Must have full Dolphin emulator in directory with all associated files.
