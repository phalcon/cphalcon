
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

/**
 * Marker contract for a per-endpoint Action. An Action is a Handler:
 * `__invoke(request): response`.
 */
interface Action extends Handler
{
}
