
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon;

use Phalcon\Di\DiInterface;
use Phalcon\Di\Injectable;
use Phalcon\Filter\FilterInterface;
use Phalcon\Messages\MessageInterface;
use Phalcon\Messages\Messages;
use Phalcon\Validation\ValidationInterface;
use Phalcon\Validation\Exception;
use Phalcon\Validation\ValidatorInterface;
use Phalcon\Validation\AbstractCombinedFieldsValidator;

/**
 * Allows to validate data using custom or built-in validators
 */
class Validation extends Injectable implements ValidationInterface
{
    protected combinedFieldsValidators;
    protected data { get };
    protected entity;
    protected filters = [];
    protected labels = [];
    protected messages;
    protected validators { set };
    protected values;

    /**
     * Phalcon\Validation constructor
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
     * @return ValidatorInterface
     */
    public function add(var field, <ValidatorInterface> validator) -> <ValidationInterface>
    {
        var singleField;

        if typeof field == "array" {
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
     * Gets the a value to validate in the array/object data source
     */
    public function getValue(string field) -> var | null
    {
        var entity, method, value, data, values, filters, fieldFilters,
            container, filterService, camelizedField;

        let entity = this->entity;

        //  If the entity is an object use it to retrieve the values
        if typeof entity == "object" {
            let camelizedField = camelize(field);
            let method = "get" . camelizedField;

            if method_exists(entity, method) {
                let value = entity->{method}();
            } elseif method_exists(entity, "readAttribute") {
                let value = entity->readAttribute(field);
            } elseif isset entity->{field} {
                let value = entity->{field};
            } else {
                let value = null;
            }
        } else {
            let data = this->data;

            if unlikely (typeof data != "array" && typeof data != "object") {
                throw new Exception("There is no data to validate");
            }

            // Check if there is a calculated value
            let values = this->values;

            if fetch value, values[field] {
                return value;
            }

            let value = null;

            if typeof data == "array" {
                if isset data[field] {
                    let value = data[field];
                }
            } elseif typeof data == "object" {
                if isset data->{field} {
                    let value = data->{field};
                }
            }
        }

        if value === null {
            return null;
        }

        let filters = this->filters;

        if fetch fieldFilters, filters[field] {
            if fieldFilters {
                let container = this->getDI();

                if typeof container != "object" {
                    let container = Di::getDefault();

                    if unlikely typeof container != "object" {
                        throw new Exception(
                            Exception::containerServiceNotFound(
                                "the 'filter' service"
                            )
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
                if typeof entity == "object" {
                    let method = "set" . camelizedField;

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
     * @return ValidatorInterface
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

    /**
     * Validate a set of data according to a set of rules
     *
     * @param array|object data
     * @param object entity
     */
    public function validate(var data = null, var entity = null) -> <Messages>
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
        let this->values = null;

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
     */
    protected function preChecking(var field, <ValidatorInterface> validator) -> bool
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
