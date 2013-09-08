
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

namespace Phalcon\Db;

/**
 * Phalcon\Db\Profiler
 *
 * Instances of Phalcon\Db can generate execution profiles
 * on SQL statements sent to the relational database. Profiled
 * information includes execution time in miliseconds.
 * This helps you to identify bottlenecks in your applications.
 *
 *<code>
 *
 *	profiler = new Phalcon\Db\Profiler();
 *
 *	//Set the connection profiler
 *	connection->setProfiler(profiler);
 *
 *	sql = "SELECT buyer_name, quantity, product_name
 *	FROM buyers LEFT JOIN products ON
 *	buyers.pid=products.id";
 *
 *	//Execute a SQL statement
 *	connection->query(sql);
 *
 *	//Get the last profile in the profiler
 *	profile = profiler->getLastProfile();
 *
 *	echo "SQL Statement: ", profile->getSQLStatement(), "\n";
 *	echo "Start Time: ", profile->getInitialTime(), "\n";
 *	echo "Final Time: ", profile->getFinalTime(), "\n";
 *	echo "Total Elapsed Time: ", profile->getTotalElapsedSeconds(), "\n";
 *
 *</code>
 *
 */
class Profiler {

	/**
	 * All the Phalcon\Db\Profiler\Item in the active profile
	 *
	 * @var array
	 */
	protected _allProfiles;

	/**
	 * Active Phalcon\Db\Profiler\Item
	 *
	 * @var Phalcon\Db\Profiler\Item
	 */
	protected _activeProfile;

	/**
	 * Total time spent by all profiles to complete
	 *
	 * @var float
	 */
	protected _totalSeconds = 0;

}