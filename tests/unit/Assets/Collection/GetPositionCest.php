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

class GetPositionCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getPosition()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-15
     */
    public function assetsCollectionGetPosition(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getPosition()');

        $collection = new Collection();

        $I->assertEquals(0, $collection->getPosition());

        $collection->next();

        $I->assertEquals(1, $collection->getPosition());

        $collection->rewind();

        $I->assertEquals(0, $collection->getPosition());
    }
}
