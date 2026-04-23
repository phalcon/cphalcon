<?php // phpcs:disable PSR1.Classes.ClassDeclaration.MissingNamespace

use Phalcon\Mvc\Controller;

/**
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Nikolaos Dimopoulos <nikos@phalcon.io>
 */
class DispatcherTestDefaultNoNamespaceController extends Controller
{
    public const RETURN_VALUE_INT    = 5;
    public const RETURN_VALUE_STRING = 'string';

    public function afterExecuteRoute()
    {
        $this->trace('afterExecuteRoute-method');
    }

    public function beforeExecuteRoute()
    {
        $this->trace('beforeExecuteRoute-method');
    }

    public function exceptionAction()
    {
        $this->trace('exceptionAction');

        throw new Exception('An exception occurred.');
    }

    public function forwardExternalAction()
    {
        $this->trace('forwardExternalAction');

        $di = $this->getDI();

        $dispatcher = $di->getShared('dispatcher');

        $dispatcher->forward(
            [
                'namespace'  => 'Phalcon\Tests\Unit\Mvc\Dispatcher\Helper',
                'controller' => 'dispatcher-test-default',
                'action'     => 'index',
            ]
        );
    }

    public function forwardLocalAction()
    {
        $this->trace('forwardLocalAction');

        $di = $this->getDI();

        $dispatcher = $di->getShared('dispatcher');

        $dispatcher->forward(
            [
                'action' => 'index2',
            ]
        );
    }

    public function index2Action()
    {
        $this->trace('index2Action');
    }

    public function indexAction()
    {
        $this->trace('indexAction');
    }

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
}
