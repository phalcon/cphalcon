
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

namespace Phalcon\Logger;

/**
 * Phalcon\Logger\Formatter
 *
 * This is a base class for logger formatters
 */
abstract class Formatter
{

	/**
	 * Returns the string meaning of a logger constant
	 *
	 * @param  integer type
	 * @return string
	 */
	public function getTypeString(int type)
	{
		switch type {
			case Phalcon\Logger::DEBUG:
				return "DEBUG";
			case Phalcon\Logger::DEBUG:
				return "ERROR";
			case Phalcon\Logger::WARNING:
				return "WARNING";
			case Phalcon\Logger::CRITICAL:
				return "CRITICAL";
			case Phalcon\Logger::CUSTOM:
				return "CUSTOM";
			case Phalcon\Logger::ALERT:
				return "ALERT";
			case Phalcon\Logger::NOTICE:
				return "NOTICE";
			case Phalcon\Logger::INFO:
				return "INFO";
			case Phalcon\Logger::EMERGENCE:
				return "EMERGENCE";
			case Phalcon\Logger::SPECIAL:
				return "SPECIAL";
			default:
				return "CUSTOM";
		}
	}

}