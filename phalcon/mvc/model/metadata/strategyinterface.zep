
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Model\MetaData;

use Phalcon\Mvc\ModelInterface;
use Phalcon\DiInterface;

interface StrategyInterface
{
	/**
	 * The meta-data is obtained by reading the column descriptions from the database information schema
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param Phalcon\DiInterface dependencyInjector
	 * @return array
	 */
	public function getMetaData(<ModelInterface> model, <DiInterface> dependencyInjector);

	/**
	 * Read the model's column map, this can't be inferred
	 *
	 * @param Phalcon\Mvc\ModelInterface model
	 * @param Phalcon\DiInterface dependencyInjector
	 * @return array
	 * @todo Not implemented
	 */
	public function getColumnMaps(<ModelInterface> model, <DiInterface> dependencyInjector);

}
