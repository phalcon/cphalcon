
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
 * Phalcon\Db\Reference
 *
 * Interface for Phalcon\Db\Reference
 */
interface ReferenceInterface
{

	/**
	 * Phalcon\Db\ReferenceInterface constructor
	 */
	public function __construct(string! referenceName, array! definition);

	/**
	 * Gets the index name
	 *
	 * @return string
	 */
	public function getName();

	/**
	 * Gets the schema where referenced table is
	 *
	 * @return string
	 */
	public function getSchemaName();

	/**
	 * Gets the schema where referenced table is
	 *
	 * @return string
	 */
	public function getReferencedSchema();

	/**
	 * Gets local columns which reference is based
	 *
	 * @return array
	 */
	public function getColumns();

	/**
	 * Gets the referenced table
	 *
	 * @return string
	 */
	public function getReferencedTable();

	/**
	 * Gets referenced columns
	 *
	 * @return array
	 */
	public function getReferencedColumns();

	/**
	 * Gets the referenced on delete
	 *
	 * @return string
	 */
	public function getOnDelete();

	/**
	 * Gets the referenced on update
	 *
	 * @return string
	 */
	public function getOnUpdate();

	/**
	 * Restore a Phalcon\Db\Reference object from export
	 */
	public static function __set_state(array! data) -> <ReferenceInterface>;

}