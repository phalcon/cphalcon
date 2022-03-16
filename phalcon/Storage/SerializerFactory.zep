
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage;

use Phalcon\Factory\AbstractFactory;
use Phalcon\Storage\Serializer\SerializerInterface;

class SerializerFactory extends AbstractFactory
{
    /**
     * SerializerFactory constructor.
     *
     * @param array services
     */
    public function __construct(array! services = [])
    {
        this->init(services);
    }

    /**
     * @param string name
     *
     * @return SerializerInterface
     * @throws Exception
     */
    public function newInstance(string! name) -> <SerializerInterface>
    {
        var definition;

        let definition = this->getService(name);

        return create_instance(definition);
    }

    /**
     * @return string
     */
    protected function getExceptionClass() -> string
    {
        return "Phalcon\\Storage\\Exception";
    }

    /**
     * Returns the available adapters
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "base64"             : "Phalcon\\Storage\\Serializer\\Base64",
            "igbinary"           : "Phalcon\\Storage\\Serializer\\Igbinary",
            "json"               : "Phalcon\\Storage\\Serializer\\Json",
            "memcached_igbinary" : "Phalcon\\Storage\\Serializer\\MemcachedIgbinary",
            "memcached_json"     : "Phalcon\\Storage\\Serializer\\MemcachedJson",
            "memcached_php"      : "Phalcon\\Storage\\Serializer\\MemcachedPhp",
            "msgpack"            : "Phalcon\\Storage\\Serializer\\Msgpack",
            "none"               : "Phalcon\\Storage\\Serializer\\None",
            "php"                : "Phalcon\\Storage\\Serializer\\Php",
            "redis_igbinary"     : "Phalcon\\Storage\\Serializer\\RedisIgbinary",
            "redis_json"         : "Phalcon\\Storage\\Serializer\\RedisJson",
            "redis_msgpack"      : "Phalcon\\Storage\\Serializer\\RedisMsgpack",
            "redis_none"         : "Phalcon\\Storage\\Serializer\\RedisNone",
            "redis_php"          : "Phalcon\\Storage\\Serializer\\RedisPhp"
        ];
    }
}
