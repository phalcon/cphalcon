
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

namespace Phalcon\Auth\Adapter;

use Phalcon\Auth\Exception;
use Phalcon\Contracts\Auth\Adapter\Adapter;
use Phalcon\Support\AbstractLocator;

/**
 * Service locator for Phalcon\Auth adapters. Utilizes the container to
 * obtain the service. For the Phalcon\Container\Container one can use
 * autowiring. For the Phalcon\Di\Di, one needs to register the gates in it
 * to be used here.
 *
 * @extends AbstractLocator<Adapter>
 *
 */
class AdapterLocator extends AbstractLocator
{
    /**
     * @return class-string<\Throwable>
     */
    protected function getExceptionClass() -> string
    {
        return Exception::class;
    }

    /**
     * @return class-string
     */
    protected function getInterfaceClass() -> string
    {
        return Adapter::class;
    }

    /**
     * @return array<string, class-string<Adapter>>
     */
    protected function getServices() -> array
    {
        return [
            "memory" : Memory::class,
            "model"  : Model::class,
            "stream" : Stream::class
        ];
    }
}
