<?php

namespace Phalcon\Test\Unit\Session;

use Phalcon\Session\Bag;
use Phalcon\DI\FactoryDefault;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Session\BagTest
 * Tests the \Phalcon\Session\Bag component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Session
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class BagTest extends UnitTest
{
    /**
     * executed before each test
     */
    protected function _before()
    {
        FactoryDefault::reset();
        new FactoryDefault;
    }

    /**
     * Tests read and write
     *
     * @author Kamil Skowron <kamil@hedonsoftware.com>
     * @since  2015-07-17
     */
    public function testBagGetAndSet()
    {
        $this->specify(
            "Session bag incorrectly handling writing and reading",
            function () {
                @session_start();

                // Using getters and setters
                $bag = new Bag('test1');
                $bag->set('a', ['b' => 'c']);
                expect($bag->get('a'))->equals(['b' => 'c']);
                expect($_SESSION['test1']['a'])->same(['b' => 'c']);

                // Using direct access
                $bag = new Bag('test2');
                $bag->{'a'} = ['b' => 'c'];
                expect($bag->{'a'})->equals(['b' => 'c']);
                expect($_SESSION['test2']['a'])->same(['b' => 'c']);

                @session_destroy();
            }
        );
    }

    /**
     * Tests write empty array
     *
     * @author Kamil Skowron <kamil@hedonsoftware.com>
     * @since  2015-07-17
     */
    public function testBagSetEmptyArray()
    {
        $this->specify(
            "Setting an empty array to Session Bag do not return the same",
            function () {
                $bag    = new Bag('container');
                $value  = [];
                $bag->a = $value;

                expect($bag->a)->same([]);
            }
        );
    }
}
