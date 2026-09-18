
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by phalcon-api and AuraPHP
 * @link    https://github.com/phalcon/phalcon-api
 * @license https://github.com/phalcon/phalcon-api/blob/master/LICENSE
 * @link    https://github.com/auraphp/Aura.Payload
 * @license https://github.com/auraphp/Aura.Payload/blob/3.x/LICENSE
 *
 * @see Original inspiration for the https://github.com/phalcon/phalcon-api
 */

namespace Phalcon\Domain\Payload;

use Throwable;

/**
 * Holds the payload
 */
class Payload implements PayloadInterface
{
    /**
     * Exception if any
     */
    protected ?<Throwable> exception = null;

    /**
     * Extra information
     *
     * @var mixed
     */
    protected extras;

    /**
     * Input
     *
     * @var mixed
     */
    protected input;

    /**
     * Messages
     *
     * @var mixed
     */
    protected messages;

    /**
     * Output
     *
     * @var mixed
     */
    protected output;

    /**
     * Status
     *
     * @var mixed
     */
    protected status;

    /**
     * Gets the potential exception thrown in the domain layer
     */
    public function getException() -> <Throwable> | null
    {
        return this->exception;
    }

    /**
     * Extra information
     */
    public function getExtras() -> var
    {
        return this->extras;
    }

    /**
     * Input
     */
    public function getInput() -> var
    {
        return this->input;
    }

    /**
     * Messages
     */
    public function getMessages() -> var
    {
        return this->messages;
    }

    /**
     * Output
     */
    public function getOutput() -> var
    {
        return this->output;
    }

    /**
     * Status
     *
     * Status values are drawn from the `Status` vocabulary.
     *
     * @see Status
     */
    public function getStatus() -> var
    {
        return this->status;
    }

    /**
     * Sets an exception thrown in the domain
     */
    public function setException(<Throwable> exception) -> <PayloadInterface>
    {
        let this->exception = exception;

        return this;
    }

    /**
     * Sets arbitrary extra domain information.
     */
    public function setExtras(var extras) -> <PayloadInterface>
    {
        let this->extras = extras;

        return this;
    }

    /**
     * Sets the domain input.
     */
    public function setInput(var input) -> <PayloadInterface>
    {
        let this->input = input;

        return this;
    }

    /**
     * Sets the domain messages.
     */
    public function setMessages(var messages) -> <PayloadInterface>
    {
        let this->messages = messages;

        return this;
    }

    /**
     * Sets the domain output.
     */
    public function setOutput(var output) -> <PayloadInterface>
    {
        let this->output = output;

        return this;
    }

    /**
     * Sets the payload status.
     *
     * Status values are drawn from the `Status` vocabulary.
     *
     * @see Status
     */
    public function setStatus(var status) -> <PayloadInterface>
    {
        let this->status = status;

        return this;
    }
}
