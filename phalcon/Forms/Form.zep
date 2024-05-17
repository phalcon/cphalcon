
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms;

use Countable;
use Iterator;
use Phalcon\Di\Injectable;
use Phalcon\Di\DiInterface;
use Phalcon\Filter\FilterInterface;
use Phalcon\Forms\Element\ElementInterface;
use Phalcon\Html\Attributes;
use Phalcon\Html\Attributes\AttributesInterface;
use Phalcon\Html\TagFactory;
use Phalcon\Messages\Messages;
use Phalcon\Tag;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\ValidationInterface;

/**
 * This component allows to build forms using an object-oriented interface
 */
class Form extends Injectable implements Countable, Iterator, AttributesInterface
{
    /**
     * @var AttributesInterface|null
     */
    protected attributes = null;

    /**
     * @var array
     */
    protected data = [];

    /**
     * @var array
     */
    protected filteredData = [];

    /**
     * @var array
     */
    protected elements = [];

    /**
     * @var array
     */
    protected elementsIndexed = [];

    /**
     * @var object|null
     */
    protected entity = null;

    /**
     * @var Messages|array|null
     */
    protected messages = null;

    /**
     * @var int
     */
    protected position = 0;

    /**
     * @var array
     */
    protected options = [];

    /**
     * @var TagFactory|null
     */
    protected tagFactory = null;

    /**
     * @var ValidationInterface|null
     */
    protected validation = null;

    /**
     * @var array
     */
    protected whitelist = [];

    /**
     * Phalcon\Forms\Form constructor
     */
    public function __construct(var entity = null, array userOptions = [])
    {
        if unlikely (entity !== null && typeof entity != "object") {
            throw new Exception("The base entity is not valid");
        }

        let this->entity = entity;

        /**
         * Update the user options
         */
        let this->options = userOptions;

        /**
        * Set form attributes
        */
        let this->attributes = new Attributes();

        /**
         * Check for an 'initialize' method and call it
         */
        if method_exists(this, "initialize") {
            this->{"initialize"}(entity, userOptions);
        }
    }

    /**
     * Adds an element to the form
     */
    public function add(<ElementInterface> element, string position = null, bool type = null) -> <Form>
    {
        var name, key, value;
        array elements;

        /**
         * Gets the element's name
         */
        let name = element->getName();

        /**
         * Link the element to the form
         */
        element->setForm(this);
        if method_exists(element, "setTagFactory") && this->tagFactory !== null {
            element->{"setTagFactory"}(this->tagFactory);
        }

        if position == null || empty this->elements {
            /**
             * Append the element by its name
             */
            let this->elements[name] = element;
        } else {
            let elements = [];

            /**
             * Walk elements and add the element to a particular position
             */
            for key, value in this->elements {
                if key == position {
                    if type {
                        /**
                         * Add the element before position
                         */
                        let elements[name] = element,
                            elements[key] = value;
                    } else {
                        /**
                         * Add the element after position
                         */
                        let elements[key] = value,
                            elements[name] = element;
                    }
                } else {
                    /**
                     * Copy the element to new array
                     */
                    let elements[key] = value;
                }
            }

            let this->elements = elements;
        }

        return this;
    }

    /**
     * Binds data to the entity
     *
     * @param object entity
     * @param array whitelist
     */
    public function bind(array! data, var entity = null, array whitelist = []) -> <Form>
    {
        var filter, key, value, element, filters, container, filteredValue;
        array assignData, filteredData;
        string method;

        if unlikely empty this->elements {
            throw new Exception("There are no elements in the form");
        }

        if empty whitelist {
            let whitelist = this->whitelist;
        }

        let filter = null;
        let assignData = [];
        let filteredData = [];

        for key, value in data {
            /**
             * Get the element
             */
            if !fetch element, this->elements[key] {
                continue;
            }

            /**
             * Check if the item is in the whitelist
             */
            if !empty whitelist && !in_array(key, whitelist) {
                continue;
            }

            /**
             * Check if the method has filters
             */
            let filters = element->getFilters();

            if filters {
                if typeof filter != "object" {
                    let container = this->getDI(),
                        filter = <FilterInterface> container->getShared("filter");
                }

                /**
                 * Sanitize the filters
                 */
                let filteredValue = filter->sanitize(value, filters);
            } else {
                let filteredValue = value;
            }

            let assignData[key] = value;
            let filteredData[key] = filteredValue;

            if entity !== null {
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
                if (!globals_get("form.strict_entity_property_check")) {
                    let entity->{key} = filteredValue;

                    continue;
                }

                if (property_exists(entity, key)) {
                    let entity->{key} = filteredValue;
                }
            }
        }

        let this->data = assignData;
        let this->filteredData = filteredData;

        return this;
    }

