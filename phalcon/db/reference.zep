
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
 * Allows to define reference constraints on tables
 *
 *<code>
 *	$reference = new \Phalcon\Db\Reference("field_fk", array(
 *		'referencedSchema' => "invoicing",
 *		'referencedTable' => "products",
 *		'columns' => array("product_type", "product_code"),
 *		'referencedColumns' => array("type", "code")
 *	));
 *</code>
 */
class Reference implements ReferenceInterface
{

	/**
	 * Constraint name
	 *
	 * @var string
	 */
	protected _name  { get };

	protected _schemaName { get };

	protected _referencedSchema { get };

	/**
	 * Referenced Table
	 *
	 * @var string
	 */
	protected _referencedTable { get };

	/**
	 * Local reference columns
	 *
	 * @var array
	 */
	protected _columns { get };

	/**
	 * Referenced Columns
	 *
	 * @var array
	 */
	protected _referencedColumns { get };

	/**
	 * ON DELETE
	 *
	 * @var array
	 */
	protected _onDelete { get };

	/**
	 * ON UPDATE
	 *
	 * @var array
	 */
	protected _onUpdate { get };

	/**
	 * Phalcon\Db\Reference constructor
	 */
	public function __construct(string! name, array! definition)
	{
		var columns, schema, referencedTable,
			referencedSchema, referencedColumns,
			onDelete, onUpdate;

		let this->_name = name;

		if fetch referencedTable, definition["referencedTable"] {
			let this->_referencedTable = referencedTable;
		} else {
			throw new Exception("Referenced table is required");
		}

		if fetch columns, definition["columns"] {
			let this->_columns = columns;
		} else {
			throw new Exception("Foreign key columns are required");
		}

		if fetch referencedColumns, definition["referencedColumns"] {
			let this->_referencedColumns = referencedColumns;
		} else {
			throw new Exception("Referenced columns of the foreign key are required");
		}

		if fetch schema, definition["schema"] {
			let this->_schemaName = schema;
		}

		if fetch referencedSchema, definition["referencedSchema"] {
			let this->_referencedSchema = referencedSchema;
		}

		if fetch onDelete, definition["onDelete"] {
			let this->_onDelete = onDelete;
		}

		if fetch onUpdate, definition["onUpdate"] {
			let this->_onUpdate = onUpdate;
		}

		if count(columns) != count(referencedColumns) {
			throw new Exception("Number of columns is not equals than the number of columns referenced");
		}
	}

	/**
	 * Restore a Phalcon\Db\Reference object from export
	 */
	public static function __set_state(array! data) -> <Reference>
	{
		var referencedSchema, referencedTable, columns,
			referencedColumns, constraintName,
			onDelete, onUpdate;

		if !fetch constraintName, data["_referenceName"] {
			if !fetch constraintName, data["_name"] {
				throw new Exception("_name parameter is required");
			}
		}

		fetch referencedSchema, data["_referencedSchema"];
		fetch referencedTable, data["_referencedTable"];
		fetch columns, data["_columns"];
		fetch referencedColumns, data["_referencedColumns"];
		fetch onDelete, data["_onDelete"];
		fetch onUpdate, data["_onUpdate"];

		return new Reference(constraintName, [
			"referencedSchema"  : referencedSchema,
			"referencedTable"   : referencedTable,
			"columns"           : columns,
			"referencedColumns" : referencedColumns,
			"onDelete"          : onDelete,
			"onUpdate"          : onUpdate
		]);
	}

}
