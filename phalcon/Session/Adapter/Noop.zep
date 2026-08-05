
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session\Adapter;

use SessionHandlerInterface;
use SessionUpdateTimestampHandlerInterface;

/**
 * Phalcon\Session\Adapter\Noop
 *
 * This is an "empty" or null adapter. It can be used for testing or any
 * other purpose that no session needs to be invoked
 *
 * ```php
 * <?php
 *
 * use Phalcon\Session\Manager;
 * use Phalcon\Session\Adapter\Noop;
 *
 * $session = new Manager();
 * $session->setAdapter(new Noop());
 * ```
 */
class Noop implements SessionHandlerInterface, SessionUpdateTimestampHandlerInterface
{
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
        return true;
    }

    /**
     * Garbage Collector
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
        return "";
    }

    /**
     * Refresh the session lifetime without changing the session data
     */
    public function updateTimestamp(string id, string data) -> bool
    {
        return true;
    }

    /**
     * Validate the session id (used when strict mode is enabled)
     */
    public function validateId(string id) -> bool
    {
        return true;
    }

    /**
     * Write
     */
    public function write(string id, string data) -> bool
    {
        return true;
    }
}
