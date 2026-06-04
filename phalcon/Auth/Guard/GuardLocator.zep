
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

namespace Phalcon\Auth\Guard;

use Phalcon\Contracts\Auth\Guard\Guard;
use Phalcon\Support\AbstractLocator;

/**
 * Service locator for Phalcon\Auth guards. Utilizes the container to obtain
 * the service. For Phalcon\Container\Container one can use autowiring; for
 * Phalcon\Di\Di, register the guards in it before resolution.
 *
 * @extends AbstractLocator<Guard>
 */
class GuardLocator extends AbstractLocator
{
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
        return "Phalcon\\Contracts\\Auth\\Guard\\Guard";
    }

    /**
     * @return array<string, class-string<Guard>>
     */
    protected function getServices() -> array
    {
        return [
            "session" : "Phalcon\\Auth\\Guard\\Session",
            "token"   : "Phalcon\\Auth\\Guard\\Token"
        ];
    }
}
