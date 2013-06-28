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
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Test;

use \Phalcon\Mvc\Dispatcher as PhDispatcher;
use \Phalcon\Escaper as PhEscaper;

abstract class FunctionalTestCase extends ModelTestCase
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
        $this->di->set(
            'dispatcher',
            function () {
                $dispatcher = new PhDispatcher();
                $dispatcher->setControllerName('test');
                $dispatcher->setActionName('empty');
                $dispatcher->setParams(array());
                return $dispatcher;
            }
        );

        $this->di->set(
            'escaper',
            function () {
                return new PhEscaper();
            }
        );
    }
}