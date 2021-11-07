
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator\StringLength;

use Phalcon\Messages\Message;
use Phalcon\Validation;
use Phalcon\Validation\AbstractValidator;
use Phalcon\Validation\Exception;

/**
 * Validates that a string has the specified maximum constraints
 * The test is passed if for a string's length L, L<=max, i.e. L must
 * be at most max.
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\StringLength\Max;
 *
 * $validator = new Validation();
 *
 * $validation->add(
 *     "name_last",
 *     new Max(
 *         [
 *             "max"      => 50,
 *             "message"  => "We don't like really long names",
 *             "included" => true
 *         ]
 *     )
 * );
 *
 * $validation->add(
 *     [
 *         "name_last",
 *         "name_first",
 *     ],
 *     new Max(
 *         [
 *             "max" => [
 *                 "name_last"  => 50,
 *                 "name_first" => 40,
 *             ],
 *             "message" => [
 *                 "name_last"  => "We don't like really long last names",
 *                 "name_first" => "We don't like really long first names",
 *             ],
 *             "included" => [
 *                 "name_last"  => false,
 *                 "name_first" => true,
 *             ]
 *         ]
 *     )
 * );
 * ```
 */
class Max extends AbstractValidator
{
    protected template = "Field :field must not exceed :max characters long";

    /**
     * Constructor
     *
     * @param array options = [
     *     'message' => '',
     *     'template' => '',
     *     'allowEmpty' => false,
     *     'max' => 1000,
     *     'included' => false
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
        var value, length, maximum, replacePairs, included, result;

        let value = validation->getValue(field);
        if this->allowEmpty(field, value) {
            return true;
        }

        // Check if mbstring is available to calculate the correct length
        if function_exists("mb_strlen") {
            let length = mb_strlen(value);
        } else {
            let length = strlen(value);
        }

        let maximum = this->getOption("max");

        if typeof maximum == "array" {
            let maximum = maximum[field];
        }

        let included = this->getOption("included");

        if typeof included == "array" {
            let included = (bool) included[field];
        } else {
            let included = (bool) included;
        }

        if included {
            let result = length >= maximum;
        } else {
            let result = length > maximum;
        }

        if result {
            let replacePairs = [
                ":max" : maximum
            ];

            validation->appendMessage(
                this->messageFactory(validation, field, replacePairs)
            );

            return false;
        }

        return true;
    }
}
