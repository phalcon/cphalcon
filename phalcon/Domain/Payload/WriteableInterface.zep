
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
 * This interface is used for consumers (write)
 */
interface WriteableInterface
{
    /**
     * Sets an exception produced by the domain layer.
     *
     * @param Throwable $exception The exception thrown in the domain layer
     *
     * @return PayloadInterface
     */
    public function setException(<Throwable> exception) -> <PayloadInterface>;

    /**
     * Sets arbitrary extra values produced by the domain layer.
     *
     * @param mixed $extras Arbitrary extra values produced by the domain layer.
     *
     * @return PayloadInterface
     */
    public function setExtras(var extras) -> <PayloadInterface>;

    /**
     * Sets the input received by the domain layer.
     *
     * @param mixed $input The input received by the domain layer.
     *
     * @return PayloadInterface
     */
    public function setInput(var input) -> <PayloadInterface>;

    /**
     * Sets the messages produced by the domain layer.
     *
     * @param mixed $messages The messages produced by the domain layer.
     *
     * @return PayloadInterface
     */
    public function setMessages(var messages) -> <PayloadInterface>;

    /**
     * Sets the output produced from the domain layer.
     *
     * @param mixed $output The output produced from the domain layer.
     *
     * @return PayloadInterface
     */
    public function setOutput(var output) -> <PayloadInterface>;

    /**
     * Sets the status of this payload.
     *
     * @param mixed $status The status for this payload.
     *
     * @return PayloadInterface
     */
    public function setStatus(var status) -> <PayloadInterface>;
}
