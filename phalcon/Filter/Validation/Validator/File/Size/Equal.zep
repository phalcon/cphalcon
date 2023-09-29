
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator\File\Size;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\File\AbstractFile;

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
 *     new Equal(
 *         [
 *             "size"     => "2M",
 *             "included" => true,
 *             "message"  => ":field exceeds the equal file size (:size)",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new Equal(
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
 *                 "file"        => "file does not have the right file size",
 *                 "anotherFile" => "anotherFile wrong file size (4MB)",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class Equal extends AbstractFile
{
    /**
     * @var string|null
     */
    protected template = "File :field does not have the exact :size file size";

    /**
     * Executes the validation
     *
     * @param Validation $validation
     * @param string     $field
     *
     * @return bool
     * @throws Validation\Exception
     */
    public function validate(<Validation> validation, string field) -> bool
    {
        var bytes, included, fileSize, replacePairs, size, value;

        // Check file upload
        if (true !== this->checkUpload(validation, field)) {
            return false;
        }

        let value = validation->getValue(field);
        let size  = this->checkArray(this->getOption("size"), field);

        let bytes    = round(this->getFileSizeInBytes(size), 6);
        let fileSize = round(floatval(value["size"]), 6);

        let included = (bool)this->checkArray(
            this->getOption("included", false),
            field
        );

        if (true === this->getConditional(bytes, fileSize, included)) {
            let replacePairs = [
                ":size" : size
            ];

            validation->appendMessage(
                this->messageFactory(validation, field, replacePairs)
            );

            return false;
        }

        return true;
    }

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
        return included === false && source !== target;
    }
}
