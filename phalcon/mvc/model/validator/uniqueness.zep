
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

namespace Phalcon\Mvc\Model\Validator;

use Phalcon\Mvc\Model;

use Phalcon\Mvc\ModelInterface;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Validator;
use Phalcon\Mvc\Model\ValidatorInterface;

/**
 * Phalcon\Mvc\Model\Validator\Uniqueness
 *
 * Validates that a field or a combination of a set of fields are not
 * present more than once in the existing records of the related table
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Uniqueness as Uniqueness;
 *
 *class Subscriptors extends \Phalcon\Mvc\Model
 *{
 *
 *  public function validation()
 *  {
 *      $this->validate(new Uniqueness(array(
 *          "field" => 'email'
 *      )));
 *      if ($this->validationHasFailed() == true) {
 *          return false;
 *      }
 *  }
 *
 *}
 *</code>
 */
class Uniqueness extends Validator implements ValidatorInterface
{
	/**
	 * Executes the validator
	 */
	public function validate(<ModelInterface> record) -> boolean
	{
		var field, dependencyInjector, metaData, message, bindTypes, bindDataTypes,
			columnMap, conditions, bindParams, number, composeField, columnField,
			bindType, primaryField, attributeField, params, className, replacePairs;

		let dependencyInjector = record->getDI();
		let metaData = dependencyInjector->getShared("modelsMetadata");

		/**
		 * PostgreSQL check if the compared constant has the same type as the column, so we make cast to the data passed to match those column types
		 */
		let bindTypes = [];
		let bindDataTypes = metaData->getBindTypes(record);

		if globals_get("orm.column_renaming") {
			let columnMap = metaData->getReverseColumnMap(record);
		} else {
			let columnMap = null;
		}

		let conditions = [];
		let bindParams = [];
		let number = 0;

		let field = this->getOption("field");
		if typeof field == "array" {

			/**
			 * The field can be an array of values
			 */
			for composeField in field {

				/**
				 * The reversed column map is used in the case to get real column name
				 */
				if typeof columnMap == "array" {
					if !fetch columnField, columnMap[composeField] {
						throw new Exception("Column '" . composeField . "' isn't part of the column map");
					}
				} else {
					let columnField = composeField;
				}

				/**
				 * Some database systems require that we pass the values using bind casting
				 */
				if !fetch bindType, bindDataTypes[columnField] {
					throw new Exception("Column '" . columnField . "' isn't part of the table columns");
				}

				/**
				 * The attribute could be "protected" so we read using "readattribute"
				 */
				let conditions[] = "[" . composeField . "] = ?" . number;
				let bindParams[] = record->readAttribute(composeField);
				let bindTypes[] = bindType;

				let number++;
			}

		} else {

			/**
			 * The reversed column map is used in the case to get real column name
			 */
			if typeof columnMap == "array" {
				if !fetch columnField, columnMap[field] {
					throw new Exception("Column '" . field . "' isn't part of the column map");
				}
			} else {
				let columnField = field;
			}

			/**
			 * Some database systems require that we pass the values using bind casting
			 */
			if !fetch bindType, bindDataTypes[columnField] {
				throw new Exception("Column '" . columnField . "' isn't part of the table columns");
			}

			/**
			 * We're checking the uniqueness with only one field
			 */
			let conditions[] = "[" . field . "] = ?0";
			let bindParams[] = record->readAttribute(field);
			let bindTypes[]  = bindType;

			let number++;
		}

		/**
		 * If the operation is update, there must be values in the object
		 */
		if record->getOperationMade() == Model::OP_UPDATE {

			/**
			 * We build a query with the primary key attributes
			 */
			if globals_get("orm.column_renaming") {
				let columnMap = metaData->getColumnMap(record);
			} else {
				let columnMap = null;
			}

			for primaryField in metaData->getPrimaryKeyAttributes(record) {

				if !fetch bindType, bindDataTypes[primaryField] {
					throw new Exception("Column '" . primaryField . "' isn't part of the table columns");
				}

				/**
				 * Rename the column if there is a column map
				 */
				if typeof columnMap == "array" {
					if !fetch attributeField, columnMap[primaryField] {
						throw new Exception("Column '" . primaryField . "' isn't part of the column map");
					}
				} else {
					let attributeField = primaryField;
				}

				/**
				 * Create a condition based on the renamed primary key
				 */
				let conditions[] = "[" . attributeField . "] <> ?" . number;
				let bindParams[] = record->readAttribute(primaryField);
				let bindTypes[] = bindType;

				let number++;
			}
		}

		/**
		 * We don't trust the user, so we pass the parameters as bound parameters
		 */
		let params = [];
		let params["di"] = dependencyInjector;
		let params["conditions"] = join(" AND ", conditions);
		let params["bind"] = bindParams;
		let params["bindTypes"] = bindTypes;

		let className = get_class(record);

		/**
		 * Check if the record does exist using a standard count
		 */
		if {className}::count(params) != 0 {

			/**
			 * Check if the developer has defined a custom message
			 */
			let message = this->getOption("message");
			
			if typeof field == "array" {
				let replacePairs = [":fields": join(", ", field)];
				if empty message {
					let message = "Value of fields: :fields are already present in another record";
				}
			} else {
				let replacePairs = [":field": field];
				if empty message {
					let message = "Value of field: ':field' is already present in another record";
				}
			}

			/**
			 * Append the message to the validator
			 */
			this->appendMessage(strtr(message, replacePairs), field, "Unique");
			return false;
		}

		return true;
	}
}
