
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 *
 * Implementation of this file has also been heavily influenced by Autoroute.
 *
 * @link    https://pmjones.io/adr/
 *
 * @link    https://github.com/pmjones/AutoRoute
 * @license https://github.com/pmjones/AutoRoute/blob/2.x/LICENSE.md
 */

namespace Phalcon\ADR\Router;

use Phalcon\Contracts\ADR\Router\RouterMatch as RouterMatchInterface;

/**
 * Immutable result of a successful route match.
 */
final class RouterMatch implements RouterMatchInterface
{
    /**
     * @var string
     */
    protected action;

    /**
     * @var array
     */
    protected attributes;

    /**
     * @var array
     */
    protected middleware;

    /**
     * @var string|null
     */
    protected name;

    public function __construct(
        string action, 
        array attributes = [], 
        array middleware = [], 
        string name = null
    ) {
        let this->action     = action,
            this->attributes = attributes,
            this->middleware = middleware,
            this->name       = name;
    }

    public function getAction() -> string
    {
        return this->action;
    }

    public function getAttributes() -> array
    {
        return this->attributes;
    }

    public function getMiddleware() -> array
    {
        return this->middleware;
    }

    public function getName() -> string | null
    {
        return this->name;
    }
}
