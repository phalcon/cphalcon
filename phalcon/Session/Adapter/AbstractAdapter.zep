
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
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
    public function destroy(var sessionId) -> bool
    {
        if !empty(sessionId) && this->adapter->has(sessionId) {
            return this->adapter->delete(sessionId);
        }

        return true;
    }

    /**
     * Garbage Collector
     *
     * @param int $maxlifetime
     * @return false|int
     */
    public function gc(int maxlifetime) -> int|bool
    {
        return true;
    }

    /**
     * Read
     */
    public function read(var sessionId) -> string
    {
        var data;
        let data = this->adapter->get(sessionId);

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
    public function write(var sessionId, var data) -> bool
    {
        return this->adapter->set(sessionId, data);
    }

    /**
     * @todo Remove this when we get traits
     */
    protected function getArrVal(
        array! collection,
        var index,
        var defaultValue = null
    ) -> var {
        var value;

        if unlikely !fetch value, collection[index] {
            return defaultValue;
        }

        return value;
    }
}
