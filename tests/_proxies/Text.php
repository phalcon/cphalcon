<?php

namespace Phalcon\Test\Proxy;

use Phalcon\Text as PhText;

/**
 * Phalcon\Test\Proxy\Text.php
 * Text proxy class for \Phalcon\Text
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Text extends PhText
{
    public static function camelize($str, $delimiter = null)
    {
        return parent::camelize($str, $delimiter);
    }

    public static function uncamelize($str, $delimiter = null)
    {
        return parent::uncamelize($str, $delimiter);
    }

    public static function increment($str, $separator = "_")
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

    public static function lower($str, $encoding = "UTF-8")
    {
        return parent::lower($str, $encoding);
    }

    public static function upper($str, $encoding = "UTF-8")
    {
        return parent::upper($str, $encoding);
    }

    public static function reduceSlashes($str)
    {
        return parent::reduceSlashes($str);
    }

    public static function concat($separator, $a, $b)
    {
        return call_user_func_array('parent::concat', func_get_args());
    }

    public static function dynamic($text, $leftDelimiter = '{', $rightDelimiter = '}', $separator = '|')
    {
        return parent::dynamic($text, $leftDelimiter, $rightDelimiter, $separator);
    }
}
