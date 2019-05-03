
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage;

use Phalcon\Service\Locator;
use Phalcon\Service\LocatorInterface;
use Phalcon\Service\LocatorFactoryInterface;

/**
 * Phalcon\Storage\AdapterLocatorFactory
 *
 * ServiceLocator implementation for Tag helpers
 */
class AdapterLocatorFactory implements LocatorFactoryInterface
{
    /**
     * Returns a Locator object with all the helpers defined in anonynous
     * functions
     */
    public function newInstance() -> <LocatorInterface>
    {
        var helpers, locator;

        /**
         * Available helpers. This needs to change when Zephir supports use
         * statements to inject the Escaper service in each helper
         */
        let helpers = [
            "apcu"         : function (options) {
                return new \Phalcon\Storage\Adapter\Apcu(options);
            },
            "libmemcached" : function (options) {
                return new \Phalcon\Storage\Adapter\Libmemcached(options);
            },
            "memory"       : function (options) {
                return new \Phalcon\Storage\Adapter\Memory(options);
            },
            "redis"        : function (options) {
                return new \Phalcon\Storage\Adapter\Redis(options);
            },
            "stream"       : function (options) {
                return new \Phalcon\Storage\Adapter\Stream(options);
            }
        ];

        let locator = new Locator(helpers);

        return locator;
    }
}
