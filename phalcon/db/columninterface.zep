
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
 * Phalcon\Db\ColumnInterface
 *
 * Interface for Phalcon\Db\Column
 */
interface ColumnInterface
{
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
	 */
	public function isUnsigned() -> boolean;

	/**
	 * Not null
	 */
	public function isNotNull() -> boolean;

	/**
	 * Column is part of the primary key?
	 */
	public function isPrimary() -> boolean;

	/**
	 * Auto-Increment
	 */
	public function isAutoIncrement() -> boolean;

	/**
	 * Check whether column have an numeric type
	 */
	public function isNumeric() -> boolean;

	/**
	 * Check whether column have first position in table
	 */
	public function isFirst() -> boolean;

	/**
	 * Check whether field absolute to position in table
	 *
	 * @return string
	 */
	public function getAfterPosition();

	/**
	 * Returns the type of bind handling
	 */
	public function getBindType() -> int;

	/**
	 * Returns default value of column
	 *
	 * @return int
	 */
	public function getDefault();

	/**
	 * Check whether column has default value
	 */
	public function hasDefault() -> boolean;

	/**
	 * Restores the internal state of a Phalcon\Db\Column object
	 */
	public static function __set_state(array! data) -> <ColumnInterface>;

}
