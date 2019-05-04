
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Storage\Adapter\Libmemcached as StorageLibmemcached;
use Phalcon\Storage\SerializerFactory;
use SessionHandlerInterface;

/**
 * Phalcon\Session\Adapter\Libmemcached
 *
 * This is an "empty" or null adapter. It can be used for testing or any
 * other purpose that no session needs to be invoked
 *
 * <code>
 * <?php
 *
 * use Phalcon\Session\Manager;
 * use Phalcon\Session\Adapter\Libmemcached;
 *
 * $session = new Manager();
 * $adapter = new Libmemcached(
 *     [
 *         "servers" => [
 *             [
 *                 "host"   => "localhost",
 *                 "port"   => 11211,
 *                 "weight" => 1,
 *             ],
 *         ],
 *         "client" => [
 *              Memcached::OPT_HASH       => Memcached::HASH_MD5,
 *              Memcached::OPT_PREFIX_KEY => "prefix.",
 *         ],
 *         "ttl"    => 3600,
 *         "prefix" => "my_",
 *     ]
 * );
 *
 * $session->setHandler($adapter);
 * </code>
 */
class Libmemcached extends StorageLibmemcached implements SessionHandlerInterface
{
    /**
     * Constructor
     */
    public function __construct(<SerializerFactory> factory, array! options = []) -> void
    {
        let options["prefix"] = "sess-memc-";

        parent::__construct(factory, options);
    }

    /**
     * Close
     */
    public function close() -> bool
    {
        return true;
    }

    /**
     * Destroy
     */
    public function destroy(var id) -> bool
    {
        if !empty(id) && this->has(id) {
            return this->delete(id);
        }

        return true;
    }

    /**
     * Garbage Collector
     */
    public function gc(var maxlifetime) -> bool
    {
        return true;
    }

    /**
     * Read
     */
    public function read(var id) -> string
    {
        return this->get(id);
    }

    /**
     * Open
     */
    public function open(var savePath, var sessionName) -> bool
    {
        return true;
    }

    /**
     * Write
     */
    public function write(var id, var data) -> bool
    {
        return this->set(id, data);
    }
}
