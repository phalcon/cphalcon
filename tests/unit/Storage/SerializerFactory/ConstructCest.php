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

namespace Phalcon\Test\Unit\Storage\SerializerFactory;

use Phalcon\Storage\SerializerFactory;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Storage\SerializerFactory :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-04
     */
    public function storageSerializerFactoryConstruct(UnitTester $I)
    {
        $I->wantToTest('Storage\SerializerFactory - __construct()');

        $service = new SerializerFactory();
        $I->assertInstanceOf(SerializerFactory::class, $service);
    }
}
