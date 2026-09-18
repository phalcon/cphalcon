
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Debug\Traits;

use Phalcon\Contracts\Support\SupportTypes;

/**
 * Shared store for named, overridable template strings. A using class supplies
 * the embedded defaults via defaultTemplate().
 *
 * Note: this trait has no Zephir equivalent; the cphalcon mirror duplicates
 * these members in each class until Zephir supports traits.
 *
 * @phpstan-import-type support_debug_templates from SupportTypes
 */
trait TemplateAwareTrait
{
    /**
     * @phpstan-var support_debug_templates
     */
    protected array templates = [];

    public function getTemplate(string name) -> string
    {
        return isset(this->templates[name]) ? this->templates[name] : this->defaultTemplate(name);
    }

    public function setTemplate(string name, string template) -> <static>
    {
        let this->templates[name] = template;

        return this;
    }

    /**
     * Returns the embedded default template for the given name.
     */
    abstract protected function defaultTemplate(string name) -> string;
}
