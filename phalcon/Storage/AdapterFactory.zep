
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
use Phalcon\Storage\Adapter\AdapterInterface;
use Phalcon\Storage\SerializerFactory;

class AdapterFactory extends AbstractLocator
{
    /**
     * @var <SerializerFactory>
     */
    protected serializerFactory;

    /**
     * Constructor
     */
    public function __construct(<SerializerFactory> factory, array! mapper = []) -> void
    {
        var helpers;

        /**
         * Available helpers
         */
        let helpers = [
            "apcu"         : "\\Phalcon\\Storage\\Adapter\\Apcu",
            "libmemcached" : "\\Phalcon\\Storage\\Adapter\\Libmemcached",
            "memory"       : "\\Phalcon\\Storage\\Adapter\\Memory",
            "redis"        : "\\Phalcon\\Storage\\Adapter\\Redis",
            "stream"       : "\\Phalcon\\Storage\\Adapter\\Stream"
        ];

        let helpers                 = array_merge(helpers, mapper),
            this->serializerFactory = factory;

        this->init(helpers);
    }

    /**
     * Returns a serializer object
     */
    public function newInstance(string! name, array! options = []) -> <AdapterInterface>
    {
        let options = array_merge(
            [this->serializerFactory],
            options
        );

        return this->get(name, options);
    }
}


