
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

}
