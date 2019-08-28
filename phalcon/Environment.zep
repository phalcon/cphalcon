namespace Phalcon;

use Exception;
use Phalcon\Di\Injectable;
use RuntimeException;

/**
 * Phalcon\Environment is a component that allows for easy access to environment variables.
 *
 * Typically, getenv is used to get environment variables. This component leverages getenv, but also gives the
 * ability to specify the default value. Additionally, it will automatically convert all envs to the proper type:
 *
 * A=true => bool (true)
 * A=(false) => bool (false)
 * A=1 => int (1)
 * A=2.0 => float (2.0)
 * A=empty => string ("")
 * A=(empty) => string ("")
 * A=null => null
 * A=(null) => null
 * A="something" => string ("something")
 * A=else => string ("else")
 *
 *
 *```php
 * use Phalcon\Environment;
 *
 * $env = new Environment();
 *
 * $var = $env->getValue("ABC", "blah"); //$var === "blah"
 *
 * $env->setValue("SOMETHING", "else");
 * $var = $nv->getValue("SOMETHING"); //$var === "else"
 *
 * putenv('SOMETHING=BLAH')
 * $var = $nv->getValue("SOMETHING", "else"); //$var === "BLAH"
 *
 *```
 */
class Environment extends Injectable
{
    /** @var array */
    private envVars = [];

    /** @var bool */
    private _isLoaded = false;

    /**
    * Has environment been loaded?
    */
    protected function isLoaded() -> bool
    {
        return this->_isLoaded;
    }

    /**
     * Disables Debug Info
     */
    public function __debugInfo()
    {
        return [];
    }

    /**
     * Set Environment Variable Override
     *
     * @param string envName Environment Variable To Set
     * @param string envValue Environment Variable Value
     */
    public function setValue(string envName, var envValue) -> <Environment>
    {
        let this->envVars[envName] = envValue;

        return this;
    }

    /**
     * Retrive Environemnt Variable
     *
     * @param string envName ENV To Retrieve
     * @param mixed defaultValue Default Value If ENV Does Not Exist
     */
    public function getValue(string envName, var defaultValue = null) -> var
    {
        //Lazy Load Environment
        if (!this->isLoaded()) {
            this->loadEnvironment();
        }

        var value = this->retrieveValue(envName);
        if unlikely value === null {
            return defaultValue;
        }

        return this->parseValue(value);
    }

    /**
     * Retrieve Value.
     *
     * @param string envName ENV To Retrieve
     * @private
     * @return mixed
     */
    protected function retrieveValue(string envName) -> var
    {
        var value = getenv(envName);
        if value !== false {
            return value;
        } elseif isset this->envVars[envName] {
            return this->envVars[envName];
        }

        let value = null;

        return value;
    }

    /**
     * Parses ENV To Scalar Type If Possible
     *
     * @param string Value To Parse
     * @return mixed
     */
    private function parseValue(var value)
    {
        //Strip Off Wrapping Quotes
        if unlikely strlen(value) > 1 && substr(value, 0, 1) === "\"" && substr(value, -1) === "\"" {
            let value = substr(value, 1, -1);
        }

        //Return Literal Numbers
        if is_numeric(value) {
            //Cannot Do Strict Comparison
            if value != (int) value || strpos(value, '.') !== false {
                return (float) value;
            }

            return (int) value;
        }

        //Convert Specific Types
        switch strtolower(value) {
            case "true":
            case "(true)":
                return true;
            case "false":
            case "(false)":
                return false;
            case "empty":
            case "(empty)":
                return "";
            case "null":
            case "(null)":
                return;
        }

        return value;
    }

    /**
     * Loads Project Overrides
     */
    protected function loadEnvironment() -> <Environment>
    {
        let this->_isLoaded = true;

        return this;
    }
}
