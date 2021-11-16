
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator;

use DateTime;
use Phalcon\Messages\Message;
use Phalcon\Validation;
use Phalcon\Validation\AbstractValidator;

/**
 * Checks if a value is a valid date
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Date as DateValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "date",
 *     new DateValidator(
 *         [
 *             "format"  => "d-m-Y",
 *             "message" => "The date is invalid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "date",
 *         "anotherDate",
 *     ],
 *     new DateValidator(
 *         [
 *             "format" => [
 *                 "date"        => "d-m-Y",
 *                 "anotherDate" => "Y-m-d",
 *             ],
 *             "message" => [
 *                 "date"        => "The date is invalid",
 *                 "anotherDate" => "The another date is invalid",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class Date extends AbstractValidator
{
    protected template = "Field :field is not a valid date";

    /**
     * Constructor
     *
     * @param array options = [
     *     'message' => '',
     *     'template' => '',
     *     'format' => 'Y-m-d',
     *     'allowEmpty' => false
     * ]
     */
    public function __construct(array! options = [])
    {
        parent::__construct(options);
    }

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var value, format;

        let value = validation->getValue(field);
        if this->allowEmpty(field, value) {
            return true;
        }

        let format = this->getOption("format");
        if typeof format == "array" {
            let format = format[field];
        }

        if empty format {
            let format = "Y-m-d";
        }

        if !this->checkDate(value, format) {
            validation->appendMessage(
                this->messageFactory(validation, field)
            );

            return false;
        }

        return true;
    }

    private function checkDate(value, format) -> bool
    {
        var date, errors;

        if !is_string(value) {
            return false;
        }

        let date = DateTime::createFromFormat(format, value);
        let errors = DateTime::getLastErrors();

        return errors["warning_count"] == 0 && errors["error_count"] == 0;
    }
}
