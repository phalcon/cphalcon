
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Image;

class Enum
{
    // Resizing constraints
    /**
     * @var int
     */
    const AUTO    = 4;
    /**
     * @var int
     */
    const HEIGHT  = 3;
    /**
     * @var int
     */
    const INVERSE = 5;
    /**
     * @var int
     */
    const NONE    = 1;
    /**
     * @var int
     */
    const PRECISE = 6;
    /**
     * @var int
     */
    const TENSILE = 7;
    /**
     * @var int
     */
    const WIDTH   = 2;

    // Flipping directions
    /**
     * @var int
     */
    const HORIZONTAL = 11;
    /**
     * @var int
     */
    const VERTICAL   = 12;
}
