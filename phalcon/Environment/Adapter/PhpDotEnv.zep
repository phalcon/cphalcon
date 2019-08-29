namespace Phalcon\Environment\Adapter;

use DotEnv\DotEnv;
use Phalcon\Di\DiInterface;
use Phalcon\Environment;
use RuntimeException;

/**
 * Phalcon\Environment\Adapter\PhpDotEnv is a component that leverages the vlucas/phpdotenv package to load
 * environment configs from a .env file.
 *
 * A service of "DotEnv\DotEnv" must be registered in the DIC for this component to work.
 *
 *```php
 * use DotEnv\DotEnv
 * use Phalcon\Di
 * use Phalcon\Environment\Adapter\PhpDotEnv;
 *
 * $di = new Di();
 * $di->set(DotEnv::class, function () {
 *    return DotEnv::create(__DIR__);
 * });
 *
 * $env = new Environment();
 * $env->setDi($di);
 *
 * $var = $env->getValue("ABC", "blah");
 *```
 */
class PhpDotEnv extends Environment
{
    public function __construct()
    {
        if unlikely !class_exists("DotEnv\\DotEnv") {
            throw new RuntimeException("Missing Required Composer Plugin vlucas/phpdotenv");
        }
    }

    protected function retrieveValue(string envName) -> var
    {
        var value;

        let value = parent::retrieveValue(envName);

        if likely value === null {
            let value = this->getService()->getEnvironmentVariable(envName);
        }

        return value;
    }

    private function getService() -> <DotEnv>
    {
        if unlikely !this->getDi()->has("DotEnv\\DotEnv") {
            throw new RuntimeException("Missing Required Service DotEnv\\DotEnv");
        }

        return this->getDi()->get("DotEnv\\DotEnv");
    }
}
