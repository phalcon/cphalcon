
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2016 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\CombinedFieldsValidator;
use Phalcon\Validation\Exception;
use Phalcon\Validation\Message;
use Phalcon\Mvc\Model;

/**
 * Phalcon\Validation\Validator\Uniqueness
 *
 * Check that a field is unique in the related table
 *
 * <code>
 * use Phalcon\Validation\Validator\Uniqueness as UniquenessValidator;
 *
 * $validator->add('username', new UniquenessValidator([
 *     'model' => new Users(),
 *     'message' => ':field must be unique'
 * ]));
 * </code>
 *
 * Different attribute from the field:
 * <code>
 * $validator->add('username', new UniquenessValidator([
 *     'model' => new Users(),
 *     'attribute' => 'nick'
 * ]));
 * </code>
 *
 * In model:
 * <code>
 * $validator->add('username', new UniquenessValidator());
 * </code>
 *
 * Combination of fields in model:
 * <code>
 * $validator->add(['firstName', 'lastName'], new UniquenessValidator());
 * </code>
 *
 * It is possible to convert values before validation. This is useful in
 * situations where values need to be converted to do the database lookup:
 * <code>
 * $validator->add('username', new UniquenessValidator([
 *     'convert' => function (array $values) {
 *         $values['username'] = strtolower($values['username']);
 *
 *         return $values;
 *     }
 * ]));
 * </code>
 */
class Uniqueness extends CombinedFieldsValidator
{
	private columnMap = null;

	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, var field) -> boolean
	{
		var message, label;

		if !this->isUniqueness(validation, field) {

			let label   = this->getOption("label"),
				message = this->getOption("message");

			if empty label {
				let label = validation->getLabel(field);
			}

			if empty message {
				let message = validation->getDefaultMessage("Uniqueness");
			}

			validation->appendMessage(new Message(strtr(message, [":field": label]), field, "Uniqueness", this->getOption("code")));
			return false;
		}

		return true;
	}

	protected function isUniqueness(<Validation> validation, var field) -> boolean
	{
		var value, values, convert, record, attribute, except,
			index, params, metaData, primaryField, className, singleField, fieldExcept, singleExcept, notInValues, exceptConditions;

		let exceptConditions = [];
		let index  = 0;
		let params = [
			"conditions": [],
			"bind": []
		];

		if typeof field != "array" {
			let singleField = field;
			let field = [];
			let field[] = singleField;
		}

		let values = [];
		let convert = this->getOption("convert");

		for singleField in field {
			let values[singleField] = validation->getValue(singleField);
		}

		if convert != null {
			let values = {convert}(values);

			if !is_array(values) {
				throw new Exception("Value conversion must return an array");
			}
		}

		for singleField in field {
			let fieldExcept = null;
			let notInValues = [];
			let record = this->getOption("model");
			let value = values[singleField];

			if empty record || typeof record != "object" {
				// check validation getEntity() method
				let record = validation->getEntity();
				if empty record {
					throw new Exception("Model of record must be set to property \"model\"");
				}
			}

			let attribute = this->getColumnNameReal(record, this->getOption("attribute", singleField)),
				except = this->getOption("except");

			if value != null {
				let params["conditions"][] = attribute . " = ?" . index;
				let params["bind"][] = value;
				let index++;
			}
			else {
				let params["conditions"][] = attribute . " IS NULL";
			}

			if except {
				if typeof except == "array" && count(field) > 1 {
					if isset except[singleField] {
						let fieldExcept = except[singleField];
					}
				}

				if fieldExcept != null {
					if typeof fieldExcept == "array" {
						for singleExcept in fieldExcept {
							let notInValues[] = "?" . index;
							let params["bind"][] = singleExcept;
							let index++;
						}
						let exceptConditions[] = attribute . " NOT IN (" . join(",", notInValues) . ")";
					}
					else {
						let exceptConditions[] = attribute . " <> ?" . index;
						let params["bind"][] = fieldExcept;
						let index++;
					}
				}
				elseif typeof except == "array" && count(field) == 1 {
					for singleExcept in except {
						let notInValues[] = "?" . index;
						let params["bind"][] = singleExcept;
						let index++;
					}
					let params["conditions"][] = attribute . " NOT IN (" . join(",", notInValues) . ")";
				}
				elseif count(field) == 1 {
					let params["conditions"][] = attribute . " <> ?" . index;
					let params["bind"][] = except;
					let index++;
				}
			}
		}

		/**
		 * If the operation is update, there must be values in the object
		 */
		if record->getDirtyState() == Model::DIRTY_STATE_PERSISTENT {
			let metaData = record->getDI()->getShared("modelsMetadata");

			for primaryField in metaData->getPrimaryKeyAttributes(record) {
				let params["conditions"][] = this->getColumnNameReal(record, primaryField) . " <> ?" . index;
				let params["bind"][] = record->readAttribute(primaryField);
				let index++;
			}
		}

		let className = get_class(record);
		if !empty exceptConditions {
			let params["conditions"][] = "(" . join(" OR ", exceptConditions) . ")";
		}
		let params["conditions"] = join(" AND ", params["conditions"]);

		return {className}::count(params) == 0;
	}

	/**
	 * The column map is used in the case to get real column name
	 */
	protected function getColumnNameReal(var record, string! field) -> string
	{
		// Caching columnMap
		if globals_get("orm.column_renaming") && !this->columnMap {
			let this->columnMap = record->getDI()
				->getShared("modelsMetadata")
				->getColumnMap(record);
		}

		if typeof this->columnMap == "array" && isset this->columnMap[field] {
			return this->columnMap[field];
		}

		return field;
	}
}
