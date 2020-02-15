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

class IsSetAutoVersionCest
{
    /**
     * Unit Tests Phalcon\Assets\Collection :: isAutoVersion() / setAutoVersion()
     *
     * @author Jeremy PASTOURET <https://github.com/jenovateurs>
     * @since  2020-02-15
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
