
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db;

use Phalcon\Db\Profiler\Item;

/**
 * Instances of Phalcon\Db can generate execution profiles
 * on SQL statements sent to the relational database. Profiled
 * information includes execution time in milliseconds.
 * This helps you to identify bottlenecks in your applications.
 *
 * ```php
 * use Phalcon\Db\Profiler;
 * use Phalcon\Events\Event;
 * use Phalcon\Events\Manager;
 *
 * $profiler = new Profiler();
 * $eventsManager = new Manager();
 *
 * $eventsManager->attach(
 *     "db",
 *     function (Event $event, $connection) use ($profiler) {
 *         if ($event->getType() === "beforeQuery") {
 *             $sql = $connection->getSQLStatement();
 *
 *             // Start a profile with the active connection
 *             $profiler->startProfile($sql);
 *         }
 *
 *         if ($event->getType() === "afterQuery") {
 *             // Stop the active profile
 *             $profiler->stopProfile();
 *         }
 *     }
 * );
 *
 * // Set the event manager on the connection
 * $connection->setEventsManager($eventsManager);
 *
 *
 * $sql = "SELECT buyer_name, quantity, product_name
 * FROM buyers LEFT JOIN products ON
 * buyers.pid=products.id";
 *
 * // Execute a SQL statement
 * $connection->query($sql);
 *
 * // Get the last profile in the profiler
 * $profile = $profiler->getLastProfile();
 *
 * echo "SQL Statement: ", $profile->getSQLStatement(), "\n";
 * echo "Start Time: ", $profile->getInitialTime(), "\n";
 * echo "Final Time: ", $profile->getFinalTime(), "\n";
 * echo "Total Elapsed Time: ", $profile->getTotalElapsedSeconds(), "\n";
 * ```
 */
class Profiler
{
    /**
     * Active Phalcon\Db\Profiler\Item
     *
     * @var Phalcon\Db\Profiler\Item
     */
    protected activeProfile;

    /**
     * All the Phalcon\Db\Profiler\Item in the active profile
     *
     * @var \Phalcon\Db\Profiler\Item[]
     */
    protected allProfiles;

    /**
     * Total time spent by all profiles to complete
     *
     * @var float
     */
    protected totalSeconds = 0;

    /**
     * Returns the last profile executed in the profiler
     */
    public function getLastProfile() -> <Item>
    {
        return this->activeProfile;
    }

    /**
     * Returns the total number of SQL statements processed
     */
    public function getNumberTotalStatements() -> int
    {
        return count(this->allProfiles);
    }

    /**
     * Returns the total time in seconds spent by the profiles
     */
    public function getTotalElapsedSeconds() -> double
    {
        return this->totalSeconds;
    }

    /**
     * Returns all the processed profiles
     */
    public function getProfiles() -> <Item[]>
    {
        return this->allProfiles;
    }

    /**
     * Resets the profiler, cleaning up all the profiles
     */
    public function reset() -> <Profiler>
    {
        let this->allProfiles = [];

        return this;
    }

    /**
     * Starts the profile of a SQL sentence
     */
    public function startProfile(string sqlStatement, var sqlVariables = null, var sqlBindTypes = null) -> <Profiler>
    {
        var activeProfile, version;

        let activeProfile = new Item();

        activeProfile->setSqlStatement(sqlStatement);

        if typeof sqlVariables == "array" {
            activeProfile->setSqlVariables(sqlVariables);
        }

        if typeof sqlBindTypes == "array" {
            activeProfile->setSqlBindTypes(sqlBindTypes);
        }

        let version = phpversion();

        /**
         * @todo Remove this check when we target min PHP 7.3
         */
        if starts_with(version, "7.2") {
            activeProfile->setInitialTime(microtime(true));
        } else {
            activeProfile->setInitialTime(hrtime(true));
        }

        if method_exists(this, "beforeStartProfile") {
            this->{"beforeStartProfile"}(activeProfile);
        }

        let this->activeProfile = activeProfile;

        return this;
    }

    /**
     * Stops the active profile
     */
    public function stopProfile() -> <Profiler>
    {
        var activeProfile, finalTime, initialTime, version;

        let version = phpversion();

        /**
         * @todo Remove this check when we target min PHP 7.3
         */
        if starts_with(version, "7.2") {
            let finalTime = microtime(true);
        } else {
            let finalTime = hrtime(true);
        }

        let activeProfile = <Item> this->activeProfile;

        activeProfile->setFinalTime(finalTime);

        let initialTime = activeProfile->getInitialTime(),
            this->totalSeconds = this->totalSeconds + (finalTime - initialTime),
            this->allProfiles[] = activeProfile;

        if method_exists(this, "afterEndProfile") {
            this->{"afterEndProfile"}(activeProfile);
        }

        return this;
    }
}
