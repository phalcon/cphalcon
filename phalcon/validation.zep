
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
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

namespace Phalcon;

use Phalcon\Di\Injectable;
use Phalcon\ValidationInterface;
use Phalcon\Validation\Exception;
use Phalcon\Validation\Message\Group;
use Phalcon\Validation\MessageInterface;
use Phalcon\Validation\ValidatorInterface;
use Phalcon\Validation\CombinedFieldsValidator;

/**
 * Phalcon\Validation
 *
 * Allows to validate data using custom or built-in validators
 */
class Validation extends Injectable implements ValidationInterface
{
	protected _data { get };

	protected _entity;

	protected _validators = [] { set };

	protected _combinedFieldsValidators = [];

	protected _filters = [];

	protected _messages;

	protected _defaultMessages;

	protected _labels = [];

	protected _values;

	/**
	 * Phalcon\Validation constructor
	 */
	public function __construct(array validators = null)
	{
		if count(validators) {
			let this->_validators = array_filter(validators, function(var element) {
				return typeof element[0] != "array" || !(element[1] instanceof CombinedFieldsValidator);
			});
			let this->_combinedFieldsValidators = array_filter(validators, function(var element) {
				return typeof element[0] == "array" && element[1] instanceof CombinedFieldsValidator;
			});
		}

		this->setDefaultMessages();

		/**
		 * Check for an 'initialize' method
		 */
		if method_exists(this, "initialize") {
			this->{"initialize"}();
		}
	}

	/**
	 * Validate a set of data according to a set of rules
	 *
	 * @param array|object data
	 * @param object entity
	 * @return \Phalcon\Validation\Message\Group
	 */
	public function validate(var data = null, var entity = null) -> <Group>
	{
		var validators, messages, scope, field, validator, status, combinedFieldsValidators;

		let validators = this->_validators;
		let combinedFieldsValidators = this->_combinedFieldsValidators;

		if typeof validators != "array" {
			throw new Exception("There are no validators to validate");
		}

		/**
		 * Clear pre-calculated values
		 */
		let this->_values = null;

		/**
		 * Implicitly creates a Phalcon\Validation\Message\Group object
		 */
		let messages = new Group();

		if entity !== null {
			this->setEntity(entity);
		}

		/**
		 * Validation classes can implement the 'beforeValidation' callback
		 */
		if method_exists(this, "beforeValidation") {
			let status = this->{"beforeValidation"}(data, entity, messages);
			if status === false {
				return status;
			}
		}

		let this->_messages = messages;

		if data !== null {
			if typeof data == "array" || typeof data == "object" {
				let this->_data = data;
			} else {
				throw new Exception("Invalid data to validate");
			}
		}

		for scope in validators {

			if typeof scope != "array" {
				throw new Exception("The validator scope is not valid");
			}

			let field = scope[0],
				validator = scope[1];

			if typeof validator != "object" {
				throw new Exception("One of the validators is not valid");
			}

			/**
			 * Call internal validations, if it returns true, then skip the current validator
			 */
			if this->preChecking(field, validator) {
				continue;
			}

			/**
			 * Check if the validation must be canceled if this validator fails
			 */
			if validator->validate(this, field) === false {
				if validator->getOption("cancelOnFail") {
					break;
				}
			}
		}

		for scope in combinedFieldsValidators {
			if typeof scope != "array" {
				throw new Exception("The validator scope is not valid");
			}

			let field = scope[0],
				validator = scope[1];

			if typeof validator != "object" {
				throw new Exception("One of the validators is not valid");
			}

			/**
			 * Call internal validations, if it returns true, then skip the current validator
			 */
			if this->preChecking(field, validator) {
				continue;
			}

			/**
			 * Check if the validation must be canceled if this validator fails
			 */
			if validator->validate(this, field) === false {
				if validator->getOption("cancelOnFail") {
					break;
				}
			}
		}

		/**
		 * Get the messages generated by the validators
		 */
		if method_exists(this, "afterValidation") {
			this->{"afterValidation"}(data, entity, this->_messages);
		}

		return this->_messages;
	}

	/**
	 * Adds a validator to a field
	 */
	public function add(var field, <ValidatorInterface> validator) -> <Validation>
	{
		var singleField;
		if typeof field == "array" {
			// Uniqueness validator for combination of fields is handled differently
			if validator instanceof CombinedFieldsValidator {
				let this->_combinedFieldsValidators[] = [field, validator];
			}
			else {
				for singleField in field {
					let this->_validators[] = [singleField, validator];
				}
			}
		}
		elseif typeof field == "string" {
			let this->_validators[] = [field, validator];
		}
		else {
			throw new Exception("Field must be passed as array of fields or string");
		}
		return this;
	}

