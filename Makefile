# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  GLFW_config = debug
  Glad_config = debug
  ImGui_config = debug
  Kokoro_config = debug
  Sandbox_config = debug

else ifeq ($(config),release)
  GLFW_config = release
  Glad_config = release
  ImGui_config = release
  Kokoro_config = release
  Sandbox_config = release

else ifeq ($(config),dist)
  GLFW_config = dist
  Glad_config = dist
  ImGui_config = dist
  Kokoro_config = dist
  Sandbox_config = dist

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := GLFW Glad ImGui Kokoro Sandbox

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

GLFW:
ifneq (,$(GLFW_config))
	@echo "==== Building GLFW ($(GLFW_config)) ===="
	@${MAKE} --no-print-directory -C Kokoro/vendor/GLFW -f Makefile config=$(GLFW_config)
endif

Glad:
ifneq (,$(Glad_config))
	@echo "==== Building Glad ($(Glad_config)) ===="
	@${MAKE} --no-print-directory -C Kokoro/vendor/Glad -f Makefile config=$(Glad_config)
endif

ImGui:
ifneq (,$(ImGui_config))
	@echo "==== Building ImGui ($(ImGui_config)) ===="
	@${MAKE} --no-print-directory -C Kokoro/vendor/imgui -f Makefile config=$(ImGui_config)
endif

Kokoro: GLFW Glad ImGui
ifneq (,$(Kokoro_config))
	@echo "==== Building Kokoro ($(Kokoro_config)) ===="
	@${MAKE} --no-print-directory -C Kokoro -f Makefile config=$(Kokoro_config)
endif

Sandbox: Kokoro
ifneq (,$(Sandbox_config))
	@echo "==== Building Sandbox ($(Sandbox_config)) ===="
	@${MAKE} --no-print-directory -C Sandbox -f Makefile config=$(Sandbox_config)
endif

clean:
	@${MAKE} --no-print-directory -C Kokoro/vendor/GLFW -f Makefile clean
	@${MAKE} --no-print-directory -C Kokoro/vendor/Glad -f Makefile clean
	@${MAKE} --no-print-directory -C Kokoro/vendor/imgui -f Makefile clean
	@${MAKE} --no-print-directory -C Kokoro -f Makefile clean
	@${MAKE} --no-print-directory -C Sandbox -f Makefile clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo "  dist"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   GLFW"
	@echo "   Glad"
	@echo "   ImGui"
	@echo "   Kokoro"
	@echo "   Sandbox"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"