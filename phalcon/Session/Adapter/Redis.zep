
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Storage\Adapter\Redis as StorageRedis;
use Phalcon\Helper\Arr;
use Phalcon\Session\Exception;
use SessionHandlerInterface;

/**
 * Phalcon\Session\Adapter\Noop
 *
 * This is an "empty" or null adapter. It can be used for testing or any
 * other purpose that no session needs to be invoked
 *
 * <code>
 * <?php
 *
 * use Phalcon\Session\Manager;
 * use Phalcon\Session\Adapter\Redis;
 *
 * $session = new Manager();
 * $adapter = new Redis(
 *     [
 *         "host"       => "localhost",
 *         "port"       => 6379,
 *         "auth"       => "foobared",
 *         "persistent" => false,
 *         "index"      => 0,
 *     ]
 * );
 *
 * $session->setHandler($adapter);
 * </code>
 */
 class Redis extends StorageRedis implements SessionHandlerInterface
{
    public function __construct(array! options = []) -> void
    {
        let options["prefix"] = "sess-reds-";

        parent::__construct(options);
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
