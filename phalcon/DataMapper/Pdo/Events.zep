
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\DataMapper\Pdo;

/**
 * Lifecycle event names fired by the DataMapper connections through
 * Phalcon\Events\Manager. One public constant per event.
 *
 * The `before*` events are cancellable. To cancel an operation, a listener
 * must stop the event and return false:
 *
 *     $manager->attach(
 *         Events::BEFORE_PERFORM,
 *         function ($event) {
 *             $event->stop();
 *
 *             return false;
 *         }
 *     );
 *
 * Both parts are necessary. `stop()` alone abandons the queue but returns
 * the listener's own value, which the connection cannot tell apart from
 * "no listeners". `return false` alone is replaced by any later non-null
 * return while the manager's stopOnFalse mode is off, which is the default.
 * A cancelled operation throws
 * Phalcon\DataMapper\Pdo\Exception\OperationCancelled.
 *
 * The `after*` events are not cancellable. The operation is complete when
 * they fire.
 *
 * There are two groups of events. The operation events - perform, exec,
 * query and the three transaction events - belong to one operation each.
 * `prepare()` has no operation events because `perform()` calls it, and
 * nested events for one logical operation give listeners two counts of the
 * same work. The connection events - connect, disconnect and connectionLost
 * - report a change of the connection state. They fire each time the state
 * changes, whichever method causes it. An automatic reconnect from any
 * method therefore reports the lost connection and the new one.
 */
class Events
{
    /**
     * @var string
     */
    const AFTER_BEGIN_TRANSACTION = "dm:afterBeginTransaction";

    /**
     * @var string
     */
    const AFTER_COMMIT = "dm:afterCommit";

    /**
     * @var string
     */
    const AFTER_CONNECT = "dm:afterConnect";

    /**
     * @var string
     */
    const AFTER_DISCONNECT = "dm:afterDisconnect";

    /**
     * @var string
     */
    const AFTER_EXEC = "dm:afterExec";

    /**
     * @var string
     */
    const AFTER_PERFORM = "dm:afterPerform";

    /**
     * @var string
     */
    const AFTER_QUERY = "dm:afterQuery";

    /**
     * @var string
     */
    const AFTER_ROLLBACK = "dm:afterRollBack";

    /**
     * @var string
     */
    const BEFORE_BEGIN_TRANSACTION = "dm:beforeBeginTransaction";

    /**
     * @var string
     */
    const BEFORE_COMMIT = "dm:beforeCommit";

    /**
     * @var string
     */
    const BEFORE_CONNECT = "dm:beforeConnect";

    /**
     * @var string
     */
    const BEFORE_DISCONNECT = "dm:beforeDisconnect";

    /**
     * @var string
     */
    const BEFORE_EXEC = "dm:beforeExec";

    /**
     * @var string
     */
    const BEFORE_PERFORM = "dm:beforePerform";

    /**
     * @var string
     */
    const BEFORE_QUERY = "dm:beforeQuery";

    /**
     * @var string
     */
    const BEFORE_ROLLBACK = "dm:beforeRollBack";

    /**
     * @var string
     */
    const CONNECTION_LOST = "dm:connectionLost";
}
