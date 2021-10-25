
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

/**
 * Class Uncamelize
 *
 * @package Phalcon\Support\Str
 */
class Uncamelize
{
    /**
     * Converts strings to camelize style
     *
     * ```php
     * use Phalcon\Support\Helper\Str;
     *
     * echo Str::camelize("coco_bongo");            // CocoBongo
     * echo Str::camelize("co_co-bon_go", "-");     // Co_coBon_go
     * echo Str::camelize("co_co-bon_go", "_-");    // CoCoBonGo
     * ```
     *
     * @param string $text
     * @param string $delimiters
     *
     * @return string
     */
    public function __invoke(
        string text,
        string delimiter = "_"
    ) -> string {
        return mb_strtolower(
            preg_replace(
                "/[A-Z]/",
                delimiter . "\\0",
                lcfirst(text)
            )
        );
    }
}
