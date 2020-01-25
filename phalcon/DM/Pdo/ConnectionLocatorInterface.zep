
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */

namespace Phalcon\DM\Pdo;

use Phalcon\DM\Pdo\Connection\ConnectionInterface;

/**
 * Locates PDO connections for default, read, and write databases.
 */
interface ConnectionLocatorInterface
{
    /**
     * Returns the default connection object.
     *
     * @return ConnectionInterface
     */
    public function getMaster() -> <ConnectionInterface>;

    /**
     * Returns a read connection by name; if no name is given, picks a
     * random connection; if no read connections are present, returns the
     * default connection.
     *
     * @param string $name
     *
     * @return ConnectionInterface
     */
    public function getRead(string name = "") -> <ConnectionInterface>;

    /**
     * Returns a write connection by name; if no name is given, picks a
     * random connection; if no write connections are present, returns the
     * default connection.
     *
     * @param string $name
     *
     * @return ConnectionInterface
     */
    public function getWrite(string name = "") -> <ConnectionInterface>;

    /**
     * Sets the default connection registry entry.
     *
     * @param callable $callable
     *
     * @return ConnectionLocatorInterface
     */
    public function setMaster(callable callableObject) -> <ConnectionLocatorInterface>;

    /**
     * Sets a read connection registry entry by name.
     *
     * @param string   $name
     * @param callable $callable
     *
     * @return ConnectionLocatorInterface
     */
    public function setRead(string name, callable callableObject) -> <ConnectionLocatorInterface>;

    /**
     * Sets a write connection registry entry by name.
     *
     * @param string   $name
     * @param callable $callable
     *
     * @return ConnectionLocatorInterface
     */
    public function setWrite(string name, callable callableObject) -> <ConnectionLocatorInterface>;
}
