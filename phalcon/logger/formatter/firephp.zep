
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Author: Ivan Zubok <chi_no@ukr.net>                                    |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Logger\Formatter;

use Phalcon\Logger;
use Phalcon\Logger\Formatter;
use Phalcon\Logger\FormatterInterface;

/**
 * Phalcon\Logger\Formatter\Firephp
 *
 * Formats messages so that they can be sent to FirePHP
 */
class FirePHP extends Formatter implements FormatterInterface
{
	protected _showBacktrace = true;

	protected _enableLabels = true;

	/**
	 * Returns the string meaning of a logger constant
	 *
	 * @param  integer $type
	 * @return string
	 */
	public function getTypeString(int type) -> string
	{
		var typeString;

		switch type {
			case Logger::EMERGENCY:
			case Logger::CRITICAL:
			case Logger::ERROR:
				let typeString = "ERROR";
				break;

			case Logger::ALERT:
			case Logger::WARNING:
				let typeString = "WARN";
				break;

			case Logger::INFO:
			case Logger::NOTICE:
			case Logger::CUSTOM:
				let typeString = "INFO";
				break;

			case Logger::DEBUG:
			case Logger::SPECIAL:
				let typeString = "LOG";
				break;

			default:
				let typeString = "CUSTOM";
				break;
		}

		return typeString;
	}

	/**
	 * Returns the string meaning of a logger constant
	 *
	 * @return this
	 */
	public function setShowBacktrace(boolean isShow = null) -> <\Phalcon\Logger\Formatter\FirePHP>
	{
		let this->_showBacktrace = isShow;
		return this;
	}

	/**
	 * Returns the string meaning of a logger constant
	 *
	 * @return boolean
	 */
	public function getShowBacktrace() -> boolean
	{
		return this->_showBacktrace;
	}

	/**
	 * Returns the string meaning of a logger constant
	 *
	 * @return this
	 */
	public function enableLabels(boolean isEnable = null) -> <\Phalcon\Logger\Formatter\FirePHP>
	{
		let this->_enableLabels = isEnable;
		return this;
	}

	/**
	 * Returns the labels enabled
	 *
	 * @return boolean
	 */
	public function labelsEnabled() -> boolean
	{
		return this->_enableLabels;
	}

	/**
	 * Applies a format to a message before sending it to the log
	 *
	 * @param string $message
	 * @param int $type
	 * @param int $timestamp
	 * @param array $context
	 * @return array
	 */
	public function format(string message, int type, int timestamp, var context = null) -> array
	{
		if typeof context === "array" {
			let message = this->interpolate(message, context);
		}

		return [
			"Type": this->getTypeString(type),
			"Label": message
		];
	}
}