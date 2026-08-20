
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
 * Class Title
 */
class Title extends AbstractHelper
{
    /**
     * @phpstan-var list<string>
     */
    protected array append = [];
    /**
     * Untyped on purpose. A typed `array` default is shared by all instances
     * and `prepend()` mutates it in place, which corrupts the heap. See
     * team/Planning/2026-08-20-zephir-typed-array-property-shared-default.md
     *
     * @phpstan-var list<string>
     */
    protected prepend = [];
    protected string title = "";
    protected string separator = "";

    /**
     * Sets the separator and returns the object back
     */
    public function __invoke(
        string indent = "    ",
        string delimiter = null
    ) -> <static> {
        let this->delimiter = null === delimiter ? PHP_EOL : delimiter,
            this->indent    = indent;

        return this;
    }

    /**
     * Returns the title tags
     */
    public function __toString()
    {
        var items;

        let items = array_merge(
            this->prepend,
            [this->title],
            this->append
        );

        let this->append  = [],
            this->prepend = [],
            this->title   = "";

        return this->indent
            . this->renderFullElement(
                "title",
                implode(this->separator, items),
                [],
                true
            )
            . this->delimiter;
    }

    /**
     * Appends text to current document title
     */
    public function append(string text, bool raw = false) -> <static>
    {
        let text = raw ? text : this->escaper->html(text);

        let this->append[] = text;

        return this;
    }

    /**
     * Returns the title
     */
    public function get() -> string
    {
        return this->title;
    }

    /**
     * Prepends text to current document title
     */
    public function prepend(string text, bool raw = false) -> <static>
    {
        var prepend;

        let text = raw ? text : this->escaper->html(text);

        let prepend = this->prepend;

        array_unshift(prepend, text);

        let this->prepend = prepend;

        return this;
    }

    /**
     * Sets the title
     */
    public function set(string text, bool raw = false) -> <static>
    {
        let text = raw ? text : this->escaper->html(text);

        let this->title = text;

        return this;
    }

    /**
     * Sets the separator
     */
    public function setSeparator(string separator, bool raw = false) -> <static>
    {
        let this->separator = raw ? separator : this->escaper->html(separator);

        return this;
    }
}
