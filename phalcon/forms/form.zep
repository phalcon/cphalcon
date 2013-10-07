
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

namespace Phalcon\Forms;

/**
 * Phalcon\Forms\Form
 *
 * This component allows to build forms using an object-oriented interface
 */
class Form extends Phalcon\Di\Injectable implements Countable, Iterator
{

	protected _position;

	protected _entity;

	protected _options;

	protected _data;

	protected _elements;

	protected _elementsIndexed;

	protected _messages;

	protected _action;

	/**
	 * Phalcon\Forms\Form constructor
	 *
	 * @param object entity
	 * @param array userOptions
	 */
	public function __construct(var entity=null, userOptions=null)
	{
		if typeof entity != "null" {
			if typeof entity != "object" {
				throw new Phalcon\Forms\Exception("The base entity is not valid");
			}
			let this->_entity = entity;
		}

		/**
		 * Update the user options
		 */
		if typeof userOptions == "array" {
			let this->_options = userOptions;
		}

		/**
		 * Check for an 'initialize' method and call it
		 */
		if method_exists(this, "initialize") {
			this->{"initialize"}(entity, userOptions);
		}
	}

	/**
	 * Sets the form's action
	 *
	 * @param string action
	 * @return Phalcon\Forms\Form
	 */
	public function setAction(var action) -> <Phalcon\Forms\Form>
	{
		let this->_action = action;
		return this;
	}

	/**
	 * Returns the form's action
	 *
	 * @return string
	 */
	public function getAction() -> string
	{
		return this->_action;
	}

	/**
	 * Sets an option for the form
	 *
	 * @param string option
	 * @param mixed value
	 * @return Phalcon\Forms\Form
	 */
	public function setUserOption(var option, var value) -> <Phalcon\Forms\Form>
	{
		let this->_options[option] = value;
		return this;
	}

	/**
	 * Returns the value of an option if present
	 *
	 * @param string option
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function getUserOption(var option, defaultValue=null)
	{
		var value, options;
		let options = this->_options;
		if fetch value, options[option] {
			return value;
		}
		return defaultValue;
	}

	/**
	 * Sets options for the element
	 *
	 * @param array options
	 * @return Phalcon\Forms\Form
	 */
	public function setUserOptions(options) -> <Phalcon\Forms\Form>
	{
		if typeof options != "array" {
			throw new Phalcon\Forms\Exception("Parameter 'options' must be an array");
		}
		let this->_options = options;
		return this;
	}

	/**
	 * Returns the options for the element
	 *
	 * @return array
	 */
	public function getUserOptions()
	{
		return this->_options;
	}

	/**
	 * Sets the entity related to the model
	 *
	 * @param object entity
	 * @return Phalcon\Forms\Form
	 */
	public function setEntity(entity) -> <Phalcon\Forms\Form>
	{
		let this->_entity = entity;
		return this;
	}

	/**
	 * Returns the entity related to the model
	 *
	 * @return object
	 */
	public function getEntity()
	{
		return this->_entity;
	}

	/**
	 * Returns the form elements added to the form
	 *
	 * @return Phalcon\Forms\ElementInterface[]
	 */
	public function getElements() -> <Phalcon\Forms\ElementInterface[]>
	{
		return this->_elements;
	}

	/**
	 * Binds data to the entity
	 *
	 * @param array data
	 * @param object entity
	 * @param array whitelist
	 * @return Phalcon\Forms\Form
	 */
	public function bind(data, entity, whitelist=null) -> <Phalcon\Forms\Form>
	{
		var elements, filter, key, value, element, filters,
			dependencyInjector, filteredValue, method;

		/**
		 * The data must be an array
		 */
		if typeof data != "array" {
			throw new Phalcon\Forms\Exception("The data must be an array");
		}

		let elements = this->_elements;
		if typeof elements != "array" {
			throw new Phalcon\Forms\Exception("There are no elements in the form");
		}

		let filter = null;
		for key, value in data {

			if !isset elements[key] {
				continue;
			}

			/**
			 * Check if the item is in the whitelist
			 */
			if typeof whitelist == "array" {
				if !in_array(key, whitelist) {
					continue;
				}
			}

			/**
			 * Get the element
			 */
			let element = elements[key];

			/**
			 * Check if the method has filters
			 */
			let filters = element->getFilters();

			if filters {

				if typeof filter != "object" {
					let dependencyInjector = this->getDI(),
						filter = <Phalcon\FilterInterface> dependencyInjector->getShared("filter");
				}

				/**
				 * Sanitize the filters
				 */
				let filteredValue = filter->sanitize(value, filters);
			} else {
				let filteredValue = value;
			}

			/**
			 * Use the setter if any available
			 */
			let method = "set" . key;
			if method_exists(entity, method) {
				entity->{method}(filteredValue);
				continue;
			}

			/**
			 * Use the public property if it doesn't have a setter
			 */
			let entity->{key} = filteredValue;
		}

		let this->_data = data;

		return this;
	}

