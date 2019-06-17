
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Collection;

use Phalcon\Mvc\CollectionInterface;
use Phalcon\Mvc\Collection\BehaviorInterface;
use Phalcon\Events\ManagerInterface as EventsManagerInterface;

/**
 * Phalcon\Mvc\Collection\Manager
 *
 * This components controls the initialization of collections, keeping record of relations
 * between the different collections of the application.
 *
 * A CollectionManager is injected to a collection via a Dependency Injector Container such as Phalcon\Di.
 *
 * <code>
 * $di = new \Phalcon\Di();
 *
 * $di->set(
 *     "collectionManager",
 *     function() {
 *         return new \Phalcon\Mvc\Collection\Manager();
 *     }
 * );
 *
 * $robot = new Robots(di);
 * </code>
 */
interface ManagerInterface
{
    /**
     * Binds a behavior to a collection
     */
    public function addBehavior(<CollectionInterface> collection, <BehaviorInterface> behavior);

    /**
     * Returns the connection related to a collection
     */
    public function getConnection(<CollectionInterface> collection);

    /**
     * Returns a custom events manager related to a collection
     */
    public function getCustomEventsManager(<CollectionInterface> collection) -> var | null;

    /**
     * Get the latest initialized collection
     */
    public function getLastInitialized() -> <CollectionInterface>;

    /**
     * Initializes a collection in the collections manager
     */
    public function initialize(<CollectionInterface> collection);

    /**
     * Check whether a collection is already initialized
     */
    public function isInitialized(string! className) -> bool;

    /**
     * Checks if a collection is using implicit object ids
     */
    public function isUsingImplicitObjectIds(<CollectionInterface> collection) -> bool;

    /**
     * Receives events generated in the collections and dispatches them to an events-manager if available
     * Notify the behaviors that are listening in the collection
     */
    public function notifyEvent(string! eventName, <CollectionInterface> collection);

    /**
     * Sets a custom events manager for a specific collection
     */
    public function setCustomEventsManager(<CollectionInterface> collection, <EventsManagerInterface> eventsManager);

    /**
     * Sets a connection service for a specific collection
     */
    public function setConnectionService(<CollectionInterface> collection, string! connectionService);

    /**
     * Sets if a collection must use implicit objects ids
     */
    public function useImplicitObjectIds(<CollectionInterface> collection, bool useImplicitObjectIds);
}
