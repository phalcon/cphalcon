
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

namespace Phalcon\Contracts\ADR\Router;

/**
 * Validates, casts and converts a router match's positional tail segments into
 * named request attributes, driven by the matched Action's optional static
 * `params()` declaration.
 */
interface AttributeFilter
{
    public function filter(string actionClass, array attributes) -> array;
}
