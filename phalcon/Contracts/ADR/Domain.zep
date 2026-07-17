
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

namespace Phalcon\Contracts\ADR;

use Phalcon\Contracts\ADR\Payload\Payload;

/**
 * The business-logic seam - HTTP-free. Generic over its input type via docblock
 * generics: the runtime parameter is `var`, and the generic is enforced by the
 * IDE and static analysis through the generated stubs.
 *
 * @template TInput of object
 */
interface Domain
{
    /**
     * @param TInput $input
     */
    public function __invoke(var input) -> <Payload>;
}
