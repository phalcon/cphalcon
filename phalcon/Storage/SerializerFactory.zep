
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage;

use Phalcon\Service\AbstractLocator;
use Phalcon\Storage\Serializer\SerializerInterface;

class SerializerFactory extends AbstractLocator
{
    /**
     * Constructor
     */
    public function __construct(array! mapper = []) -> void
    {
        var helpers;

        /**
         * Available helpers
         */
        let helpers = [
            "base64"   : "Phalcon\\Storage\\Serializer\\Base64",
            "igbinary" : "Phalcon\\Storage\\Serializer\\Igbinary",
            "json"     : "Phalcon\\Storage\\Serializer\\Json",
            "msgpack"  : "Phalcon\\Storage\\Serializer\\Msgpack",
            "none"     : "Phalcon\\Storage\\Serializer\\None",
            "php"      : "Phalcon\\Storage\\Serializer\\Php"
        ];

        let helpers = array_merge(helpers, mapper);

        this->init(helpers);
    }

    /**
     * Returns a serializer object
     */
    public function newInstance(string! name) -> <SerializerInterface>
    {
        return this->get(name);
    }
}


