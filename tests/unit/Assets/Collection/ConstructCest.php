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

namespace Phalcon\Tests\Unit\Assets\Collection;

use Phalcon\Assets\Collection;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Collection :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionConstruct(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - __construct()');

        $collection = new Collection();
        $I->assertInstanceOf(Collection::class, $collection);
    }
}
