
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator\File\Size;

/**
 * Checks if a value has a correct file
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\File\Size;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Min(
 *         [
 *             "size"     => "2M",
 *             "included" => true,
 *             "message"  => ":field exceeds the min file size (:size)",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Min(
 *         [
 *             "size" => [
 *                 "file"        => "2M",
 *                 "anotherFile" => "4M",
 *             ],
 *             "included" => [
 *                 "file"        => false,
 *                 "anotherFile" => true,
 *             ],
 *             "message" => [
 *                 "file"        => "file exceeds the min file size 2M",
 *                 "anotherFile" => "anotherFile exceeds the min file size 4M",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class Min extends Equal
{
    /**
     * @var string|null
     */
    protected template = "File :field can not have the minimum size of :size";

    /**
     * Executes the conditional
     *
     * @param float $source
     * @param float $target
     * @param bool  $included
     *
     * @return bool
     */
    protected function getConditional(
        float source,
        float target,
        bool included = false
    ) {
        if (included === true) {
            return target <= source;
        }

        return target < source;
    }
}
