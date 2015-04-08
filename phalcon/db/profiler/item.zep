
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
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
