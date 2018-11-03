<?php

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Di\ServiceTest
 * Tests the \Phalcon\Di\Service component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Di
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ServiceTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        require_once PATH_DATA . 'di/SomeService.php';
    }

    /**
     * Tests resolving service
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-29
     */
    public function testResolvingService()
    {
        $this->specify(
            "Di does not resolves service correctly",
            function () {
                $di = new Di();
                $di->set('resolved', function () {
                    return new \SomeService();
                });
                $di->set('notResolved', function () {
                    return new \SomeService();
                });

                expect($di->getService('resolved')->isResolved())->false();
                expect($di->getService('notResolved')->isResolved())->false();

                $di->get('resolved');

                expect($di->getService('resolved')->isResolved())->true();
                expect($di->getService('notResolved')->isResolved())->false();
            }
        );
    }
}
