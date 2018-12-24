
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db;

/**
 * Phalcon\Db\Reference
 *
 * Interface for Phalcon\Db\Reference
 */
interface ReferenceInterface
{
	/**
	 * Gets the index name
	 */
	public function getName() -> string;

	/**
	 * Gets the schema where referenced table is
	 */
	public function getSchemaName() -> string;

	/**
	 * Gets the schema where referenced table is
	 */
	public function getReferencedSchema() -> string;

	/**
	 * Gets local columns which reference is based
	 */
	public function getColumns() -> array;

	/**
	 * Gets the referenced table
	 */
	public function getReferencedTable() -> string;

	/**
	 * Gets referenced columns
	 */
	public function getReferencedColumns() -> array;

	/**
	 * Gets the referenced on delete
	 */
	public function getOnDelete() -> string;

	/**
	 * Gets the referenced on update
	 */
	public function getOnUpdate() -> string;

	/**
	 * Restore a Phalcon\Db\Reference object from export
	 */
	public static function __set_state(array! data) -> <ReferenceInterface>;

}
