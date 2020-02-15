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

namespace Phalcon\Test\Unit\Assets\Collection;

use Phalcon\Assets\Collection;
use UnitTester;

class GetSetTargetLocalCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getTargetLocal() / setTargetLocal()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-15
     */
    public function assetsCollectionGetSetTargetLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getTargetLocal() / setTargetLocal()');

        $collection = new Collection();

        $I->assertEquals(true, $collection->getTargetLocal());

        $collection->setTargetLocal(false);

        $I->assertEquals(false, $collection->getTargetLocal());
    }
}
