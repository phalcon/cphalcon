
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

use Phalcon\Support\Helper\Exception;

/**
 * Class Friendly
 *
 * @package Phalcon\Support\Str
 */
class Friendly extends AbstractStr
{
    /**
     * Changes a text to a URL friendly one
     *
     * @param string     $text
     * @param string     $separator
     * @param bool       $lowercase
     * @param mixed|null $replace
     *
     * @return string
     * @throws Exception
     */
    public function __invoke(
        string! text,
        string! separator = "-",
        bool lowercase = true,
        var replace = null
    ) -> string {
        var friendly, matrix;

        if replace {
            let replace = this->checkReplace(replace);
        } else {
            let replace = [];
        }

        let matrix = $this->getMatrix(replace);

        let text     = str_replace(array_keys(matrix), array_values(matrix), text),
            friendly = preg_replace(
                "/[^a-zA-Z0-9\\/_|+ -]/",
                "",
                text
            );

        if lowercase {
            let friendly = strtolower(friendly);
        }

        let friendly = preg_replace("/[\\/_|+ -]+/", separator, friendly);

        return trim(friendly, separator);
    }

    /**
     * @param mixed $replace
     *
     * @return array
     * @throws Exception
     */
    private function checkReplace(replace) -> array
    {
        if typeof replace !== "array" && typeof replace !== "string" {
            throw new Exception(
                "Parameter replace must be an array or a string"
            );
        }

        if typeof replace === "string" {
            let replace = [replace];
        }

        return replace;
    }

    /**
     * @param mixed $replace
     *
     * @return array
     * @throws Exception
     */
    private function getMatrix(array replace) -> array
    {
        var item;
        array matrix;

        let matrix = [
            "Š"    : "S",     "š"    : "s", "Đ"    : "Dj", "Ð"    : "Dj",
            "đ"    : "dj",    "Ž"    : "Z", "ž"    : "z",  "Č"    : "C",
            "č"    : "c",     "Ć"    : "C", "ć"    : "c",  "À"    : "A",
            "Á"    : "A",     "Â"    : "A", "Ã"    : "A",  "Ä"    : "A",
            "Å"    : "A",     "Æ"    : "A", "Ç"    : "C",  "È"    : "E",
            "É"    : "E",     "Ê"    : "E", "Ë"    : "E",  "Ì"    : "I",
            "Í"    : "I",     "Î"    : "I", "Ï"    : "I",  "Ñ"    : "N",
            "Ò"    : "O",     "Ó"    : "O", "Ô"    : "O",  "Õ"    : "O",
            "Ö"    : "O",     "Ø"    : "O", "Ù"    : "U",  "Ú"    : "U",
            "Û"    : "U",     "Ü"    : "U", "Ý"    : "Y",  "Þ"    : "B",
            "ß"    : "Ss",    "à"    : "a", "á"    : "a",  "â"    : "a",
            "ã"    : "a",     "ä"    : "a", "å"    : "a",  "æ"    : "a",
            "ç"    : "c",     "è"    : "e", "é"    : "e",  "ê"    : "e",
            "ë"    : "e",     "ì"    : "i", "í"    : "i",  "î"    : "i",
            "ï"    : "i",     "ð"    : "o", "ñ"    : "n",  "ò"    : "o",
            "ó"    : "o",     "ô"    : "o", "õ"    : "o",  "ö"    : "o",
            "ø"    : "o",     "ù"    : "u", "ú"    : "u",  "û"    : "u",
            "ý"    : "y",     "þ"    : "b",  "ÿ"   : "y",  "Ŕ"    : "R",
            "ŕ"    : "r",     "ē"    : "e",  "'"   : "",   "&"    : " and ",
            "\r\n" : " ",     "\n"   : " "
        ];

        for item in replace {
            let matrix[item] = " ";
        }

        return matrix;
    }
}
