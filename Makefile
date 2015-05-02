default: all

LIB_SRC_FILES = sample.c flow.c counter.c
APP_SRC_FILES = $(LIB_SRC_FILES) timerImpl.c flowSensorSimulator.c console.c main.c
APP_EXE_FILE = flow.exe
TEST_SRC_FILES = $(LIB_SRC_FILES) timerStub.c allTest.c
TEST_DEP_FILES = $(TEST_SRC_FILES) flowTest.c sampleTest.c
TEST_EXE_FILE = flowTest.exe
UNITY_SRC_FILES = unity\unity.c unity\unity_fixture.c

$(APP_EXE_FILE): $(APP_SRC_FILES)
	cl $(APP_SRC_FILES) /link user32.lib /out:$(APP_EXE_FILE)

$(TEST_EXE_FILE): $(TEST_DEP_FILES) $(UNITY_SRC_FILES)
	cl $(TEST_SRC_FILES) $(UNITY_SRC_FILES) /link user32.lib /out:$(TEST_EXE_FILE)

test: $(TEST_EXE_FILE)
	$(TEST_EXE_FILE)

build: $(APP_EXE_FILE)

all: build test

run: build
	start $(APP_EXE_FILE)

clean:
	del $(APP_EXE_FILE)
	del $(TEST_EXE_FILE)

pp:
	cl /E flowTest.c 

