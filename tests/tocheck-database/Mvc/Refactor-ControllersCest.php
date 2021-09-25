<?php

namespace Phalcon\Tests\Integration\Mvc;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Tests\Controllers\ViewRequestController;

/**
 * \Phalcon\Tests\Integration\Mvc\ControllerCest
 * Tests the Phalcon\Mvc\Controller component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          http://www.phalcon.io
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Phalcon Team <team@phalcon.io>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalcon.io
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
     */
    public function _before(IntegrationTester $I)
    {
        Di::setDefault(
            $I->getApplication()->getDI()
        );

        $this->modelsManager = $I->getApplication()->getDI()->getShared('modelsManager');

        $I->addServiceToContainer(
            'modelsMetadata',
            function () {
                return new Memory();
            },
            true
        );
    }

    public function testControllers(IntegrationTester $I)
    {
        $di = Di::getDefault();

        $controller = new ViewRequestController();

        $controller->setDI($di);

        $view = $di->getShared('view');

        $_POST['email'] = ';ans@ecom.com';

        $I->assertEquals(
            'ans@ecom.com',
            $controller->requestAction()
        );

        $controller->viewAction();

        $I->assertCount(
            1,
            $view->getParamsToView()
        );
    }
}
