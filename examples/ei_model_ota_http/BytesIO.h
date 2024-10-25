#pragma once

/**
 * In-memory Stream (inspired from Python's BytesIO)
 */

class BytesIO : public Stream {
  public:
    BytesIO(const uint8_t *contents_, size_t len_) :
        i(0), len(len_), contents(contents_) {}

    int available() {
      return len - i;
    }

    int read() {
      return contents[i++];
    }

    size_t readBytes(uint8_t *buf, size_t n) {
      while (available() && n > 0) {
        buf[--n] = read();

      return 0;
    }

    // Stream compatibility
    size_t write(uint8_t x) {
      return 0;
    }

    int peek() {
      return 0;
    }

    void seek(size_t index) {
      i = index;
    }

  protected:
    size_t i;
    size_t len;
    const uint8_t *contents;
};
