
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Filter;

use Phalcon\Di\Di;
use Phalcon\Di\DiInterface;
use Phalcon\Di\Injectable;
use Phalcon\Filter\FilterInterface;
use Phalcon\Messages\MessageInterface;
use Phalcon\Messages\Messages;
use Phalcon\Filter\Validation\ValidationInterface;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\ValidatorInterface;
use Phalcon\Filter\Validation\AbstractCombinedFieldsValidator;

/**
 * Allows to validate data using custom or built-in validators
 */
class Validation extends Injectable implements ValidationInterface
{
    /**
     * @var array
     */
    protected combinedFieldsValidators = [];

    /**
     * @var mixed
     */
    protected data;

    /**
     * @var object|null
     */
    protected entity = null;

    /**
     * @var array
     */
    protected filters = [];

    /**
     * @var array
     */
    protected labels = [];

    /**
     * @var Messages|null
     */
    protected messages = null;

    /**
     * List of validators
     *
     * @var array
     */
    protected validators = [];

    /**
     * Calculated values
     *
     * @var array
     */
    protected values = [];

    /**
     * Phalcon\Filter\Validation constructor
     */
    public function __construct(array validators = [])
    {
        let this->validators = array_filter(
            validators,
            function(var element) {
                return typeof element[0] != "array" || !(element[1] instanceof AbstractCombinedFieldsValidator);
            }
        );

        let this->combinedFieldsValidators = array_filter(
            validators,
            function(var element) {
                return typeof element[0] == "array" && element[1] instanceof AbstractCombinedFieldsValidator;
            }
        );

        /**
         * Check for an 'initialize' method
         */
        if method_exists(this, "initialize") {
            this->{"initialize"}();
        }
    }

    /**
     * Adds a validator to a field
     *
     * @param string|array       $field
     * @param ValidatorInterface $validator
     *
     * @return ValidationInterface
     */
    public function add(var field, <ValidatorInterface> validator) -> <ValidationInterface>
    {
        var singleField;

        if typeof field === "array" {
            // Uniqueness validator for combination of fields is handled differently
            if validator instanceof AbstractCombinedFieldsValidator {
                let this->combinedFieldsValidators[] = [field, validator];
            } else {
                for singleField in field {
                    let this->validators[singleField][] = validator;
                }
            }
        } elseif typeof field == "string" {
            let this->validators[field][] = validator;
        } else {
            throw new Exception(
                "Field must be passed as array of fields or string"
            );
        }

        return this;
    }

    /**
     * Appends a message to the messages list
     *
     * @param MessageInterface $message
     */
    public function appendMessage(<MessageInterface> message) -> <ValidationInterface>
    {
        var messages;

        let messages = this->messages;

        if typeof messages != "object" {
            let messages = new Messages();
        }

        messages->appendMessage(message);

        let this->messages = messages;

        return this;
    }

    /**
     * Assigns the data to an entity
     * The entity is used to obtain the validation values
     *
     * @param object entity
     * @param array|object data
     */
    public function bind(entity, data) -> <ValidationInterface>
    {
        this->setEntity(entity);

        if unlikely (typeof data != "array" && typeof data != "object") {
            throw new Exception("Data to validate must be an array or object");
        }

        let this->data = data;

        return this;
    }

    /**
     * @return mixed
     */
    public function getData() -> var
    {
        return this->data;
    }

    /**
     * Returns the bound entity
     *
     * @return object
     */
    public function getEntity() -> var
    {
        return this->entity;
    }

    /**
     * Returns all the filters or a specific one
     */
    public function getFilters(string field = null) -> var | null
    {
        var filters, fieldFilters;

        let filters = this->filters;

        if !field {
            return filters;
        }

        if !fetch fieldFilters, filters[field] {
            return null;
        }

        return fieldFilters;
    }

    /**
     * Get label for field
     *
     * @param string field
     */
    public function getLabel(var field) -> string
    {
        var labels, value;

        let labels = this->labels;

        if typeof field == "array" {
            return join(", ", field);
        }

        if fetch value, labels[field] {
            return value;
        }

        return field;
    }

    /**
     * Returns the registered validators
     */
    public function getMessages() -> <Messages>
    {
        return this->messages;
    }

    /**
     * Returns the validators added to the validation
     */
    public function getValidators() -> array
    {
        return this->validators;
    }

    /**
     * Gets the a value to validate in the object entity source
     *
     * @param mixed $entity
     * @param string $field
     */
    public function getValueByEntity(var entity, string field) -> var | null
    {
        string method;

        let method = "get" . camelize(field);

        if method_exists(entity, method) {
            return entity->{method}();
        }

        if method_exists(entity, "readAttribute") {
            return entity->readAttribute(field);
        }

        if isset entity->{field} {
            return entity->{field};
        }

        return null;
    }

    /**
     * Gets the a value to validate in the array/object data source
     *
     * @param mixed $data
     * @param string $field
     */
    public function getValueByData(var data, string field) -> var | null
    {
        var value, values;

        // Check if there is a calculated value
        let values = this->values;

        if fetch value, values[field] {
            return value;
        }

        if typeof data === "array" {
            if isset data[field] {
                return data[field];
            }
        }

        if typeof data === "object" {
            if isset data->{field} {
                return data->{field};
            }
        }

        return null;
    }

