
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation;

use Phalcon\Contracts\Filter\FilterTypes;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exceptions\FieldNotPrintable;
use Phalcon\Messages\Message;
use Phalcon\Support\Helper\Arr\Whitelist;

/**
 * This is a base class for validators
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 * @phpstan-import-type filter_validator_replacements from FilterTypes
 * @phpstan-import-type filter_validator_templates from FilterTypes
 */
abstract class AbstractValidator implements ValidatorInterface
{
    /**
     * @phpstan-var filter_validator_options
     */
    protected array options = [];
    /**
     * Message template
     *
     * @var string|null
     */
    protected template = null;

    /**
     * Whether the template/message has been explicitly assigned on the
     * instance (constructor `message`/`template` option or setTemplate()).
     * While false, `template` still holds the validator's class default and a
     * global default registered via Validation::setDefaultMessages() applies.
     */
    protected bool templateChanged = false;

    /**
     * Message templates
     *
     * @phpstan-var filter_validator_templates
     */
    protected array templates = [];

    /**
     * Phalcon\Filter\Validation\Validator constructor
     *
     * @param array $options
     *
     * @phpstan-param filter_validator_options $options
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
     */
    public function getOption(string key, var defaultValue = null) -> var
    {
        var value;

        if !fetch value, this->options[key] {
            return defaultValue;
        }

        return value;
    }

    /**
     * Get the template message
     */
    public function getTemplate(string field = null) -> string
    {
        var defaultMessage;

        // there is a template in field
        if field !== null && isset this->templates[field] {
            return this->templates[field];
        }

        // an explicitly assigned template/message wins over a global default
        if this->templateChanged && this->template {
            return this->template;
        }

        // a global default message registered for this validator class
        let defaultMessage = Validation::getDefaultMessage(get_class(this));

        if defaultMessage !== "" {
            return defaultMessage;
        }

        // custom or class default template
        if this->template {
            return this->template;
        }

        // default template message
        return "The field :field is not valid for " . get_class(this);
    }

    /**
     * Get templates collection object
     *
     * @phpstan-return filter_validator_templates
     */
    public function getTemplates() -> array
    {
        return this->templates;
    }

    /**
     * Checks if an option is defined
     */
    public function hasOption(string key) -> bool
    {
        return isset this->options[key];
    }

    /**
     * Checks whether the field can be considered empty and therefore
     * skipped, honoring the `allowEmpty` option (boolean flag, list of
     * empty values, or per-field map).
     */
    public function isAllowEmpty(<Validation> validation, string field) -> bool
    {
        var value;

        let value = validation->getValue(field);

        return this->allowEmpty(field, value);
    }

    /**
     * Create a default message by factory
     *
     * @param array|string $field
     *
     * @phpstan-param mixed                         $field
     * @phpstan-param filter_validator_replacements $replacements
     */
    public function messageFactory(
        <Validation> validation,
        var field,
        array replacements = []
    ) -> <Message> {
        var singleField;

        if typeof field == "array" {
            let singleField = implode(", ", field);
        } elseif typeof field == "string" {
            let singleField = field;
        } else {
            throw new FieldNotPrintable();
        }

        let replacements = array_merge(
            [
                ":field" : this->prepareLabel(validation, singleField)
            ],
            replacements
        );

        return new Message(
            strtr(this->getTemplate(singleField), replacements),
            singleField,
            get_class(this),
            this->prepareCode(singleField)
        );
    }

    /**
     * Sets an option in the validator
     */
    public function setOption(string key, value) -> void
    {
        let this->options[key] = value;
    }

    /**
     * Set a new template message
     */
    public function setTemplate(string template) -> <ValidatorInterface>
    {
        let this->template = template,
            this->templateChanged = true;

        return this;
    }

    /**
     * Clear current templates and set new from an array,
     *
     * @phpstan-param filter_validator_templates $templates
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
     */
    abstract public function validate(
        <Validation> validation,
        var field
    ) -> bool;

    /**
     * Checks if field can be empty.
     */
    protected function allowEmpty(var field, var value) -> bool
    {
        var allowEmpty, emptyValue;

        let allowEmpty = this->getOption("allowEmpty", false);

        if typeof allowEmpty === "array" {
            /**
             * Per-field map: ['fieldName' => true/false]
             * Used by multi-field validators such as Ip.
             */
            if fetch emptyValue, allowEmpty[field] {
                return emptyValue && empty value;
            }

            /**
             * Value list: [null, '']
             * Strict comparison so that '0' is not treated as empty.
             */
            for emptyValue in allowEmpty {
                if emptyValue === value {
                    return true;
                }
            }

            return false;
        }

        return allowEmpty && empty value;
    }

    /**
     * Checks if a value is an array and returns the element based on the
     * passed field name
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
     */
    protected function prepareLabel(<Validation> validation, string field) -> var
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
     * Rejects a value that cannot be a string: an array, or an object without
     * __toString(). A cast would turn an array into the constant "Array",
     * which satisfies the string checks. Appends the message and returns
     * true when the value is rejected.
     *
     * @phpstan-assert-if-false string|int|float|bool|Stringable|null $value
     */
    protected function rejectNonStringable(
        <Validation> validation,
        var field,
        var value
    ) -> bool {
        if typeof value === "array" || (typeof value === "object" && !method_exists(value, "__toString")) {
            validation->appendMessage(
                this->messageFactory(validation, field)
            );

            return true;
        }

        return false;
    }
}
