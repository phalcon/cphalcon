<?php
/**
 * Text.php
 * \PhalconTest\Text
 *
 * Text proxy class
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace PhalconTest;

use \Phalcon\Text as PhText;

class Text extends PhText
{
	public static function camelize($str)
	{
		return parent::camelize($str);
	}

	public static function uncamelize($str)
	{
		return parent::uncamelize($str);
	}

	public static function increment($str, $separator = null)
	{
		return parent::increment($str, $separator);
	}

	public static function random($type = 0, $length = 8)
	{
		return parent::random($type, $length);
	}

	public static function startsWith($str, $start, $ignoreCase = true)
	{
		return parent::startsWith($str, $start, $ignoreCase);
	}

	public static function endsWith($str, $end, $ignoreCase = true)
	{
		return parent::endsWith($str, $end, $ignoreCase);
	}

	public static function lower($str)
	{
		return parent::lower($str);
	}

	public static function upper($str)
	{
		return parent::upper($str);
	}

	public static function reduceSlashes($str)
	{
		return parent::reduceSlashes($str);
	}

	public static function concat($separator, $a, $b)
	{
		return call_user_func_array('parent::concat', func_get_args());
	}
}
