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
 * Class GetSetVersionCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class GetSetVersionCest
{
    /**
     * Unit Tests Phalcon\Assets\Collection :: getVersion() / setVersion()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionGetSetVersion(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - getVersion() / setVersion()');

        $collection = new Collection();
        $version    = '1.0';
        $collection->setVersion($version);

        $I->assertEquals($version, $collection->getVersion());
    }
}
