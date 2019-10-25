
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms\Element;

use InvalidArgumentException;
use Phalcon\Forms\Form;
use Phalcon\Forms\Exception;
use Phalcon\Messages\MessageInterface;
use Phalcon\Messages\Messages;
use Phalcon\Tag;
use Phalcon\Validation\ValidatorInterface;

/**
 * This is a base class for form elements
 */
abstract class AbstractElement implements ElementInterface
{
    protected attributes;
    protected filters;
    protected form;
    protected label;
    protected messages;
    protected name;
    protected options;

    /**
     * @var array
     */
    protected validators = [];

    protected value;

    /**
     * Phalcon\Forms\Element constructor
     *
     * @param string name       Attribute name (value of 'name' attribute of HTML element)
     * @param array  attributes Additional HTML element attributes
     */
    public function __construct(string name, array attributes = [])
    {
        let name = trim(name);

        if unlikely empty name {
            throw new InvalidArgumentException(
                "Form element name is required"
            );
        }

        let this->name = name;
        let this->attributes = attributes;
        let this->messages = new Messages();
    }

    /**
     * Magic method __toString renders the widget without attributes
     */
    public function __toString() -> string
    {
        return this->{"render"}();
    }

    /**
     * Adds a filter to current list of filters
     */
    public function addFilter(string filter) -> <ElementInterface>
    {
        var filters;

        let filters = this->filters;

        if typeof filters == "array" {
            let this->filters[] = filter;
        } else {
            if typeof filters == "string" {
                let this->filters = [filters, filter];
            } else {
                let this->filters = [filter];
            }
        }

        return this;
    }

    /**
     * Adds a validator to the element
     */
    public function addValidator(<ValidatorInterface> validator) -> <ElementInterface>
    {
        let this->validators[] = validator;

        return this;
    }

    /**
     * Adds a group of validators
     *
     * @param \Phalcon\Validation\ValidatorInterface[] validators
     * @param bool                                     merge
     */
    public function addValidators(array! validators, bool merge = true) -> <ElementInterface>
    {
        if merge {
            let validators = array_merge(
                this->validators,
                validators
            );
        }

        let this->validators = validators;

        return this;
    }

    /**
     * Appends a message to the internal message list
     */
    public function appendMessage(<MessageInterface> message) -> <ElementInterface>
    {
        this->messages->appendMessage(message);

        return this;
    }

    /**
     * Clears element to its default value
     */
    public function clear() -> <ElementInterface>
    {
        var form  = this->form,
            name  = this->name,
            value = this->value;

        if typeof form == "object" {
            form->clear(name);
        } else {
            Tag::setDefault(name, value);
        }

        return this;
    }

    /**
     * Returns the value of an attribute if present
     */
    public function getAttribute(string attribute, var defaultValue = null) -> var
    {
        var attributes, value;

        let attributes = this->attributes;

        if !fetch value, attributes[attribute] {
            return defaultValue;
        }

        return value;
    }

    /**
     * Returns the default attributes for the element
     */
    public function getAttributes() -> array
    {
        var attributes;

        let attributes = this->attributes;

        return attributes;
    }

    /**
     * Returns the default value assigned to the element
     */
    public function getDefault() -> var
    {
        return this->value;
    }

    /**
     * Returns the element filters
     *
     * @return mixed
     */
    public function getFilters()
    {
        return this->filters;
    }

    /**
     * Returns the parent form to the element
     */
    public function getForm() -> <Form>
    {
        return this->form;
    }

    /**
     * Returns the element label
     */
    public function getLabel() -> string
    {
        return this->label;
    }

    /**
     * Returns the messages that belongs to the element
     * The element needs to be attached to a form
     */
    public function getMessages() -> <Messages>
    {
        return this->messages;
    }

    /**
     * Returns the element name
     */
    public function getName() -> string
    {
        return this->name;
    }

    /**
     * Returns the value of an option if present
     */
    public function getUserOption(string option, var defaultValue = null) -> var
    {
        var value;

        if !fetch value, this->options[option] {
            return defaultValue;
        }

        return value;
    }

    /**
     * Returns the options for the element
     */
    public function getUserOptions() -> array
    {
        return this->options;
    }

    /**
     * Returns the validators registered for the element
     */
    public function getValidators() -> <ValidatorInterface[]>
    {
        return this->validators;
    }

    /**
     * Returns the element's value
     */
    public function getValue() -> var
    {
        var name  = this->name,
            form  = this->form,
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
         * Assign the default value if there is no form available or
         * Phalcon\Tag returns null
         */
        if value === null {
            let value = this->value;
        }

        return value;
    }

    /**
     * Checks whether there are messages attached to the element
     */
    public function hasMessages() -> bool
    {
        return count(this->messages) > 0;
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
            let name = this->name;
        }

        if !isset attributes["for"] {
            let attributes["for"] = name;
        }

        let code = Tag::renderAttributes("<label", attributes);

        /**
         * Use the default label or leave the same name as label
         */
        let label = this->label;

        if label || is_numeric(label) {
            let code .= ">" . label . "</label>";
        } else {
            let code .= ">" . name . "</label>";
        }

        return code;
    }

    /**
     * Returns an array of prepared attributes for Phalcon\Tag helpers
     * according to the element parameters
     */
    public function prepareAttributes(array attributes = [], bool useChecked = false) -> array
    {
        var value, name, mergedAttributes, defaultAttributes, currentValue;

        let name = this->name;

        let attributes[0] = name;

        /**
         * Merge passed parameters with default ones
         */
        let defaultAttributes = this->attributes;

        let mergedAttributes = array_merge(
            defaultAttributes,
            attributes
        );

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
        let this->attributes[attribute] = value;

        return this;
    }

    /**
     * Sets default attributes for the element
     */
    public function setAttributes(array! attributes) -> <ElementInterface>
    {
        let this->attributes = attributes;

        return this;
    }

    /**
     * Sets a default value in case the form does not use an entity
     * or there is no value available for the element in _POST
     */
    public function setDefault(var value) -> <ElementInterface>
    {
        let this->value = value;

        return this;
    }

    /**
     * Sets the element filters
     *
     * @param array|string filters
     */
    public function setFilters(var filters) -> <ElementInterface>
    {
        if unlikely (typeof filters != "string" && typeof filters != "array") {
            throw new Exception("Wrong filter type added");
        }

        let this->filters = filters;

        return this;
    }

    /**
     * Sets the parent form to the element
     */
    public function setForm(<Form> form) -> <ElementInterface>
    {
        let this->form = form;

        return this;
    }

    /**
     * Sets the element label
     */
    public function setLabel(string label) -> <ElementInterface>
    {
        let this->label = label;

        return this;
    }

    /**
     * Sets the validation messages related to the element
     */
    public function setMessages(<Messages> messages) -> <ElementInterface>
    {
        let this->messages = messages;

        return this;
    }

    /**
     * Sets the element name
     */
    public function setName(string! name) -> <ElementInterface>
    {
        let this->name = name;

        return this;
    }

    /**
     * Sets an option for the element
     */
    public function setUserOption(string option, var value) -> <ElementInterface>
    {
        let this->options[option] = value;

        return this;
    }

    /**
     * Sets options for the element
     */
    public function setUserOptions(array options) -> <ElementInterface>
    {
        let this->options = options;

        return this;
    }
}
