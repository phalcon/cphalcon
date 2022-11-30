
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
    protected finalTime;

    /**
     * Timestamp when the profile started
     *
     * @var double
     */
    protected initialTime;

    /**
     * SQL bind types related to the profile
     *
     * @var array
     */
    protected sqlBindTypes;

    /**
     * SQL statement related to the profile
     *
     * @var string
     */
    protected sqlStatement;

    /**
     * SQL variables related to the profile
     *
     * @var array
     */
    protected sqlVariables;

    /**
     * Return the timestamp when the profile ended
     */
    public function getFinalTime() -> double
    {
        return this->finalTime;
    }

    /**
     * Return the timestamp when the profile started
     */
    public function getInitialTime() -> double
    {
        return this->initialTime;
    }

    /**
     * Return the SQL bind types related to the profile
     */
    public function getSqlBindTypes() -> array
    {
        return this->sqlBindTypes;
    }

    /**
     * Return the SQL statement related to the profile
     */
    public function getSqlStatement() -> string
    {
        return this->sqlStatement;
    }

    /**
     * Return the SQL variables related to the profile
     */
    public function getSqlVariables() -> array
    {
        return this->sqlVariables;
    }

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

    /**
     * Return the timestamp when the profile ended
     */
    public function setFinalTime(double finalTime) -> <Item>
    {
        let this->finalTime = finalTime;

        return this;
    }

    /**
     * Return the timestamp when the profile started
     */
    public function setInitialTime(double initialTime) -> <Item>
    {
        let this->initialTime = initialTime;

        return this;
    }

    /**
     * Return the SQL bind types related to the profile
     */
    public function setSqlBindTypes(array sqlBindTypes) -> <Item>
    {
        let this->sqlBindTypes = sqlBindTypes;

        return this;
    }

    /**
     * Return the SQL statement related to the profile
     */
    public function setSqlStatement(string sqlStatement) -> <Item>
    {
        let this->sqlStatement = sqlStatement;

        return this;
    }

    /**
     * Return the SQL variables related to the profile
     */
    public function setSqlVariables(array sqlVariables) -> <Item>
    {
        let this->sqlVariables = sqlVariables;

        return this;
    }
}
