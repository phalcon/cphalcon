namespace Phalcon\Environment\Adapter;

use DotEnv\DotEnv;
use Phalcon\Di\DiInterface;
use Phalcon\Environment;
use RuntimeException;

class PhpDotEnv extends Environment
{
    public function __construct()
    {
        if unlikely !class_exists("DotEnv\\DotEnv") {
            throw new RuntimeException("Missing Required Composer Plugin vlucas/phpdotenv");
        }
    }

    private function getService() -> <DotEnv>
    {
        if unlikely !this->getDi()->has("DotEnv\\DotEnv") {
            throw new RuntimeException("Missing Required Service DotEnv\\DotEnv");
        }

        return this->getDi()->get("DotEnv\\DotEnv");
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
}
