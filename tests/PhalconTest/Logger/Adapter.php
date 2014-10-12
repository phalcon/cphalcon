<?php
/**
 * Adapter.php
 * \PhalconTest\Logger\Adapter
 *
 * Logger\Adapter proxy class
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

class Adapter
{
    protected $adapter = null;

    public function __desctruct()
    {
        unset($this->adapter);
    }

    public function setLogLevel($level)
	{
		return $this->adapter->setLogLevel($level);
	}

    public function getLogLevel()
	{
        return $this->adapter->getLogLevel();
	}

	public function setFormatter($formatter)
	{
        return $this->adapter->setFormatter($formatter);
	}

	public function begin()
	{
        return $this->adapter->begin();
	}

	public function commit()
	{
        return $this->adapter->commit();
	}

	public function rollback()
	{
        return $this->adapter->rollback();
	}

	public function emergency($message, $context = null)
	{
        return $this->adapter->emergency($message, $context);
	}

	public function debug($message, $context = null)
	{
        return $this->adapter->debug($message, $context);
	}

	public function error($message, $context = null)
	{
        return $this->adapter->error($message, $context);
	}

	public function info($message, $context = null)
	{
        return $this->adapter->info($message, $context);
	}

	public function notice($message, $context = null)
	{
        return $this->adapter->notice($message, $context);
	}

	public function warning($message, $context = null)
	{
        return $this->adapter->warning($message, $context);
	}

	public function alert($message, $context = null)
	{
        return $this->adapter->alert($message, $context);
	}

	public function log($type, $message = null, $context = null)
	{
        return $this->adapter->log($type, $message, $context);
	}
}
