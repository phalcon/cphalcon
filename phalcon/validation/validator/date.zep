
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Validation\Validator;

use Phalcon\Validation;
use Phalcon\Validation\Validator;
use Phalcon\Validation\Message;

/**
 * Phalcon\Validation\Validator\Date
 *
 * Checks if a value is a valid date
 *
 * <code>
 * use Phalcon\Validation\Validator\Date as DateValidator;
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
 * </code>
 */
class Date extends Validator
{
    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, string! field) -> boolean
    {
        var value, format, label, message, replacePairs;

        let value = validation->getValue(field);
        let format = this->getOption("format");

        if typeof format == "array" {
            let format = format[field];
        }

        if empty format {
            let format = "Y-m-d";
        }

        if !this->checkDate(value, format) {
            let label = this->getOption("label");
            if typeof label == "array" {
                let label = label[field];
            }
            if empty label {
                let label = validation->getLabel(field);
            }

            let message = this->getOption("message");
            if typeof message == "array" {
                let message = message[field];
            }
            let replacePairs = [":field": label];
            if empty message {
                let message = validation->getDefaultMessage("Date");
            }

            validation->appendMessage(new Message(strtr(message, replacePairs), field, "Date"));

            return false;
        }

        return true;
    }

    private function checkDate(value, format) -> boolean
    {
        var date, errors;

        if !is_string(value) {
            return false;
        }

        let date = \DateTime::createFromFormat(format, value);
        let errors = \DateTime::getLastErrors();

        if errors["warning_count"] > 0 || errors["error_count"] > 0 {
            return false;
        }

        return true;
    }
}
