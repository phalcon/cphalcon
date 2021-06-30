
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use Phalcon\Storage\Adapter\AdapterInterface;
use SessionHandlerInterface;

abstract class AbstractAdapter implements SessionHandlerInterface
{
    /**
     * @var AdapterInterface
     */
    protected adapter;

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
        if !empty(id) && this->adapter->has(id) {
            return this->adapter->delete(id);
        }

        return true;
    }

    /**
     * Garbage Collector
     */
    public function gc(var maxlifetime)
    {
        return true;
    }

    /**
     * Read
     */
    public function read(var id) -> string
    {
        var data;
        let data = this->adapter->get(id);

        return null === data ? "" : data;
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
        return this->adapter->set(id, data);
    }
}
