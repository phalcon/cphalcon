
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator;

use Phalcon\Messages\Message;
use Phalcon\Validation;
use Phalcon\Validation\Exception;
use Phalcon\Validation\AbstractValidator;

/**
 * Checks that two values have the same value
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Confirmation;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "password",
 *     new Confirmation(
 *         [
 *             "message" => "Password doesn't match confirmation",
 *             "with"    => "confirmPassword",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "password",
 *         "email",
 *     ],
 *     new Confirmation(
 *         [
 *             "message" => [
 *                 "password" => "Password doesn't match confirmation",
 *                 "email"    => "Email doesn't match confirmation",
 *             ],
 *             "with" => [
 *                 "password" => "confirmPassword",
 *                 "email"    => "confirmEmail",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class Confirmation extends AbstractValidator
{
    protected template = "Field :field must be the same as :with";

    /**
     * Constructor
     *
     * @param array options = [
     *     'message' => '',
     *     'template' => '',
     *     'with' => '',
     *     'labelWith' => '',
     *     'ignoreCase' => false,
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
        var fieldWith, value, valueWith, labelWith, replacePairs;

        let fieldWith = this->getOption("with");

        if typeof fieldWith == "array" {
            let fieldWith = fieldWith[field];
        }

        let value = validation->getValue(field),
            valueWith = validation->getValue(fieldWith);

        if !this->compare(value, valueWith) {
            let labelWith = this->getOption("labelWith");

            if typeof labelWith == "array" {
                let labelWith = labelWith[fieldWith];
            }

            if empty labelWith {
                let labelWith = validation->getLabel(fieldWith);
            }

            let replacePairs = [
                ":with":  labelWith
            ];

            validation->appendMessage(
                this->messageFactory(validation, field, replacePairs)
            );

            return false;
        }

        return true;
    }

    /**
     * Compare strings
     */
    final protected function compare(string a, string b) -> bool
    {
        if this->getOption("ignoreCase", false) {
            /**
             * mbstring is required here
             */
            if unlikely !function_exists("mb_strtolower") {
                throw new Exception("Extension 'mbstring' is required");
            }

            let a = mb_strtolower(a, "utf-8");
            let b = mb_strtolower(b, "utf-8");
        }

        return strcmp(a, b) === 0;
    }
}
