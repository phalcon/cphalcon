
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
use Phalcon\Storage\Serializer\Base64;
use Phalcon\Storage\Serializer\Igbinary;
use Phalcon\Storage\Serializer\Json;
use Phalcon\Storage\Serializer\MemcachedIgbinary;
use Phalcon\Storage\Serializer\MemcachedJson;
use Phalcon\Storage\Serializer\MemcachedPhp;
use Phalcon\Storage\Serializer\Msgpack;
use Phalcon\Storage\Serializer\None;
use Phalcon\Storage\Serializer\Php;
use Phalcon\Storage\Serializer\RedisIgbinary;
use Phalcon\Storage\Serializer\RedisJson;
use Phalcon\Storage\Serializer\RedisMsgpack;
use Phalcon\Storage\Serializer\RedisNone;
use Phalcon\Storage\Serializer\RedisPhp;
use Phalcon\Storage\Serializer\SerializerInterface;

class SerializerFactory extends AbstractFactory
{
    /**
     * SerializerFactory constructor.
     *
     * @param array services
     */
    public function __construct( array services = [])
    {
        this->init(services);
    }

    /**
     * @param string name
     *
     * @return SerializerInterface
     * @throws Exception
     */
    public function newInstance( string name) -> <SerializerInterface>
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
        return Exception::class;
    }

    /**
     * Returns the available adapters
     *
     * @return string[]
     */
    protected function getServices() -> array
    {
        return [
            "base64"             : Base64::class,
            "igbinary"           : Igbinary::class,
            "json"               : Json::class,
            "memcached_igbinary" : MemcachedIgbinary::class,
            "memcached_json"     : MemcachedJson::class,
            "memcached_php"      : MemcachedPhp::class,
            "msgpack"            : Msgpack::class,
            "none"               : None::class,
            "php"                : Php::class,
            "redis_igbinary"     : RedisIgbinary::class,
            "redis_json"         : RedisJson::class,
            "redis_msgpack"      : RedisMsgpack::class,
            "redis_none"         : RedisNone::class,
            "redis_php"          : RedisPhp::class
        ];
    }
}
