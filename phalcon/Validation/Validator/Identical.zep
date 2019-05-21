
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator;

use Phalcon\Messages\Message;
use Phalcon\Validation;
use Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\Identical
 *
 * Checks if a value is identical to other
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Identical;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "terms",
 *     new Identical(
 *         [
 *             "accepted" => "yes",
 *             "message" => "Terms and conditions must be accepted",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "terms",
 *         "anotherTerms",
 *     ],
 *     new Identical(
 *         [
 *             "accepted" => [
 *                 "terms"        => "yes",
 *                 "anotherTerms" => "yes",
 *             ],
 *             "message" => [
 *                 "terms"        => "Terms and conditions must be accepted",
 *                 "anotherTerms" => "Another terms  must be accepted",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
class Identical extends Validator
{
    protected advice = "Field :field does not have the expected value";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var label, replacePairs, value, valid, accepted, valueOption, code;

        let value = validation->getValue(field);

        if this->hasOption("accepted") {
            let accepted = this->getOption("accepted");

            if typeof accepted == "array" {
                let accepted = accepted[field];
            }

            let valid = value == accepted;
        } else {
            if this->hasOption("value") {
                let valueOption = this->getOption("value");

                if typeof valueOption == "array" {
                    let valueOption = valueOption[field];
                }

                let valid = value == valueOption;
            }
        }

        if !valid {
            let label = this->prepareLabel(validation, field),
                code = this->prepareCode(field);

            let replacePairs = [
                ":field": label
            ];

            validation->appendMessage(
                new Message(
                    strtr(this->getAdvice(field), replacePairs),
                    field,
                    get_class(this),
                    code
                )
            );

            return false;
        }

        return true;
    }
}
