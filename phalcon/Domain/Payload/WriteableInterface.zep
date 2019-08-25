
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

use Phalcon\Domain\Payload\PayloadInterface;

/**
 * This interface is used for consumers (write)
 */
interface WriteableInterface
{
    /**
     * Sets the status of this payload.
     *
     * @param mixed $status The status for this payload.
     */
    public function setStatus(var status) -> <PayloadInterface>;

    /**
     *
     * Sets the input received by the domain layer.
     *
     * @param mixed $input The input received by the domain layer.
     *
     */
    public function setInput(var input) -> <PayloadInterface>;

    /**
     * Sets the output produced from the domain layer.
     *
     * @param mixed $output The output produced from the domain layer.
     */
    public function setOutput(var output) -> <PayloadInterface>;

    /**
     * Sets the messages produced by the domain layer.
     *
     * @param mixed $messages The messages produced by the domain layer.
     */
    public function setMessages(var messages) -> <PayloadInterface>;

    /**
     * Sets arbitrary extra values produced by the domain layer.
     *
     * @param mixed $extras Arbitrary extra values produced by the domain layer.
     */
    public function setExtras(var extras) -> <PayloadInterface>;
}
