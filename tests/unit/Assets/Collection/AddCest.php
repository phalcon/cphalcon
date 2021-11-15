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

use Phalcon\Assets\Asset;
use Phalcon\Assets\Collection;
use UnitTester;

/**
 * Class AddCest
 *
 * @package Phalcon\Tests\Unit\Assets\Collection
 */
class AddCest
{
    /**
     * Tests Phalcon\Assets\Collection :: add()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionAdd(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - add()');

        $collection = new Collection();
        $collection->add(new Asset('js', 'js/jquery.js'));
        $collection->add(new Asset('js', 'js/jquery-ui.js'));

        $expected = 'js';
        foreach ($collection as $asset) {
            $actual = $asset->getType();
            $I->assertEquals($expected, $actual);
        }

        $I->assertCount(2, $collection);
    }

    /**
     * Tests Phalcon\Assets\Collection :: add() - duplicate
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10938
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsCollectionAddDuplicate(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - add() - duplicate');

        $collection = new Collection();

        for ($counter = 0; $counter < 10; $counter++) {
            $collection->add(new Asset('js', 'js/jquery.js'));
            $collection->add(new Asset('js', 'js/jquery-ui.js'));
        }

        $I->assertCount(2, $collection->getAssets());
    }
}
