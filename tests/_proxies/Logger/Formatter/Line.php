<?php

namespace Phalcon\Test\Proxy\Logger\Formatter;

use Phalcon\Logger\Formatter\Line as PhLine;

/**
 * \Phalcon\Test\Proxy\Logger\Formatter\Line
 * Line Formatter proxy class for \Phalcon\Logger\Formatter\Line
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Logger\Formatter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Line extends PhLine
{
    public function __construct($format = null, $dateFormat = null)
    {
        parent::__construct($format, $dateFormat);
    }

    public function getDateFormat()
    {
        return parent::getDateFormat();
    }

    public function setDateFormat($dateFormat)
    {
        parent::setDateFormat($dateFormat);
    }

    public function getFormat()
    {
        return parent::getFormat();
    }

    public function setFormat($format)
    {
        parent::setFormat($format);
    }

    public function format($message, $type, $timestamp, $context = null)
    {
        return parent::format($message, $type, $timestamp, $context);
    }
}
