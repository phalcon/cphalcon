
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
	protected _sqlStatement;

	/**
	 * Timestamp when the profile started
	 *
	 * @var double
	 */
	protected _initialTime;

	/**
	 * Timestamp when the profile ended
	 *
	 * @var double
	 */
	protected _finalTime;

	/**
	 * Sets the SQL statement related to the profile
	 *
	 * @param string sqlStatement
	 */
	public function setSQLStatement(sqlStatement)
	{
		let this->_sqlStatement = sqlStatement;
	}

	/**
	 * Returns the SQL statement related to the profile
	 *
	 * @return string
	 */
	public function getSQLStatement()
	{
		return this->_sqlStatement;
	}

	/**
	 * Sets the timestamp on when the profile started
	 *
	 * @param int initialTime
	 */
	public function setInitialTime(initialTime)
	{
		let this->_initialTime = initialTime;
	}

	/**
	 * Sets the timestamp on when the profile ended
	 *
	 * @param int finalTime
	 */
	public function setFinalTime(finalTime)
	{
		let this->_finalTime = finalTime;
	}

	/**
	 * Returns the initial time in milseconds on when the profile started
	 *
	 * @return double
	 */
	public function getInitialTime()
	{
		return this->_initialTime;
	}

	/**
	 * Returns the initial time in milseconds on when the profile ended
	 *
	 * @return double
	 */
	public function getFinalTime()
	{
		return this->_finalTime;
	}

	/**
	 * Returns the total time in seconds spent by the profile
	 *
	 * @return double
	 */
	public function getTotalElapsedSeconds()
	{
		return this->_finalTime - this->_initialTime;
	}

}
