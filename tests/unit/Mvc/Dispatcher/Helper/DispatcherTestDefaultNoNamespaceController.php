<?php

// @codingStandardsIgnoreStart
use Phalcon\Mvc\Controller;
// @codingStandardsIgnoreSEnd

/**
 * \DispatcherTestDefaultNoNamespaceController
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
class DispatcherTestDefaultNoNamespaceController extends Controller
{
    const RETURN_VALUE_STRING = 'string';
    const RETURN_VALUE_INT = 5;

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
    }

    public function indexAction()
    {
        $this->trace('indexAction');
    }

    public function index2Action()
    {
        $this->trace('index2Action');
    }

    public function forwardLocalAction()
    {
        $this->trace('forwardLocalAction');
        $this->getDI()->getShared('dispatcher')->forward([
            'action' => 'index2'
        ]);
    }

    public function forwardExternalAction()
    {
        $this->trace('forwardExternalAction');
        $this->getDI()->getShared('dispatcher')->forward([
            'namespace' => 'Phalcon\Test\Unit\Mvc\Dispatcher\Helper',
            'controller' => 'dispatcher-test-default',
            'action' => 'index'
        ]);
    }

    public function exceptionAction()
    {
        $this->trace('exceptionAction');
        throw new Exception('An exception occurred.');
    }

    public function afterExecuteRoute()
    {
        $this->trace('afterExecuteRoute-method');
    }
}
