
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\View\Traits;

/**
 * Shared view parameter and content accessors
 *
 * @todo v7 - inspect the View/Simple interfaces (ViewInterface vs ViewBaseInterface) to see whether these accessors can be unified behind a shared contract
 */
trait ViewParamsTrait
{
    /**
     * @var string
     */
    protected content = "";

    /**
     * @var array
     *
     * @todo Use a default [] once Zephir supports array trait defaults
     */
    protected registeredEngines = null;

    /**
     * @var array
     *
     * @todo Use a default [] once Zephir supports array trait defaults
     */
    protected viewParams = null;

    /**
     * Returns output from another view stage
     *
     * @return string
     */
    public function getContent() -> string
    {
        return this->content;
    }

    /**
     * Returns parameters to views
     *
     * @return array
     */
    public function getParamsToView() -> array
    {
        return (array) this->viewParams;
    }

    /**
     * @return array
     */
    public function getRegisteredEngines() -> array
    {
        return (array) this->registeredEngines;
    }

    /**
     * Returns a parameter previously set in the view
     *
     * @return mixed|null
     */
    public function getVar(string key) -> var | null
    {
        var value;

        if !fetch value, this->viewParams[key] {
            return null;
        }

        return value;
    }

    /**
     * Externally sets the view content
     *
     *```php
     * $this->view->setContent("<h1>hello</h1>");
     *```
     *
     * @return static
     */
    public function setContent(string content) -> <static>
    {
        let this->content = content;

        return this;
    }

    /**
     * Set a single view parameter
     *
     *```php
     * $this->view->setVar("products", $products);
     *```
     *
     * @return static
     */
    public function setVar(string key, var value) -> <static>
    {
        let this->viewParams[key] = value;

        return this;
    }
}
