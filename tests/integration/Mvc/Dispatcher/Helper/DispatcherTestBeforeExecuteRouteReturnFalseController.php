<?php

namespace Phalcon\Test\Integration\Mvc\Dispatcher\Helper;

use Phalcon\Mvc\Controller\AbstractController;

/**
 * \Phalcon\Test\Integration\Mvc\Dispatcher\Helper\DispatcherTestBeforeExecuteRouteReturnFalseController
 * Dispatcher Controller for testing different dispatch scenarios
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          http://www.phalconphp.com
 * @author        Andres Gutierrez <andres@phalconphp.com>
 * @author        Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class DispatcherTestBeforeExecuteRouteReturnFalseController extends AbstractController
{
    public function initialize()
    {
        $this->trace('initialize-method');
    }

    /**
     * Add tracing information into the current dispatch tracer
     */
    protected function trace($text)
    {
        $this->getDI()->getShared('dispatcherListener')->trace($text);
    }

    public function beforeExecuteRoute()
    {
        $this->trace('beforeExecuteRoute-method');

        return false;
    }

    public function indexAction()
    {
        $this->trace('indexAction');
    }
}
