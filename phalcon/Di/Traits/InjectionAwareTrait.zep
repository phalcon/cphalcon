
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di\Traits;

use Phalcon\Di\DiInterface;

/**
 * This abstract class offers common access to the DI in a class
 *
 * Class AbstractInjectionAware
 *
 * @package Phalcon\Di
 *
 * @property object $container
 */
trait InjectionAwareTrait
{
    /**
     * Dependency Injector
     *
     * @var object|null
     */
    protected ?<DiInterface> container = null;

    /**
     * Returns the internal dependency injector
     */
    public function getDI() -> <DiInterface> | null
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

    /**
     * @param string $exceptionClass
     *
     * @return void
     */
    protected function checkContainer(
        string exceptionClass,
        string message,
        int code = 0
    ) -> void {
        if (null === this->container) {
            throw new {exceptionClass}(
                "A dependency injection container is required to access "
                . message,
                code
            );
        }
    }
}
