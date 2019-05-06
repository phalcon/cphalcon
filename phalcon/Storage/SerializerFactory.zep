
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage;

use Phalcon\Storage\Serializer\SerializerInterface;

class SerializerFactory
{
    /**
     * @var array
     */
    private mapper = [];

    /**
     * @var array
     */
    private services = [];

    /**
     * SerializerFactory constructor.
     *
     * @param array services
     */
    public function __construct(array! services = [])
    {
        var helpers, name, service;

        let helpers = [
            "base64"   : "\\Phalcon\\Storage\\Serializer\\Base64",
            "igbinary" : "\\Phalcon\\Storage\\Serializer\\Igbinary",
            "json"     : "\\Phalcon\\Storage\\Serializer\\Json",
            "msgpack"  : "\\Phalcon\\Storage\\Serializer\\Msgpack",
            "none"     : "\\Phalcon\\Storage\\Serializer\\None",
            "php"      : "\\Phalcon\\Storage\\Serializer\\Php"
        ];

        let helpers = array_merge(helpers, services);

        for name, service in helpers {
            let this->mapper[name] = service;
            unset(this->services[name]);
        }
    }

    /**
     * @param string name
     *
     * @return mixed
     * @throws Exception
     */
    public function newInstance(string! name) -> <SerializerInterface>
    {
        var definition;

        if !isset this->mapper[name] {
            throw new Exception("Service " . name . " is not registered");
        }

        if !isset this->services[name] {
            let definition           = this->mapper[name],
                this->services[name] = new {definition}();
        }

        return this->services[name];
    }
}
