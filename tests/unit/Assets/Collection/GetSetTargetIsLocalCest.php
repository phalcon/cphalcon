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
 * Class GetSetTargetLocalCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class GetSetTargetIsLocalCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getTargetIsLocal()/setTargetIsLocal()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionGetSetTargetIsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getTargetIsLocal()/setTargetIsLocal()');

        $collection = new Collection();
        $I->assertEquals(true, $collection->getTargetIsLocal());

        $collection->setTargetIsLocal(false);
        $I->assertEquals(false, $collection->getTargetIsLocal());
    }
}