	/**
	 * Validates the form
	 *
	 * @param array data
	 * @param object entity
	 * @return boolean
	 */
	public function isValid(data=null, entity=null) -> boolean
	{
		var elements, notFailed, messages, element,
			validators, name, preparedValidators, filters,
			validator, validation, elementMessages;

		let elements = this->_elements;
		if typeof elements != "array" {
			return true;
		}

		/**
		 * If the user doesn't pass an entity we use the one in this_ptr->_entity
		 */
		if typeof entity == "object" {
			this->bind(data, entity);
		}

		/**
		 * If the data is not an array use the one passed previously
		 */
		if typeof data != "array" {
			let data = this->_data;
		}

		/**
		 * Check if there is a method 'beforeValidation'
		 */
		if method_exists(this, "beforeValidation") {
			if this->{"beforeValidation"}(data, entity) === false {
				return false;
			}
		}

		let notFailed = true,
			messages = [];

		for element in elements {

			let validators = element->getValidators();
			if typeof validators == "array" {
				if count(validators) {

					/**
					 * Element's name
					 */
					let name = element->getName();

					/**
					 * Prepare the validators
					 */
					let preparedValidators = [];

					for validator in validators {
						let preparedValidators[] = [name, validator];
					}

					/**
					 * Create an implicit validation
					 */
					let validation = new Phalcon\Validation(preparedValidators);

					/**
					 * Get filters in the element
					 */
					let filters = element->getFilters();

					/**
					 * Assign the filters to the validation
					 */
					if typeof filters == "array" {
						validation->setFilters(element->getName(), filters);
					}

					/**
					 * Perform the validation
					 */
					let elementMessages = validation->validate(data, entity);
					if count(elementMessages) {
						let messages[element->getName()] = elementMessages,
							notFailed = false;
					}

				}

			}
		}

		/**
		 * If the validation fails update the messages
		 */
		if !notFailed {
			let this->_messages = messages;
		}

		/**
		 * Check if there is a method 'afterValidation'
		 */
		if method_exists(this, "afterValidation") {
			this->{"afterValidation"}(messages);
		}

		/**
		 * Return the validation status
		 */
		return notFailed;
	}

	/**
	 * Returns the messages generated in the validation
	 *
	 * @param boolean byItemName
	 * @return array
	 */
	public function getMessages(boolean byItemName=false) -> <Phalcon\Validation\Message\Group>
	{
		var messages, group, element, elementMessages;

		let messages = this->_messages;
		if byItemName {
			if typeof messages != "array" {
				return new Phalcon\Validation\Message\Group();
			}
			return messages;
		}

		let group = new Phalcon\Validation\Message\Group();
		for element, elementMessages in messages {
			group->appendMessages(elementMessages);
		}

		return group;
	}

	/**
	 * Returns the messages generated for a specific element
	 *
	 * @return Phalcon\Validation\Message\Group
	 */
	public function getMessagesFor(name) -> <Phalcon\Validation\Message\Group>
	{
		var messages, elementMessages, group;

		let messages = this->_messages;
		if fetch elementMessages, messages[name] {
			return elementMessages;
		}

		let group = new Phalcon\Validation\Message\Group(),
			this->_messages[name] = group;
		return group;
	}

	/**
	 * Check if messages were generated for a specific element
	 *
	 * @return boolean
	 */
	public function hasMessagesFor(name) -> boolean
	{
		var messages;
		let messages = this->_messages;
		return isset messages[name];
	}

	/**
	 * Adds an element to the form
	 *
	 * @param Phalcon\Forms\ElementInterface element
	 * @return Phalcon\Forms\Form
	 */
	public function add(<Phalcon\Forms\ElementInterface> element) -> <Phalcon\Forms\Form>
	{
		var name;

		if typeof element != "object" {
			throw new Phalcon\Forms\Exception("The element is not valid");
		}

		/**
		 * Gets the element's name
		 */
		let name = element->getName();

		/**
		 * Link the element to the form
		 */
		element->setForm(this);

		/**
		 * Append the element by its name
		 */
		let this->_elements[name] = element;
		return this;
	}

