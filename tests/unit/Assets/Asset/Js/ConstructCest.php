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

namespace Phalcon\Test\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

class ConstructCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset\Js :: __construct() - local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - local');
        $asset = new Js('js/jquery.js');

        $actual = $asset->getLocal();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: __construct() - remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - remote');
        $asset = new Js('js/jquery.js', false);
        // ( bool filter = true, array attributes = [])


        $actual = $asset->getLocal();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: __construct() - filter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter');
        $asset = new Js('js/jquery.js');

        $actual = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: __construct() - filter set
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter set');
        $asset = new Js('js/jquery.js', true, false);

        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: __construct() - attributes
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - attributes');
        $asset = new Js('js/jquery.js');

        $expected = [];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: __construct() - attributes set
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - attributes set');
        $asset = new Js('js/jquery.js', true, true, ['data' => 'phalcon']);

        $expected = ['data' => 'phalcon'];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }
}
