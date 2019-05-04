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

namespace Phalcon\Test\Unit\Storage\SerializerLocator;

use Phalcon\Service\LocatorInterface;
use Phalcon\Storage\SerializerLocator;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Storage\SerializerLocator :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-04
     */
    public function storageSerializerLocatorConstruct(UnitTester $I)
    {
        $I->wantToTest('Storage\SerializerLocator - __construct()');

        $locator = new SerializerLocator();

        $class = LocatorInterface::class;
        $I->assertInstanceOf($class, $locator);
    }
}
