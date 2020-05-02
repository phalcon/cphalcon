
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
 * Class Link
 */
class Link extends AbstractSeries
{
    /**
     * Add an element to the list
     *
     * @param string $rel
     * @param string $href
     *
     * @return Link
     */
    public function add(string rel, string href) -> <Link>
    {
        var attributes;

        let attributes = [
            "rel"  : rel,
            "href" : href
        ];

        let this->store[] = [
            "renderTag",
            [
                this->getTag(),
                attributes,
                "/"
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
        return "link";
    }
}
