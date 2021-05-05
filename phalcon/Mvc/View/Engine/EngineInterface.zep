
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\View\Engine;

/**
 * Interface for Phalcon\Mvc\View engine adapters
 */
interface EngineInterface
{
    /**
     * Returns cached output on another view stage
     */
    public function getContent() -> string;

    /**
     * Renders a partial inside another view
     */
    public function partial(string! partialPath, var params = null) -> void;

    /**
     * Renders a view using the template engine
     *
     * TODO: Change params to array type
     */
    public function render(string path, var params, bool mustClean = false);
}
