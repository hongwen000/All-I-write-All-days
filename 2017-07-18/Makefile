CC=g++
SRC=./src
BIN=./bin
OBJ_DIR=./obj
OBJ=$(OBJ_DIR)/Record.o $(OBJ_DIR)/main.o
INCLUDE=-I/usr/local/include/opencv -I/usr/local/include -L/usr/local/lib
LIB=-lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core -pthread
all: $(OBJ)
	$(CC) $(INCLUDE) -o $(BIN)/Recoder $(OBJ)
$(OBJ_DIR)/main.o : main.cpp
	$(CC) $(LIB) -c main.cpp -o $(OBJ_DIR)/main.o
$(OBJ_DIR)/Record.o : $(SRC)/Record.cpp
	$(CC) $(LIB) -c $(SRC)/Record.cpp -o $(OBJ_DIR)Recod.o
clean:
	rm $(BIN)/Recoder $(OBJ)
