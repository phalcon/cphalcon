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

namespace Phalcon\Test\Unit\Storage\Adapter\Memory;

use Phalcon\Storage\Adapter\AdapterInterface;
use Phalcon\Storage\Adapter\Memory;
use Phalcon\Storage\SerializerFactory;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Storage\Adapter\Memory :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-09
     */
    public function storageAdapterMemoryConstruct(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Memory - __construct()');

        $serializer = new SerializerFactory();
        $adapter    = new Memory($serializer);

        $class = Memory::class;
        $I->assertInstanceOf($class, $adapter);

        $class = AdapterInterface::class;
        $I->assertInstanceOf($class, $adapter);
    }
}