	/**
	 * Alias of `add` method
	 */
	public function rule(var field, <ValidatorInterface> validator) -> <Validation>
	{
		return this->add(field, validator);
	}

	/**
	 * Adds the validators to a field
	 */
	public function rules(var field, array! validators) -> <Validation>
	{
		var validator;

		for validator in validators {
			if validator instanceof ValidatorInterface {
				this->add(field, validator);
			}
		}

		return this;
	}

	/**
	 * Adds filters to the field
	 *
	 * @param array|string field
	 * @param array|string filters
	 * @return \Phalcon\Validation
	 */
	public function setFilters(var field, filters) -> <Validation>
	{
		var singleField;
		if typeof field == "array" {
			for singleField in field {
				let this->_filters[singleField] = filters;
			}
		}
		elseif typeof field == "string" {
			let this->_filters[field] = filters;
		}
		else {
			throw new Exception("Field must be passed as array of fields or string.");
		}
		return this;
	}

	/**
	 * Returns all the filters or a specific one
	 *
	 * @param string field
	 * @return mixed
	 */
	public function getFilters(string field = null)
	{
		var filters, fieldFilters;
		let filters = this->_filters;

		if field === null || field === "" {
			return filters;
		}

		if !fetch fieldFilters, filters[field] {
			return null;
		}

		return fieldFilters;
	}

	/**
	 * Returns the validators added to the validation
	 */
	public function getValidators() -> array
	{
		return this->_validators;
	}

	/**
	 * Sets the bound entity
	 *
	 * @param object entity
	 */
	public function setEntity(entity)
	{
		if typeof entity != "object" {
			throw new Exception("Entity must be an object");
		}
		let this->_entity = entity;
	}

	/**
	 * Returns the bound entity
	 *
	 * @return object
	 */
	public function getEntity()
	{
		return this->_entity;
	}

	/**
	 * Adds default messages to validators
	 */
	public function setDefaultMessages(array messages = []) -> array
	{
		var defaultMessages;

		let defaultMessages = [
			"Alnum": "Field :field must contain only letters and numbers",
			"Alpha": "Field :field must contain only letters",
			"Between": "Field :field must be within the range of :min to :max",
			"Confirmation": "Field :field must be the same as :with",
			"Digit": "Field :field must be numeric",
			"Email": "Field :field must be an email address",
			"ExclusionIn": "Field :field must not be a part of list: :domain",
			"FileEmpty": "Field :field must not be empty",
			"FileIniSize": "File :field exceeds the maximum file size",
			"FileMaxResolution": "File :field must not exceed :max resolution",
			"FileMinResolution": "File :field must be at least :min resolution",
			"FileSize": "File :field exceeds the size of :max",
			"FileType": "File :field must be of type: :types",
			"FileValid": "Field :field is not valid",
			"Identical": "Field :field does not have the expected value",
			"InclusionIn": "Field :field must be a part of list: :domain",
			"Numericality": "Field :field does not have a valid numeric format",
			"PresenceOf": "Field :field is required",
			"Regex": "Field :field does not match the required format",
			"TooLong": "Field :field must not exceed :max characters long",
			"TooShort": "Field :field must be at least :min characters long",
			"Uniqueness": "Field :field must be unique",
			"Url": "Field :field must be a url",
			"CreditCard": "Field :field is not valid for a credit card number",
			"Date": "Field :field is not a valid date"
		];

		let this->_defaultMessages = array_merge(defaultMessages, messages);

		return this->_defaultMessages;
	}

	/**
	 * Get default message for validator type
	 */
	public function getDefaultMessage(string! type) -> string
	{
		var defaultMessage;

		if fetch defaultMessage, this->_defaultMessages[type] {
			return defaultMessage;
		}

		return "";
	}

	/**
	 * Returns the registered validators
	 */
	public function getMessages() -> <Group>
	{
		return this->_messages;
	}

	/**
	 * Adds labels for fields
	 */
	public function setLabels(array! labels)
	{
		let this->_labels = labels;
	}

	/**
	 * Get label for field
	 *
	 * @param string field
	 * @return string
	 */
	public function getLabel(var field)
	{
		var labels, value;

		let labels = this->_labels;

		if typeof field == "array" {
			return join(", ", field);
		}

		if fetch value, labels[field] {
			return value;
		}

		return field;
	}

