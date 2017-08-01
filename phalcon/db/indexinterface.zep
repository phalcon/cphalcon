
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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
 * Phalcon\Db\IndexInterface
 *
 * Interface for Phalcon\Db\Index
 */
interface IndexInterface
{
	/**
	 * Gets the index name
	 */
	public function getName() -> string;

	/**
	 * Gets the columns that corresponds the index
	 */
	public function getColumns() -> array;

	/**
	 * Gets the index type
	 */
	public function getType() -> string;

	/**
	 * Restore a Phalcon\Db\Index object from export
	 */
	public static function __set_state(array! data) -> <IndexInterface>;

}
