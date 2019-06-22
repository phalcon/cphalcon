
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator\File\Size;

use Phalcon\Messages\Message;
use Phalcon\Validation;
use Phalcon\Validation\Validator\File\Size\Equal;
use Phalcon\Validation\Validator\File\FileAbstract;

/**
 * Phalcon\Validation\Validator\File
 *
 * Checks if a value has a correct file
 *
 * ```php
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File\Size;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new Equal(
 *         [
 *             "size"     => "2M",
 *             "included" => true,
 *             "message"  => ":field exceeds the equal filesize (:size)",
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
 *                 "file"        => "file does not have the rigth filesize",
 *                 "anotherFile" => "anotherFile wrong filesize (4MB)",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
class Equal extends FileAbstract
{
    protected template = "File :field does not have the exact :size filesize";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var bytes, fileSize, replacePairs, size, value;

        // Check file upload
        if (this->checkUpload(validation, field) === false) {
            return false;
        }

        let value = validation->getValue(field),
            size = this->getOption("size");

        if typeof size == "array" {
            let size = size[field];
        }

        let bytes = round(this->getFileSizeInBytes(size), 6),
            fileSize = round(floatval(value["size"]), 6);

        if bytes !== fileSize {
            let replacePairs = [
                ":size"  : size
            ];

            validation->appendMessage(
                this->messageFactory(validation, field, replacePairs)
            );

            return false;
        }

        return true;
    }
}
