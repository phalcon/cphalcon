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
 * Class HasCest
 */
class HasCest
{
    /**
     * Tests Phalcon\Assets\Collection :: has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsCollectionHas(UnitTester $I)
    {
        $I->wantToTest('Assets\Collection - has()');
        $collection = new Collection();

        $asset1 = new Asset('js', 'js/jquery.js');
        $asset2 = new Asset('js', 'js/jquery-ui.js');

        $collection->add($asset1);

        $actual = $collection->has($asset1);
        $I->assertTrue($actual);
        $actual = $collection->has($asset2);
        $I->assertFalse($actual);
    }
}
