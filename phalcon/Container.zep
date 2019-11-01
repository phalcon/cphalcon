
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

use Psr\Container\ContainerInterface;
use Phalcon\Di\DiInterface;

/**
 * PSR-11 Wrapper for `Phalcon\Di`
 */
class Container implements ContainerInterface
{
    /**
     * @var DiInterface
     */
    protected container;

    /**
     * Phalcon\Container constructor
     */
    public function __construct(<DiInterface> container)
    {
        let this->container = container;
    }

    /**
     * Return the service
     */
    public function get(var name) -> var
    {
        return this->container->getShared(name);
    }

    /**
     * Whether a service exists or not in the container
     */
    public function has(var name) -> bool
    {
        return this->container->has(name);
    }
}
