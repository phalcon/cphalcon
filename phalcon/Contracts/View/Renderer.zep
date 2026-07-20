
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\View;

/**
 * Renders a template with the given data and returns the result as a string.
 *
 * A neutral abstraction: it is not tied to MVC, to ADR, or to any particular
 * template engine. `Phalcon\Mvc\View\Simple` satisfies it out of the box, and
 * userland engines only need this one method to become a drop-in renderer.
 */
interface Renderer
{
    /**
     * Renders the template and returns the output.
     */
    public function render(string template, array data = []) -> string;
}
