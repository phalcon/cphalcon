
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
use Phalcon\Validation\AbstractValidator;

/**
 * Allows validate if the value of a field matches a regular expression
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Regex as RegexValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "created_at",
 *     new RegexValidator(
 *         [
 *             "pattern" => "/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])$/",
 *             "message" => "The creation date is invalid",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "created_at",
 *         "name",
 *     ],
 *     new RegexValidator(
 *         [
 *             "pattern" => [
 *                 "created_at" => "/^[0-9]{4}[-\/](0[1-9]|1[12])[-\/](0[1-9]|[12][0-9]|3[01])$/",
 *                 "name"       => "/^[a-z]$/",
 *             ],
 *             "message" => [
 *                 "created_at" => "The creation date is invalid",
 *                 "name"       => "The name is invalid",
 *             ]
 *         ]
 *     )
 * );
 * ```
 */
class Regex extends AbstractValidator
{
    protected template = "Field :field does not match the required format";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var matches, value, pattern;
        bool failed;

        // Regular expression is set in the option 'pattern'
        // Check if the value match using preg_match in the PHP userland
        let matches = null;
        let value = validation->getValue(field);

        let pattern = this->getOption("pattern");

        if typeof pattern == "array" {
            let pattern = pattern[field];
        }

        if preg_match(pattern, value, matches) {
            let failed = matches[0] != value;
        } else {
            let failed = true;
        }

        if failed {
            validation->appendMessage(
                this->messageFactory(validation, field)
            );

            return false;
        }

        return true;
    }
}
