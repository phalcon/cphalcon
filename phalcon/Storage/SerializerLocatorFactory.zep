
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage;

use Phalcon\Storage\SerializerLocator;
use Phalcon\Service\LocatorInterface;
use Phalcon\Service\LocatorFactoryInterface;

class SerializerLocatorFactory implements LocatorFactoryInterface
{
    /**
     * Returns a Locator object with all the helpers defined in anonynous
     * functions
     */
    public function newInstance() -> <LocatorInterface>
    {
        var locator, helpers;

        /**
         * Available helpers
         */
        let helpers = [
            "base64"   : function () { return new \Phalcon\Storage\Serializer\Base64(); },
            "igbinary" : function () { return new \Phalcon\Storage\Serializer\Igbinary(); },
            "json"     : function () { return new \Phalcon\Storage\Serializer\Json(); },
            "msgpack"  : function () { return new \Phalcon\Storage\Serializer\Msgpack(); },
            "none"     : function () { return new \Phalcon\Storage\Serializer\None(); },
            "php"      : function () { return new \Phalcon\Storage\Serializer\Php(); }
        ];

        let locator = new SerializerLocator(helpers);

        return locator;
    }
}


