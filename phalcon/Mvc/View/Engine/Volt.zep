
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
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Events\ManagerInterface;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Mvc\View\Exception;

/**
 * Designer friendly and fast template engine for PHP written in Zephir/C
 */
class Volt extends AbstractEngine implements EventsAwareInterface
{
    protected compiler;
    protected eventsManager;
    protected macros;
    protected options;

    /**
     * Checks if a macro is defined and calls it
     */
    public function callMacro(string! name, array arguments = []) -> var
    {
        var macro;

        if unlikely !fetch macro, this->macros[name] {
            throw new Exception("Macro '" . name . "' does not exist");
        }

        return call_user_func(macro, arguments);
    }

    /**
     * Performs a string conversion
     */
    public function convertEncoding(string text, string! from, string! to) -> string
    {
        /**
         * Try to use utf8_encode if conversion is 'latin1' to 'utf8'
         */
        if from == "latin1" || to == "utf8" {
            return utf8_encode(text);
        }

        /**
         * Try to use utf8_decode if conversion is 'utf8' to 'latin1'
         */
        if to == "latin1" || from == "utf8" {
            return utf8_decode(text);
        }

        /**
         * Fallback to iconv
         */
        if function_exists("iconv") {
            return iconv(from, to, text);
        }

        return mb_convert_encoding(text, from, to);
    }

    /**
     * Returns the Volt's compiler
     */
    public function getCompiler() -> <Compiler>
    {
        var compiler, container, options;

        let compiler = this->compiler;

        if typeof compiler != "object" {
            let compiler = new Compiler(this->view);

            /**
             * Pass the IoC to the compiler only of it's an object
             */
            let container = <DiInterface> this->container;

            if typeof container == "object" {
                compiler->setDi(container);
            }

            /**
             * Pass the options to the compiler only if they're an array
             */
            let options = this->options;

            if typeof options == "array" {
                compiler->setOptions(options);
            }

            let this->compiler = compiler;
        }

        return compiler;
    }

    /**
     * Returns the internal event manager
     */
    public function getEventsManager() -> <ManagerInterface> | null
    {
        return this->eventsManager;
    }

    /**
     * Return Volt's options
     */
    public function getOptions() -> array
    {
        return this->options;
    }

    /**
     * Checks if the needle is included in the haystack
     */
    public function isIncluded(var needle, var haystack) -> bool
    {
        if typeof haystack == "array" {
            return in_array(needle, haystack);
        }

        if typeof haystack == "string" {
            return mb_strpos(haystack, needle) !== false;
        }

        throw new Exception("Invalid haystack");
    }

    /**
     * Length filter. If an array/object is passed a count is performed otherwise a strlen/mb_strlen
     */
    public function length(var item) -> int
    {
        if typeof item == "object" || typeof item == "array" {
            return count(item);
        }

        return mb_strlen(item);
    }

    /**
     * Renders a view using the template engine
     */
    public function render(string! templatePath, var params, bool mustClean = false)
    {
        var compiler, compiledTemplatePath, eventsManager, key, value;

        if mustClean {
            ob_clean();
        }

        /**
         * The compilation process is done by Phalcon\Mvc\View\Engine\Volt\Compiler
         */
        let compiler      = this->getCompiler(),
            eventsManager = this->eventsManager;

        if typeof eventsManager == "object" {
            if eventsManager->fire("view:beforeCompile", this) === false {
                return null;
            }
        }

        compiler->compile(templatePath);

        if typeof eventsManager == "object" {
            if eventsManager->fire("view:afterCompile", this) === false {
                return null;
            }
        }

        let compiledTemplatePath = compiler->getCompiledTemplatePath();

        /**
         * Export the variables the current symbol table
         */
        if typeof params == "array"    {
            for key, value in params {
                let {key} = value;
            }
        }

        require compiledTemplatePath;

        if mustClean {
            this->view->setContent(ob_get_contents());
        }
    }

    /**
     * Sets the events manager
     */
    public function setEventsManager(<ManagerInterface> eventsManager) -> void
    {
        let this->eventsManager = eventsManager;
    }

    /**
     * Set Volt's options
     */
    public function setOptions(array! options)
    {
        let this->options = options;
    }

    /**
     * Extracts a slice from a string/array/traversable object value
     */
    public function slice(var value, int start = 0, var end = null)
    {
        var length;
        array slice;
        int position;

        /**
         * Objects must implement a Traversable interface
         */
        if typeof value == "object" {
            if end === null {
                let end = count(value) - 1;
            }

            let position = 0,
                slice = [];

            value->rewind();

            while value->valid() {
                if position >= start && position <= end {
                    let slice[] = value->current();
                }

                value->next();

                let position++;
            }

            return slice;
        }

        /**
         * Calculate the slice length
         */
        if end !== null {
            let length = (end - start) + 1;
        } else {
            let length = null;
        }

        /**
         * Use array_slice on arrays
         */
        if typeof value == "array" {
            return array_slice(value, start, length);
        }

        if length !== null {
            return mb_substr(value, start, length);
        }

        return mb_substr(value, start);
    }

    /**
     * Sorts an array
     */
    public function sort(array value) -> array
    {
        asort(value);

        return value;
    }
}
