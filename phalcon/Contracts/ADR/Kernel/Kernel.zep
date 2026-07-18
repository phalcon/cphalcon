
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

namespace Phalcon\Contracts\ADR\Kernel;

/**
 * Boots the container, handles the incoming request and emits the response.
 * Returns a process exit code.
 */
interface Kernel
{
    public function run() -> int;
}
