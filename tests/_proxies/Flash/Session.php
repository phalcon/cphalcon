<?php

namespace Phalcon\Test\Proxy\Flash;

use Phalcon\DiInterface;
use Phalcon\Flash\Session as PhSession;

/**
 * \Phalcon\Test\Proxy\Flash\Session
 * Flash Session proxy class for \Phalcon\Flash\Session
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Flash
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Session extends PhSession
{
    public function message($type, $message)
    {
        parent::message($type, $message);
    }

    public function output($remove = true)
    {
        parent::output($remove);
    }

    public function setImplicitFlush($implicitFlush)
    {
        return parent::setImplicitFlush($implicitFlush);
    }

    public function setAutomaticHtml($automaticHtml)
    {
        return parent::setAutomaticHtml($automaticHtml);
    }

    public function setCssClasses(array $cssClasses)
    {
        return parent::setCssClasses($cssClasses);
    }

    public function error($message)
    {
        return parent::error($message);
    }

    public function notice($message)
    {
        return parent::notice($message);
    }

    public function success($message)
    {
        return parent::success($message);
    }

    public function warning($message)
    {
        return parent::warning($message);
    }

    public function outputMessage($type, $message)
    {
        return parent::outputMessage($type, $message);
    }
}
