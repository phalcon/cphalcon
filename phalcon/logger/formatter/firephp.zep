
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
 |          Ivan Zubok <chi_no@ukr.net>                                   |
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
class Firephp extends Formatter implements FormatterInterface
{
	protected _showBacktrace = true;

	protected _enableLabels = true;

	/**
	 * Returns the string meaning of a logger constant
	 */
	public function getTypeString(int type) -> string
	{
		switch type {

			case Logger::EMERGENCY:
			case Logger::CRITICAL:
			case Logger::ERROR:
				return "ERROR";

			case Logger::ALERT:
			case Logger::WARNING:
				return "WARN";

			case Logger::INFO:
			case Logger::NOTICE:
			case Logger::CUSTOM:
				return "INFO";

			case Logger::DEBUG:
			case Logger::SPECIAL:
				return "LOG";
		}

		return "CUSTOM";
	}

	/**
	 * Returns the string meaning of a logger constant
	 */
	public function setShowBacktrace(boolean isShow = null) -> <Firephp>
	{
		let this->_showBacktrace = isShow;
		return this;
	}

	/**
	 * Returns the string meaning of a logger constant
	 */
	public function getShowBacktrace() -> boolean
	{
		return this->_showBacktrace;
	}

	/**
	 * Returns the string meaning of a logger constant
	 */
	public function enableLabels(boolean isEnable = null) -> <Firephp>
	{
		let this->_enableLabels = isEnable;
		return this;
	}

	/**
	 * Returns the labels enabled
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
	 *
	 * @return string
	 */
	public function format(string message, int type, int timestamp, var context = null) -> string
	{
		var meta, body, backtrace, encoded, len, lastTrace;

		if typeof context === "array" {
			let message = this->interpolate(message, context);
		}

		let meta = ["Type": this->getTypeString(type)];

		if this->_showBacktrace {
			var param, backtraceItem, key;
			let param = false;

			if !version_compare(PHP_VERSION, "5.3.6", "<") {
				let param = DEBUG_BACKTRACE_IGNORE_ARGS;
			}

			let backtrace = debug_backtrace(param),
				lastTrace = end(backtrace);

			if isset(lastTrace["file"]) {
				let meta["File"] = lastTrace["file"];
			}

			if isset(lastTrace["line"]) {
				let meta["Line"] = lastTrace["line"];
			}

			for key, backtraceItem in backtrace {
				unset(backtraceItem["object"]);
				unset(backtraceItem["args"]);

				let backtrace[key] = backtraceItem;
			}
		}

		if this->_enableLabels {
			let meta["Label"] = message;
		}

		if !this->_enableLabels && !this->_showBacktrace {
			let body = message;
		} elseif this->_enableLabels && !this->_showBacktrace {
			let body = "";
		} else {
			let body = [];

			if this->_showBacktrace {
				let body["backtrace"] = backtrace;
			}

			if !this->_enableLabels {
				let body["message"] = message;
			}
		}

		let encoded = json_encode([meta, body]),
			len = strlen(encoded);

		return len . "|" . encoded . "|";
	}
}