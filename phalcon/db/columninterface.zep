
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
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
	 * Restores the internal state of a Phalcon\Db\Column object
	 */
	public static function __set_state(array! data) -> <ColumnInterface>;

	/**
	 * Check whether field absolute to position in table
	 *
	 * @return string
	 */
	public function getAfterPosition() -> string;

	/**
	 * Returns the type of bind handling
	 */
	public function getBindType() -> int;

	/**
	 * Returns default value of column
	 *
	 * @return mixed|null
	 */
	public function getDefault();

	/**
	 * Returns column name
	 *
	 * @return string
	 */
	public function getName() -> string;

	/**
	 * Returns column scale
	 *
	 * @return int
	 */
	public function getScale() -> int;

	/**
	 * Returns schema's table related to column
	 *
	 * @return string
	 */
	public function getSchemaName() -> string;

	/**
	 * Returns column size
	 *
	 * @return int
	 */
	public function getSize() -> int;

	/**
	 * Returns column type
	 *
	 * @return int|string
	 */
	public function getType() -> int;

	/**
	 * Returns column type reference
	 *
	 * @return int
	 */
	public function getTypeReference() -> int;

	/**
	 * Returns column type values
	 *
	 * @return array|string
	 */
	public function getTypeValues() -> array | string;


	/**
	 * Check whether column has default value
	 */
	public function hasDefault() -> bool;
	/**
	 * Auto-Increment
	 */
	public function isAutoIncrement() -> bool;

	/**
	 * Check whether column have first position in table
	 */
	public function isFirst() -> bool;

	/**
	 * Not null
	 */
	public function isNotNull() -> bool;

	/**
	 * Check whether column have an numeric type
	 */
	public function isNumeric() -> bool;

	/**
	 * Column is part of the primary key?
	 */
	public function isPrimary() -> bool;

	/**
	 * Returns true if number column is unsigned
	 */
	public function isUnsigned() -> bool;
}
