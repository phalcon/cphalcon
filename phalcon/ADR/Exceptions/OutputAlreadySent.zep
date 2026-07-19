
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */

namespace Phalcon\ADR\Exceptions;

/**
 * Thrown when the emitter is asked to send a response after output has already
 * been sent.
 */
class OutputAlreadySent extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Output has already been sent; cannot emit the response."
        );
    }
}
