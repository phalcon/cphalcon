<?php
/**
 * Stream.php
 * \PhalconTest\Logger\Adapter\Stream
 *
 * Logger\Adapter\Stream proxy class
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

namespace PhalconTest\Logger\Adapter;

use \Phalcon\Logger\Adapter\Stream as PhLoggerStream;
use \PhalconTest\Logger\Adapter as PhTAdapter;

class Stream extends PhTAdapter
{
    public function __construct($name, $options = null)
	{
        $this->adapter = new PhLoggerStream($name, $options);
	}

	public function getFormatter()
	{
        return $this->adapter->getFormatter();
	}

	public function logInternal($message, $type, $time, $context)
	{
        $this->adapter->logInternal($message, $type, $time, $context);
	}

	public function close()
	{
        return $this->adapter->close();
	}
}
