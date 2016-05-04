<?php

namespace Phalcon\Test\Proxy\Logger;

use Phalcon\Logger\Multiple as PhMultiple;
use Phalcon\Logger\AdapterInterface;
use Phalcon\Logger\FormatterInterface;

/**
 * \Phalcon\Test\Proxy\Logger\Multiple
 * File proxy class for \Phalcon\Logger\Multiple
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Logger
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Multiple extends PhMultiple
{
    public function getLoggers()
    {
        return parent::getLoggers();
    }

    public function getFormatter()
    {
        return parent::getFormatter();
    }

    public function getLogLevel()
    {
        return parent::getLogLevel();
    }

    public function push(AdapterInterface $logger)
    {
        parent::push($logger);
    }

    public function setFormatter(FormatterInterface $formatter)
    {
        parent::setFormatter($formatter);
    }

    public function setLogLevel($level)
    {
        parent::setLogLevel($level);
    }

    public function log($type, $message = null, array $context = null)
    {
        parent::log($type, $message, $context);
    }

    public function critical($message, array $context = null)
    {
        parent::critical($message, $context);
    }

    public function emergency($message, array $context = null)
    {
        parent::emergency($message, $context);
    }

    public function debug($message, array $context = null)
    {
        parent::debug($message, $context);
    }

    public function error($message, array $context = null)
    {
        parent::error($message, $context);
    }

    public function info($message, array $context = null)
    {
        parent::info($message, $context);
    }

    public function notice($message, array $context = null)
    {
        parent::notice($message, $context);
    }

    public function warning($message, array $context = null)
    {
        parent::warning($message, $context);
    }

    public function alert($message, array $context = null)
    {
        parent::alert($message, $context);
    }
}