    /**
     * Clears every element in the form to its default value
     *
     * @param array|string|null fields
     */
    public function clear(var fields = null) -> <Form>
    {
        var elements, element, data, field;

        let data     = this->data,
            elements = this->elements;

        /**
         * If fields is string, clear just that field.
         * If it's array, clear only fields in array.
         * If null, clear all
         */
        if null === fields {
            let data = [];

            for element in elements {
                let data[element->getName()] = element->getDefault();
            }
        } else {
            if typeof fields != "array" {
                let fields = [fields];
            }

            for field in fields {
                if isset data[field] {
                    unset data[field];
                }

                if fetch element, elements[field] {
                    let data[element->getName()] = element->getDefault();
                }
            }
        }

        let this->data = data;

        return this;
    }

    /**
     * Returns the number of elements in the form
     */
    public function count() -> int
    {
        return count(this->elements);
    }

    /**
     * Returns the current element in the iterator
     */
    public function current() -> mixed
    {
        var element;

        if !fetch element, this->elementsIndexed[this->position] {
            return false;
        }

        return element;
    }

    /**
     * Returns an element added to the form by its name
     */
    public function get(string! name) -> <ElementInterface>
    {
        var element;

        if unlikely !fetch element, this->elements[name] {
            throw new Exception(
                "Element with ID=" . name . " is not part of the form"
            );
        }

        return element;
    }

    /**
     * Returns the form's action
     */
    public function getAction() -> string
    {
        return (string) this->getAttributes()->get("action");
    }

    /**
    * Get Form attributes collection
    */
    public function getAttributes() -> <Attributes>
    {
        if unlikely null === this->attributes {
            let this->attributes = new Attributes();
        }

        return this->attributes;
    }

    /**
     * Returns the form elements added to the form
     */
    public function getElements() -> <ElementInterface[]>
    {
        return this->elements;
    }

    /**
     * Returns the entity related to the model
     *
     * @return object
     */
    public function getEntity()
    {
        return this->entity;
    }

    /**
     * Gets a value from the internal filtered data or calls getValue(name)
     */
    public function getFilteredValue(string! name) -> var | null
    {
        var filteredData, value;

        let filteredData = this->filteredData;

        if typeof filteredData == "array" {
            /**
             * Check if the data is in the data array
             */
            if fetch value, filteredData[name] {
                return value;
            }
        }

        return this->getValue(name);
    }

