<?php
/**
 * Syslog.php
 * \PhalconTest\Logger\Formatter\Syslog
 *
 * Logger\Formatter\Syslog proxy class
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

namespace PhalconTest\Logger\Formatter;

use \Phalcon\Logger\Formatter\Syslog as PhFormatterSyslog;
use \PhalconTest\Logger\Formatter as PhTFormatter;

class Syslog extends PhTFormatter
{
    private $formatter = null;

    public function __construct()
	{
        $this->formatter = new PhFormatterSyslog();
	}

    public function __destruct()
    {
        unset($this->formatter);
    }

	public function format($message, $type, $timestamp, $context = null)
	{
	    return $this->formatter->format($message, $type, $timestamp, $context);
	}
}
