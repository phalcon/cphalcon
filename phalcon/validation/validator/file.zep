
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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

use Phalcon\Validation;
use Phalcon\Validation\Message;
use Phalcon\Validation\Validator;

/**
 * Phalcon\Validation\Validator\File
 *
 * Checks if a value has a correct file
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\File as FileValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "file",
 *     new FileValidator(
 *         [
 *             "maxSize"              => "2M",
 *             "messageSize"          => ":field exceeds the max filesize (:max)",
 *             "allowedTypes"         => [
 *                 "image/jpeg",
 *                 "image/png",
 *             ],
 *             "messageType"          => "Allowed file types are :types",
 *             "maxResolution"        => "800x600",
 *             "messageMaxResolution" => "Max resolution of :field is :max",
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
 *                 "file"        => "file exceeds the max filesize 2M",
 *                 "anotherFile" => "anotherFile exceeds the max filesize 4M",
 *             "allowedTypes" => [
 *                 "file"        => [
 *                     "image/jpeg",
 *                     "image/png",
 *                 ],
 *                 "anotherFile" => [
 *                     "image/gif",
 *                     "image/bmp",
 *                 ],
 *             ],
 *             "messageType" => [
 *                 "file"        => "Allowed file types are image/jpeg and image/png",
 *                 "anotherFile" => "Allowed file types are image/gif and image/bmp",
 *             ],
 *             "maxResolution" => [
 *                 "file"        => "800x600",
 *                 "anotherFile" => "1024x768",
 *             ],
 *             "messageMaxResolution" => [
 *                 "file"        => "Max resolution of file is 800x600",
 *                 "anotherFile" => "Max resolution of file is 1024x768",
 *             ],
 *         ]
 *     )
 * );
 * </code>
 */
class File extends Validator
{

	/**
	 * Executes the validation
	 */
	public function validate(<Validation> validation, string! field) -> boolean
	{
		var value, message, label, replacePairs, types, byteUnits, unit, maxSize, matches, bytes, mime, tmp, width,
			height, minResolution, maxResolution, minWidth, maxWidth, minHeight, maxHeight, fieldTypes, code,
			minResolutionArray, maxResolutionArray;

		let value = validation->getValue(field),
			label = this->prepareLabel(validation, field),
			code = this->prepareCode(field);

		// Upload is larger than PHP allowed size (post_max_size or upload_max_filesize)
		if _SERVER["REQUEST_METHOD"] == "POST" && empty _POST && empty _FILES && _SERVER["CONTENT_LENGTH"] > 0 || isset value["error"] && value["error"] === UPLOAD_ERR_INI_SIZE {
			let message = this->prepareMessage(validation, field, "FileIniSize", "messageIniSize"),
			    replacePairs = [":field": label];

			validation->appendMessage(
				new Message(
					strtr(message, replacePairs),
					field,
					"FileIniSize",
					code
				)
			);

			return false;
		}

		if !isset value["error"] || !isset value["tmp_name"] || value["error"] !== UPLOAD_ERR_OK || !is_uploaded_file(value["tmp_name"]) {
			let message = this->prepareMessage(validation, field, "FileEmpty", "messageEmpty"),
			    replacePairs = [":field": label];

			validation->appendMessage(
				new Message(
					strtr(message, replacePairs),
					field,
					"FileEmpty",
					code
				)
			);

			return false;
		}

		if !isset value["name"] || !isset value["type"] || !isset value["size"] {
			let message = this->prepareMessage(validation, field, "FileValid", "messageValid"),
			    replacePairs = [":field": label];

			validation->appendMessage(
				new Message(
					strtr(message, replacePairs),
					field,
					"FileValid",
					code
				)
			);

			return false;
		}

		if this->hasOption("maxSize") {

			let byteUnits = ["B": 0, "K": 10, "M": 20, "G": 30, "T": 40, "KB": 10, "MB": 20, "GB": 30, "TB": 40],
				maxSize = this->getOption("maxSize"),
				matches = null,
				unit = "B";

			if typeof maxSize == "array" {
				let maxSize = maxSize[field];
			}

			preg_match("/^([0-9]+(?:\\.[0-9]+)?)(".implode("|", array_keys(byteUnits)).")?$/Di", maxSize, matches);

			if isset matches[2] {
				let unit = matches[2];
			}

			let bytes = floatval(matches[1]) * pow(2, byteUnits[unit]);

			if floatval(value["size"]) > floatval(bytes) {
				let message = this->prepareMessage(validation, field, "FileSize", "messageSize"),
					replacePairs = [":field": label, ":max": maxSize];

				validation->appendMessage(
					new Message(
						strtr(message, replacePairs),
						field,
						"FileSize",
						code
					)
				);

				return false;
			}
		}

		if this->hasOption("allowedTypes") {

			let types = this->getOption("allowedTypes");

			if fetch fieldTypes, types[field] {
				let types = fieldTypes;
			}

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
				let message = this->prepareMessage(validation, field, "FileType", "messageType"),
					replacePairs = [":field": label, ":types": join(", ", types)];

				validation->appendMessage(
					new Message(
						strtr(message, replacePairs),
						field,
						"FileType",
						code
					)
				);

				return false;
			}
		}

		if this->hasOption("minResolution") || this->hasOption("maxResolution") {
			let tmp = getimagesize(value["tmp_name"]),
				width = tmp[0],
				height = tmp[1];

			if this->hasOption("minResolution") {
				let minResolution = this->getOption("minResolution");
				if typeof minResolution == "array" {
					let minResolution = minResolution[field];
				}
				let minResolutionArray = explode("x", minResolution),
					minWidth = minResolutionArray[0],
					minHeight = minResolutionArray[1];
			} else {
				let minWidth = 1,
					minHeight = 1;
			}

			if width < minWidth || height < minHeight {
				let message = this->prepareMessage(validation, field, "FileMinResolution", "messageMinResolution"),
					replacePairs = [":field": label, ":min": minResolution];

				validation->appendMessage(
					new Message(
						strtr(message, replacePairs),
						field,
						"FileMinResolution",
						code
					)
				);

				return false;
			}

			if this->hasOption("maxResolution") {

				let maxResolution = this->getOption("maxResolution");
				if typeof maxResolution == "array" {
					let maxResolution = maxResolution[field];
				}
				let maxResolutionArray = explode("x", maxResolution),
					maxWidth = maxResolutionArray[0],
					maxHeight = maxResolutionArray[1];

				if width > maxWidth || height > maxHeight {
					let message = this->prepareMessage(validation, field, "FileMaxResolution", "messageMaxResolution"),
						replacePairs = [":field": label, ":max": maxResolution];


					validation->appendMessage(
						new Message(
							strtr(message, replacePairs),
							field,
							"FileMaxResolution",
							code
						)
					);

					return false;
				}
			}
		}

		return true;
	}

	/**
	 * Check on empty
	 */
	public function isAllowEmpty(<Validation> validation, string! field) -> boolean
	{
		var value;
		let value = validation->getValue(field);

		return empty value || isset value["error"] && value["error"] === UPLOAD_ERR_NO_FILE;
	}
}
