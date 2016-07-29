<?php

namespace Phalcon\Test\Proxy\Flash;

use Phalcon\Flash\Direct as PhDirect;

/**
 * \Phalcon\Test\Proxy\Flash\Direct
 * Flash Direct proxy class for \Phalcon\Flash\Direct
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
class Direct extends PhDirect
{
    public function setImplicitFlush($implicitFlush)
    {
        return parent::setImplicitFlush($implicitFlush);
    }

    public function setAutomaticHtml($automaticHtml)
    {
        parent::setAutomaticHtml($automaticHtml);
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

    public function message($type, $message)
    {
        return parent::message($type, $message);
    }
}
