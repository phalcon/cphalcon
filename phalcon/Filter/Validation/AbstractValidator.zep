
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation;

use Phalcon\Support\Helper\Arr\Whitelist;
use Phalcon\Messages\Message;
use Phalcon\Filter\Validation;

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
     */
    public function __construct(array! options = [])
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
     * Get the template message
     *
     * @return string
     * @throw InvalidArgumentException When the field does not exists
     */
    public function getTemplate(string! field = null) -> string
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
    * Clear current templates and set new from an array,
    *
    * @return ValidatorInterface
    */
    public function setTemplates(array! templates) -> <ValidatorInterface>
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
    * Set a new template message
    *
    * @return ValidatorInterface
    */
    public function setTemplate(string! template) -> <ValidatorInterface>
    {
        let this->template = template;

        return this;
    }

    /**
     * Returns an option in the validator's options
     * Returns null if the option hasn't set
     */
    public function getOption(string! key, var defaultValue = null) -> var
    {
        var value, fieldValue;

        if !fetch value, this->options[key] {
            return defaultValue;
        }

        /*
         * If we have attribute it means it's Uniqueness validator, we
         * can have here multiple fields, so we need to check it
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
     */
    public function hasOption(string! key) -> bool
    {
        return isset this->options[key];
    }

    /**
     * Sets an option in the validator
     */
    public function setOption(string! key, value) -> void
    {
        let this->options[key] = value;
    }

    /**
     * Executes the validation
     */
    abstract public function validate(<Validation> validation, var field) -> bool;

    /**
     * Prepares a validation code.
     */
    protected function prepareCode(string! field) -> int | null
    {
        var code;

        let code = this->getOption("code");

        if typeof code == "array" {
            let code = code[field];
        }

        return code;
    }

    /**
     * Prepares a label for the field.
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

    /**
     * Checks if field can be empty.
     *
     * @param mixed field
     * @param mixed value
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
     * Create a default message by factory
     *
     * @return Message
     *
     * @throw Exception
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
}
