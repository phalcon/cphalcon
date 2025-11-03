
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator\File;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\AbstractValidator;
use Phalcon\Messages\Message;

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
    protected messageFileEmpty = "Field :field must not be empty";

    /**
     * File exceeds the file size set in PHP configuration
     *
     * @var string
     */
    protected messageIniSize = "File :field exceeds the maximum file size";

    /**
     * File is not valid
     *
     * @var string
     */
    protected messageValid = "Field :field is not valid";

    /**
     * Check upload
     *
     * @param Validation $validation
     * @param string     $field
     *
     * @return bool
     * @throws Validation\Exception
     */
    public function checkUpload(<Validation> validation, string field) -> bool
    {
        if this->getOption("ignoreCheckUploadedFile") {
            return this->checkUploadMaxSize(validation, field)
                && this->checkUploadIsValid(validation, field);
        }

        return this->checkUploadMaxSize(validation, field)
            && this->checkUploadIsEmpty(validation, field)
            && this->checkUploadIsValid(validation, field);
    }

    /**
     * Check if upload is empty
     *
     * @param Validation $validation
     * @param string     $field
     *
     * @return bool
     * @throws Validation\Exception
     */
    public function checkUploadIsEmpty(
        <Validation> validation,
        string field
    ) -> bool {
        var value, label, replacePairs;

        let value = validation->getValue(field);

        // If the value is not an array, we consider it valid (no file provided)
        if !is_array(value) {
            return true;
        }

        // Case: ignoreCheckUploadedFile = true
        if this->getOption("ignoreCheckUploadedFile") {
            // Only check for minimum required keys
            if isset(value["name"]) && isset(value["tmp_name"]) && value["error"] === 0 {
                return true;
            }

            // Missing required keys -> append error message
            let label        = this->prepareLabel(validation, field);
            let replacePairs = [":field" : label];

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

        // Case: Normal strict validation
        if (
            !isset(value["error"]) ||
            !isset(value["tmp_name"]) ||
            value["error"] !== UPLOAD_ERR_OK ||
            !this->checkIsUploadedFile(value["tmp_name"])
        ) {
            let label        = this->prepareLabel(validation, field);
            let replacePairs = [
                ":field" : label
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
     * @param string     $field
     *
     * @return bool
     * @throws Validation\Exception
     */
    public function checkUploadIsValid(
        <Validation> validation,
        string field
    ) -> bool {
        var label, replacePairs, value;

        let value = validation->getValue(field);

        if (
            is_array(value) &&
            (
                true !== isset(value["name"]) ||
                true !== isset(value["type"]) ||
                true !== isset(value["size"])
            )
        ) {
            let label        = this->prepareLabel(validation, field);
            let replacePairs = [
                ":field" : label
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
     * Check if uploaded file is larger than PHP allowed size
     *
     * @param Validation $validation
     * @param string     $field
     *
     * @return bool
     * @throws Validation\Exception
     */
    public function checkUploadMaxSize(
        <Validation> validation,
        string field
    ) -> bool {
        var files, label, length, method, post, replacePairs, server, value;

    let value  = validation->getValue(field);
    let server = [];
    let post   = [];
    let files  = [];
    let method = "GET";
    let length = 0;

    // Skip all max size and POST-size checks when ignoreCheckUploadedFile is true
    if this->getOption("ignoreCheckUploadedFile") {
        return true;
    }

    if _SERVER {
        let server = _SERVER;
    }
    if _POST {
        let post = _POST;
    }
    if _FILES {
        let files = _FILES;
    }
    if isset(server["REQUEST_METHOD"]) {
        let method = server["REQUEST_METHOD"];
    }
    if isset(server["CONTENT_LENGTH"]) {
        let length = server["CONTENT_LENGTH"];
    }

        // Upload is larger than PHP allowed size (post_max_size or upload_max_filesize)
        if (
            "POST" === method &&
            true === empty(post) &&
            true === empty(files) &&
            (int)length > 0 ||
            is_array(value) &&
            true === isset(value["error"]) &&
            value["error"] === UPLOAD_ERR_INI_SIZE
        ) {
            let label        = this->prepareLabel(validation, field);
            let replacePairs = [
                ":field" : label
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
     * Convert a string like "2.5MB" in bytes
     *
     * @param string $size
     *
     * @return float
     */
    public function getFileSizeInBytes(string size) -> float
    {
        var byteUnits, matches, unit;

        let byteUnits = [
            "B"  : 0,
            "K"  : 10,
            "M"  : 20,
            "G"  : 30,
            "T"  : 40,
            "KB" : 10,
            "MB" : 20,
            "GB" : 30,
            "TB" : 40
        ];
        let unit    = "B";
        let matches = [];

        preg_match(
            "/^([0-9]+(?:\\.[0-9]+)?)("
            . implode("|", array_keys(byteUnits))
            . ")?/Di",
            size,
            matches
        );

        if (true === isset(matches[2])) {
            let unit = matches[2];
        }

        return floatval(matches[1]) * pow(2, byteUnits[unit]);
    }

    /**
     * Empty is empty
     *
     * @return string
     */
    public function getMessageFileEmpty() -> string
    {
        return this->messageFileEmpty;
    }

    /**
     * File exceeds the file size set in PHP configuration
     *
     * @return string
     */
    public function getMessageIniSize() -> string
    {
        return this->messageIniSize;
    }

    /**
     * File is not valid
     *
     * @return string
     */
    public function getMessageValid() -> string
    {
        return this->messageValid;
    }

    /**
     * Check on empty
     *
     * @param Validation $validation
     * @param string     $field
     *
     * @return bool
     * @throws Validation\Exception
     */
    public function isAllowEmpty(<Validation> validation, string field) -> bool
    {
        var value;

        let value = validation->getValue(field);

        return true === empty(value) ||
            is_array(value) &&
            true === isset(value["error"]) &&
            value["error"] === UPLOAD_ERR_NO_FILE;
    }

    /**
     * Empty is empty
     *
     * @param string $message
     *
     * @return void
     */
    public function setMessageFileEmpty(string message) -> void
    {
        let this->messageFileEmpty = message;
    }

    /**
     * File exceeds the file size set in PHP configuration
     *
     * @param string $message
     *
     * @return void
     */
    public function setMessageIniSize(string message) -> void
    {
        let this->messageIniSize = message;
    }

    /**
     * File is not valid
     *
     * @param string $message
     *
     * @return void
     */
    public function setMessageValid(string message) -> void
    {
        let this->messageValid = message;
    }

    /**
     * Checks if a file has been uploaded; Internal check that can be
     * overridden in a subclass if you do not want to check uploaded files
     *
     * @param string $name
     *
     * @return bool
     */
    protected function checkIsUploadedFile(string name) -> bool
    {
        /**
         * When ignoreCheckUploadedFile = true,
         * skip the system-level check (is_uploaded_file)
         * but still ensure that the file physically exists.
         *
         * This allows CLI / test environments to validate
         * fake uploads safely.
         */
        if this->getOption("ignoreCheckUploadedFile") {
            return file_exists(name);
        }

        return is_uploaded_file(name);
    }
}
