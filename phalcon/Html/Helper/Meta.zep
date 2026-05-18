
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Exception;

/**
 * Class Meta
 */
class Meta extends AbstractSeries
{
    /**
     * Add an element to the list
     *
     * @param array $attributes
     *
     * @return Meta
     */
    public function add(array attributes = [], int position = -1) -> <Meta>
    {
        this->pushOrPlace(
            [
                "renderTag",
                [
                    this->getTag(),
                    attributes
                ],
                this->indent()
            ],
            position
        );

        return this;
    }

    /**
     * @param string $httpEquiv
     * @param string $content
     * @param int    $position
     *
     * @return Meta
     * @throws Exception
     */
    public function addHttp(string httpEquiv, string content, int position = -1) -> <Meta>
    {
        return this->addElement("http-equiv", httpEquiv, content, position);
    }

    /**
     * @param string $name
     * @param string $content
     * @param int    $position
     *
     * @return Meta
     * @throws Exception
     */
    public function addName(string name, string content, int position = -1) -> <Meta>
    {
        this->addElement("name", name, content, position);

        return this;
    }

    /**
     * @param string $name
     * @param string $content
     * @param int    $position
     *
     * @return Meta
     * @throws Exception
     */
    public function addProperty(string name, string content, int position = -1) -> <Meta>
    {
        this->addElement("property", name, content, position);

        return this;
    }

    /**
     * @return string
     */
    protected function getTag() -> string
    {
        return "meta";
    }

    /**
     * @param string $element
     * @param string $value
     * @param string $content
     * @param int    $position
     *
     * @return Meta
     * @throws Exception
     */
    private function addElement(
        string element,
        string value,
        string content,
        int position = -1
    ) -> <Meta> {
        array attributes;

        let attributes = [
            element   : value,
            "content" : content
        ];

        return this->add(attributes, position);
    }
}
