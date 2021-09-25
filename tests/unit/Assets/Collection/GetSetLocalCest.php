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

class GetSetLocalCest
{
    /**
     * Tests Phalcon\Assets\Collection :: getLocal() / setLocal()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-15
     */
    public function assetsCollectionGetSetLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getLocal() / setLocal()');

        $collection = new Collection();

        $I->assertTrue($collection->getLocal());

        $collection->setLocal(false);

        $I->assertFalse($collection->getLocal());
    }
}
