
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
use Phalcon\Validation\Validator;
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
 */
class Uniqueness extends Validator
{
	private columnMap = null;

	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, string! field) -> boolean
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

	protected function isUniqueness(<Validation> validation, string! field) -> boolean
	{
		var value, record, attribute, except,
			index, params, metaData, primaryField, className;

		let value = validation->getValue(field),
			record = this->getOption("model");

		if empty record || typeof record != "object" {
			throw new Exception("Model of record must be set to property \"model\"");
		}

		let attribute = this->getColumnNameReal(record, this->getOption("attribute", field)),
			except = this->getOption("except");

		let index  = 0;
		let params = [
			"conditions": [],
			"bind": []
		];

		let params["conditions"][] = attribute . " = ?" . index;
		let params["bind"][] = value;
		let index++;

		if except {
			let params["conditions"][] = attribute . " <> ?" . index;
			let params["bind"][] = except;
			let index++;
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