    /**
     * Returns a label for an element
     */
    public function getLabel(string! name) -> string
    {
        var element, label;

        if unlikely !fetch element, this->elements[name] {
            throw new Exception(
                "Element with ID=" . name . " is not part of the form"
            );
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
     * Returns the messages generated in the validation.
     *
     * ```php
     * if ($form->isValid($_POST) == false) {
     *     $messages = $form->getMessages();
     *
     *     foreach ($messages as $message) {
     *         echo $message, "<br>";
     *     }
     * }
     * ```
     */
    public function getMessages() -> <Messages> | array
    {
        var messages;

        let messages = this->messages;

        if !(typeof messages == "object" && messages instanceof Messages) {
            return new Messages();
        }

        return messages;
    }

    /**
     * Returns the messages generated for a specific element
     */
    public function getMessagesFor(string! name) -> <Messages>
    {
        if !this->has(name) {
            return new Messages();
        }

        return this->get(name)->getMessages();
    }

    /**
     * Returns the tagFactory object
     */
    public function getTagFactory() -> <TagFactory> | null
    {
        return this->tagFactory;
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
     * Gets a value from the internal related entity or from the default value
     */
    public function getValue(string! name) -> var | null
    {
        var entity, value, data, internalEntity, element;
        array forbidden;
        string method;

        let entity = this->entity;
        let data   = this->data;

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
            "attributes":    true,
            "validation":    true,
            "action":        true,
            "useroption":    true,
            "useroptions":   true,
            "entity":        true,
            "elements":      true,
            "messages":      true,
            "messagesfor":   true,
            "label":         true,
            "value":         true,
            "di":            true,
            "tagFactory":    true,
            "eventsmanager": true
        ];

        /**
         * Check if the method is internal
         */
        let internalEntity = strtolower(name);
        if isset forbidden[internalEntity] {
            return null;
        }

        /**
         * Check if form has a getter
         */
        let method = "get" . camelize(name);
        if method_exists(this, method) {
            return this->{method}();
        }

        /**
         * Check if element has default value
         */
        if fetch element, this->elements[name] {
            return element->getDefault();
        }

        return null;
    }

    /**
     * return ValidationInterface|null
     */
    public function getValidation() -> <ValidationInterface> | null
    {
        return this->validation;
    }

    /**
     * return array
     */
    public function getWhitelist() -> array
    {
        return this->whitelist;
    }

    /**
     * Check if the form contains an element
     */
    public function has(string! name) -> bool
    {
        /**
         * Checks if the element is in the form
         */
        return isset this->elements[name];
    }

    /**
     * Check if messages were generated for a specific element
     */
    public function hasMessagesFor(string! name) -> bool
    {
        return this->getMessagesFor(name)->count() > 0;
    }

    /**
     * Validates the form
     *
     * @param array data
     * @param object entity
     * @param array whitelist
     */
    public function isValid(var data = null, var entity = null, array whitelist = []) -> bool
    {
        var messages, element, validators, name, filters, validator, validation,
            elementMessage;
        bool validationStatus;

        if empty this->elements {
            return true;
        }

        if empty whitelist {
            let whitelist = this->whitelist;
        }

        /**
         * If the data is not an array use the one passed previously
         */
        if typeof data != "array" {
            let data = this->data;
        }

        /**
         * If the user doesn't pass an entity we use the one in this_ptr->entity
         */
        if typeof entity != "object" && typeof this->entity == "object" {
            let entity = this->entity;
        }

        this->bind(data, entity, whitelist);

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

        for element in this->elements {
            let validators = element->getValidators();

            if count(validators) == 0 {
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
            let this->messages = messages;
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
     * Returns the current position/key in the iterator
     */
    public function key() -> int
    {
        return this->position;
    }

    /**
     * Generate the label of an element added to the form including HTML
     */
    public function label(string! name, array attributes = []) -> string
    {
        var element;

        if unlikely !fetch element, this->elements[name] {
            throw new Exception(
                "Element with ID=" . name . " is not part of the form"
            );
        }

        return element->label(attributes);
    }

    /**
     * Moves the internal iteration pointer to the next position
     */
    public function next() -> void
    {
        let this->position++;
    }

    /**
     * Renders a specific item in the form
     */
    public function render(string! name, array attributes = []) -> string
    {
        var element;

        if unlikely !fetch element, this->elements[name] {
            throw new Exception(
                "Element with ID=" . name . " is not part of the form"
            );
        }

        return element->render(attributes);
    }

    /**
     * Removes an element from the form
     */
    public function remove(string! name) -> bool
    {
        /**
         * Checks if the element is in the form
         */
        if isset this->elements[name] {
            unset this->elements[name];

            return true;
        }

        /**
         * Clean the iterator index
         */
        let this->elementsIndexed = null;

        return false;
    }

    /**
     * Rewinds the internal iterator
     */
    public function rewind() -> void
    {
        let this->position = 0;

        let this->elementsIndexed = array_values(this->elements);
    }

    /**
     * Sets the form's action
     *
     * @return Form
     */
    public function setAction(string! action) -> <Form>
    {
        this->getAttributes()->set("action", action);

        return this;
    }

    /**
    * Set form attributes collection
    */
    public function setAttributes(<Attributes> attributes) -> <AttributesInterface>
    {
        let this->attributes = attributes;

        return this;
    }

    /**
     * Sets the entity related to the model
     *
     * @param object entity
     */
    public function setEntity(var entity) -> <Form>
    {
        let this->entity = entity;

        return this;
    }

    /**
     * Sets the tagFactory for the form
     */
    public function setTagFactory(<TagFactory> tagFactory) -> <Form>
    {
        let this->tagFactory = tagFactory;

        return this;
    }

    /**
     * Sets the default validation
     *
     * @param ValidationInterface validation
     */
    public function setValidation(<ValidationInterface> validation) -> <Form>
    {
        let this->validation = validation;

        return this;
    }

    /**
     * Sets the default whitelist
     *
     * @param array whitelist
     */
    public function setWhitelist(array whitelist) -> <Form>
    {
        let this->whitelist = whitelist;

        return this;
    }

    /**
     * Sets an option for the form
     */
    public function setUserOption(string option, var value) -> <Form>
    {
        let this->options[option] = value;

        return this;
    }

    /**
     * Sets options for the element
     */
    public function setUserOptions(array! options) -> <Form>
    {
        let this->options = options;

        return this;
    }

    /**
     * Check if the current element in the iterator is valid
     */
    public function valid() -> bool
    {
        return isset this->elementsIndexed[this->position];
    }
}
