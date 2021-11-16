
/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

/**
 * Creates Doctype tags
 */
class Doctype
{
    const HTML32               = 1;
    const HTML401_STRICT       = 2;
    const HTML401_TRANSITIONAL = 3;
    const HTML401_FRAMESET     = 4;
    const HTML5                = 5;
    const XHTML10_STRICT       = 6;
    const XHTML10_TRANSITIONAL = 7;
    const XHTML10_FRAMESET     = 8;
    const XHTML11              = 9;
    const XHTML20              = 10;
    const XHTML5               = 11;

    /**
     * @var string
     */
    private delimiter;

    /**
     * @var int
     */
    private flag;

    public function __construct()
    {
        let this->flag      = self::HTML5,
            this->delimiter = PHP_EOL;
    }

    /**
     * Produce a <doctype> tag
     *
     * @param int    $flag
     * @param string $delimiter
     */
    public function __invoke(
        int flag = self::HTML5,
        string delimiter = "\n"
    ) -> void {
        let this->flag      = flag,
            this->delimiter = delimiter;
    }

    /**
     * @return string
     */
    public function __toString() -> string
    {
        switch this->flag {
            case self::HTML32:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">"
                    . this->delimiter;
            case self::HTML401_STRICT:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01//EN\""
                    . this->delimiter
                    . "\t\"http://www.w3.org/TR/html4/strict.dtd\">"
                    . this->delimiter;
            case self::HTML401_TRANSITIONAL:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\""
                    . this->delimiter
                    . "\t\"http://www.w3.org/TR/html4/loose.dtd\">"
                    . this->delimiter;
            case self::HTML401_FRAMESET:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Frameset//EN\""
                    . this->delimiter
                    . "\t\"http://www.w3.org/TR/html4/frameset.dtd\">"
                    . this->delimiter;
            case self::XHTML10_STRICT:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Strict//EN\""
                    . this->delimiter
                    . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd\">"
                    . this->delimiter;
            case self::XHTML10_TRANSITIONAL:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Transitional//EN\""
                    . this->delimiter
                    . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd\">"
                    . this->delimiter;
            case self::XHTML10_FRAMESET:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.0 Frameset//EN\""
                    . this->delimiter
                    . "\t\"http://www.w3.org/TR/xhtml1/DTD/xhtml1-frameset.dtd\">"
                    . this->delimiter;
            case self::XHTML11:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 1.1//EN\""
                    . this->delimiter
                    . "\t\"http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd\">"
                    . this->delimiter;
            case self::XHTML20:
                return "<!DOCTYPE html PUBLIC \"-//W3C//DTD XHTML 2.0//EN\""
                    . this->delimiter
                    . "\t\"http://www.w3.org/MarkUp/DTD/xhtml2.dtd\">"
                    . this->delimiter;
        }

        return "<!DOCTYPE html>" . this->delimiter;
    }
}
