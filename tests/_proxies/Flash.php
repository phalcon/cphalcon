<?php

namespace Phalcon\Test\Proxy;

use Phalcon\DiInterface;
use Phalcon\EscaperInterface;
use Phalcon\Flash as PhFlash;

/**
 * \Phalcon\Test\Proxy\Flash
 * Flash proxy class for \Phalcon\Flash
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
abstract class Flash extends PhFlash
{
    public function __construct($cssClasses = null)
    {
        parent::__construct($cssClasses);
    }

    public function getAutoescape()
    {
        return parent::getAutoescape();
    }

    public function setAutoescape($autoescape)
    {
        return parent::setAutoescape($autoescape);
    }

    public function getEscaperService()
    {
        return parent::getEscaperService();
    }

    public function setEscaperService(EscaperInterface $escaperService)
    {
        return parent::setEscaperService($escaperService);
    }

    public function setDI(DiInterface $dependencyInjector)
    {
        return parent::setDI($dependencyInjector);
    }

    public function getDI()
    {
        return parent::getDI();
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

    public function clear()
    {
        parent::clear();
    }
}
