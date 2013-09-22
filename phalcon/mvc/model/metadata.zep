
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Mvc\Model;

/**
 * Phalcon\Mvc\Model\MetaData
 *
 * <p>Because Phalcon\Mvc\Model requires meta-data like field names, data types, primary keys, etc.
 * this component collect them and store for further querying by Phalcon\Mvc\Model.
 * Phalcon\Mvc\Model\MetaData can also use adapters to store temporarily or permanently the meta-data.</p>
 *
 * <p>A standard Phalcon\Mvc\Model\MetaData can be used to query model attributes:</p>
 *
 * <code>
 *	$metaData = new Phalcon\Mvc\Model\MetaData\Memory();
 *	$attributes = $metaData->getAttributes(new Robots());
 *	print_r($attributes);
 * </code>
 *
 */
abstract class MetaData //implements Phalcon\Di\InjectionAwareInterface
{

	protected _dependencyInjector;

	protected _strategy;

	protected _metaData;

	protected _columnMap;

	const MODELS_ATTRIBUTES = 0;

	const MODELS_PRIMARY_KEY = 1;

	const MODELS_NON_PRIMARY_KEY = 2;

	const MODELS_NOT_NULL = 3;

	const MODELS_DATA_TYPES = 4;

	const MODELS_DATA_TYPES_NUMERIC = 5;

	const MODELS_DATE_AT = 6;

	const MODELS_DATE_IN = 7;

	const MODELS_IDENTITY_COLUMN = 8;

	const MODELS_DATA_TYPES_BIND = 9;

	const MODELS_AUTOMATIC_DEFAULT_INSERT = 10;

	const MODELS_AUTOMATIC_DEFAULT_UPDATE = 11;

	const MODELS_COLUMN_MAP = 0;

	const MODELS_REVERSE_COLUMN_MAP = 1;

}
