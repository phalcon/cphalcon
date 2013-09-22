
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
 * Phalcon\Mvc\Model\Relation
 *
 * This class represents a relationship between two models
 */
class Relation //implements Phalcon\Mvc\Model\RelationInterface
{

	protected _type;

	protected _referencedModel;

	protected _fields;

	protected _referencedFields;

	protected _intermediateModel;

	protected _intermediateFields;

	protected _intermediateReferencedFields;

	protected _options;

	const BELONGS_TO = 0;

	const HAS_ONE = 1;

	const HAS_MANY = 2;

	const HAS_ONE_THROUGH = 3;

	const HAS_MANY_THROUGH = 4;

	const NO_ACTION = 0;

	const ACTION_RESTRICT = 1;

	const ACTION_CASCADE = 2;

}