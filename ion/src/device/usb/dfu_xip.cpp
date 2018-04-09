#include "calculator.h"
#include "../device.h"

namespace Ion {
namespace USB {

void DFU() {
  if (Ion::USB::Device::Calculator::PollAndReset()) {
    Ion::Device::jumpReset();
  }
}

}
}
