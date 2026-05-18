
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
        string indent = "    ",
        string delimiter = null,
        array attributes = []
    ) -> <AbstractList> {
        let this->attributes = attributes,
            this->delimiter  = empty(delimiter) ? PHP_EOL : delimiter,
	        this->indent     = indent,
            this->store      = [];

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
