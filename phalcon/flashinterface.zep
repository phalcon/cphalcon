
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

namespace Phalcon;

/**
 * Phalcon\FlashInterface
 *
 * Interface for Phalcon\Flash
 */
interface FlashInterface
{

	/**
	 * Shows a HTML error message
	 *
	 * @param string message
	 * @return string
	 */
	public function error(message);

	/**
	 * Shows a HTML notice/information message
	 *
	 * @param string message
	 * @return string
	 */
	public function notice(message);

	/**
	 * Shows a HTML success message
	 *
	 * @param string message
	 * @return string
	 */
	public function success(message);

	/**
	 * Shows a HTML warning message
	 *
	 * @param string message
	 * @return string
	 */
	public function warning(message);

	/**
	 * Outputs a message
	 *
	 * @param  string type
	 * @param  string message
	 * @return string
	 */
	public function message(type, message);

}