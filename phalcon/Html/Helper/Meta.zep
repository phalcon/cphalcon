
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
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
    public function add(array attributes = []) -> <Meta>
    {
        let this->store[] = [
            "renderTag",
            [
                this->getTag(),
                attributes
            ],
            this->indent()
        ];

        return this;
    }

    /**
     * @param string $httpEquiv
     * @param string $content
     *
     * @return Meta
     * @throws Exception
     */
    public function addHttp(string httpEquiv, string content) -> <Meta>
    {
        return this->addElement("http-equiv", httpEquiv, content);
    }

    /**
     * @param string $name
     * @param string $content
     *
     * @return Meta
     * @throws Exception
     */
    public function addName(string name, string content) -> <Meta>
    {
        this->addElement("name", name, content);

        return this;
    }

    /**
     * @param string $name
     * @param string $content
     *
     * @return Meta
     * @throws Exception
     */
    public function addProperty(string name, string content) -> <Meta>
    {
        this->addElement("property", name, content);

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
     *
     * @return Meta
     * @throws Exception
     */
    private function addElement(
        string element,
        string value,
        string content
    ) -> <Meta> {
        array attributes;

        let attributes = [
            element   : value,
            "content" : content
        ];

        return this->add(attributes);
    }
}
