
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

namespace Phalcon\Mvc\Model\Validator;

/**
 * Phalcon\Mvc\Model\Validator\Uniqueness
 *
 * Validates that a field or a combination of a set of fields are not
 * present more than once in the existing records of the related table
 *
 *<code>
 *use Phalcon\Mvc\Model\Validator\Uniqueness as Uniqueness;
 *
 *class Subscriptors extends Phalcon\Mvc\Model
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
 *
 */
class Uniqueness extends Phalcon\Mvc\Model\Validator implements Phalcon\Mvc\Model\ValidatorInterface 
{
	/**
	 * Executes the validator
	 *
	 * @param Phalcon\Mvc\ModelInterface record
	 * @return boolean
	 */
	public function validate(<Phalcon\Mvc\ModelInterface> record) -> boolean
	{
		var field, dependencyInjector, metaData, message, bindTypes, bindDataTypes,
			columnMap, conditions, bindParams, number, composeField, value, columnField,
			composeCondition, bindType, condition, operationMade, primaryFields, primaryField,
			attributeField, joinConditions, params, className, joinFields, replacePairs;

		let field = this->getOption("field");
 
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
		if typeof field == "array" {
 
			/**
			 * The field can be an array of values
			 */
			for composeField in field 
			{
 
				/**
				 * The reversed column map is used in the case to get real column name
				 */
				if typeof columnMap == "array" {
					if isset columnMap[composeField] {
						let columnField = columnMap[composeField];
					} else {
						throw new Phalcon\Mvc\Model\Exception("Column '".composeField."' isn't part of the column map");
					}
				} else {
					let columnField = composeField;
				}
 
				/**
				 * Some database systems require that we pass the values using bind casting
				 */
				if !isset bindDataTypes[columnField] {
					throw new Phalcon\Mvc\Model\Exception("Column '".columnField."' isn't part of the table columns");
				}
 
				/**
				 * The attribute could be "protected" so we read using "readattribute"
				 */
				let value = record->readAttribute(composeField);
				let composeCondition = "[".composeField."] = ?".number;
				let conditions[] = composeCondition;
				let bindParams[] = value;
 
				let bindType = bindDataTypes[columnField];
				let bindTypes[] = bindType;
 
				let number = number + 1;
			}
 
		} else {
 
			/**
			 * The reversed column map is used in the case to get real column name
			 */
			if typeof columnMap == "array" {
				if isset columnMap[field] {
					let columnField = columnMap[field];
				} else {
					throw new Phalcon\Mvc\Model\Exception("Column '".field."' isn't part of the column map");
				}
			} else {
				let columnField = field;
			}
 
			/**
			 * Some database systems require that we pass the values using bind casting
			 */
			if !isset bindDataTypes[columnField] {
				throw new Phalcon\Mvc\Model\Exception("Column '".columnField."' isn't part of the table columns");
			}
 
			/**
			 * We're checking the uniqueness with only one field
			 */
			let value = record->readAttribute(field);
			let condition = "[".field."] = ?0";
			let conditions[] = condition;
			let bindParams[] = value;
 
			let bindType = bindDataTypes[columnField];
			let bindTypes[] = bindType;
 
			let number = number + 1;
		}
 
		/**
		 * If the operation is update, there must be values in the object
		 */
		let operationMade = record->getOperationMade();
		if operationMade == 2 {
 
			/**
			 * We build a query with the primary key attributes
			 */
			if globals_get("orm.column_renaming") {
				let columnMap = metaData->getColumnMap(record);
			} else {
				let columnMap = null;
			}
 
			let primaryFields = metaData->getPrimaryKeyAttributes(record);
			for primaryField in primaryFields {
 
				if !isset bindDataTypes[primaryField] {
					throw new Phalcon\Mvc\Model\Exception("Column '".primaryField."' isn't part of the table columns");
				}
 
				/**
				 * Rename the column if there is a column map
				 */
				if typeof columnMap == "array" {
					if isset columnMap[primaryField] {
						let attributeField = columnMap[primaryField];
					} else {
						throw new Phalcon\Mvc\Model\Exception("Column '".primaryField."' isn't part of the column map");
					}
				} else {
					let attributeField = primaryField;
				}
 
				/**
				 * Create a condition based on the renamed primary key
				 */
				let value = record->readAttribute(primaryField);
				let condition = '[' . attributeField . "] <> ?".number;
				let conditions[] = condition;
				let bindParams[] = value;
 
				let bindType = bindDataTypes[primaryField];
				let bindTypes[] = bindType;
 
				let number = number + 1;
			}
		}
 
		let joinConditions = join(" AND ", conditions);
 
		/**
		 * We don't trust the user, so we pass the parameters as bound parameters
		 */
		let params = [];
		let params["di"] = dependencyInjector;
		let params["conditions"] = joinConditions;
		let params["bind"] = bindParams;
		let params["bindTypes"] = bindTypes;
 
		let className = get_class(record);
 
		/**
		 * Check using a standard count
		 */
		let number = {className}::count(params);
		if number != 0 {
 
			/**
			 * Check if the developer has defined a custom message
			 */
			let message = this->getOption("message");
                        let replacePairs = [":field": field];
			if empty message {
				if typeof field == "array" {
					let replacePairs = [":fields": join(", ", field)];
                                        let message = strtr("Value of fields: :fields are already present in another record", replacePairs);
				} else {
                                        let message = strtr("Value of field: :field is already present in another record", replacePairs);
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
