<?php

namespace Phalcon\Test\Unit\Session;

use ReflectionClass;
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
 * bundled with this package in the file LICENSE.txt
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
        parent::_before();

        FactoryDefault::reset();
        new FactoryDefault;

        if (session_status() === PHP_SESSION_NONE) {
            session_start();
        }
    }

    /**
     * executed after each test
     */
    protected function _after()
    {
        parent::_after();

        if (session_status() === PHP_SESSION_ACTIVE) {
            session_destroy();
        }
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

                expect($bag->a)->same($value);
            }
        );
    }

    /**
     * Delete a value in a bag (not initialized internally)
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12647
     * @author Fabio Mora <mail@fabiomora.com>
     * @since  2017-02-21
     */
    public function shouldDeleteInitializeInternalData()
    {
        $this->specify(
            "Delete a value in a non initialized bag has failed",
            function () {
                $reflectionClass = new ReflectionClass(Bag::class);
                $_data = $reflectionClass->getProperty('_data');
                $_data->setAccessible(true);
                $_initialized = $reflectionClass->getProperty('_initialized');
                $_initialized->setAccessible(true);

                // Setup a bag with a value
                $bag = new Bag('fruit');
                $bag->set('apples', 10);

                expect($bag->get('apples'))->same(10);
                expect($_data->getValue($bag))->same(['apples' => 10]);
                expect($_initialized->getValue($bag))->true();

                // Emulate a reset of the internal status (e.g. as would be done by a sleep/wakeup handler)
                $serializedBag = serialize($bag);
                unset($bag);

                $bag = unserialize($serializedBag);
                $_data->setValue($bag, null);
                $_initialized->setValue($bag, false);

                // Delete
                expect($_initialized->getValue($bag))->false();
                expect($bag->remove('apples'))->true();
                expect($bag->get('apples'))->null();
                expect($_initialized->getValue($bag))->true();
            }
        );
    }
}
