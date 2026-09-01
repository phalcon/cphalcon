
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
use Phalcon\Traits\Support\Helper\Arr\GetTrait;
use SessionHandlerInterface;
use SessionUpdateTimestampHandlerInterface;

abstract class AbstractAdapter implements SessionHandlerInterface, SessionUpdateTimestampHandlerInterface
{
    use GetTrait;

    protected <AdapterInterface> adapter;

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
    public function destroy(string id) -> bool
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
    public function gc(int max_lifetime) -> false | int
    {
        return 1;
    }

    /**
     * Open
     */
    public function open(string path, string name) -> bool
    {
        return true;
    }

    /**
     * Read
     */
    public function read(string id) -> string
    {
        var data;
        let data = this->adapter->get(id);

        return null === data ? "" : data;
    }

    /**
     * Refresh the session lifetime without changing the session data
     */
    public function updateTimestamp(string id, string data) -> bool
    {
        return this->write(id, data);
    }

    /**
     * Validate the session id (used when strict mode is enabled)
     */
    public function validateId(string id) -> bool
    {
        return this->adapter->has(id);
    }

    /**
     * Write
     */
    public function write(string id, string data) -> bool
    {
        return this->adapter->set(id, data);
    }
}
