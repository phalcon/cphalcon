
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di\FactoryDefault;

use Phalcon\Di\Service;
use Phalcon\Di\FactoryDefault;

 /**
 * Phalcon\Di\FactoryDefault\Cli
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework.
 * Thanks to this, the developer does not need to register each service individually.
 * This class is specially suitable for CLI applications
 */
class Cli extends FactoryDefault
{

	/**
	 * Phalcon\Di\FactoryDefault\Cli constructor
	 */
	public function __construct()
	{
		parent::__construct();

		let this->_services = [
			"annotations":        new Service("Phalcon\\Annotations\\Adapter\\Memory", true),
			"dispatcher":         new Service("Phalcon\\Cli\\Dispatcher", true),
			"escaper":            new Service("Phalcon\\Escaper", true),
			"eventsManager":      new Service("Phalcon\\Events\\Manager", true),
			"filter":             new Service("Phalcon\\Filter", true),
			"modelsManager":      new Service("Phalcon\\Mvc\\Model\\Manager", true),
			"modelsMetadata":     new Service("Phalcon\\Mvc\\Model\\MetaData\\Memory", true),
			"router":             new Service("Phalcon\\Cli\\Router", true),
			"security":           new Service("Phalcon\\Security", true),
			"transactionManager": new Service("Phalcon\\Mvc\\Model\\Transaction\\Manager", true)
		];
	}
}
