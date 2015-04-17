
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

namespace Phalcon;

class Image
{

	/*
	 * Resizing constraints
	 */
	const NONE    = 1;
	const WIDTH   = 2;
	const HEIGHT  = 3;
	const AUTO    = 4;
	const INVERSE = 5;
	const PRECISE = 6;
	const TENSILE = 7;

	// Flipping directions
	const HORIZONTAL = 11;
	const VERTICAL   = 12;
}
