
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms;

use Phalcon\Contracts\Forms\Schema;
use Phalcon\Forms\Form;

/**
 * Forms Manager
 */
class Manager
{
    /**
     * @var array
     */
    protected forms = [];

    /**
     * @var FormsLocator
     */
    protected locator;

    /**
     * Manager constructor.
     *
     * @param FormsLocator|null $locator
     */
    public function __construct(<FormsLocator> locator = null)
    {
        if locator === null {
            let locator = new FormsLocator();
        }

        let this->locator = locator;
    }

    /**
     * Creates a form registering it in the forms manager
     *
     * @param object entity
     */
    public function create(string name, entity = null) -> <Form>
    {
        var form;

        let form = new Form(entity),
            this->forms[name] = form;

        return form;
    }

    /**
     * Returns a form by its name
     */
    public function get(string name) -> <Form>
    {
        var form;

        if unlikely !fetch form, this->forms[name] {
            throw new Exception("There is no form with name='" . name . "'");
        }

        return form;
    }

    /**
     * Returns the FormsLocator instance.
     */
    public function getLocator() -> <FormsLocator>
    {
        return this->locator;
    }

    /**
     * Checks if a form is registered in the forms manager
     */
    public function has(string name) -> bool
    {
        return isset this->forms[name];
    }

    /**
     * Creates a form from a Schema source, registers it in the manager,
     * and registers a factory in the locator for entity-aware retrieval.
     *
     * @param string      $name
     * @param Schema      $schema
     * @param object|null $entity
     *
     * @return Form
     * @throws Exception
     */
    public function loadForm(string name, <Schema> schema, var entity = null) -> <Form>
    {
        var form, locator;

        let locator           = this->locator,
            form              = (new Form(entity))->load(schema, locator),
            this->forms[name] = form;

        this->locator->set(
            name,
            function (var e) use (schema, locator) {
                return (new Form(e))->load(schema, locator);
            }
        );

        return form;
    }

    /**
     * Registers a form in the Forms Manager
     */
    public function set(string name, <Form> form) -> <Manager>
    {
        let this->forms[name] = form;

        return this;
    }
}
