.PHONY: all build flash

FQBN=arduino:avr:leonardo
PORT=/dev/cu.usbmodem2301

all: build flash

build:
	arduino-cli compile --fqbn ${FQBN} morse

flash:
	arduino-cli upload -p ${PORT} --fqbn ${FQBN} morse
