
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Support\Debug;

/**
 * Canonical contract for components that render through named, overridable
 * template strings.
 */
interface TemplateAware
{
    /**
     * Returns the template for the given name (override if set, default
     * otherwise).
     *
     * @param string $name
     *
     * @return string
     */
    public function getTemplate(string name) -> string;

    /**
     * Overrides the template for the given name.
     *
     * @param string $name
     * @param string $template
     *
     * @return static
     */
    public function setTemplate(string name, string template) -> <static>;
}
