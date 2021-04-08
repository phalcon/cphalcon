
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Profiler;

/**
 * This class identifies each profile in a Phalcon\Db\Profiler
 */
class Item
{
    /**
     * Timestamp when the profile ended
     *
     * @var double
     */
    protected finalTime { set, get };

    /**
     * Timestamp when the profile started
     *
     * @var double
     */
    protected initialTime { set, get };

    /**
     * SQL bind types related to the profile
     *
     * @var array
     */
    protected sqlBindTypes { set, get };

    /**
     * SQL statement related to the profile
     *
     * @var string
     */
    protected sqlStatement { set, get };

    /**
     * SQL variables related to the profile
     *
     * @var array
     */
    protected sqlVariables { set, get };

    /**
     * Returns the total time in nanoseconds spent by the profile
     */
    public function getTotalElapsedNanoseconds() -> double
    {
        return this->finalTime - this->initialTime;
    }

    /**
     * Returns the total time in milliseconds spent by the profile
     */
    public function getTotalElapsedMilliseconds() -> double
    {
        return this->getTotalElapsedNanoseconds() / 1000000;
    }

    /**
     * Returns the total time in seconds spent by the profile
     */
    public function getTotalElapsedSeconds() -> double
    {
        return this->getTotalElapsedMilliseconds() / 1000;
    }
}
