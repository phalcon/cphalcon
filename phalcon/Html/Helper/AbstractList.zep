
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
 * Class AbstractList
 */
abstract class AbstractList extends AbstractHelper
{
    /**
     * @var array
     */
    protected attributes = [];

    /**
     * @var string
     */
    protected elementTag = "li";

    /**
     * @var array
     */
    protected store = [];

    /**
     * @param string $indent
     * @param string $delimiter
     * @param array  $attributes
     *
     * @return AbstractList
     */
    public function __invoke(
        string indent = null,
        string delimiter = null,
        array attributes = []
    ) -> <AbstractList> {
        let this->attributes = attributes;

        if unlikely !empty delimiter {
            let this->delimiter = delimiter;
        }

        if unlikely !empty indent {
            let this->indent = indent;
        }

        let this->store = [];

        return this;
    }

    /**
     * Generates and returns the HTML for the list.
     *
     * @return string
     * @throws Exception
     */
    public function __toString()
    {
        var contents;

        if empty this->store {
            return "";
        }

        let contents = this->delimiter .
            this->renderArrayElements(
                this->store,
                this->delimiter
            );

        return this->renderFullElement(
            this->getTag(),
            contents,
            this->attributes,
            true
        );
    }

    /**
     *
     * Returns the tag name.
     *
     * @return string
     *
     */
    abstract protected function getTag() -> string;
}
