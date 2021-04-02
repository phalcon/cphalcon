
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Validation\Validator\File;

use Phalcon\Messages\Message;
use Phalcon\Validation;
use Phalcon\Validation\AbstractValidator;

/**
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
 *     new Size(
 *         [
 *             "maxSize"              => "2M",
 *             "messageSize"          => ":field exceeds the max file size (:size)",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "file",
 *         "anotherFile",
 *     ],
 *     new FileValidator(
 *         [
 *             "maxSize" => [
 *                 "file"        => "2M",
 *                 "anotherFile" => "4M",
 *             ],
 *             "messageSize" => [
 *                 "file"        => "file exceeds the max file size 2M",
 *                 "anotherFile" => "anotherFile exceeds the max file size 4M",
 *             ],
 *         ]
 *     )
 * );
 * ```
 */
abstract class AbstractFile extends AbstractValidator
{
    /**
     * Empty is empty
     *
     * @var string
     */
    protected messageFileEmpty = "Field :field must not be empty" { get, set };

    /**
     * File exceeds the file size set in PHP configuration
     *
     * @var string
     */
    protected messageIniSize = "File :field exceeds the maximum file size" { get, set };

    /**
     * File is not valid
     *
     * @var string
     */
    protected messageValid = "Field :field is not valid" { get, set };

    /**
     * Check on empty
     *
     * @param Validation $validation
     * @param string $field
     * @return bool
     */
    public function isAllowEmpty(<Validation> validation, string! field) -> bool
    {
        var value = validation->getValue(field);

        return empty value || isset value["error"] && value["error"] === UPLOAD_ERR_NO_FILE;
    }

    /**
    * Check upload
    *
    * @param Validation $validation
    * @param mixed $field
    * @return bool
    */
    public function checkUpload(<Validation> validation, var field) -> bool
    {
        return this->checkUploadMaxSize(validation, field) &&
               this->checkUploadIsEmpty(validation, field) &&
               this->checkUploadIsValid(validation, field);
    }

    /**
    * Check if uploaded file is larger than PHP allowed size
    *
    * @param Validation $validation
    * @param mixed $field
    * @return boolean
    */
    public function checkUploadMaxSize(<Validation> validation, var field) -> bool
    {
        var label, replacePairs, value;

        let value = validation->getValue(field);

        // Upload is larger than PHP allowed size (post_max_size or upload_max_filesize)
        if _SERVER["REQUEST_METHOD"] == "POST" &&
            empty _POST &&
            empty _FILES &&
            _SERVER["CONTENT_LENGTH"] > 0 ||
            isset value["error"] && value["error"] === UPLOAD_ERR_INI_SIZE
        {
            let label = this->prepareLabel(validation, field),
                replacePairs = [
                    ":field": label
                ];

            validation->appendMessage(
                new Message(
                    strtr(this->getMessageIniSize(), replacePairs),
                    field,
                    get_class(this),
                    this->prepareCode(field)
                )
            );

            return false;
        }

        return true;
    }

    /**
    * Check if upload is empty
    *
    * @param Validation $validation
    * @param mixed $field
    * @return boolean
    */
    public function checkUploadIsEmpty(<Validation> validation, var field) -> bool
    {
        var label, replacePairs, value;

        let value = validation->getValue(field);

        if !isset value["error"] || !isset value["tmp_name"] || value["error"] !== UPLOAD_ERR_OK || !is_uploaded_file(value["tmp_name"]) {
            let label = this->prepareLabel(validation, field),
                replacePairs = [
                    ":field": label
                ];

            validation->appendMessage(
                new Message(
                    strtr(this->getMessageFileEmpty(), replacePairs),
                    field,
                    get_class(this),
                    this->prepareCode(field)
                )
            );

            return false;
        }

        return true;
    }

    /**
    * Check if upload is valid
    *
    * @param Validation $validation
    * @param mixed $field
    * @return boolean
    */
    public function checkUploadIsValid(<Validation> validation, var field) -> bool
    {
        var label, replacePairs, value;

        let value = validation->getValue(field);

        if !isset value["name"] || !isset value["type"] || !isset value["size"] {
            let label = this->prepareLabel(validation, field),
                replacePairs = [
                    ":field": label
                ];

            validation->appendMessage(
                new Message(
                    strtr(this->getMessageValid(), replacePairs),
                    field,
                    get_class(this),
                    this->prepareCode(field)
                )
            );

            return false;
        }

        return true;
    }

    /**
    * Convert a string like "2.5MB" in bytes
    *
    * @param string $size
    * @return float
    */
    public function getFileSizeInBytes(string! size) -> float
    {
        var byteUnits = [
            "B": 0,
            "K": 10,
            "M": 20,
            "G": 30,
            "T": 40,
            "KB": 10,
            "MB": 20,
            "GB": 30,
            "TB": 40
        ], unit = "B", matches = null;

        preg_match(
            "/^([0-9]+(?:\\.[0-9]+)?)(" . implode("|", array_keys(byteUnits)) . ")?$/Di",
            size,
            matches
        );

        if isset matches[2] {
            let unit = matches[2];
        }

        return floatval(matches[1]) * pow(2, byteUnits[unit]);
    }
}
