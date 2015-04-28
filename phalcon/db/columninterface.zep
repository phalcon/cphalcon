
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
 * Phalcon\Db\ColumnInterface
 *
 * Interface for Phalcon\Db\Column
 */
interface ColumnInterface
{

	/**
	 * Phalcon\Db\ColumnInterface constructor
	 */
	public function __construct(string! columnName, array! definition);

	/**
	 * Returns schema's table related to column
	 *
	 * @return string
	 */
	public function getSchemaName();

	/**
	 * Returns column name
	 *
	 * @return string
	 */
	public function getName();

	/**
	 * Returns column type
	 *
	 * @return int
	 */
	public function getType();

	/**
	 * Returns column type reference
	 *
	 * @return int
	 */
	public function getTypeReference();

	/**
	 * Returns column type values
	 *
	 * @return int
	 */
	public function getTypeValues();

	/**
	 * Returns column size
	 *
	 * @return int
	 */
	public function getSize();

	/**
	 * Returns column scale
	 *
	 * @return int
	 */
	public function getScale();

	/**
	 * Returns true if number column is unsigned
	 *
	 * @return boolean
	 */
	public function isUnsigned();

	/**
	 * Not null
	 *
	 * @return boolean
	 */
	public function isNotNull();

	/**
	 * Column is part of the primary key?
	 *
	 * @return boolean
	 */
	public function isPrimary();

	/**
	 * Auto-Increment
	 *
	 * @return boolean
	 */
	public function isAutoIncrement();

	/**
	 * Check whether column have an numeric type
	 *
	 * @return boolean
	 */
	public function isNumeric();

	/**
	 * Check whether column have first position in table
	 *
	 * @return boolean
	 */
	public function isFirst();

	/**
	 * Check whether field absolute to position in table
	 *
	 * @return string
	 */
	public function getAfterPosition();

	/**
	 * Returns the type of bind handling
	 *
	 * @return int
	 */
	public function getBindType();

	/**
	 * Returns default value of column
	 *
	 * @return int
	 */
	public function getDefault();

	/**
	 * Restores the internal state of a Phalcon\Db\Column object
	 */
	public static function __set_state(array! data) -> <ColumnInterface>;

}