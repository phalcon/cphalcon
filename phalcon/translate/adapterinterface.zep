
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

namespace Phalcon\Translate;

/**
 * Phalcon\Translate\AdapterInterface
 *
 * Interface for Phalcon\Translate adapters
 */
interface AdapterInterface
{

	/**
	 * Phalcon\Translate\Adapter\NativeArray constructor
	 *
	 * @param array options
	 */
	public function __construct(options);

	/**
	 * Returns the translation string of the given key
	 *
	 * @param	string translateKey
	 * @param	array placeholders
	 * @return	string
	 */
	public function t(translateKey, placeholders=null);

	/**
	 * Returns the translation related to the given key
	 *
	 * @param	string index
	 * @param	array placeholders
	 * @return	string
	 */
	public function query(index, placeholders=null);

	/**
	 * Check whether is defined a translation key in the internal array
	 *
	 * @param 	string index
	 * @return	bool
	 */
	public function exists(index);

}
