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

class GetSetJoinCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getJoin() / join()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-15
     */
    public function assetsCollectionGetSetJoin(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getJoin() / join()');

        $collection = new Collection();

        $I->assertTrue($collection->getJoin());

        $collection->join(false);

        $I->assertFalse($collection->getJoin());
    }
}
