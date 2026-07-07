
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Validation\Validator;

use Phalcon\Messages\Messages;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\AbstractValidator;
use Phalcon\Messages\Messages;

/**
 * Validates an array of uploaded files by delegating each file to the `File`
 * validator. Accepts the same options as `Phalcon\Filter\Validation\Validator\File`
 * and forwards them to each delegated file. A standard multiple-file upload
 * (`<input name="files[]" type="file" multiple>`) arrives as a transposed
 * `$_FILES` node; this validator normalizes it into individual files and fails
 * on the first file that violates a rule.
 *
 * ```php
 * use Phalcon\Filter\Validation;
 * use Phalcon\Filter\Validation\Validator\Files as FilesValidator;
 *
 * $validation = new Validation();
 *
 * $validation->add(
 *     "photos",
 *     new FilesValidator(
 *         [
 *             "maxSize"      => "2M",
 *             "messageSize"  => ":field exceeds the max file size (:size)",
 *             "allowedTypes" => ["image/jpeg", "image/png"],
 *             "messageType"  => "Allowed file types are :types",
 *         ]
 *     )
 * );
 * ```
 */
class Files extends AbstractValidator
{
    /**
     * Whole-field empty check: true when the field carries no uploaded files.
     *
     * @param Validation $validation
     * @param string     $field
     *
     * @return bool
     */
    public function isAllowEmpty(<Validation> validation, string field) -> bool
    {
        var value, files, single;

        let value = validation->getValue(field);

        if empty value {
            return true;
        }

        let files = this->normalizeFiles(value);

        for single in files {
            if !(
                typeof single == "array" &&
                isset single["error"] &&
                single["error"] === UPLOAD_ERR_NO_FILE
            ) {
                return false;
            }
        }

        return true;
    }

    /**
     * Executes the validation, delegating each file to a `File` validator.
     *
     * @param Validation $validation
     * @param mixed      $field
     *
     * @return bool
     * @throws Validation\Exception
     */
    public function validate(<Validation> validation, var field) -> bool
    {
        var value, files, single, validator, inner, messages, message, data;

        let value     = validation->getValue(field);
        let files     = this->normalizeFiles(value);
        let validator = new File(this->options);

        for single in files {
            let inner = new Validation();
            inner->add(field, validator);

            let data        = [];
            let data[field] = single;
            let messages    = inner->validate(data);

            if messages->count() > 0 {
                for message in iterator(messages) {
                    validation->appendMessage(message);
                }

                return false;
            }
        }

        return true;
    }

    /**
     * Normalizes a single file or a transposed multi-file `$_FILES` node into a
     * list of single-file structures.
     *
     * @param mixed $value
     *
     * @return array
     */
    protected function normalizeFiles(var value) -> array
    {
        var files, names, types, tmpNames, sizes, errors, index, name,
            type, tmpName, size, error;

        // Not an array (e.g. null/missing) -> delegate once so File reports it
        if typeof value != "array" {
            return [value];
        }

        // Single-file structure: "name" is a scalar, not an array
        if !isset value["name"] || typeof value["name"] != "array" {
            return [value];
        }

        let names    = value["name"];
        let types    = isset value["type"] ? value["type"] : [];
        let tmpNames = isset value["tmp_name"] ? value["tmp_name"] : [];
        let sizes    = isset value["size"] ? value["size"] : [];
        let errors   = isset value["error"] ? value["error"] : [];
        let files    = [];

        for index, name in names {
            let type    = null;
            let tmpName = null;
            let size    = null;
            let error   = null;

            if isset types[index] {
                let type = types[index];
            }

            if isset tmpNames[index] {
                let tmpName = tmpNames[index];
            }

            if isset sizes[index] {
                let size = sizes[index];
            }

            if isset errors[index] {
                let error = errors[index];
            }

            let files[] = [
                "name":     name,
                "type":     type,
                "tmp_name": tmpName,
                "size":     size,
                "error":    error
            ];
        }

        return files;
    }
}
