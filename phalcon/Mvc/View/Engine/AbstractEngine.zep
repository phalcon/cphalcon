
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\View\Engine;

use Phalcon\Di\DiInterface;
use Phalcon\Di\Injectable;
use Phalcon\Mvc\ViewBaseInterface;

/**
 * All the template engine adapters must inherit this class. This provides
 * basic interfacing between the engine and the Phalcon\Mvc\View component.
 */
abstract class AbstractEngine extends Injectable implements EngineInterface
{
    protected view;

    /**
     * Phalcon\Mvc\View\Engine constructor
     */
    public function __construct(<ViewBaseInterface> view, <DiInterface> container = null)
    {
        let this->view = view;
        let this->container = container;
    }

    /**
     * Returns cached output on another view stage
     */
    public function getContent() -> string
    {
        return this->view->getContent();
    }

    /**
     * Returns the view component related to the adapter
     */
    public function getView() -> <ViewBaseInterface>
    {
        return this->view;
    }

    /**
     * Renders a partial inside another view
     *
     * @param array params
     */
    public function partial(string! partialPath, var params = null) -> void
    {
        this->view->partial(partialPath, params);
    }
}
