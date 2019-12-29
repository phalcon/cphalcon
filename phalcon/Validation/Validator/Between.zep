
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
 * Validates that a value is between an inclusive range of two values.
 * For a value x, the test is passed if minimum<=x<=maximum.
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Between;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "price",
 *     new Between(
 *         [
 *             "minimum" => 0,
 *             "maximum" => 100,
 *             "message" => "The price must be between 0 and 100",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "price",
 *         "amount",
 *     ],
 *     new Between(
 *         [
 *             "minimum" => [
 *                 "price"  => 0,
 *                 "amount" => 0,
 *             ],
 *             "maximum" => [
 *                 "price"  => 100,
 *                 "amount" => 50,
 *             ],
 *             "message" => [
 *                 "price"  => "The price must be between 0 and 100",
 *                 "amount" => "The amount must be between 0 and 50",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class Between extends AbstractValidator
{
    protected template = "Field :field must be within the range of :min to :max";

    /**
     * Constructor
     *
     * @param array options = [
     *     'message' => '',
     *     'template' => '',
     *     'minimum' => 5,
     *     'maximum' => 50,
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
        var value, minimum, maximum, replacePairs;

        let value = validation->getValue(field),
            minimum = this->getOption("minimum"),
            maximum = this->getOption("maximum");

        if typeof minimum == "array" {
            let minimum = minimum[field];
        }

        if typeof maximum == "array" {
            let maximum = maximum[field];
        }

        if value < minimum || value > maximum {
            let replacePairs = [
                ":min":   minimum,
                ":max":   maximum
            ];

            validation->appendMessage(
                this->messageFactory(validation, field, replacePairs)
            );

            return false;
        }

        return true;
    }
}
