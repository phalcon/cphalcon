
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator\StringLength;

use Phalcon\Contracts\Filter\FilterTypes;
use Phalcon\Filter\Validation;
use Phalcon\Messages\Message;

/**
 * Validates that a string has the specified maximum constraints
 * The test is passed if for a string's length L, L<=max, i.e. L must
 * be at most max.
 *
 * The "included" option is true by default. Set the option to false
 * for L<max, i.e. L must be less than max. The "includedMaximum" option
 * is an alias of "included". If you set the two options, "included" has
 * precedence.
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\StringLength\Max;
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
 *
 * @phpstan-import-type filter_validator_options from FilterTypes
 */
class Max extends AbstractStringLength
{
    /**
     * @var string|null
     */
    protected template = "Field :field must not exceed :max characters long";

    /**
     * Constructor
     *
     * @phpstan-param filter_validator_options $options
     */
    public function __construct(array options = [])
    {
        parent::__construct(options);
    }

    /**
     * Compares the length of the value with the maximum
     */
    protected function validateLength(
        <Validation> validation,
        var field,
        int length
    ) -> bool {
        var failed, included, maximum, replacePairs;

        let maximum = this->getOption("max");

        if typeof maximum == "array" {
            let maximum = maximum[field];
        }

        // "includedMaximum" is an alias of "included". The maximum is
        // inclusive if no option is set. hasOption() uses isset(), thus a
        // null value also counts as not set
        let included = true;

        if this->hasOption("included") {
            let included = this->getOption("included");
        } elseif this->hasOption("includedMaximum") {
            let included = this->getOption("includedMaximum");
        }

        if typeof included == "array" {
            let included = (bool) included[field];
        } else {
            let included = (bool) included;
        }

        if included {
            let failed = length > maximum;
        } else {
            let failed = length >= maximum;
        }

        if failed {
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
