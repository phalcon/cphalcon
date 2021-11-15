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
 * Class IsSetAutoVersionCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class IsSetAutoVersionCest
{
    /**
     * Unit Tests Phalcon\Assets\Collection :: isAutoVersion() /
     * setAutoVersion()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionIsSetAutoVersion(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - isAutoVersion() / setAutoVersion()');

        $collection = new Collection();
        $I->assertFalse($collection->isAutoVersion());

        $collection->setAutoVersion(true);
        $I->assertTrue($collection->isAutoVersion());
    }
}
