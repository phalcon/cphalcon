
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter;

/**
 * Lazy loads, stores and exposes sanitizer objects
 *
 * @method absint(mixed $input): int
 * @method alnum(mixed $input): string
 * @method alpha(mixed $input): string
 * @method bool(mixed $input): bool
 * @method email(string $input): string
 * @method float(mixed $input): float
 * @method int(string $input): int
 * @method lower(string $input): string
 * @method lowerfirst(string $input): string
 * @method regex(mixed $input, mixed $pattern, mixed $replace): mixed
 * @method remove(mixed $input, mixed $replace): mixed
 * @method replace(mixed $input, mixed $source, mixed $target): mixed
 * @method special(string $input): string
 * @method specialfull(string $input): string
 * @method string(string $input): string
 * @method striptags(string $input): string
 * @method trim(string $input): string
 * @method upper(string $input): string
 * @method upperFirst(string $input): string
 * @method upperWords(string $input): string|null
 * @method url(string $input): string|null
 *
 * @property array $mapper
 * @property array $services
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
    const FILTER_LOWERFIRST  = "lowerfirst";
    const FILTER_REGEX       = "regex";
    const FILTER_REMOVE      = "remove";
    const FILTER_REPLACE     = "replace";
    const FILTER_SPECIAL     = "special";
    const FILTER_SPECIALFULL = "specialfull";
    const FILTER_STRING      = "string";
    const FILTER_STRIPTAGS   = "striptags";
    const FILTER_TRIM        = "trim";
    const FILTER_UPPER       = "upper";
    const FILTER_UPPERFIRST  = "upperfirst";
    const FILTER_UPPERWORDS  = "upperwords";
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
     * Filter constructor.
     *
     * @param array $mapper
     */
    public function __construct(array mapper = [])
    {
        this->init(mapper);
    }

    /**
     * Magic call to make the helper objects available as methods.
     *
     * @param string $name
     * @param array  $args
     *
     * @return mixed
     * @throws Exception
     */
    public function __call(string name, array args)
    {
        var sanitizer;

        let sanitizer = this->get(name);

        return call_user_func_array([sanitizer, "__invoke"], args);
    }

    /**
     * Get a service. If it is not in the mapper array, create a new object,
     * set it and then return it.
     *
     * @param string $name
     *
     * @return mixed
     * @throws Exception
     */
    public function get(string name) -> var
    {
        var definition;

        if (true !== isset(this->mapper[name])) {
            throw new Exception(
                "Filter " . name . " is not registered"
            );
        }

        if (true !== isset(this->services[name])) {
            let definition           = this->mapper[name],
                this->services[name] = this->createInstance(definition);
        }

        return this->services[name];
    }

    /**
     * Checks if a service exists in the map array
     *
     * @param string $name
     *
     * @return bool
     */
    public function has(string name) -> bool
    {
        return isset(this->mapper[name]);
    }

    /**
     * Sanitizes a value with a specified single or set of sanitizers
     *
     * @param mixed $value
     * @param mixed $sanitizers
     * @param bool  $noRecursive
     *
     * @return array|false|mixed|null
     * @throws Exception
     */
    public function sanitize(var value, var sanitizers, bool noRecursive = false) -> var
    {
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
         *     '  mary had a little lamb ',
         *     [
         *         'trim',
         *         'replace' => [' ', '-'],
         *         'remove'  => ['mary'],
         *     ]
         * );
         *
         * The above should produce "-had-a-little-lamb"
         */

        /**
         * Filter is an array
         */
        if typeof sanitizers === "array" {
            return this->processArraySanitizers(sanitizers, value, noRecursive);
        }

        /**
         * Apply a single sanitizer to the values. Check if the values are an
         * array
         */
        if typeof value === "array" && !noRecursive {
            return this->processArrayValues(value, sanitizers);
        }

        /**
         * One value one sanitizer
         */
        return this->sanitizer(value, sanitizers);
    }

    /**
     * Set a new service to the mapper array
     *
     * @param string $name
     * @param mixed  $service
     */
    public function set(string name, var service) -> void
    {
        let this->mapper[name] = service;

        unset this->services[name];
    }

    /**
     * Loads the objects in the internal mapper array
     *
     * @param array $mapper
     */
    protected function init(array mapper) -> void
    {
        var name, service;

        for name, service in mapper {
            this->set(name, service);
        }
    }

    /**
     * @param mixed $definition
     *
     * @return mixed
     */
    private function createInstance(var definition)
    {
        var instance;

        let instance = definition;
        if typeof instance === "string" {
            return create_instance(instance);
        }

        return instance;
    }

    /**
     * @param array $sanitizers
     * @param mixed $value
     * @param bool  $noRecursive
     *
     * @return array|false|mixed|null
     * @throws Exception
     */
    private function processArraySanitizers(
        array sanitizers,
        var value,
        bool noRecursive
    ) {
        var sanitizer, sanitizerKey, sanitizerName, sanitizerParams, split;

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
            let split           = this->splitSanitizerParameters(sanitizerKey, sanitizer),
                sanitizerName   = split[0],
                sanitizerParams = split[1];

            /**
             * Check if the value is an array of elements. If `noRecursive`
             * has been defined it is a straight up; otherwise recursion is
             * required
             */
            let value = this->processValueIsArray(
                value,
                sanitizerName,
                sanitizerParams,
                noRecursive
            );

            let value = this->processValueIsNotArray(
                value,
                sanitizerName,
                sanitizerParams
            );
        }

        return value;
    }

    /**
     * Processes the array values with the relevant sanitizers
     *
     * @param array  $values
     * @param string $sanitizerName
     * @param array  $sanitizerParams
     *
     * @return array
     * @throws Exception
     */
    private function processArrayValues(
        array values,
        string sanitizerName,
        array sanitizerParams = []
    ) -> array {
        var itemKey, itemValue;
        array arrayValues = [];

        for itemKey, itemValue in values {
            let arrayValues[itemKey] = this->sanitizer(
                itemValue,
                sanitizerName,
                sanitizerParams
            );
        }

        return arrayValues;
    }

    /**
     * Internal sanitize wrapper for recursion
     *
     * @param mixed  $value
     * @param string $sanitizerName
     * @param array  $sanitizerParams
     *
     * @return false|mixed
     * @throws Exception
     */
    private function sanitizer(
        var value,
        string sanitizerName,
        array sanitizerParams = []
    ) {
        var params, sanitizerObject;

        if true !== this->has(sanitizerName) {
            if true !== empty(sanitizerName) {
                trigger_error(
                    "Sanitizer '" . sanitizerName . "' is not registered",
                    E_USER_NOTICE
                );
            }

            return value;
        }

        let sanitizerObject = this->get(sanitizerName),
            params          = array_merge([value], sanitizerParams);

        return call_user_func_array(sanitizerObject, params);
    }

    /**
     * @param mixed  $value
     * @param string $sanitizerName
     * @param array  $sanitizerParams
     * @param bool   $noRecursive
     *
     * @return array|mixed
     * @throws Exception
     */
    private function processValueIsArray(
        var value,
        string sanitizerName,
        array sanitizerParams,
        bool noRecursive
    ) {
        if typeof value === "array" && !noRecursive {
            let value = this->processArrayValues(
                value,
                sanitizerName,
                sanitizerParams
            );
        }

        return value;
    }

    /**
     * @param mixed  $value
     * @param string $sanitizerName
     * @param array  $sanitizerParams
     *
     * @return array|false|mixed
     * @throws Exception
     */
    private function processValueIsNotArray(
        var value,
        string sanitizerName,
        array sanitizerParams
    ) {
        if typeof value !== "array" {
            let value = this->sanitizer(
                value,
                sanitizerName,
                sanitizerParams
            );
        }

        return value;
    }

    /**
     * @param mixed $sanitizerKey
     * @param mixed $sanitizer
     *
     * @return array
     */
    private function splitSanitizerParameters(var sanitizerKey, var sanitizer) -> array
    {
        /**
         * If `sanitizer` is an array, that means that the sanitizerKey
         * is the name of the sanitizer.
         */
        if typeof sanitizer === "array" {
            return [sanitizerKey, sanitizer];
        }

        return [sanitizer, []];
    }
}
