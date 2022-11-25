// given block i/o interface, build bytebuffer interface

// given block i/o interface, build bytebuffer interface

class BlockIO {
public:
  virtual void readBlock(int blockNumber, char* buffer) = 0;
  virtual void writeBlock(int blockNumber, char* buffer) = 0;
  virtual void seek(int blockNumber) = 0;
  virtual int blockSize() = 0;
};

class ByteBuffer {
public:
  ByteBuffer(BlockIO* blockIO, int blockSize, int numBlocks);
  void read(int position, char* buffer, int length);
  void write(int position, char* buffer, int length);
  void seek(int position);
private:
  BlockIO* blockIO;
  int blockSize;
  int numBlocks;
  int currentPosition;
  int blockNumber;
};

void read(int position, char* buffer, int length) {
  int blockNumber = position / blockSize;
  int blockOffset = position % blockSize;
  int bytesRemaining = length;
  int bytesToRead = 0;
  while (bytesRemaining > 0) {
    if (blockOffset + bytesRemaining > blockSize) {
      bytesToRead = blockSize - blockOffset;
    }
    else {
      bytesToRead = bytesRemaining;
    }
    blockIO->readBlock(blockNumber, buffer);
    blockNumber++;
    blockOffset = 0;
    bytesRemaining -= bytesToRead;
    buffer += bytesToRead;
  }
}

void write(int position, char* buffer, int length) {
  int blockNumber = position / blockSize;
  int blockOffset = position % blockSize;
  int bytesRemaining = length;
  int bytesToWrite = 0;
  while (bytesRemaining > 0) {
    if (blockOffset + bytesRemaining > blockSize) {
      bytesToWrite = blockSize - blockOffset;
    }
    else {
      bytesToWrite = bytesRemaining;
    }
    blockIO->writeBlock(blockNumber, buffer);
    blockNumber++;
    blockOffset = 0;
    bytesRemaining -= bytesToWrite;
    buffer += bytesToWrite;
  }
}

void seek(int position) {
  int blockNumber = position / blockSize;
  blockIO->seek(blockNumber);
}
