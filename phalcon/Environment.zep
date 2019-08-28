namespace Phalcon;

use Exception;
use Phalcon\Di\Injectable;
use RuntimeException;

/**
 * Environment Class To Retrieve Environment Variables (IE: getenv).
 *
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
