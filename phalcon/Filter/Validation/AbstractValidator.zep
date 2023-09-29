
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation;

use Phalcon\Messages\Message;
use Phalcon\Filter\Validation;
use Phalcon\Support\Helper\Arr\Whitelist;

/**
 * This is a base class for validators
 */
abstract class AbstractValidator implements ValidatorInterface
{
    /**
     * Message template
     *
     * @var string|null
     */
    protected template = null;

    /**
     * Message templates
     *
     * @var array
     */
    protected templates = [];

    /**
     * @var array
     */
    protected options = [];

    /**
     * Phalcon\Filter\Validation\Validator constructor
     *
     * @param array $options
     */
    public function __construct(array options = [])
    {
        var template, whitelist;

        let whitelist = new Whitelist(),
            template  = current(whitelist->__invoke(options, ["template", "message", 0]));

        if typeof template == "array" {
            this->setTemplates(template);
        } elseif typeof template == "string" {
            this->setTemplate(template);
        }

        if template {
            // save custom message in options
            let options["message"] = template;

            unset options["template"];
            unset options[0];
        }

        let this->options = options;
    }

    /**
     * Returns an option in the validator's options
     * Returns null if the option hasn't set
     *
     * @param string     $key
     * @param mixed|null $defaultValue
     *
     * @return mixed
     */
    public function getOption(string! key, var defaultValue = null) -> var
    {
        var value, fieldValue;

        if !fetch value, this->options[key] {
            return defaultValue;
        }

        /*
         * If we have `attribute` as a key, it means it is a Uniqueness
         * validator, we can have here multiple fields, so we need to check it
         */
        if key == "attribute" && typeof value == "array" {
            if fetch fieldValue, value[key] {
                return fieldValue;
            }
        }

        return value;
    }

    /**
     * Checks if an option is defined
     *
     * @param string $key
     *
     * @return bool
     */
    public function hasOption(string! key) -> bool
    {
        return isset this->options[key];
    }

    /**
     * Get the template message
     *
     * @param string|null $field
     *
     * @return string
     */
    public function getTemplate(string field = null) -> string
    {
        // there is a template in field
        if field !== null && isset this->templates[field] {
            return this->templates[field];
        }

        // there is a custom template
        if this->template {
            return this->template;
        }

        // default template message
        return "The field :field is not valid for " . get_class(this);
    }

    /**
     * Get templates collection object
     *
     * @return array
     */
    public function getTemplates() -> array
    {
        return this->templates;
    }

    /**
     * Create a default message by factory
     *
     * @param Validation   $validation
     * @param array|string $field
     * @param array        $replacements
     *
     * @return Message
     */
    public function messageFactory(<Validation> validation, var field, array! replacements = []) -> <Message>
    {
        var singleField;

        if typeof field == "array" {
            let singleField = implode(", ", field);
        } elseif typeof field == "string" {
            let singleField = field;
        } else {
            throw new Exception("The field can not be printed");
        }

        let replacements = array_merge(
            [
                ":field" : this->prepareLabel(validation, singleField)
            ],
            replacements
        );

        return new Message(
            strtr(this->getTemplate(singleField), replacements),
            field,
            get_class(this),
            this->prepareCode(singleField)
        );
    }

    /**
     * Sets an option in the validator
     *
     * @param string $key
     * @param mixed  $value
     *
     * @return void
     */
    public function setOption(string! key, value) -> void
    {
        let this->options[key] = value;
    }

    /**
     * Set a new template message
     *
     * @return ValidatorInterface
     */
    public function setTemplate(string template) -> <ValidatorInterface>
    {
        let this->template = template;

        return this;
    }

    /**
     * Clear current templates and set new from an array,
     *
     * @return ValidatorInterface
     */
    public function setTemplates(array templates) -> <ValidatorInterface>
    {
        var field, template;

        let this->templates = [];

        for field, template in templates {
            let field                  = (string) field,
                template               = (string) template,
                this->templates[field] = template;
        }

        return this;
    }

    /**
     * Executes the validation
     *
     * @param Validation $validation
     * @param string     $field
     *
     * @return bool
     */
    abstract public function validate(
        <Validation> validation,
        var field
    ) -> bool;

    /**
     * Checks if field can be empty.
     *
     * @param string $field
     * @param mixed  $value
     *
     * @return bool
     */
    protected function allowEmpty(var field, var value) -> bool
    {
        var allowEmpty;

        let allowEmpty = this->getOption("allowEmpty", false);

        if typeof allowEmpty === "array" {
            let allowEmpty = isset allowEmpty[field] ? allowEmpty[field] : false;
        }

        return allowEmpty && empty value;
    }

    /**
     * Checks if a value is an array and returns the element based on the
     * passed field name
     *
     * @param mixed  $value
     * @param string $field
     *
     * @return mixed
     */
    protected function checkArray(var value, string field) -> var
    {
        if (
            typeof value === "array" && isset value[field]
        ) {
            let value = value[field];
        }

        return value;
    }

    /**
     * Prepares a validation code.
     *
     * @param string $field
     *
     * @return int
     */
    protected function prepareCode(string field) -> int
    {
        var code;

        let code = this->getOption("code", 0);

        if typeof code === "array" {
            let code = code[field];
        }

        return code;
    }

    /**
     * Prepares a label for the field.
     *
     * @param Validation $validation
     * @param string     $field
     *
     * @return mixed
     */
    protected function prepareLabel(<Validation> validation, string! field) -> var
    {
        var label;

        let label = this->getOption("label");

        if typeof label == "array" {
            let label = label[field];
        }

        if empty label {
            let label = validation->getLabel(field);
        }

        return label;
    }
}
