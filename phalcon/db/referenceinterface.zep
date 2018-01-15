
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
