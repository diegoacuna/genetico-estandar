##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=tarea1_ag
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/diego/.codelite/workspace"
ProjectPath            := "/home/diego/.codelite/workspace/tarea1_ag"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=diego
Date                   :=08/27/2012
CodeLitePath           :="/home/diego/.codelite"
LinkerName             :=gcc
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=gcc
C_CompilerName         :=gcc
OutputFile             :=$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             := -g $(Preprocessors)
LinkOptions            :=  -lm
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)." 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/ag$(ObjectSuffix) $(IntermediateDirectory)/operadores$(ObjectSuffix) $(IntermediateDirectory)/seleccion$(ObjectSuffix) $(IntermediateDirectory)/utilidades$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.c $(IntermediateDirectory)/main$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "main.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/ag$(ObjectSuffix): ag.c $(IntermediateDirectory)/ag$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "ag.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/ag$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ag$(DependSuffix): ag.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/ag$(ObjectSuffix) -MF$(IntermediateDirectory)/ag$(DependSuffix) -MM "ag.c"

$(IntermediateDirectory)/ag$(PreprocessSuffix): ag.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ag$(PreprocessSuffix) "ag.c"

$(IntermediateDirectory)/operadores$(ObjectSuffix): operadores.c $(IntermediateDirectory)/operadores$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "operadores.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/operadores$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/operadores$(DependSuffix): operadores.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/operadores$(ObjectSuffix) -MF$(IntermediateDirectory)/operadores$(DependSuffix) -MM "operadores.c"

$(IntermediateDirectory)/operadores$(PreprocessSuffix): operadores.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/operadores$(PreprocessSuffix) "operadores.c"

$(IntermediateDirectory)/seleccion$(ObjectSuffix): seleccion.c $(IntermediateDirectory)/seleccion$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "seleccion.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/seleccion$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/seleccion$(DependSuffix): seleccion.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/seleccion$(ObjectSuffix) -MF$(IntermediateDirectory)/seleccion$(DependSuffix) -MM "seleccion.c"

$(IntermediateDirectory)/seleccion$(PreprocessSuffix): seleccion.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/seleccion$(PreprocessSuffix) "seleccion.c"

$(IntermediateDirectory)/utilidades$(ObjectSuffix): utilidades.c $(IntermediateDirectory)/utilidades$(DependSuffix)
	$(C_CompilerName) $(SourceSwitch) "utilidades.c" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/utilidades$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utilidades$(DependSuffix): utilidades.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/utilidades$(ObjectSuffix) -MF$(IntermediateDirectory)/utilidades$(DependSuffix) -MM "utilidades.c"

$(IntermediateDirectory)/utilidades$(PreprocessSuffix): utilidades.c
	@$(C_CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utilidades$(PreprocessSuffix) "utilidades.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ag$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ag$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ag$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/operadores$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/operadores$(DependSuffix)
	$(RM) $(IntermediateDirectory)/operadores$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/seleccion$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/seleccion$(DependSuffix)
	$(RM) $(IntermediateDirectory)/seleccion$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/utilidades$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/utilidades$(DependSuffix)
	$(RM) $(IntermediateDirectory)/utilidades$(PreprocessSuffix)
	$(RM) $(OutputFile)


