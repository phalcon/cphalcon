
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

namespace Phalcon\Contracts\ADR\Emitter;

use Phalcon\Http\ResponseInterface;

/**
 * Sends a response to the client. Called by the front controller only.
 */
interface Emitter
{
    public function emit(<ResponseInterface> response) -> void;
}