    /**
     * Gets the a value to validate in the array/object data source
     *
     * @param string $field
     */
    public function getValue(string field) -> var | null
    {
        var entity, method, value, data, filters, fieldFilters,
            container, filterService;
        bool isRawFetched;

        let isRawFetched = false;
        let entity = this->entity;
        let data = this->data;

        //  If the entity is an object use it to retrieve the values
        if typeof entity == "object" {
            let value = this->getValueByEntity(entity, field);
            if value === null {
                let isRawFetched = true;
                let value = this->getValueByData(data, field);
            }
        } else {
            if unlikely (typeof data != "array" && typeof data != "object") {
                throw new Exception("There is no data to validate");
            }
            let value = this->getValueByData(data, field);
        }

        if value === null {
            return null;
        }

        let filters = this->filters;

        if fetch fieldFilters, filters[field] {
            if fieldFilters {
                let container = this->getDI();

                if container === null {
                    let container = Di::getDefault();

                    if container === null {
                        throw new Exception(
                            "A dependency injection container is required to access the 'filter' service"
                        );
                    }
                }

                let filterService = <FilterInterface> container->getShared("filter");

                if unlikely typeof filterService != "object" {
                    throw new Exception("Returned 'filter' service is invalid");
                }

                let value = filterService->sanitize(value, fieldFilters);

                /**
                 * Set filtered value in entity
                 */
                if typeof entity == "object" && isRawFetched === false {
                    let method = "set" . camelize(field);

                    if method_exists(entity, method) {
                        entity->{method}(value);
                    } elseif method_exists(entity, "writeAttribute") {
                        entity->writeAttribute(field, value);
                    } elseif property_exists(entity, field) {
                        let entity->{field} = value;
                    }
                }

                return value;
            }
        }

        // Cache the calculated value only if it's not entity
        if typeof entity != "object" {
            let this->values[field] = value;
        }

        return value;
    }

    /**
     * Alias of `add` method
     *
     * @param string|array       $field
     * @param ValidatorInterface $validator
     *
     * @return ValidationInterface
     */
    public function rule(var field, <ValidatorInterface> validator) -> <ValidationInterface>
    {
        return this->add(field, validator);
    }

    /**
     * Adds the validators to a field
     */
    public function rules(var field, array! validators) -> <ValidationInterface>
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
     * Sets the bound entity
     *
     * @param object entity
     */
    public function setEntity(entity) -> void
    {
        if unlikely typeof entity != "object" {
            throw new Exception("Entity must be an object");
        }

        let this->entity = entity;
    }

    /**
     * Adds filters to the field
     *
     * @param string field
     * @param array|string filters
     */
    public function setFilters(var field, filters) -> <ValidationInterface>
    {
        var singleField;

        if typeof field == "array" {
            for singleField in field {
                let this->filters[singleField] = filters;
            }
        } elseif typeof field == "string" {
            let this->filters[field] = filters;
        } else {
            throw new Exception(
                "Field must be passed as array of fields or string."
            );
        }

        return this;
    }

    /**
     * Adds labels for fields
     */
    public function setLabels(array! labels) -> void
    {
        let this->labels = labels;
    }

    public function setValidators(array validators) -> <Validation>
    {
        let this->validators = validators;

        return this;
    }

    /**
     * Validate a set of data according to a set of rules
     *
     * @param array|object data
     * @param object entity
     *
     * @return Messages|false
     */
    public function validate(var data = null, var entity = null) -> <Messages> | bool
    {
        var combinedFieldsValidators, field, messages, scope, status, validator,
            validatorData, validators;

        let validatorData            = this->validators,
            combinedFieldsValidators = this->combinedFieldsValidators;

        if unlikely typeof validatorData != "array" {
            throw new Exception("There are no validators to validate");
        }

        /**
         * Clear pre-calculated values
         */
        let this->values = [];

        /**
         * Implicitly creates a Phalcon\Messages\Messages object
         */
        let messages = new Messages();

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

        let this->messages = messages;

        if data !== null {
            if unlikely (typeof data != "array" && typeof data != "object") {
                throw new Exception("Invalid data to validate");
            }

            let this->data = data;
        }

        for field, validators in validatorData {
            for validator in validators {
                if unlikely typeof validator != "object" {
                    throw new Exception("One of the validators is not valid");
                }

                /**
                 * Call internal validations, if it returns true, then skip the
                 * current validator
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
        }

        for scope in combinedFieldsValidators {
            if unlikely typeof scope != "array" {
                throw new Exception("The validator scope is not valid");
            }

            let field     = scope[0],
                validator = scope[1];

            if unlikely typeof validator != "object" {
                throw new Exception("One of the validators is not valid");
            }

            /**
             * Call internal validations, if it returns true, then skip the
             * current validator
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
            this->{"afterValidation"}(data, entity, this->messages);
        }

        return this->messages;
    }

    /**
     * Internal validations, if it returns true, then skip the current validator
     *
     * @param array|string $field
     * @param ValidatorInterface $validator
     */
    protected function preChecking(var field, <ValidatorInterface> validator) -> bool
    {
        var singleField, allowEmpty, emptyValue, value;
        array results = [];

        if typeof field == "array" {
            for singleField in field {
                let results[] = this->preChecking(singleField, validator);

                if in_array(false, results) {
                    return false;
                }

                return true;
            }
        } else {
            let allowEmpty = validator->getOption("allowEmpty", false);

            if allowEmpty {
                if method_exists(validator, "isAllowEmpty") {
                    return validator->isAllowEmpty(this, field);
                }

                let value = this->getValue(field);

                if typeof allowEmpty == "array" {
                    for emptyValue in allowEmpty {
                        if emptyValue === value {
                            return true;
                        }
                    }

                    return false;
                }

                return empty value;
            }
        }

        return false;
    }
}
