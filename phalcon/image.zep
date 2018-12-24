
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

class Image
{
	// Resizing constraints
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
