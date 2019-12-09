<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Storage\Adapter\Apcu;

use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;
use UnitTester;

class GetKeysCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Apcu :: getKeys()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-13
     */
    public function storageAdapterApcuGetKeys(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Apcu - getKeys()');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $adapter->clear();

        $key = 'key-1';
        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);

        $key = 'key-2';
        $adapter->set($key, 'test');
        $actual = $adapter->has($key);
        $I->assertTrue($actual);

        $expected = [
            'ph-apcu-key-1',
            'ph-apcu-key-2',
        ];
        $actual   = $adapter->getKeys();
        sort($actual);
        $I->assertEquals($expected, $actual);
    }
}