	/**
	 * Appends a message to the messages list
	 */
	public function appendMessage(<MessageInterface> message) -> <Validation>
	{
		var messages;

		let messages = this->_messages;
		if typeof messages != "object" {
			let messages = new Group();
		}

		messages->appendMessage(message);

		let this->_messages = messages;

		return this;
	}

	/**
	 * Assigns the data to an entity
	 * The entity is used to obtain the validation values
	 *
	 * @param object entity
	 * @param array|object data
	 * @return \Phalcon\Validation
	 */
	public function bind(entity, data) -> <Validation>
	{
		if typeof entity != "object" {
			throw new Exception("Entity must be an object");
		}

		if typeof data != "array" && typeof data != "object" {
			throw new Exception("Data to validate must be an array or object");
		}

		let this->_entity = entity,
			this->_data = data;

		return this;
	}

	/**
	 * Gets the a value to validate in the array/object data source
	 *
	 * @param string field
	 * @return mixed
	 */
	public function getValue(string field)
	{
		var entity, method, value, data, values,
			filters, fieldFilters, dependencyInjector,
			filterService, camelizedField;

		let entity = this->_entity;

		//  If the entity is an object use it to retrieve the values
		if typeof entity == "object" {
			let camelizedField = camelize(field);
			let method = "get" . camelizedField;
			if method_exists(entity, method) {
				let value = entity->{method}();
			} else {
				if method_exists(entity, "readAttribute") {
					let value = entity->readAttribute(field);
				} else {
					if isset entity->{field} {
						let value = entity->{field};
					} else {
						let value = null;
					}
				}
			}
		}
		else {
			let data = this->_data;

			if typeof data != "array" && typeof data != "object" {
				throw new Exception("There is no data to validate");
			}

			// Check if there is a calculated value
			let values = this->_values;
			if fetch value, values[field] {
				return value;
			}

			let value = null;
			if typeof data == "array" {
				if isset data[field] {
					let value = data[field];
				}
			} else {
				if typeof data == "object" {
					if isset data->{field} {
						let value = data->{field};
					}
				}
			}
		}

		if typeof value == "null" {
			return null;
		}

		let filters = this->_filters;

		if fetch fieldFilters, filters[field] {

			if fieldFilters {

				let dependencyInjector = this->getDI();
				if typeof dependencyInjector != "object" {
					let dependencyInjector = Di::getDefault();
					if typeof dependencyInjector != "object" {
						throw new Exception("A dependency injector is required to obtain the 'filter' service");
					}
				}

				let filterService = dependencyInjector->getShared("filter");
				if typeof filterService != "object" {
					throw new Exception("Returned 'filter' service is invalid");
				}

				let value = filterService->sanitize(value, fieldFilters);

				/**
				 * Set filtered value in entity
				 */
				if typeof entity == "object" {
					let method = "set" . camelizedField;
					if method_exists(entity, method) {
						entity->{method}(value);
					} else {
						if method_exists(entity, "writeAttribute") {
							entity->writeAttribute(field, value);
						} else {
							if property_exists(entity, field) {
								let entity->{field} = value;
							}
						}
					}
				}

				return value;
			}
		}

		// Cache the calculated value only if it's not entity
		if typeof entity != "object" {
			let this->_values[field] = value;
		}

		return value;
	}

	/**
	 * Internal validations, if it returns true, then skip the current validator
	 */
	protected function preChecking(var field, <ValidatorInterface> validator) -> boolean
	{
		var singleField, allowEmpty, emptyValue, value, result;

		if typeof field == "array" {
			for singleField in field {
				let result = this->preChecking(singleField, validator);
				if result {
					return result;
				}
			}
		} else {
			let allowEmpty = validator->getOption("allowEmpty", false);

			if allowEmpty {
				if method_exists(validator, "isAllowEmpty") {
					return validator->isAllowEmpty(this, field);
				}

				let value = this->getValue(field);

				// 'allowEmpty' => [null, false, RawValue('NULL')]
				if typeof allowEmpty == "array" {
					for emptyValue in allowEmpty {
						if emptyValue === value {
							return true;
						} elseif typeof emptyValue == "object" && typeof value == "object" && emptyValue == value {
							return true;
						}
					}

					return false;
				}

				var raw;

				// Workaround for \Phalcon\Db\RawValue('NULL')
				if unlikely typeof value == "object" && method_exists(value, "__toString") {
					// NULL -> null
					let raw = strtolower(value->__toString());

					if in_array(raw, ["null", "false", ""], true) {
						return true;
					}
				}

				return empty value;
			}
		}

		return false;
	}
}
