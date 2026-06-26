
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter;

use Phalcon\Filter\Exceptions\FilterNotRegistered;

/**
 * Lazy loads, stores and exposes sanitizer objects
 *
 * @method int          absint(mixed $input)
 * @method string       alnum(mixed $input)
 * @method string       alpha(mixed $input)
 * @method bool         bool(mixed $input)
 * @method string       email(string $input)
 * @method float        float(mixed $input)
 * @method int          int(string $input)
 * @method string|false ip(string $input, int $filter = FILTER_FLAG_NONE)
 * @method string       lower(string $input)
 * @method string       lowerfirst(string $input)
 * @method mixed        regex(mixed $input, mixed $pattern, mixed $replace)
 * @method mixed        remove(mixed $input, mixed $replace)
 * @method mixed        replace(mixed $input, mixed $source, mixed $target)
 * @method string       special(string $input)
 * @method string       specialfull(string $input)
 * @method string       string(string $input)
 * @method string       stringlegacy(mixed $input)
 * @method string       striptags(string $input)
 * @method string       trim(string $input)
 * @method string       upper(string $input)
 * @method string       upperFirst(string $input)
 * @method string|null  upperWords(string $input)
 * @method string|null  url(string $input)
 *
 * @property array $mapper
 * @property array $services
 */
class Filter implements FilterInterface
{
    /**
     * @var string
     */
    const FILTER_ABSINT        = "absint";
    /**
     * @var string
     */
    const FILTER_ALNUM         = "alnum";
    /**
     * @var string
     */
    const FILTER_ALPHA         = "alpha";
    /**
     * @var string
     */
    const FILTER_BOOL          = "bool";
    /**
     * @var string
     */
    const FILTER_EMAIL         = "email";
    /**
     * @var string
     */
    const FILTER_FLOAT         = "float";
    /**
     * @var string
     */
    const FILTER_INT           = "int";
    /**
     * @var string
     */
    const FILTER_IP            = "ip";
    /**
     * @var string
     */
    const FILTER_LOWER         = "lower";
    /**
     * @var string
     */
    const FILTER_LOWERFIRST    = "lowerfirst";
    /**
     * @var string
     */
    const FILTER_REGEX         = "regex";
    /**
     * @var string
     */
    const FILTER_REMOVE        = "remove";
    /**
     * @var string
     */
    const FILTER_REPLACE       = "replace";
    /**
     * @var string
     */
    const FILTER_SPECIAL       = "special";
    /**
     * @var string
     */
    const FILTER_SPECIALFULL   = "specialfull";
    /**
     * @var string
     */
    const FILTER_STRING        = "string";
    /**
     * @var string
     */
    const FILTER_STRING_LEGACY = "stringlegacy";
    /**
     * @var string
     */
    const FILTER_STRIPTAGS     = "striptags";
    /**
     * @var string
     */
    const FILTER_TRIM          = "trim";
    /**
     * @var string
     */
    const FILTER_UPPER         = "upper";
    /**
     * @var string
     */
    const FILTER_UPPERFIRST    = "upperfirst";
    /**
     * @var string
     */
    const FILTER_UPPERWORDS    = "upperwords";
    /**
     * @var string
     */
    const FILTER_URL           = "url";

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
            throw new FilterNotRegistered(name);
        }

        if (true !== isset(this->services[name])) {
            let definition           = this->mapper[name],
                this->services[name] = this->createInstance(definition);
        }

        return this->services[name];
    }

    /**
     * Returns the default sanitizer name to class map. This is the single
     * source for the built-in sanitizer registry: when adding a sanitizer,
     * add its `FILTER_*` constant and its entry here.
     *
     * @return string[]
     */
    public static function getDefaultMapper() -> array
    {
        return [
            self::FILTER_ABSINT        : "Phalcon\\Filter\\Sanitize\\AbsInt",
            self::FILTER_ALNUM         : "Phalcon\\Filter\\Sanitize\\Alnum",
            self::FILTER_ALPHA         : "Phalcon\\Filter\\Sanitize\\Alpha",
            self::FILTER_BOOL          : "Phalcon\\Filter\\Sanitize\\BoolVal",
            self::FILTER_EMAIL         : "Phalcon\\Filter\\Sanitize\\Email",
            self::FILTER_FLOAT         : "Phalcon\\Filter\\Sanitize\\FloatVal",
            self::FILTER_INT           : "Phalcon\\Filter\\Sanitize\\IntVal",
            self::FILTER_IP            : "Phalcon\\Filter\\Sanitize\\Ip",
            self::FILTER_LOWER         : "Phalcon\\Filter\\Sanitize\\Lower",
            self::FILTER_LOWERFIRST    : "Phalcon\\Filter\\Sanitize\\LowerFirst",
            self::FILTER_REGEX         : "Phalcon\\Filter\\Sanitize\\Regex",
            self::FILTER_REMOVE        : "Phalcon\\Filter\\Sanitize\\Remove",
            self::FILTER_REPLACE       : "Phalcon\\Filter\\Sanitize\\Replace",
            self::FILTER_SPECIAL       : "Phalcon\\Filter\\Sanitize\\Special",
            self::FILTER_SPECIALFULL   : "Phalcon\\Filter\\Sanitize\\SpecialFull",
            self::FILTER_STRING        : "Phalcon\\Filter\\Sanitize\\StringVal",
            self::FILTER_STRING_LEGACY : "Phalcon\\Filter\\Sanitize\\StringValLegacy",
            self::FILTER_STRIPTAGS     : "Phalcon\\Filter\\Sanitize\\Striptags",
            self::FILTER_TRIM          : "Phalcon\\Filter\\Sanitize\\Trim",
            self::FILTER_UPPER         : "Phalcon\\Filter\\Sanitize\\Upper",
            self::FILTER_UPPERFIRST    : "Phalcon\\Filter\\Sanitize\\UpperFirst",
            self::FILTER_UPPERWORDS    : "Phalcon\\Filter\\Sanitize\\UpperWords",
            self::FILTER_URL           : "Phalcon\\Filter\\Sanitize\\Url"
        ];
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
     * Array policy: when `$value` is an array and `$noRecursive` is `false`
     * (the default), each element is passed to the sanitizer individually
     * and an array is returned - recursion is one level deep only. Elements
     * that are themselves arrays are passed to the sanitizer as-is, which
     * raises a `TypeError` for sanitizers that type their value parameter
     * (e.g. `trim`). When `$noRecursive` is `true`, the whole array is
     * passed to the sanitizer as a single value.
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
             if typeof value === "array" {
                let value = this->processValueIsArray(
                    value,
                    sanitizerName,
                    sanitizerParams,
                    noRecursive
                );
             } else {
                 let value = this->processValueIsNotArray(
                     value,
                     sanitizerName,
                     sanitizerParams
                 );
             }
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
        if noRecursive {
            let value = this->sanitizer(
                value,
                sanitizerName,
                sanitizerParams
            );
        } else {
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
