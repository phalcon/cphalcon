
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator\File;

use Phalcon\Contracts\Filter\FilterTypes;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exceptions\InvalidAllowedTypes;
use Phalcon\Traits\Php\InfoTrait;

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
 *
 * @phpstan-import-type filter_uploaded_file from FilterTypes
 */
class MimeType extends AbstractFile
{
    use InfoTrait;

    /**
     * @var string|null
     */
    protected template = "File :field must be of type: :types";

    /**
     * Executes the validation
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var allowWildcards, fieldTypes, replacePairs, tmp, type, types, value,
            matched = false,
            mime    = null;

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
            throw new InvalidAllowedTypes();
        }

        if this->phpFunctionExists("finfo_open") {
            let tmp = finfo_open(FILEINFO_MIME_TYPE);
            if (tmp) {
                let mime = finfo_file(tmp, value["tmp_name"]);
            }
        }

        if (!mime) {
            let mime = value["type"];
        }

        let allowWildcards = (bool) this->getOption("allowWildcards", false);

        if allowWildcards {
            for type in types {
                if mime === type || preg_match("#^" . type . "$#", mime) {
                    let matched = true;

                    break;
                }
            }
        } else {
            let matched = in_array(mime, types);
        }

        if !matched {
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
