
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
 * Phalcon\Storage\SerializerLocatorFactory
 *
 * ServiceLocator implementation for Tag helpers
 */
class SerializerLocatorFactory implements LocatorFactoryInterface
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
            "base64"   : function (data) {
                return new \Phalcon\Storage\Serializer\Base64(data);
            },
            "igbinary" : function (data) {
                return new \Phalcon\Storage\Serializer\Igbinary(data);
            },
            "json"     : function (data) {
                return new \Phalcon\Storage\Serializer\Json(data);
            },
            "msgpack"  : function (data) {
                return new \Phalcon\Storage\Serializer\Msgpack(data);
            },
            "none"     : function (data) {
                return new \Phalcon\Storage\Serializer\None(data);
            },
            "php"      : function (data) {
                return new \Phalcon\Storage\Serializer\Php(data);
            }
        ];

        let locator = new Locator(helpers);

        return locator;
    }
}
