<?php
/**
 * Multiple.php
 * \PhalconTest\Logger\Multiple
 *
 * Logger\Multiple proxy class
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

namespace PhalconTest\Logger;

use \Phalcon\Logger\Multiple as PhMultiple;

class Multiple
{
    protected $multiple = null;

    public function __construct()
    {
        $this->multiple = new PhMultiple();
    }

    public function __desctruct()
    {
        unset($this->multiple);
    }

    protected function getLoggers()
	{
		return $this->multiple->getLoggers();
	}

    protected function getFormatter()
	{
		return $this->multiple->getFormatter();
	}

	public function push($logger)
	{
        $this->multiple->push($logger);
	}

	public function setFormatter($formatter)
	{
        $this->multiple->setFormatter($formatter);
	}

	public function log($message, $type = 7)
	{
        $this->multiple->log($message, $type);
	}

	public function emergency($message)
	{
        $this->multiple->emergency($message);
	}

	public function debug($message)
	{
        $this->multiple->debug($message);
	}

	public function error($message)
	{
        $this->multiple->error($message);
	}

	public function info($message)
	{
        $this->multiple->info($message);
	}

	public function notice($message)
	{
        $this->multiple->notice($message);
	}

	public function warning($message)
	{
        $this->multiple->warning($message);
	}

	public function alert($message)
	{
        $this->multiple->alert($message);
	}
}
