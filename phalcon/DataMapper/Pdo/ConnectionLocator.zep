
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

namespace Phalcon\DataMapper\Pdo;

use Phalcon\DataMapper\Pdo\Connection\ConnectionInterface;
use Phalcon\DataMapper\Pdo\Exception\ConnectionNotFound;

/**
 * Manages Connection instances for default, read, and write connections.
 *
 * @property callable $master
 * @property array    $read
 * @property array    $write
 */
class ConnectionLocator implements ConnectionLocatorInterface
{
    /**
     * A default Connection connection factory/instance.
     *
     * @var ConnectionInterface
     */
    protected master;

    /**
     * A registry of Connection "read" factories/instances.
     *
     * @var array
     */
    protected read = [];

    /**
     * A registry of Connection "write" factories/instances.
     *
     * @var array
     */
    protected write = [];

    /**
     * A collection of resolved instances
     *
     * @var array
     */
    private instances = [];

    /**
     * Constructor.
     *
     * @param ConnectionInterface $master
     * @param array               $read
     * @param array               $write
     */
    public function __construct(
        <ConnectionInterface> master,
        array read = [],
        array write = []
    ) {
        var name, callableObject;

        this->setMaster(master);

        for name, callableObject in read {
            this->setRead(name, callableObject);
        }

        for name, callableObject in write {
            this->setWrite(name, callableObject);
        }
    }

    /**
     * Returns the default connection object.
     *
     * @return ConnectionInterface
     */
    public function getMaster() -> <ConnectionInterface>
    {
        return this->master;
    }

    /**
     * Returns a read connection by name; if no name is given, picks a
     * random connection; if no read connections are present, returns the
     * default connection.
     *
     * @param string $name
     *
     * @return ConnectionInterface
     * @throws ConnectionNotFound
     */
    public function getRead(string name = "") -> <ConnectionInterface>
    {
        return this->getConnection("read", name);
    }

    /**
     * Returns a write connection by name; if no name is given, picks a
     * random connection; if no write connections are present, returns the
     * default connection.
     *
     * @param string $name
     *
     * @return ConnectionInterface
     * @throws ConnectionNotFound
     */
    public function getWrite(string name = "") -> <ConnectionInterface>
    {
        return this->getConnection("write", name);
    }

    /**
     * Sets the default connection factory.
     *
     * @param ConnectionInterface $callable
     *
     * @return ConnectionLocatorInterface
     */
    public function setMaster(<ConnectionInterface> callableObject) -> <ConnectionLocatorInterface>
    {
        let this->master = callableObject;

        return this;
    }

    /**
     * Sets a read connection factory by name.
     *
     * @param string   $name
     * @param callable $callable
     *
     * @return ConnectionLocatorInterface
     */
    public function setRead(
        string name,
        callable callableObject
    ) -> <ConnectionLocatorInterface> {
        let this->read[name] = callableObject;

        return this;
    }

    /**
     * Sets a write connection factory by name.
     *
     * @param string   $name
     * @param callable $callable
     *
     * @return ConnectionLocatorInterface
     */
    public function setWrite(
        string name,
        callable callableObject
    ) -> <ConnectionLocatorInterface> {
        let this->write[name] = callableObject;

        return this;
    }

    /**
     * Returns a connection by name.
     *
     * @param string $type
     * @param string $name
     *
     * @return ConnectionInterface
     * @throws ConnectionNotFound
     */
    protected function getConnection(
        string type,
        string name = ""
    ) -> <ConnectionInterface> {
        var collection, instanceName, instances, requested;

        let collection = this->{type},
            requested  = name,
            instances  = this->instances;

        /**
         * No collection returns the master
         */
        if empty collection {
            return this->getMaster();
        }

        /**
         * If the requested name is empty, get a random connection
         */
        if "" === requested {
            let requested = array_rand(collection);
        }

        /**
         * If the connection name does not exist, send an exception back
         */
        if !isset collection[requested] {
            throw new ConnectionNotFound(
                "Connection not found: " . type . ":" . requested
            );
        }

        /**
         * Check if the connection has been resolved already, if yes return
         * it, otherwise resolve it. The keys in the `resolved` array are
         * formatted as "type-name"
         */
        let instanceName = type . "-" . requested;

        if !isset instances[instanceName] {
            let instances[instanceName] = call_user_func(collection[requested]),
                this->instances         = instances;
        }

        return instances[instanceName];
    }
}
