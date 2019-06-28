
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

namespace Phalcon\Forms;

use Phalcon\Validation;
use Phalcon\ValidationInterface;
use Phalcon\DiInterface;
use Phalcon\FilterInterface;
use Phalcon\Di\Injectable;
use Phalcon\Forms\Exception;
use Phalcon\Forms\ElementInterface;
use Phalcon\Validation\Message\Group;

/**
 * Phalcon\Forms\Form
 *
 * This component allows to build forms using an object-oriented interface
 */
class Form extends Injectable implements \Countable, \Iterator
{
	protected _position;

	protected _entity;

	protected _options = [];

	protected _data;

	protected _elements = [];

	protected _elementsIndexed;

	protected _messages;

	protected _action;

	protected _validation { set, get };

	/**
	 * Phalcon\Forms\Form constructor
	 *
	 * @param object entity
	 * @param array userOptions
	 */
	public function __construct(var entity = null, var userOptions = null)
	{
		if typeof entity != "null" {
			if typeof entity != "object" {
				throw new Exception("The base entity is not valid");
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
	 */
	public function setAction(string! action) -> <Form>
	{
		let this->_action = action;
		return this;
	}

	/**
	 * Returns the form's action
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
	 */
	public function setUserOption(var option, var value) -> <Form>
	{
		let this->_options[option] = value;
		return this;
	}

	/**
	 * Returns the value of an option if present
	 *
	 * @param string option
	 * @param mixed defaultValue
	 */
	public function getUserOption(var option, var defaultValue = null) -> var
	{
		var value;
		if fetch value, this->_options[option] {
			return value;
		}
		return defaultValue;
	}

	/**
	 * Sets options for the element
	 */
	public function setUserOptions(array! options) -> <Form>
	{
		let this->_options = options;
		return this;
	}

	/**
	 * Returns the options for the element
	 */
	public function getUserOptions() -> array
	{
		return this->_options;
	}

	/**
	 * Sets the entity related to the model
	 *
	 * @param object entity
	 */
	public function setEntity(var entity) -> <Form>
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
	 */
	public function getElements() -> <ElementInterface[]>
	{
		return this->_elements;
	}

	/**
	 * Binds data to the entity
	 *
	 * @param array data
	 * @param object entity
	 * @param array whitelist
	 */
	public function bind(array! data, var entity, var whitelist = null) -> <Form>
	{
		var filter, key, value, element, filters,
			dependencyInjector, filteredValue, method;

		if empty this->_elements {
			throw new Exception("There are no elements in the form");
		}

		let filter = null;
		for key, value in data {

			/**
			 * Get the element
			 */
			if !fetch element, this->_elements[key] {
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
			 * Check if the method has filters
			 */
			let filters = element->getFilters();

			if filters {

				if typeof filter != "object" {
					let dependencyInjector = this->getDI(),
						filter = <FilterInterface> dependencyInjector->getShared("filter");
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
			let method = "set" . camelize(key);
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
	 */
	public function isValid(var data = null, var entity = null) -> boolean
	{
		var validationStatus, messages, element,
			validators, name, filters,
			validator, validation, elementMessage;

		if empty this->_elements {
			return true;
		}

		/**
		 * If the data is not an array use the one passed previously
		 */
		if typeof data != "array" {
			let data = this->_data;
		}

		/**
		 * If the user doesn't pass an entity we use the one in this_ptr->_entity
		 */
		if typeof entity == "object" {
			this->bind(data, entity);
		} else {
			if typeof this->_entity == "object" {
				this->bind(data, this->_entity);
			}
		}

		/**
		 * Check if there is a method 'beforeValidation'
		 */
		if method_exists(this, "beforeValidation") {
			if this->{"beforeValidation"}(data, entity) === false {
				return false;
			}
		}

		let validationStatus = true;

        let validation = this->getValidation();

        if typeof validation != "object" || !(validation instanceof ValidationInterface) {
            // Create an implicit validation
            let validation = new Validation();
        }

		for element in this->_elements {

			let validators = element->getValidators();
			if typeof validators != "array" || count(validators) == 0 {
				continue;
			}

			/**
			 * Element's name
			 */
			let name = element->getName();

            /**
            * Append (not overriding) element validators to validation class
            */
			for validator in validators {
			    validation->add(name, validator);
			}

			/**
			 * Get filters in the element
			 */
			let filters = element->getFilters();

			/**
			 * Assign the filters to the validation
			 */
			if typeof filters == "array" {
				validation->setFilters(name, filters);
			}
		}

        /**
        * Perform the validation
        */
        let messages = validation->validate(data, entity);
        if messages->count() {
            // Add validation messages to relevant elements
            for elementMessage in iterator(messages) {
                this->get(elementMessage->getField())->appendMessage(elementMessage);
            }
            messages->rewind();
            let validationStatus = false;
        }

		/**
		 * If the validation fails update the messages
		 */
		if !validationStatus {
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
		return validationStatus;
	}

	/**
	 * Returns the messages generated in the validation.
	 *
	 * <code>
	 * if ($form->isValid($_POST) == false) {
	 *     // Get messages separated by the item name
	 *     // $messages is an array of Group object
	 *     $messages = $form->getMessages(true);
	 *
	 *     foreach ($messages as $message) {
	 *         echo $message, "<br>";
	 *     }
	 *
	 *     // Default behavior.
	 *     // $messages is a Group object
	 *     $messages = $form->getMessages();
	 *
	 *     foreach ($messages as $message) {
	 *         echo $message, "<br>";
	 *     }
	 * }
	 * </code>
	 */
	public function getMessages(boolean byItemName = false) -> <Group> | array
	{
		var messages, messagesByItem, elementMessage, fieldName;

		let messages = this->_messages;

		if typeof messages == "object" && messages instanceof Group {
			/**
			 * @deprecated This part of code is for backward compatibility, it should be removed in next major version
			 */
			if unlikely byItemName {
				let messagesByItem = [];
				messages->rewind();
				
				while messages->valid() {
					let elementMessage = messages->current(),
						fieldName = elementMessage->getField();
						
						if !isset messagesByItem[fieldName] {
							let messagesByItem[fieldName] = [];
						}
						
						let messagesByItem[fieldName][] = new Group([elementMessage]);
						messages->next();
				}
				return messagesByItem;
			}
			return messages;
		}

		return new Group();
	}

	/**
	 * Returns the messages generated for a specific element
	 */
	public function getMessagesFor(string! name) -> <Group>
	{
	    if this->has(name) {
            return this->get(name)->getMessages();
	    }
	    return new Group();
	}

	/**
	 * Check if messages were generated for a specific element
	 */
	public function hasMessagesFor(string! name) -> boolean
	{
		return this->getMessagesFor(name)->count() > 0;
	}

	/**
	 * Adds an element to the form
	 */
	public function add(<ElementInterface> element, string position = null, boolean type = null) -> <Form>
	{
		var name, key, value, elements;

		/**
		 * Gets the element's name
		 */
		let name = element->getName();

		/**
		 * Link the element to the form
		 */
		element->setForm(this);

		if position == null || empty this->_elements {
			/**
			 * Append the element by its name
			 */
			let this->_elements[name] = element;
		} else {
			let elements = [];
			/**
			 * Walk elements and add the element to a particular position
			 */
			for key, value in this->_elements {
				if key == position {
					if type {
						/**
						 * Add the element before position
						 */
						let elements[name] = element, elements[key] = value;
					} else {
						/**
						 * Add the element after position
						 */
						let elements[key] = value, elements[name] = element;
					}
				} else {
					/**
					 * Copy the element to new array
					 */
					let elements[key] = value;
				}
			}
			let this->_elements = elements;
		}
		return this;
	}

	/**
	 * Renders a specific item in the form
	 *
	 * @param string name
	 * @param array attributes
	 */
	public function render(string! name, var attributes = null) -> string
	{
		var element;

		if !fetch element, this->_elements[name] {
			throw new Exception("Element with ID=" . name . " is not part of the form");
		}

		return element->render(attributes);
	}

	/**
	 * Returns an element added to the form by its name
	 */
	public function get(string! name) -> <ElementInterface>
	{
		var element;

		if fetch element, this->_elements[name] {
			return element;
		}

		throw new Exception("Element with ID=" . name . " is not part of the form");
	}

	/**
	 * Generate the label of an element added to the form including HTML
	 */
	public function label(string! name, array attributes = null) -> string
	{
		var element;

		if fetch element, this->_elements[name] {
			return element->label(attributes);
		}

		throw new Exception("Element with ID=" . name . " is not part of the form");
	}

	/**
	 * Returns a label for an element
	 */
	public function getLabel(string! name) -> string
	{
		var element, label;

		if !fetch element, this->_elements[name] {
			throw new Exception("Element with ID=" . name . " is not part of the form");
		}

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
	 */
	public function getValue(string! name) -> var | null
	{
		var entity, method, value, data, $internal, forbidden;

		let entity = this->_entity;
		let data = this->_data;

		/**
		 * Check if form has a getter
		 */
		if method_exists(this, "getCustomValue") {
			return this->{"getCustomValue"}(name, entity, data);
		}

		if typeof entity == "object" {

			/**
			 * Check if the entity has a getter
			 */
			let method = "get" . camelize(name);
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

		if typeof data == "array" {

			/**
			 * Check if the data is in the data array
			 */
			if fetch value, data[name] {
				return value;
			}
		}

		let forbidden = [
			"validation" : true,
			"action" : true,
			"useroption" : true,
			"useroptions" : true,
			"entity" : true,
			"elements" : true,
			"messages" : true,
			"messagesfor" : true,
			"label" : true,
			"value" : true,
			"di" : true,
			"eventsmanager" : true
		];

		/**
		 * Check if the method is internal
		 */
		let $internal = strtolower(name);
		if isset forbidden[$internal] {
			return null;
		}

		/**
		 * Check if form has a getter
		 */
		let method = "get" . camelize(name);
		if method_exists(this, method) {
			return this->{method}();
		}

		return null;
	}

	/**
	 * Check if the form contains an element
	 */
	public function has(string! name) -> boolean
	{
		/**
		 * Checks if the element is in the form
		 */
		return isset this->_elements[name];
	}

	/**
	 * Removes an element from the form
	 */
	public function remove(string! name) -> boolean
	{
		/**
		 * Checks if the element is in the form
		 */
		if isset this->_elements[name] {
			unset this->_elements[name];
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
	 */
	public function clear(var fields = null) -> <Form>
	{
		var elements, element, data, field;

		let data = this->_data;
		if is_null(fields) {
			let data = [];
		} else {
			if typeof fields != "array" {
                let fields = [fields];
            }

			for field in fields {
				if isset data[field] {
					unset data[field];
				}
			}
		}

		let this->_data = data,
			elements = this->_elements;

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
		if typeof this->_elements == "array" {
		    let this->_elementsIndexed = array_values(this->_elements);
		} else {
		    let this->_elementsIndexed = [];
		}
	}

	/**
	 * Returns the current element in the iterator
	 */
	public function current() -> <ElementInterface> | boolean
	{
		var element;

		if fetch element, this->_elementsIndexed[this->_position] {
			return element;
		}

		return false;
	}

	/**
	 * Returns the current position/key in the iterator
	 */
	public function key() -> int
	{
		return this->_position;
	}

	/**
	 * Moves the internal iteration pointer to the next position
	 */
	public function next() -> void
	{
		let this->_position++;
	}

	/**
	 * Check if the current element in the iterator is valid
	 */
	public function valid() -> boolean
	{
		return isset this->_elementsIndexed[this->_position];
	}
}
