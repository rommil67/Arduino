#pragma once

#include <Banks/BankAddresses.hpp>
#include <MIDI_Outputs/Bankable/Abstract/MIDIAbsoluteEncoder.hpp>
#include <MIDI_Senders/ContinuousCCSender.hpp>

BEGIN_CS_NAMESPACE

namespace Bankable {
namespace ManyAddresses {

/**
 * @brief   A class of MIDIOutputElement%s that read the input of a **quadrature
 *          (rotary) encoder** and send out absolute MIDI **Control Change**
 *          events.
 * 
 * This version can be banked using an arbitrary list of alternative
 * addresses.
 *
 * @tparam  NumBanks
 *          The number of banks.
 * 
 * @ingroup ManyAddressesMIDIOutputElements
 */
template <size_t NumBanks>
class CCAbsoluteEncoder
    : public MIDIAbsoluteEncoder<NumBanks, ManyAddresses<NumBanks>,
                                 ContinuousCCSender> {
  public:
    /**
     * @brief   Construct a new Bankable CCAbsoluteEncoder object with the given 
     *          pins, controller, channel, speed factor, and number of pulses
     *          per step.
     * 
     * @param   bank
     *          The bank that selects the address to use.
     * @param   encoder
     *          The Encoder object to use.  
     *          Usually passed as a list of the two pins connected to the 
     *          A and B outputs of the encoder, e.g. `{2, 3}`.  
     *          The internal pull-up resistors will be enabled by the Encoder
     *          library.
     * @param   addresses
     *          The list of MIDI address containing the controller number 
     *          [0, 119], channel [CHANNEL_1, CHANNEL_16], and optional cable 
     *          number [0, 15].
     * @param   speedMultiply
     *          A constant factor to increase the speed of the rotary encoder.
     *          The difference in position will just be multiplied by this 
     *          factor. 
     * @param   pulsesPerStep
     *          The number of pulses per physical click of the encoder.
     *          For a normal encoder, this is 4. If you want to increase the
     *          resolution, for the use of Jog wheels, for example, you can go
     *          as 1.  
     *          Whereas a greater speedMultiply factor will increase the 
     *          speed, increasing the number of pulsesPerStep will result in a 
     *          lower speed.
     */
    CCAbsoluteEncoder(const Bank<NumBanks> &bank, AHEncoder &&encoder,
                      const Array<MIDIAddress, NumBanks> &addresses,
                      int16_t speedMultiply = 1, uint8_t pulsesPerStep = 4)
        : MIDIAbsoluteEncoder<NumBanks, ManyAddresses<NumBanks>,
                              ContinuousCCSender>(
              {bank, addresses}, std::move(encoder), speedMultiply,
              pulsesPerStep, {}) {}
};

} // namespace ManyAddresses
} // namespace Bankable

END_CS_NAMESPACE