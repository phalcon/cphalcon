
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Events;

/**
 * Contract for event subscriber classes. A subscriber declares the events it
 * wants to listen to via a static map; Events\Manager parses the map and
 * attaches each entry as a regular listener.
 *
 * Accepted value shapes per event key:
 *
 *   'event:name' => 'methodName'
 *   'event:name' => ['methodName', priority]
 *   'event:name' => [
 *       ['methodName1'],
 *       ['methodName2', priority],
 *   ]
 *
 * Keys can be either a Phalcon event string (e.g. "db:beforeQuery") or a
 * fully qualified event class name.
 *
 * Wildcard subscriptions: Phalcon's manager fires both the prefix queue and
 * the full-name queue (e.g. "db" is fired before "db:beforeQuery"). To
 * subscribe to every event of a component, use the prefix as the key:
 *
 *   'db' => 'onAnyDbEvent'   // fires for db:beforeQuery, db:afterQuery, ...
 */
interface Subscriber
{
    /**
     * Returns a map of event name => listener config. Called once per
     * Manager::addSubscriber() / removeSubscriber() call.
     */
    public static function getSubscribedEvents() -> array;
}
