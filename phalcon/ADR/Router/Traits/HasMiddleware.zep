
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

namespace Phalcon\ADR\Router\Traits;

/**
 * Shared middleware accumulator for Route and Group: stores a list of middleware
 * class names, appended to and read back as an array.
 */
trait HasMiddleware
{
    /**
     * @var array
     */
    protected middleware = [];

    public function getMiddleware() -> array
    {
        return this->middleware;
    }

    public function pushMiddleware(array classes) -> void
    {
        var item;

        for item in classes {
            let this->middleware[] = item;
        }
    }
}
