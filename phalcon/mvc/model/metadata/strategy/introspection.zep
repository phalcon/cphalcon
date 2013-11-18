
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

namespace Phalcon\Mvc\Model\MetaData\Strategy;

/**
 * Phalcon\Mvc\Model\MetaData\Strategy\Instrospection
 *
 * Queries the table meta-data in order to instrospect the model's metadata
 */
class Introspection
{

	/**
	 * The meta-data is obtained by reading the column descriptions from the database information schema
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param Phalcon\DiInterface dependencyInjector
	 * @return array
	 */
	public function getMetaData(<Phalcon\Mvc\ModelInterface> model, <Phalcon\DiInterface> dependencyInjector)
	{
		var schema, table, readConnection, columns, attributes,
			primaryKeys, nonPrimaryKeys, completeTable, numericTyped, notNull,
			fieldTypes, automaticDefault, identityField, fieldBindTypes, column, fieldName;

		let schema    = model->getSchema(),
			table     = model->getSource();

		/**
		 * Check if the mapped table exists on the database</comment>
		 */
		let readConnection = model->getReadConnection();

		if !readConnection->tableExists(table, schema) {

			if schema {
				let completeTable = schema . "'.'" . table;
			} else {
				let completeTable = table;
			}

			/**
			 * The table not exists
			 */
			throw new Phalcon\Mvc\Model\Exception("Table '" . completeTable . "' doesn't exist on database when dumping meta-data for " . get_class(model));
		}

		/**
		 * Try to describe the table
		 */
		let columns = readConnection->describeColumns(table, schema);
		if !count(columns) {

			if schema {
				let completeTable = schema . "'.'" . table;
			} else {
				let completeTable = table;
			}

			/**
			 * The table not exists
			 */
			throw new Phalcon\Mvc\Model\Exception("Cannot obtain table columns for the mapped source '" . completeTable . "' used in model " . get_class(model));
		}

		/**
		 * Initialize meta-data
		 */
		let attributes = [];
		let primaryKeys = [];
		let nonPrimaryKeys = [];
		let numericTyped = [];
		let notNull = [];
		let fieldTypes = [];
		let fieldBindTypes = [];
		let automaticDefault = [];
		let identityField = false;

		for column in columns {

			let fieldName = column->getName(),
				attributes[] = fieldName;

			/**
			 * To mark fields as primary keys
			 */
			if column->isPrimary() === true {
				let primaryKeys[] = fieldName;
			} else {
				let nonPrimaryKeys[] = fieldName;
			}

			/**
			 * To mark fields as numeric
			 */
			if column->isNumeric() === true {
				let numericTyped[fieldName] = true;
			}

			/**
			 * To mark fields as not null
			 */
			if column->isNotNull() === true {
				let notNull[] = fieldName;
			}

			/**
			 * To mark fields as identity columns
			 */
			if column->isAutoIncrement() === true {
				let identityField = fieldName;
			}

			/**
			 * To get the internal types
			 */
			let fieldTypes[fieldName] = column->getType();

			/**
			 * To mark how the fields must be escaped
			 */
			let fieldBindTypes[fieldName] = column->getBindType();
		}

		/**
		 * Create an array using the MODELS_* constants as indexes
		 */
		return [
			0: attributes,
			1: primaryKeys,
			2: nonPrimaryKeys,
			3: notNull,
			4: fieldTypes,
			5: numericTyped,
			8: identityField,
			9: fieldBindTypes,
			10: automaticDefault,
			11: automaticDefault
		];
	}

	/**
	 * Read the model's column map, this can't be infered
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param Phalcon\DiInterface dependencyInjector
	 * @return array
	 */
	public function getColumnMaps(<Phalcon\Mvc\ModelInterface> model, <Phalcon\DiInterface> dependencyInjector)
	{
		var orderedColumnMap, userColumnMap, reversedColumnMap, name, userName;

		let orderedColumnMap = null;
		let reversedColumnMap = null;

		/**
		 * Check for a columnMap() method on the model
		 */
		if method_exists(model, "columnMap") {

			let userColumnMap = model->{"columnMap"}();
			if typeof userColumnMap != "array" {
				throw new Phalcon\Mvc\Model\Exception("columnMap() not returned an array");
			}

			let reversedColumnMap = [],
				orderedColumnMap = userColumnMap;
			for name, userName in userColumnMap {
				let reversedColumnMap[userName] = name;
			}
		}

		/**
		 * Store the column map
		 */
		return [orderedColumnMap, reversedColumnMap];
	}

}

