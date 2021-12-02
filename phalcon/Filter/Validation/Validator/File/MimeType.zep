
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator\File;

use Phalcon\Messages\Message;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;

/**
 * Checks if a value has a correct file mime type
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\File\MimeType;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new MimeType(
 *         [
 *             "types" => [
 *                 "image/jpeg",
 *                 "image/png",
 *             ],
 *             "message" => "Allowed file types are :types"
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new MimeType(
 *         [
 *             "types" => [
 *                 "file"        => [
 *                     "image/jpeg",
 *                     "image/png",
 *                 ],
 *                 "anotherFile" => [
 *                     "image/gif",
 *                     "image/bmp",
 *                 ],
 *             ],
 *             "message" => [
 *                 "file"        => "Allowed file types are image/jpeg and image/png",
 *                 "anotherFile" => "Allowed file types are image/gif and image/bmp",
 *             ]
 *         ]
 *     )
 * );
 * ```
 */
class MimeType extends AbstractFile
{
    protected template = "File :field must be of type: :types";

    /**
     * Executes the validation
     *
     * @param Validation $validation
     * @param mixed $field
     * @return bool
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var fieldTypes, mime, replacePairs, tmp, types, value;

        // Check file upload
        if this->checkUpload(validation, field) === false {
            return false;
        }

        let value = validation->getValue(field);

        let types = this->getOption("types");

        if fetch fieldTypes, types[field] {
            let types = fieldTypes;
        }

        if unlikely typeof types != "array" {
            throw new Exception(
                "Option 'allowedTypes' must be an array"
            );
        }

        if function_exists("finfo_open") {
            let tmp = finfo_open(FILEINFO_MIME_TYPE),
                mime = finfo_file(tmp, value["tmp_name"]);

            finfo_close(tmp);
        } else {
            let mime = value["type"];
        }

        if !in_array(mime, types) {
            let replacePairs = [
                ":types": join(", ", types)
            ];

            validation->appendMessage(
                this->messageFactory(validation, field, replacePairs)
            );

            return false;
        }

        return true;
    }
}
