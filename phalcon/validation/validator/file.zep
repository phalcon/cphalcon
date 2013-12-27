
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\File
 *
 * Checks if a value has a correct file
 *
 *<code>
 *use Phalcon\Validation\Validator\File as FileValidator;
 *
 *$validator->add('file', new FileValidator(array(
 *   'maxSize' => '2M',
 *   'messageSize' => ':field exceeds the max filesize (:max)',
 *   'allowedTypes' => array('jpg', 'png', 'gif'),
 *   'messageType' => 'Allowed file types are :types',
 *   'maxResolution' => '800x600',
 *   'messageMaxResolution' => 'Max resolution of :field is :max'
 *)));
 *</code>
 */
class File extends Phalcon\Validation\Validator implements Phalcon\Validation\ValidatorInterface
{

	/**
	 * Executes the validation
	 *
	 * @param  Phalcon\Validation validation
	 * @param  string             field
	 * @return boolean
	 */
	public function validate(<Phalcon\Validation> validation, string! field) -> boolean
	{
		var value, message, replacePairs, types, byteUnits, unit, maxSize, matches, bytes, tmp, width, height, minResolution, maxResolution, minWidth, maxWidth, minHeight, maxHeight;

		let value = validation->getValue(field);

                if this->isSetOption("allowEmpty") && empty value {
                    return true;
                }

                if !isset value["error"] || !isset value["name"] || !isset value["type"] || !isset value["tmp_name"] || !isset value["size"] {

                        let message = this->getOption("messageValid");
                        let replacePairs = [":field": field];
			if empty message {
                                let message = "File :field is not valid";
			}

			validation->appendMessage(new Phalcon\Validation\Message(strtr(message, replacePairs), field, "FileValid"));
			return false;
                }


                if value["error"] !== UPLOAD_ERR_OK || !is_uploaded_file(value["tmp_name"]) {

                        let message = this->getOption("messageEmpty");
                        let replacePairs = [":field": field];
			if empty message {
                                let message = "File :field must not be empty";
			}

			validation->appendMessage(new Phalcon\Validation\Message(strtr(message, replacePairs), field, "FileEmpty"));
			return false;
                }

                // Upload is larger than PHP allowed size (upload_max_filesize)
                if (value["error"] === UPLOAD_ERR_INI_SIZE) {

                        let message = this->getOption("messageIniSize");
                        let replacePairs = [":field": field];
                        if empty message {
                                let message = "The uploaded file exceeds the max filesize";
                        }

                        validation->appendMessage(new Phalcon\Validation\Message(strtr(message, replacePairs), field, "FileIniSize"));
                        return false;
                }


                if this->isSetOption("maxSize") {

                        let byteUnits = ["B": 0, "K": 10, "M": 20, "G": 30, "T": 40,
                                                 "KB": 10, "MB": 20, "GB": 30, "TB": 40];
                        let maxSize = this->getOption("maxSize"),
                                matches = NULL,
                                unit = "B";

                        preg_match("/^([0-9]+(?:\\.[0-9]+)?)(".implode("|", array_keys(byteUnits)).")?$/Di", maxSize, matches);
                        if isset matches[2] {
                            let unit = matches[2];
                        }

                        let bytes = floatval(matches[1]) * pow(2, byteUnits[unit]);

                        if floatval(value["size"]) > floatval(bytes) {

                                let message = this->getOption("messageSize");
                                let replacePairs = [":field": field, ":max": maxSize];
                                if empty message {
                                        let message = "Max filesize of file :field is :max";
                                }

                                validation->appendMessage(new Phalcon\Validation\Message(strtr(message, replacePairs), field, "FileSize"));
                                return false;
                        }
                }

                if this->isSetOption("allowedTypes") {

                        let types = this->getOption("allowedTypes");
                        if typeof types != "array" {
                                throw new Phalcon\Validation\Exception("Option 'allowedTypes' must be an array");
                        }

                        if !in_array(strtolower(pathinfo(value["name"], PATHINFO_EXTENSION)), types) {

                                let message = this->getOption("messageType");
                                let replacePairs = [":field": field, ":types": join(", ", types)];
                                if empty message {
                                        let message = "Type of :field is not valid";
                                }

                                validation->appendMessage(new Phalcon\Validation\Message(strtr(message, replacePairs), field, "FileType"));
                                return false;
                        }
                }


                if this->isSetOption("minResolution") || this->isSetOption("maxResolution") {

                        //list(width, height) = getimagesize(value["tmp_name"]);
                        let tmp = getimagesize(value["tmp_name"]);
                        let width = tmp[0];
                        let height = tmp[1];

                        if this->isSetOption("minResolution") {

                                let minResolution = explode("x", this->getOption("minResolution"));
                                let minWidth = minResolution[0],
                                        minHeight = minResolution[1];
                        } else {

                                let minWidth = 1,
                                        minHeight = 1;
                        }

                        if (width < minWidth || height < minHeight) {

                                let message = this->getOption("messageMinResolution");
                                let replacePairs = [":field": field, ":min": this->getOption("minResolution")];
                                if empty message {
                                        let message = "Min resolution of :field is :min";
                                }

                                validation->appendMessage(new Phalcon\Validation\Message(strtr(message, replacePairs), field, "FileMinResolution"));
                                return false;
                        }

                        if this->isSetOption("maxResolution") {

                                let maxResolution = explode("x", this->getOption("maxResolution"));
                                let maxWidth = maxResolution[0];
                                let maxHeight = maxResolution[1];

                                if (width > maxWidth || height > maxHeight) {

                                        let message = this->getOption("messageMaxResolution");
                                        let replacePairs = [":field": field, ":max": this->getOption("maxResolution")];
                                        if empty message {
                                                let message = "Max resolution of :field is :max";
                                        }

                                        validation->appendMessage(new Phalcon\Validation\Message(strtr(message, replacePairs), field, "FileMaxResolution"));
                                        return false;
                                }
                        }
                }

		return true;
	}
}
