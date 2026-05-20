
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Forms;

use Phalcon\Forms\Element\Check;
use Phalcon\Forms\Element\CheckGroup;
use Phalcon\Forms\Exceptions\FormNotInLocator;
use Phalcon\Forms\Exceptions\UnknownFormElementType;
use Phalcon\Forms\Element\Date;
use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\File;
use Phalcon\Forms\Element\Hidden;
use Phalcon\Forms\Element\Numeric;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\RadioGroup;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Submit;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Element\TextArea;

/**
 * A closure-based registry for named forms and element type factories.
 *
 * **Form registry** (`get`/`has`/`set`):
 * Each entry is a callable `fn(?object $entity): Form`. Without an entity the
 * resolved form is cached; with an entity a fresh form is always produced.
 *
 * **Element registry** (`getElement`/`hasElement`/`setElement`):
 * Maps type strings (e.g. 'text', 'email') to factories used by Form::load().
 * Each callable has the signature `fn(string $name, array $options, array $attributes): ElementInterface`.
 * Default types are seeded by `getDefaultServices()`. Users may add or override
 * types with `setElement()`.
 */
class FormsLocator
{
    /**
     * Element type → factory callable.
     *
     * @var array
     */
    private elements = [];

    /**
     * Form name → factory callable.
     *
     * @var array
     */
    private factories = [];

    /**
     * Cached entity-less form instances.
     *
     * @var array
     */
    private instances = [];

    /**
     * @param array $definitions  name → callable map for the form registry
     */
    public function __construct(array definitions = [])
    {
        var name, definition;

        let this->elements = this->getDefaultServices();

        for name, definition in definitions {
            this->set(name, definition);
        }
    }

    /**
     * Returns the named form.
     *
     * Without an entity the result is lazily created and cached.
     * With an entity a fresh form is always produced.
     *
     * @param string      $name
     * @param object|null $entity
     *
     * @return Form
     * @throws Exception
     */
    public function get(string name, var entity = null) -> <Form>
    {
        var factory, instance;

        if !this->has(name) {
            throw new FormNotInLocator(name);
        }

        let factory = this->factories[name];

        if entity !== null {
            return {factory}(entity);
        }

        if !fetch instance, this->instances[name] {
            let instance = {factory}(null);
            let this->instances[name] = instance;
        }

        return instance;
    }

    /**
     * Returns the factory callable for the given element type.
     *
     * @param string $type
     *
     * @return callable
     * @throws Exception
     */
    public function getElement(string type)
    {
        if !isset this->elements[type] {
            throw new UnknownFormElementType(type);
        }

        return this->elements[type];
    }

    /**
     * Checks whether a named form factory is registered.
     *
     * @param string $name
     *
     * @return bool
     */
    public function has(string name) -> bool
    {
        return isset this->factories[name];
    }

    /**
     * Checks whether an element type is registered.
     *
     * @param string $type
     *
     * @return bool
     */
    public function hasElement(string type) -> bool
    {
        return isset this->elements[type];
    }

    /**
     * Registers or replaces a named form factory.
     *
     * The callable must accept one argument (?object $entity) and return a
     * Form instance. Replacing a registration clears any cached instance so
     * the next get() call rebuilds from the new factory.
     *
     * @param string   $name
     * @param callable $factory
     */
    public function set(string name, var factory) -> void
    {
        unset this->instances[name];
        let this->factories[name] = factory;
    }

    /**
     * Registers or replaces an element type factory.
     *
     * The callable must accept (string $name, array $options, array $attributes)
     * and return an ElementInterface instance.
     *
     * @param string   $type
     * @param callable $factory
     */
    public function setElement(string type, var factory) -> void
    {
        let this->elements[type] = factory;
    }

    /**
     * Returns the built-in element type factories.
     *
     * Each value is a callable: fn(string $name, array $options, array $attributes): ElementInterface
     *
     * @return array
     */
    protected function getDefaultServices() -> array
    {
        return [
            "check":      function (string name, array options, array attributes) {
                return new Check(name, attributes);
            },
            "checkgroup": function (string name, array options, array attributes) {
                return new CheckGroup(name, options, attributes);
            },
            "date":       function (string name, array options, array attributes) {
                return new Date(name, attributes);
            },
            "email":      function (string name, array options, array attributes) {
                return new Email(name, attributes);
            },
            "file":       function (string name, array options, array attributes) {
                return new File(name, attributes);
            },
            "hidden":     function (string name, array options, array attributes) {
                return new Hidden(name, attributes);
            },
            "numeric":    function (string name, array options, array attributes) {
                return new Numeric(name, attributes);
            },
            "password":   function (string name, array options, array attributes) {
                return new Password(name, attributes);
            },
            "radio":      function (string name, array options, array attributes) {
                return new Radio(name, attributes);
            },
            "radiogroup": function (string name, array options, array attributes) {
                return new RadioGroup(name, options, attributes);
            },
            "select":     function (string name, array options, array attributes) {
                return new Select(name, options, attributes);
            },
            "submit":     function (string name, array options, array attributes) {
                return new Submit(name, attributes);
            },
            "text":       function (string name, array options, array attributes) {
                return new Text(name, attributes);
            },
            "textarea":   function (string name, array options, array attributes) {
                return new TextArea(name, attributes);
            }
        ];
    }
}
