
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
use Phalcon\Validation\Validation;
use Phalcon\Validation\AbstractValidator;

/**
 * Checks if a value is identical to other
 *
 * ```php
 * use Phalcon\Validation\Validation;
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
 * ```
 */
class Identical extends AbstractValidator
{
    protected template = "Field :field does not have the expected value";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var value, accepted;
        bool valid;

        let value = validation->getValue(field);

        if this->hasOption("accepted") {
            let accepted = this->getOption("accepted");
        } elseif this->hasOption("value") {
            let accepted = this->getOption("value");
        }

        if accepted {
            if typeof accepted == "array" {
                let accepted = accepted[field];
            }

            let valid = value == accepted;
        }

        if !valid {
            validation->appendMessage(
                this->messageFactory(validation, field)
            );

            return false;
        }

        return true;
    }
}
