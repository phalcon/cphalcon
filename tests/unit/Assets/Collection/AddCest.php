<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Assets\Collection;

use Phalcon\Assets\Asset;
use Phalcon\Assets\Collection;
use UnitTester;

/**
 * Class AddCest
 */
class AddCest
{
    /**
     * Tests Phalcon\Assets\Collection :: add()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsCollectionAdd(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - add()');
        $collection = new Collection();

        $collection->add(new Asset('js', 'js/jquery.js'));
        $collection->add(new Asset('js', 'js/jquery-ui.js'));

        $number   = 0;
        $expected = 'js';
        foreach ($collection as $asset) {
            $actual = $asset->getType();
            $I->assertEquals($expected, $actual);
            $number++;
        }

        $expected = 2;
        $actual   = $number;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Collection :: add() - duplicate
     *
     * @param UnitTester $I
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10938
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-06-02
     */
    public function assetsCollectionAddDuplicate(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - add()');
        $collection = new Collection();

        for ($i = 0; $i < 10; $i++) {
            $collection->add(new Asset('js', 'js/jquery.js'));
            $collection->add(new Asset('js', 'js/jquery-ui.js'));
        }

        $expected = 2;
        $actual   = count($collection->getAssets());
        $I->assertEquals($expected, $actual);
    }
}
