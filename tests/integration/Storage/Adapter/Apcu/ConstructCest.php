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

namespace Phalcon\Test\Integration\Storage\Adapter\Apcu;

use Phalcon\Storage\Adapter\AdapterInterface;
use Phalcon\Storage\Adapter\Apcu;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Test\Fixtures\Traits\ApcuTrait;
use UnitTester;

class ConstructCest
{
    use ApcuTrait;

    /**
     * Tests Phalcon\Storage\Adapter\Apcu :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-09
     */
    public function storageAdapterApcuConstruct(UnitTester $I)
    {
        $I->wantToTest('Storage\Adapter\Apcu - __construct()');

        $serializer = new SerializerFactory();
        $adapter    = new Apcu($serializer);

        $class = Apcu::class;
        $I->assertInstanceOf($class, $adapter);

        $class = AdapterInterface::class;
        $I->assertInstanceOf($class, $adapter);
    }
}
