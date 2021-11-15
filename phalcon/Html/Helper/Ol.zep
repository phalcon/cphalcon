
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

/**
 * Class Ol
 */
class Ol extends AbstractList
{
    /**
     * Add an element to the list
     *
     * @param string $text
     * @param array  $attributes
     * @param bool   $raw
     *
     * @return AbstractList
     */
    public function add(
        string text,
        array attributes = [],
        bool raw = false
    ) -> <AbstractList> {
        let this->store[] = [
            "renderFullElement",
            [
                this->elementTag,
                text,
                attributes,
                raw
            ],
            this->indent()
        ];

        return this;
    }

    /**
     * @return string
     */
    protected function getTag() -> string
    {
        return "ol";
    }
}
