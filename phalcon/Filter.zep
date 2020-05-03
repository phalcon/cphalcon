
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon;

use Closure;
use Phalcon\Filter\Exception;
use Phalcon\Filter\FilterInterface;

/**
 * Lazy loads, stores and exposes sanitizer objects
 */
class Filter implements FilterInterface
{
    const FILTER_ABSINT      = "absint";
    const FILTER_ALNUM       = "alnum";
    const FILTER_ALPHA       = "alpha";
    const FILTER_BOOL        = "bool";
    const FILTER_EMAIL       = "email";
    const FILTER_FLOAT       = "float";
    const FILTER_INT         = "int";
    const FILTER_LOWER       = "lower";
    const FILTER_LOWERFIRST  = "lowerFirst";
    const FILTER_REGEX       = "regex";
    const FILTER_REMOVE      = "remove";
    const FILTER_REPLACE     = "replace";
    const FILTER_SPECIAL     = "special";
    const FILTER_SPECIALFULL = "specialFull";
    const FILTER_STRING      = "string";
    const FILTER_STRIPTAGS   = "striptags";
    const FILTER_TRIM        = "trim";
    const FILTER_UPPER       = "upper";
    const FILTER_UPPERFIRST  = "upperFirst";
    const FILTER_UPPERWORDS  = "upperWords";
    const FILTER_URL         = "url";

    /**
     * @var array
     */
    protected mapper = [];

    /**
     * @var array
     */
    protected services = [];

    /**
     * Key value pairs with name as the key and a callable as the value for
     * the service object
     */
    public function __construct(array! mapper = [])
    {
        this->init(mapper);
    }

    /**
     * Get a service. If it is not in the mapper array, create a new object,
     * set it and then return it.
     *
     * @return object
     */
    public function get(string! name) -> var
    {
        var definition;

        if unlikely !isset this->mapper[name] {
            throw new Exception(
                "The service " . name . " has not been found in the locator"
            );
        }

        if !isset(this->services[name]) {
            let definition = this->mapper[name];
            if typeof definition === "string" {
                let this->services[name] = create_instance(definition);
            } else {
                let this->services[name] = definition;
            }
        }

        return this->services[name];
    }

    /**
     * Checks if a service exists in the map array
     */
    public function has(string! name) -> bool
    {
        return isset this->mapper[name];
    }

    /**
     * Sanitizes a value with a specified single or set of sanitizers
     */
    public function sanitize(var value, var sanitizers, bool noRecursive = false) -> var
    {
        var sanitizer, sanitizerKey, sanitizerName, sanitizerParams;

        /**
         * First we need to figure out whether this is one sanitizer (string) or
         * an array with different sanitizers in it.
         *
         * All is well if the sanitizer accepts only one parameter, but certain
         * sanitizers require more than one parameter. To figure this out we
         * need to of course call call_user_func_array() but with the correct
         * parameters.
         *
         * If the array is passed with just values then those are just the
         * sanitizer names i.e.
         *
         * $locator->sanitize( 'abcde', ['trim', 'upper'])
         *
         * If the sanitizer requires more than one parameter then we need to
         * inject those parameters in the sanitize also:
         *
         * $locator->sanitize(
         *         '  mary had a little lamb ',
         *         [
         *             'trim',
         *             'replace' => [' ', '-'],
         *             'remove'  => ['mary'],
         *         ]
         * );
         *
         * The above should produce "-had-a-little-lamb"
         */

        /**
         * Filter is an array
         */
        if typeof sanitizers == "array" {
            /**
             * Null value - return immediately
             */
            if null === value {
                return value;
            }

            /**
             * `value` is something. Loop through the sanitizers
             */
            for sanitizerKey, sanitizer in sanitizers {
                /**
                 * If `sanitizer` is an array, that means that the sanitizerKey
                 * is the name of the sanitizer.
                 */
                 if typeof sanitizer === "array" {
                     let sanitizerName   = sanitizerKey,
                         sanitizerParams = sanitizer;
                 } else {
                     let sanitizerName   = sanitizer,
                         sanitizerParams = [];
                 }

                /**
                 * Check if the value is an array of elements. If `noRecursive`
                 * has been defined it is a straight up; otherwise recursion is
                 * required
                 */
                if typeof value === "array" && !noRecursive {
                    let value = this->processArrayValues(
                        value,
                        sanitizerName,
                        sanitizerParams
                    );
                } else {
                    let value = this->sanitizer(
                        value,
                        sanitizerName,
                        sanitizerParams
                    );
                }
            }

            return value;
        }

        /**
         * Apply a single sanitizer to the values. Check if the values are an
         * array
         */
        if typeof value == "array" && !noRecursive {
            return this->processArrayValues(value, sanitizers);
        }

        /**
         * One value one sanitizer
         */
        return this->sanitizer(value, sanitizers);
    }

    /**
     * Set a new service to the mapper array
     */
    public function set(string! name, callable service) -> void
    {
        let this->mapper[name] = service;

        unset this->services[name];
    }

    /**
     * Loads the objects in the internal mapper array
     */
    protected function init(array! mapper) -> void
    {
        var name, service;

        for name, service in mapper {
            this->set(name, service);
        }
    }

    /**
     * Processes the array values with the relevant sanitizers
     */
    private function processArrayValues(
        array values,
        string sanitizerName,
        array sanitizerParams = []
    ) -> array
    {
        var itemKey, itemValue;
        array arrayValue;

        let arrayValue = [];

        for itemKey, itemValue in values {
            let arrayValue[itemKey] = this->sanitizer(
                itemValue,
                sanitizerName,
                sanitizerParams
            );
        }

        return arrayValue;
    }

    /**
     * Internal sanitize wrapper for recursion
     */
    private function sanitizer(
        var value,
        string! sanitizerName,
        array sanitizerParams = []
    ) -> var
    {
        var sanitizerObject, params;

        if !this->has(sanitizerName) {
            return value;
        }

        let sanitizerObject = this->get(sanitizerName),
            params          = array_merge([value], sanitizerParams);

        return call_user_func_array(sanitizerObject, params);
    }
}
