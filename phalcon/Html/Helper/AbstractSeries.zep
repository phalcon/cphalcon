
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
 * Class AbstractSeries
 */
abstract class AbstractSeries extends AbstractHelper
{
    /**
     * @var array
     */
    protected attributes = [];

    /**
     * @var array
     */
    protected store = [];

    /**
     * @param string $indent
     * @param string $delimiter
     *
     * @return AbstractSeries
     */
    public function __invoke(
        string indent = null,
        string delimiter = null
    ) -> <AbstractSeries> {

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
     */
    public function __toString()
    {
        return this->renderArrayElements(
            this->store,
            this->delimiter
        );
    }

    /**
     * Returns the tag name.
     *
     * @return string
     */
    abstract protected function getTag() -> string;
}
