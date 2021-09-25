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

class KeyNextRewindCest
{
    /**
     * Tests Phalcon\Assets\Collection :: key() / next() / rewind()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-15
     */
    public function assetsCollectionKeyNextRewind(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - key() / next() / rewind()');

        $collection = new Collection();

        $I->assertEquals(0, $collection->key());

        $collection->next();

        $I->assertEquals(1, $collection->key());

        $collection->rewind();

        $I->assertEquals(0, $collection->key());
    }
}
