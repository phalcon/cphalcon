
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

use Phalcon\Validation\Message;
use Phalcon\Validation\Validator;

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
 *   'allowedTypes' => array('image/jpeg', 'image/png'),
 *   'messageType' => 'Allowed file types are :types',
 *   'maxResolution' => '800x600',
 *   'messageMaxResolution' => 'Max resolution of :field is :max'
 *)));
 *</code>
 */
class File extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<\Phalcon\Validation> validation, string! field) -> boolean
	{
		var value, message, label, replacePairs, types, byteUnits, unit, maxSize, matches, bytes, mime, tmp, width, height, minResolution, maxResolution, minWidth, maxWidth, minHeight, maxHeight;

		let value = validation->getValue(field),
			label = this->getOption("label");

		if empty label {
			let label = validation->getLabel(field);
		}

		// Upload is larger than PHP allowed size (post_max_size or upload_max_filesize)
		if _SERVER["REQUEST_METHOD"] == "POST" && empty _POST && empty _FILES && _SERVER["CONTENT_LENGTH"] > 0 || isset value["error"] && value["error"] === UPLOAD_ERR_INI_SIZE {
			let message = this->getOption("messageIniSize"),
				replacePairs = [":field": label];

			if empty message {
				let message = validation->getDefaultMessage("FileIniSize");
			}

			validation->appendMessage(new Message(strtr(message, replacePairs), field, "FileIniSize"));
			return false;
		}

		if this->isSetOption("allowEmpty") && (empty value || isset value["error"] && value["error"] === UPLOAD_ERR_NO_FILE) {
			return true;
		}

		if !isset value["error"] || ! isset value["tmp_name"] || value["error"] !== UPLOAD_ERR_OK || !is_uploaded_file(value["tmp_name"]) {
			let message = this->getOption("messageEmpty"),
				replacePairs = [":field": label];

			if empty message {
				let message = validation->getDefaultMessage("FileEmpty");
			}

			validation->appendMessage(new Message(strtr(message, replacePairs), field, "FileEmpty"));
			return false;
		}

		if !isset value["name"] || !isset value["type"] || !isset value["size"] {
			let message = this->getOption("messageValid"),
				replacePairs = [":field": label];

			if empty message {
				let message = validation->getDefaultMessage("FileValid");
			}

			validation->appendMessage(new Message(strtr(message, replacePairs), field, "FileValid"));
			return false;
		}

		if this->isSetOption("maxSize") {
			let byteUnits = ["B": 0, "K": 10, "M": 20, "G": 30, "T": 40, "KB": 10, "MB": 20, "GB": 30, "TB": 40],
				maxSize = this->getOption("maxSize"),
				matches = NULL,
				unit = "B";

			preg_match("/^([0-9]+(?:\\.[0-9]+)?)(".implode("|", array_keys(byteUnits)).")?$/Di", maxSize, matches);

			if isset matches[2] {
				let unit = matches[2];
			}

			let bytes = floatval(matches[1]) * pow(2, byteUnits[unit]);

			if floatval(value["size"]) > floatval(bytes) {
				let message = this->getOption("messageSize"),
					replacePairs = [":field": label, ":max": maxSize];

				if empty message {
					let message = validation->getDefaultMessage("FileSize");
				}

				validation->appendMessage(new Message(strtr(message, replacePairs), field, "FileSize"));
				return false;
			}
		}

		if this->isSetOption("allowedTypes") {
			let types = this->getOption("allowedTypes");

			if typeof types != "array" {
				throw new \Phalcon\Validation\Exception("Option 'allowedTypes' must be an array");
			}

			if function_exists("finfo_open") {
				let tmp = finfo_open(FILEINFO_MIME_TYPE),
					mime = finfo_file(tmp, value["tmp_name"]);

				finfo_close(tmp);
			} else {
				let mime = value["type"];
			}

			if !in_array(mime, types) {
				let message = this->getOption("messageType"),
					replacePairs = [":field": label, ":types": join(", ", types)];

				if empty message {
					let message = validation->getDefaultMessage("FileType");
				}

				validation->appendMessage(new Message(strtr(message, replacePairs), field, "FileType"));
				return false;
			}
		}

		if this->isSetOption("minResolution") || this->isSetOption("maxResolution") {
			let tmp = getimagesize(value["tmp_name"]),
				width = tmp[0],
				height = tmp[1];

			if this->isSetOption("minResolution") {
				let minResolution = explode("x", this->getOption("minResolution")),
					minWidth = minResolution[0],
					minHeight = minResolution[1];
			} else {
				let minWidth = 1,
					minHeight = 1;
			}

			if width < minWidth || height < minHeight {
				let message = this->getOption("messageMinResolution"),
					replacePairs = [":field": label, ":min": this->getOption("minResolution")];

				if empty message {
					let message = validation->getDefaultMessage("FileMinResolution");
				}

				validation->appendMessage(new Message(strtr(message, replacePairs), field, "FileMinResolution"));
				return false;
			}

			if this->isSetOption("maxResolution") {

				let maxResolution = explode("x", this->getOption("maxResolution")),
					maxWidth = maxResolution[0],
					maxHeight = maxResolution[1];

				if width > maxWidth || height > maxHeight {
					let message = this->getOption("messageMaxResolution"),
						replacePairs = [":field": label, ":max": this->getOption("maxResolution")];

					if empty message {
						let message = validation->getDefaultMessage("FileMaxResolution");
					}

					validation->appendMessage(new Message(strtr(message, replacePairs), field, "FileMaxResolution"));
					return false;
				}
			}
		}
		return true;
	}
}