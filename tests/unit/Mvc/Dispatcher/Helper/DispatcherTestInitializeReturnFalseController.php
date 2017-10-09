<?php

namespace Phalcon\Test\Unit\Mvc\Dispatcher\Helper;

use Phalcon\Mvc\Controller;

/**
 * \Phalcon\Test\Unit\Mvc\Dispatcher\Helper\DispatcherTestInitializeReturnFalseController
 * Dispatcher Controller for testing different dispatch scenarios
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Mvc\Dispatcher\Helper
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class DispatcherTestInitializeReturnFalseController extends Controller
{
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
    }

    public function initialize()
    {
        $this->trace('initialize-method');

        return false;
    }

    public function afterExecuteRoute()
    {
        $this->trace('afterExecuteRoute-method');
    }

    public function indexAction()
    {
        $this->trace('indexAction');
    }
}
