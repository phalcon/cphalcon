
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
 * Phalcon\Forms\Element
 *
 * This is a base class for form elements
 */
abstract class Element {

	protected _form;

	protected _name;

	protected _value;

	protected _label;

	protected _attributes;

	protected _validators;

	protected _filters;

	protected _options;

	protected _messages;

	/**
	 * Phalcon\Forms\Element constructor
	 *
	 * @param string name
	 * @param array attributes
	 */
	public function __construct(string name, attributes=null)
	{
		let this->_name = name;
		if typeof attributes == "array" {
			let this->_attributes = attributes;
		}
	}

	/**
	 * Sets the parent form to the element
	 *
	 * @param Phalcon\Forms\Form form
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setForm(<Phalcon\Forms\Form> form) -> <Phalcon\Forms\ElementInterface>
	{
		let this->_form = form;
		return this;
	}

	/**
	 * Returns the parent form to the element
	 *
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function getForm() -> <Phalcon\Forms\ElementInterface>
	{
		return this->_form;
	}

	/**
	 * Sets the element name
	 *
	 * @param string name
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setName(string name) -> <Phalcon\Forms\ElementInterface>
	{
		let this->_name = name;
		return this;
	}

	/**
	 * Returns the element name
	 *
	 * @return string
	 */
	public function getName() -> string
	{
		return this->_name;
	}

	/**
	 * Sets the element filters
	 *
	 * @param array|string filters
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setFilters(var filters) -> <Phalcon\Forms\ElementInterface>
	{
		let this->_filters = filters;
		return this;
	}

	/**
	 * Adds a filter to current list of filters
	 *
	 * @param string filter
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function addFilter(string filter) -> <Phalcon\Forms\ElementInterface>
	{
		var filters;
		let filters = this->_filters;
		if typeof filters == "array" {
			let this->_filters[] = filter;
		} else {
			let this->_filters = [filters, filter];
		}
		return this;
	}

	/**
	 * Returns the element filters
	 *
	 * @return mixed
	 */
	public function getFilters()
	{
		return this->_filters;
	}

	/**
	 * Adds a group of validators
	 *
	 * @param Phalcon\Validation\ValidatorInterface[]
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function addValidators(validators, boolean merge=true) -> <Phalcon\Forms\ElementInterface>
	{
		var currentValidators, mergedValidators;
		if typeof validators != "array" {
			throw new Phalcon\Forms\Exception("The validators parameter must be an array");
		}
		if merge {
			let currentValidators = this->_validators;
			if typeof currentValidators == "array" {
				let mergedValidators = array_merge(currentValidators, validators);
			} else {
				let mergedValidators = validators;
			}
			let this->_validators = mergedValidators;
		}
		return this;
	}

	/**
	 * Adds a validator to the element
	 *
	 * @param Phalcon\Validation\ValidatorInterface
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function addValidator(<Phalcon\Validation\ValidatorInterface> validator) -> <Phalcon\Forms\ElementInterface>
	{
		if typeof validator != "object" {
			throw new Phalcon\Forms\Exception("The validators parameter must be an object");
		}
		let this->_validators[] = validator;
		return this;
	}

	/**
	 * Returns the validators registered for the element
	 *
	 * @return Phalcon\Validation\ValidatorInterface[]
	 */
	public function getValidators()
	{
		return this->_validators;
	}

	/**
	 * Returns an array of prepared attributes for Phalcon\Tag helpers
	 * according to the element parameters
	 *
	 * @param array attributes
	 * @param boolean useChecked
	 * @return array
	 */
	public function prepareAttributes(attributes=null, boolean useChecked=false)
	{
		var value, name, widgetAttributes, mergedAttributes,
			defaultAttributes, currentValue;

		let name = this->_name;

		/**
		 * Create an array of parameters
		 */
		if typeof attributes != "array" {
			let widgetAttributes = [];
		} else {
			let widgetAttributes = attributes;
		}

		let widgetAttributes[0] = name;

		/**
		 * Merge passed parameters with default ones
		 */
		let defaultAttributes = this->_attributes;
		if typeof defaultAttributes == "array" {
			let mergedAttributes = array_merge(defaultAttributes, widgetAttributes);
		} else {
			let mergedAttributes = widgetAttributes;
		}

		/**
		 * Get the current element value
		 */
		let value = this->getValue();

		/**
		 * If the widget has a value set it as default value
		 */
		if value !== null {
			if useChecked {
				/**
				 * Check if the element already has a default value, compare it with the one in the attributes, if they are the same mark the element as checked
				 */
				if fetch currentValue, mergedAttributes["value"] {
					if currentValue == value {
						let mergedAttributes["checked"] = "checked";
					}
				} else {
					/**
					 * Evaluate the current value and mark the check as checked
					 */
					if value {
						let mergedAttributes["checked"] = "checked";
					}
					let mergedAttributes["value"] = value;
				}
			} else {
				let mergedAttributes["value"] = value;
			}
		}

		return mergedAttributes;
	}

