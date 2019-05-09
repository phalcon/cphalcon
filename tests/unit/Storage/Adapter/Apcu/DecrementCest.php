<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Storage\Adapter\Apcu;

use Exception;
use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;
use UnitTester;

/**
 * Class DecrementCest
 */
class DecrementCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Apcu :: decrement()
     *
     * @param UnitTester $I
     *
     * @throws Exception
     * @since  2019-03-31
     *
     * @author Phalcon Team <team@phalconphp.com>
     */
    public function storageAdapterApcuDecrement(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Apcu - decrement()');
        $factory = new SerializerFactory();
        $adapter = new Apcu($factory);

        $key    = uniqid();
        $result = $adapter->set($key, 100);
        $I->assertTrue($result);

        $expected = 99;
        $actual   = $adapter->decrement($key);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);

        $expected = 90;
        $actual   = $adapter->decrement($key, 9);
        $I->assertEquals($expected, $actual);

        $actual = $adapter->get($key);
        $I->assertEquals($expected, $actual);
    }
}
