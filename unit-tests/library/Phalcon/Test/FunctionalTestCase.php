<?php
/**
 * FunctionalTestCase.php
 * Phalcon_Test_FunctionalTestCase
 *
 * Functional Test Helper
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

class Phalcon_Test_FunctionalTestCase extends Phalcon_Test_ModelTestCase
{
    /**
     * Sets the test up by loading the DI container and other stuff
     *
     * @return Phalcon\DI
     */
    protected function setUp()
    {
        parent::setUp();

        // Set the dispatcher
        $this->_di->set('dispatcher', function() {
            $dispatcher = new \Phalcon\Mvc\Dispatcher();
            $dispatcher->setControllerName('test');
            $dispatcher->setActionName('empty');
            $dispatcher->setParams(array());
            return $dispatcher;
        });
    }
}