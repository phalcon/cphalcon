<?php

namespace Phalcon\Test\Integration\Mvc;

use Phalcon\Di;
use Phalcon\Test\Integration\Mvc\Model\BinderCest;
use Test4Controller;
use IntegrationTester;
use Phalcon\Mvc\Dispatcher;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Test\Models\People;
use Phalcon\Mvc\Model\Metadata\Memory;

/**
 * \Phalcon\Test\Integration\Mvc\ControllerCest
 * Tests the Phalcon\Mvc\Controller component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Integration\Mvc
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ControllersCest
{
    /**
     * @var Manager
     */
    private $modelsManager;

    /**
     * Executed before each test
     *
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        Di::setDefault($I->getApplication()->getDI());

        $this->modelsManager = $I->getApplication()->getDI()->getShared('modelsManager');

        $I->haveServiceInDi('modelsMetadata', function () {
            return new Memory;
        }, true);
    }

    public function testControllers(IntegrationTester $I)
    {
        $controller = new Test4Controller;
        $controller->setDI(Di::getDefault());

        $view = Di::getDefault()->getShared('view');

        $_POST['email'] = ';ans@ecom.com';
        $I->assertEquals($controller->requestAction(), 'ans@ecom.com');

        $controller->viewAction();
        $I->assertEquals(count($view->getParamsToView()), 1);
    }

    /**
     * @todo Remove in 4.0.0
     * @see BinderCest::testDispatcher()
     * @param IntegrationTester $I
     */
    public function testModelBinding(IntegrationTester $I)
    {
        $dispatcher = new Dispatcher;
        $dispatcher->setModelBinding(true);
        $dispatcher->setDI(Di::getDefault());

        $I->assertInstanceOf('Phalcon\Di', $dispatcher->getDI());
        $I->haveServiceInDi('dispatcher', $dispatcher);

        // Model to test with
        $model = People::findFirst();

        $dispatcher->setControllerName('test10');
        $dispatcher->setActionName('view');
        $dispatcher->setParams([$model->cedula]);

        $dispatcher->dispatch();

        $I->assertInstanceOf('Phalcon\Test\Models\People', $dispatcher->getReturnedValue());
        $I->assertEquals($model->cedula, $dispatcher->getReturnedValue()->cedula);

        // Reset dispatcher
        $dispatcher = new Dispatcher;
        $dispatcher->setDI(Di::getDefault());

        $I->assertInstanceOf('Phalcon\Di', $dispatcher->getDI());
        $I->haveServiceInDi('dispatcher', $dispatcher);

        $dispatcher->setControllerName('test9');
        $dispatcher->setActionName('view');
        $dispatcher->setParams([$model->cedula]);

        try {
            $dispatcher->dispatch();

            $I->assertTrue(
                false,
                'Here must be the exception about passing non model to the controller action'
            );
        } catch (\Exception $e) {
            // PHP 5.x
            $I->assertEquals(
                'Argument 1 passed to Test9Controller::viewAction() must be an instance of Phalcon\Mvc\Model, string given',
                $e->getMessage()
            );
        } catch (\TypeError $e) {
            // PHP 7.x
            $I->assertEquals(
                'Argument 1 passed to Test9Controller::viewAction() must be an instance of Phalcon\Mvc\Model, string given',
                $e->getMessage()
            );
        }

        $dispatcher->setModelBinding(true);
        $dispatcher->dispatch();

        $I->assertInstanceOf('Phalcon\Test\Models\People', $dispatcher->getReturnedValue());
        $I->assertEquals($dispatcher->getReturnedValue()->cedula, $model->cedula);
    }
}
