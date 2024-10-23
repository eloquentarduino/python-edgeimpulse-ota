#pragma once

/**
 * In-memory Stream (inspired from Python's BytesIO)
 */

class BytesIO : public Stream {
  public:
    BytesIO(const uint8_t *c, size_t l) : contents(c), len(l), i(0) {}

    int available() {
      return len - i;
    }

    int read() {
      return contents[i++];
    }

    size_t readBytes(uint8_t *buf, size_t n) {
      size_t j = 0;

      while (available() && j < n) {
#ifdef EI_OTA_SWAP_BYTES
        buf[j] = read();
#else
        buf[n - j - 1] = read();
#endif
        j++;
      }

      return j;
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
