
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms;

use Phalcon\Tag;
use Phalcon\Forms\Exception;
use Phalcon\Messages\MessageInterface;
use Phalcon\Messages\Messages;
use Phalcon\Validation\ValidatorInterface;

/**
 * Phalcon\Forms\Element
 *
 * This is a base class for form elements
 */
abstract class Element implements ElementInterface
{

	protected _form;

	protected _name;

	protected _value;

	protected _label;

	protected _attributes;

	protected _validators = [];

	protected _filters;

	protected _options;

	protected _messages;

	/**
	 * Phalcon\Forms\Element constructor
	 */
	public function __construct(string name, array attributes = [])
	{
		let name = trim(name);

		if empty name {
			throw new \InvalidArgumentException("Form element name is required");
		}

		let this->_name = name;
		let this->_attributes = attributes;
		let this->_messages = new Messages();
	}

	/**
	 * Sets the parent form to the element
	 */
	public function setForm(<Form> form) -> <ElementInterface>
	{
		let this->_form = form;
		return this;
	}

	/**
	 * Returns the parent form to the element
	 */
	public function getForm() -> <Form>
	{
		return this->_form;
	}

	/**
	 * Sets the element name
	 */
	public function setName(string! name) -> <ElementInterface>
	{
		let this->_name = name;
		return this;
	}

	/**
	 * Returns the element name
	 */
	public function getName() -> string
	{
		return this->_name;
	}

	/**
	 * Sets the element filters
	 *
	 * @param array|string filters
	 */
	public function setFilters(var filters) -> <ElementInterface>
	{
		if typeof filters != "string" && typeof filters != "array" {
			throw new Exception("Wrong filter type added");
		}
		let this->_filters = filters;
		return this;
	}

	/**
	 * Adds a filter to current list of filters
	 */
	public function addFilter(string filter) -> <ElementInterface>
	{
		var filters;
		let filters = this->_filters;
		if typeof filters == "array" {
			let this->_filters[] = filter;
		} else {
			if typeof filters == "string" {
				let this->_filters = [filters, filter];
			} else {
				let this->_filters = [filter];
			}
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
	 * @param \Phalcon\Validation\ValidatorInterface[] validators
	 */
	public function addValidators(array! validators, bool merge = true) -> <ElementInterface>
	{
		var currentValidators, mergedValidators;
		if merge {
			let currentValidators = this->_validators;
			if typeof currentValidators == "array" {
				let mergedValidators = array_merge(currentValidators, validators);
			}
		}
		else {
			let mergedValidators = validators;
		}
		let this->_validators = mergedValidators;
		return this;
	}

	/**
	 * Adds a validator to the element
	 */
	public function addValidator(<ValidatorInterface> validator) -> <ElementInterface>
	{
		let this->_validators[] = validator;
		return this;
	}

	/**
	 * Returns the validators registered for the element
	 */
	public function getValidators() -> <ValidatorInterface[]>
	{
		return this->_validators;
	}

	/**
	 * Returns an array of prepared attributes for Phalcon\Tag helpers
	 * according to the element parameters
	 */
	public function prepareAttributes(array attributes = null, bool useChecked = false) -> array
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
				 * Check if the element already has a default value, compare it
				 * with the one in the attributes, if they are the same mark the
				 * element as checked
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
	 */
	public function setAttribute(string attribute, var value) -> <ElementInterface>
	{
		let this->_attributes[attribute] = value;
		return this;
	}

	/**
	 * Returns the value of an attribute if present
	 */
	public function getAttribute(string attribute, var defaultValue = null) -> var
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
	 */
	public function setAttributes(array! attributes) -> <ElementInterface>
	{
		let this->_attributes = attributes;
		return this;
	}

	/**
	 * Returns the default attributes for the element
	 */
	public function getAttributes() -> array
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
	 */
	public function setUserOption(string option, var value) -> <ElementInterface>
	{
		let this->_options[option] = value;
		return this;
	}

	/**
	 * Returns the value of an option if present
	 */
	public function getUserOption(string option, var defaultValue = null) -> var
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
	public function setUserOptions(array options) -> <ElementInterface>
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
	 * Sets the element label
	 */
	public function setLabel(string label) -> <ElementInterface>
	{
		let this->_label = label;
		return this;
	}

	/**
	 * Returns the element label
	 */
	public function getLabel() -> string
	{
		return this->_label;
	}

	/**
	 * Generate the HTML to label the element
	 */
	public function label(array attributes = []) -> string
	{
		var internalAttributes, label, name, code;

		/**
		 * Check if there is an "id" attribute defined
		 */
		let internalAttributes = this->getAttributes();

		if !fetch name, internalAttributes["id"] {
			let name = this->_name;
		}

		if typeof attributes == "array" {
			if !isset attributes["for"] {
				let attributes["for"] = name;
			}
		} else {
			let attributes = ["for": name];
		}

		let code = Tag::renderAttributes("<label", attributes);

		/**
		 * Use the default label or leave the same name as label
		 */
		let label = this->_label;
		if label || is_numeric(label) {
			let code .= ">" . label . "</label>";
		} else {
			let code .= ">" . name . "</label>";
		}

		return code;
	}

	/**
	 * Sets a default value in case the form does not use an entity
	 * or there is no value available for the element in _POST
	 */
	public function setDefault(var value) -> <ElementInterface>
	{
		let this->_value = value;
		return this;
	}

	/**
	 * Returns the default value assigned to the element
	 */
	public function getDefault() -> var
	{
		return this->_value;
	}

	/**
	 * Returns the element's value
	 */
	public function getValue() -> var
	{
		var name  = this->_name,
		    form  = this->_form,
			value = null;
		
		/**
		 * If element belongs to the form, get value from the form
		 */
		if typeof form == "object" {
			return form->getValue(name);
		}
		
		/**
		 * Otherwise check Phalcon\Tag
		 */
		if Tag::hasValue(name) {
			let value = Tag::getValue(name);
		}

		/**
		 * Assign the default value if there is no form available or Phalcon\Tag returns null
		 */
		if typeof value == "null" {
			let value = this->_value;
		}

		return value;
	}

	/**
	 * Returns the messages that belongs to the element
	 * The element needs to be attached to a form
	 */
	public function getMessages() -> <Messages>
	{
		return this->_messages;
	}

	/**
	 * Checks whether there are messages attached to the element
	 */
	public function hasMessages() -> bool
	{
		return count(this->_messages) > 0;
	}

	/**
	 * Sets the validation messages related to the element
	 */
	public function setMessages(<Messages> messages) -> <ElementInterface>
	{
		let this->_messages = messages;
		return this;
	}

	/**
	 * Appends a message to the internal message list
	 */
	public function appendMessage(<MessageInterface> message) -> <ElementInterface>
	{
		this->_messages->appendMessage(message);
		return this;
	}

	/**
	 * Clears element to its default value
	 */
	public function clear() -> <ElementInterface>
	{
		var form  = this->_form,
			name  = this->_name,
			value = this->_value;

		if typeof form == "object" {
			form->clear(name);
		} else {
			Tag::setDefault(name, value);
		}

		return this;
	}

	/**
	 * Magic method __toString renders the widget without attributes
	 */
	public function __toString() -> string
	{
		return this->{"render"}();
	}
}
