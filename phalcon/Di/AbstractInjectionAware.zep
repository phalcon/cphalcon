
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

use stdClass;

/**
 * This abstract class offers common access to the DI in a class
 */
abstract class AbstractInjectionAware extends stdClass implements InjectionAwareInterface
{
    /**
     * Dependency Injector
     *
     * @var DiInterface
     */
    protected container;

    /**
     * Returns the internal dependency injector
     */
    public function getDI() -> <DiInterface>
    {
        return this->container;
    }

    /**
     * Sets the dependency injector
     */
    public function setDI(<DiInterface> container) -> void
    {
        let this->container = container;
    }
}
