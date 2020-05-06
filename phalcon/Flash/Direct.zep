
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Flash;

/**
 * This is an implementation of the Phalcon\Flash\FlashInterface that
 * immediately outputs any message passed to it.
 */
class Direct extends AbstractFlash
{
    /**
     * Outputs a message
     *
     * @return null|string|void
     */
    public function message(string type, var message) -> string | null
    {
        return this->outputMessage(type, message);
    }

    /**
     * Prints the messages accumulated in the flasher
     */
    public function output(bool remove = true) -> void
    {
        var message;

        for message in this->messages {
            echo message;
        }

        if remove {
            parent::clear();
        }
    }
}
