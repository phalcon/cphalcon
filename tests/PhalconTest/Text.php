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
    static public function camelize($str)
	{
		return parent::camelize($str);
	}

    static public function uncamelize($str)
	{
        return parent::uncamelize($str);
	}

	static public function increment($str, $separator = null)
	{
        return parent::increment($str, $separator);
	}

	static public function random($type = 0, $length = 8)
	{
        return parent::random($type, $length);
	}

	static public function startsWith($str, $start, $ignoreCase = true)
	{
        return parent::startsWith($str, $start, $ignoreCase);
    }

	static public function endsWith($str, $end, $ignoreCase = true)
	{
        return parent::endsWith($str, $end, $ignoreCase);
    }

	static public function lower($str)
	{
        return parent::lower($str);
    }

	static public function upper($str)
	{
        return parent::upper($str);
    }
}
