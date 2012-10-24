<?php
/**
 * TestController.php
 * apps\controllers\TestController
 *
 * Helps with testing components that require controllers
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

class TestController extends Phalcon\Mvc\Controller {

    public function beforeDispatch()
    {
        return false;
    }

    public function indexAction(){
        return 'index';
    }

    public function emptyAction(){

    }

    public function returnIntegerAction(){
        return 100;
    }

    public function twoParametersAction($a, $b){
        return $a+$b;
    }

    public function forwardingAction(){
        return $this->dispatcher->forward(array('controller' => 'test2', 'action' => 'anotherfour'));
    }

    public function returnParametersAction(){
        return $this->dispatcher->getParam('param1')+$this->dispatcher->getParam('param2');
    }

    public function setViewVarsAction()
    {
        $this->view->setVar("a_cool_var", "got-the-life");
    }

    public function databaseQuerySetViewVarsAction()
    {
        $robot = Robots::findFirst();
        $this->view->setVar("name", $robot->name);
    }

    public function getPostVariableAction()
    {
        return $this->request->getPost('email', 'email');
    }

    public function setParameterToViewAction()
    {
        return $this->view->setParamToView('born', 'this');
    }

    public function notFoundAction()
    {
        return 'not-found';
    }
}