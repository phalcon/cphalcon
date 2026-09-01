
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
 * Thrown when the router is asked to match without an action directory; the
 * convention cannot resolve sub-namespaces without one.
 */
class ActionDirectoryNotSet extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "No action directory set; call setActionDirectory()."
        );
    }
}
