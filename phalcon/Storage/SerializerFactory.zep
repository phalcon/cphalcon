
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
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
     * @return mixed
     * @throws Exception
     */
    public function newInstance(string! name) -> <SerializerInterface>
    {
        this->checkService(name);

        return this->services[name];
    }

    protected function getAdapters() -> array
    {
        return [
            "base64"   : "\\Phalcon\\Storage\\Serializer\\Base64",
            "igbinary" : "\\Phalcon\\Storage\\Serializer\\Igbinary",
            "json"     : "\\Phalcon\\Storage\\Serializer\\Json",
            "msgpack"  : "\\Phalcon\\Storage\\Serializer\\Msgpack",
            "none"     : "\\Phalcon\\Storage\\Serializer\\None",
            "php"      : "\\Phalcon\\Storage\\Serializer\\Php"
        ];
    }
}