	/**
	 * Renders a specific item in the form
	 *
	 * @param string name
	 * @param array attributes
	 * @return string
	 */
	public function render(string! name, attributes=null) -> string
	{
		var elements, element;

		let elements = this->_elements;
		if !isset elements[name] {
			throw new Phalcon\Forms\Exception("Element with ID=" . name . " is not part of the form");
		}

		let element = elements[name];
		return element->render(attributes);
	}

	/**
	 * Returns an element added to the form by its name
	 *
	 * @param string name
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function get(string! name) -> <Phalcon\Forms\ElementInterface>
	{
		var elements, element;

		let elements = this->_elements;
		if fetch element, elements[name] {
			return element;
		}

		throw new Phalcon\Forms\Exception("Element with ID=" . name . " is not part of the form");
	}

	/**
	 * Generate the label of a element added to the form including HTML
	 *
	 * @param string name
	 * @return string
	 */
	public function label(string! name) -> string
	{
		var elements, element;

		let elements = this->_elements;
		if fetch element, elements[name] {
			return element->label();
		}

		throw new Phalcon\Forms\Exception("Element with ID=" . name . " is not part of the form");
	}

	/**
	 * Returns a label for an element
	 *
	 * @param string name
	 * @return string
	 */
	public function getLabel(string! name) -> string
	{
		var elements, element, label;

		let elements = this->_elements;
		if !isset elements[name] {
			throw new Phalcon\Forms\Exception("Element with ID=" . name . " is not part of the form");
		}

		let element = elements[name];
		let label = element->getLabel();

		/**
		 * Use the element's name as label if the label is not available
		 */
		if !label {
			return name;
		}

		return label;
	}

	/**
	 * Gets a value from the internal related entity or from the default value
	 *
	 * @param string name
	 * @return mixed
	 */
	public function getValue(string! name)
	{
		var entity, method, value, data;

		let entity = this->_entity;
		if typeof entity == "object" {

			/**
			 * Check if the entity has a getter
			 */
			let method = "get" . name;
			if method_exists(entity, method) {
				return entity->{method}();
			}

			/**
			 * Check if the entity has a public property
			 */
			if fetch value, entity->{name}  {
				return value;
			}
		}

		let data = this->_data;
		if typeof data == "array" {

			/**
			 * Check if the data is in the data array
			 */
			if fetch value, data[name] {
				return value;
			}
		}

		return null;
	}

	/**
	 * Check if the form contains an element
	 *
	 * @param string name
	 * @return boolean
	 */
	public function has(string! name) -> boolean
	{
		var elements;

		let elements = this->_elements;

		/**
		 * Checks if the element is in the form
		 */
		return isset elements[name];
	}

	/**
	 * Removes an element from the form
	 *
	 * @param string name
	 * @return boolean
	 */
	public function remove(string! name) -> boolean
	{
		var elements;

		let elements = this->_elements;

		/**
		 * Checks if the element is in the form
		 */
		if isset elements[name] {
			//unset this->_elements[name]
			return true;
		}

		/**
		 * Clean the iterator index
		 */
		let this->_elementsIndexed = null;

		return false;
	}

	/**
	 * Clears every element in the form to its default value
	 *
	 * @param array fields
	 * @return Phalcon\Forms\Form
	 */
	public function clear(fields=null) -> <Phalcon\Forms\Form>
	{
		var elements, element;

		let elements = this->_elements;
		if typeof elements == "array" {
			for element in elements {
				if typeof fields != "array" {
					element->clear();
				} else {
					if in_array(element->getName(), fields) {
						element->clear();
					}
				}
			}
		}
		return this;
	}

	/**
	 * Returns the number of elements in the form
	 *
	 * @return int
	 */
	public function count() -> int
	{
		return count(this->_elements);
	}

	/**
	 * Rewinds the internal iterator
	 */
	public function rewind() -> void
	{
		let this->_position = 0;
		let this->_elementsIndexed = array_values(this->_elements);
	}

	/**
	 * Returns the current element in the iterator
	 *
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function current() -> <Phalcon\Forms\ElementInterface> | boolean
	{
		var elements, element;

		let elements = this->_elementsIndexed;
		if fetch element, elements[this->_position] {
			return element;
		}
		return false;
	}

	/**
	 * Returns the current position/key in the iterator
	 *
	 * @return int
	 */
	public function key() -> int
	{
		return this->_position;
	}

	/**
	 * Moves the internal iteration pointer to the next position
	 *
	 */
	public function next() -> void
	{
		let this->_position++;
	}

	/**
	 * Check if the current element in the iterator is valid
	 *
	 * @return boolean
	 */
	public function valid() -> boolean
	{
		var elements;
		let elements = this->_elementsIndexed;
		return isset elements[this->_position];
	}

}
