
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Profiler;

/**
 * Phalcon\Db\Profiler\Item
 *
 * This class identifies each profile in a Phalcon\Db\Profiler
 *
 */
class Item
{

	/**
	 * SQL statement related to the profile
	 *
	 * @var string
	 */
	protected _sqlStatement { set, get };

	/**
	 * SQL variables related to the profile
	 *
	 * @var array
	 */
	protected _sqlVariables { set, get };

	/**
	 * SQL bind types related to the profile
	 *
	 * @var array
	 */
	protected _sqlBindTypes { set, get };

	/**
	 * Timestamp when the profile started
	 *
	 * @var double
	 */
	protected _initialTime { set, get };

	/**
	 * Timestamp when the profile ended
	 *
	 * @var double
	 */
	protected _finalTime { set, get };

	/**
	 * Returns the total time in seconds spent by the profile
	 */
	public function getTotalElapsedSeconds() -> double
	{
		return this->_finalTime - this->_initialTime;
	}
}
