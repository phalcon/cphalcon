
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */

namespace Phalcon\Auth\Access;

use Phalcon\Auth\Internal\ContainerResolver;
use Phalcon\Contracts\Auth\Access\Access;
use Phalcon\Support\AbstractLocator;

/**
 * Service locator for Phalcon\Auth access gates. Utilizes the container to
 * obtain the service. For the Phalcon\Container\Container one can use
 * autowiring. For the Phalcon\Di\Di, one needs to register the gates in it
 * to be used here (the binary gates also resolve unregistered through Di's
 * class builder).
 *
 * @extends AbstractLocator<Access>
 *
 */
class AccessLocator extends AbstractLocator
{
    /**
     * Resolve a fresh gate instance from the container.
     *
     * Gates carry per-activation state (the only/except action filters), so
     * resolution must yield a fresh instance: new() on the Container
     * bypasses the instance cache; on the legacy Di, get() builds
     * unregistered classes and non-shared services fresh (register gates
     * non-shared).
     *
     * @return Access
     */
    public function newInstance(string name) -> object
    {
        return <Access> ContainerResolver::resolveFresh(
            this->container,
            this->getService(name)
        );
    }

    /**
     * @return class-string<\Throwable>
     */
    protected function getExceptionClass() -> string
    {
        return "Phalcon\\Auth\\Exception";
    }

    /**
     * @return class-string
     */
    protected function getInterfaceClass() -> string
    {
        return "Phalcon\\Contracts\\Auth\\Access\\Access";
    }

    /**
     * @return array<string, class-string<Access>>
     */
    protected function getServices() -> array
    {
        return [
            "acl"   : "Phalcon\\Auth\\Access\\Acl",
            "auth"  : "Phalcon\\Auth\\Access\\Auth",
            "guest" : "Phalcon\\Auth\\Access\\Guest"
        ];
    }
}
