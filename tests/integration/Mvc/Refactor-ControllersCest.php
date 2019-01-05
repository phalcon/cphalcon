<?php

namespace Phalcon\Test\Integration\Mvc;

use IntegrationTester;
use Phalcon\Di;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\Metadata\Memory;
use Phalcon\Test\Controllers\ViewRequestController;
use Test4Controller;

/**
 * \Phalcon\Test\Integration\Mvc\ControllerCest
 * Tests the Phalcon\Mvc\Controller component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          http://www.phalconphp.com
 * @author        Andres Gutierrez <andres@phalconphp.com>
 * @author        Phalcon Team <team@phalconphp.com>
 * @package       Phalcon\Test\Integration\Mvc
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
        $controller = new ViewRequestController();
        $controller->setDI(Di::getDefault());

        $view = Di::getDefault()->getShared('view');

        $_POST['email'] = ';ans@ecom.com';
        $I->assertEquals($controller->requestAction(), 'ans@ecom.com');

        $controller->viewAction();
        $I->assertEquals(count($view->getParamsToView()), 1);
    }
}
