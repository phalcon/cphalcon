
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

namespace Phalcon\Db;

/**
 * Phalcon\Db\Index
 *
 * Allows to define indexes to be used on tables. Indexes are a common way
 * to enhance database performance. An index allows the database server to find
 * and retrieve specific rows much faster than it could do without an index
 */
class Index implements IndexInterface
{

	/**
	 * Index name
	 *
	 * @var string
	 */
	protected _name { get };

	/**
	 * Index columns
	 *
	 * @var array
	 */
	protected _columns { get };

	/**
	 * Index type
	 *
	 * @var string
	 */
	protected _type { get };

	/**
	 * Phalcon\Db\Index constructor
	 */
	public function __construct(string! name, array! columns, type = null)
	{
		let this->_name = name;
		let this->_columns = columns;
		let this->_type = (string) type;
	}

	/**
	 * Restore a Phalcon\Db\Index object from export
	 */
	public static function __set_state(array! data) -> <Index>
	{
		var indexName, columns, type;

		if !fetch indexName, data["_name"] {
			throw new Exception("_name parameter is required");
		}

		if !fetch columns, data["_columns"] {
			throw new Exception("_columns parameter is required");
		}

		if !fetch type, data["_type"] {
			let type = "";
		}

		/**
		 * Return a Phalcon\Db\Index as part of the returning state
		 */
		return new Index(indexName, columns, type);
	}

}
