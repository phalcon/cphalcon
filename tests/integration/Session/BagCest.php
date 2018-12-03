<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Session;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use ReflectionClass;
use Phalcon\Session\Bag;

class BagCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();

        if (session_status() === PHP_SESSION_NONE) {
            session_start();
        }
    }

    /**
     * executed after each test
     */
    public function _after()
    {
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
    public function testBagGetAndSet(IntegrationTester $I)
    {
        // Using getters and setters
        $bag = new Bag('test1');
        $bag->set('a', ['b' => 'c']);
        $I->assertEquals($bag->get('a'), ['b' => 'c']);
        $I->assertSame($_SESSION['test1']['a'], ['b' => 'c']);

        // Using direct access
        $bag = new Bag('test2');
        $bag->{'a'} = ['b' => 'c'];
        $I->assertEquals($bag->{'a'}, ['b' => 'c']);
        $I->assertSame($_SESSION['test2']['a'], ['b' => 'c']);
    }

    /**
     * Tests write empty array
     *
     * @author Kamil Skowron <kamil@hedonsoftware.com>
     * @since  2015-07-17
     */
    public function testBagSetEmptyArray(IntegrationTester $I)
    {
        $bag    = new Bag('container');
        $value  = [];
        $bag->a = $value;

        $I->assertSame($bag->a, $value);
    }

    /**
     * Delete a value in a bag (not initialized internally)
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12647
     * @author Fabio Mora <mail@fabiomora.com>
     * @since  2017-02-21
     */
    public function shouldDeleteInitializeInternalData(IntegrationTester $I)
    {
        $reflectionClass = new ReflectionClass(Bag::class);
        $_data = $reflectionClass->getProperty('_data');
        $_data->setAccessible(true);
        $initialized = $reflectionClass->getProperty('_initialized');
        $initialized->setAccessible(true);

        // Setup a bag with a value
        $bag = new Bag('fruit');
        $bag->set('apples', 10);

        $I->assertSame($bag->get('apples'), 10);
        $I->assertSame($_data->getValue($bag), ['apples' => 10]);
        $I->assertTrue($initialized->getValue($bag));

        // Emulate a reset of the internal status (e.g. as would be done by a sleep/wakeup handler)
        $serializedBag = serialize($bag);
        unset($bag);

        $bag = unserialize($serializedBag);
        $_data->setValue($bag, null);
        $initialized->setValue($bag, false);

        // Delete
        $I->assertFalse($initialized->getValue($bag));
        $I->assertTrue($bag->remove('apples'));
        $I->assertNull($bag->get('apples'));
        $I->assertTrue($initialized->getValue($bag));
    }
}