	/**
	 * Sets a default attribute for the element
	 *
	 * @param string attribute
	 * @param mixed value
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setAttribute(string attribute, value) -> <Phalcon\Forms\ElementInterface>
	{
		let this->_attributes[attribute] = value;
		return this;
	}

	/**
	 * Returns the value of an attribute if present
	 *
	 * @param string attribute
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function getAttribute(string attribute, defaultValue=null)
	{
		var attributes, value;
		let attributes = this->_attributes;
		if fetch value, attributes[attribute] {
			return value;
		}
		return defaultValue;
	}

	/**
	 * Sets default attributes for the element
	 *
	 * @param array attributes
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setAttributes(attributes) -> <Phalcon\Forms\ElementInterface>
	{
		if typeof attributes != "array" {
			throw new Phalcon\Forms\Exception("Parameter 'attributes' must be an array");
		}
		let this->_attributes = attributes;
		return this;
	}

	/**
	 * Returns the default attributes for the element
	 *
	 * @return array
	 */
	public function getAttributes()
	{
		var attributes;
		let attributes = this->_attributes;
		if typeof attributes != "array" {
			return [];
		}
		return attributes;
	}

	/**
	 * Sets an option for the element
	 *
	 * @param string option
	 * @param mixed value
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setUserOption(string option, value) -> <Phalcon\Forms\ElementInterface>
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
	public function getUserOption(option, defaultValue=null)
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
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setUserOptions(options) -> <Phalcon\Forms\ElementInterface>
	{
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
	 * Sets the element label
	 *
	 * @param string label
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setLabel(string label) -> <Phalcon\Forms\ElementInterface>
	{
		let this->_label = label;
		return this;
	}

	/**
	 * Returns the element label
	 *
	 * @return string
	 */
	public function getLabel() -> string
	{
		return this->_label;
	}

	/**
	 * Generate the HTML to label the element
	 *
	 * @return string
	 */
	public function label() -> string
	{
		var attributes, label, name;

		/**
		 * Check if there is an "id" attribute defined
 		 */
 		let attributes = this->_attributes;
		if fetch name, attributes["id"] {
			let name = this->_name;
		}

		/**
		 * Use the default label or leave the same name as label
		 */
		let label = this->_label;
		if label {
			return "<label for=\"" .name . "\">" . label . "</label>";
		}
		return "<label for=\"" . name . "\">" . name . "</label>";
	}

	/**
	 * Sets a default value in case the form does not use an entity
	 * or there is no value available for the element in _POST
	 *
	 * @param mixed value
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setDefault(value) -> <Phalcon\Forms\ElementInterface>
	{
		let this->_value = value;
		return this;
	}

	/**
	 * Returns the default value assigned to the element
	 *
	 * @return mixed
	 */
	public function getDefault()
	{
		return this->_value;
	}

	/**
	 * Returns the element value
	 *
	 * @return mixed
	 */
	public function getValue()
	{
		var name, form, value;

		let name = this->_name,
			value = null;

		/**
		 * Get the related form
		 */
		let form = this->_form;
		if typeof form == "object" {

			/**
			 * Check if the tag has a default value
			 */
			if !Phalcon\Tag::hasValue(name) {

				/**
				 * Gets the possible value for the widget
				 */
				let value = form->getValue(name);
			}

		}

		/**
		 * Assign the default value if there is no form available
		 */
		if typeof value == "null" {
			let value = this->_value;
		}

		return value;
	}

	/**
	 * Returns the messages that belongs to the element
	 * The element needs to be attached to a form
	 *
	 * @return Phalcon\Validation\Message\Group
	 */
	public function getMessages() -> <Phalcon\Validation\Message\Group>
	{
		var messages;

		let messages = this->_messages;
		if typeof messages == "object" {
			return messages;
		}

		let messages = new Phalcon\Validation\Message\Group(),
			this->_messages = messages;
		return messages;
	}

	/**
	 * Checks whether there are messages attached to the element
	 *
	 * @return boolean
	 */
	public function hasMessages() -> boolean
	{
		var messages;

		/**
		 * Get the related form
		 */
		let messages = this->_messages;
		if typeof messages == "object" {
			return count(messages) > 0;
		}

		return false;
	}

	/**
	 * Sets the validation messages related to the element
	 *
	 * @param Phalcon\Validation\Message\Group group
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function setMessages(<Phalcon\Validation\Message\Group> group) -> <Phalcon\Forms\ElementInterface>
	{
		let this->_messages = group;
		return this;
	}

	/**
	 * Appends a message to the internal message list
	 *
	 * @param Phalcon\Validation\Message message
	 * @return Phalcon\Forms\ElementInterface
	 */
	public function appendMessage(<Phalcon\Validation\Message> message) -> <Phalcon\Forms\ElementInterface>
	{
		var messages;

		let messages = this->_messages;
		if typeof messages != "object" {
			let this->_messages = new Phalcon\Validation\Message\Group();
		}
		messages->appendMessage(message);
		return this;
	}

	/**
	 * Clears every element in the form to its default value
	 *
	 * @return Phalcon\Forms\Element
	 */
	public function clear() -> <Phalcon\Forms\Element>
	{
		Phalcon\Tag::setDefault(this->_name, null);
		return this;
	}

	/**
	 * Magic method __toString renders the widget without atttributes
	 *
	 * @return string
	 */
	public function __toString()
	{
		return this->{"render"}();
	}

}
