
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
use SessionUpdateTimestampHandlerInterface;

abstract class AbstractAdapter implements SessionHandlerInterface, SessionUpdateTimestampHandlerInterface
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
     *
     * @param int $max_lifetime
     * @return false|int
     */
    public function gc(int max_lifetime) -> int|false
    {
        return 1;
    }

    /**
     * Open
     */
    public function open(var path, var name) -> bool
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
     * Refresh the session lifetime without changing the session data
     */
    public function updateTimestamp(var id, var data) -> bool
    {
        return this->write(id, data);
    }

    /**
     * Validate the session id (used when strict mode is enabled)
     */
    public function validateId(var id) -> bool
    {
        return this->adapter->has(id);
    }

    /**
     * Write
     */
    public function write(var id, var data) -> bool
    {
        return this->adapter->set(id, data);
    }

    /**
     * @todo Remove this when we get traits
     */
    protected function getArrVal(
         array collection,
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
