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

namespace Phalcon\Test\Unit\Html\TagLocator;

use Phalcon\Html\TagLocator;
use Phalcon\Service\LocatorInterface;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Html\TagLocator :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTaglocatorConstruct(UnitTester $I)
    {
        $I->wantToTest('Html\TagLocator - __construct()');
        $locator = new TagLocator();

        $class = LocatorInterface::class;
        $I->assertInstanceOf($class, $locator);
    }
}
