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

namespace Phalcon\Test\Unit\Assets\Asset\Css;

use Phalcon\Assets\Asset\Css;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - local');
        $asset = new Css('css/docs.css');

        $actual = $asset->getLocal();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - remote');
        $asset = new Css('css/docs.css', false);
        // ( bool filter = true, array attributes = [])


        $actual = $asset->getLocal();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - filter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter');
        $asset = new Css('css/docs.css');

        $actual = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - filter set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter set');
        $asset = new Css('css/docs.css', true, false);

        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - attributes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - attributes');
        $asset = new Css('css/docs.css');

        $expected = [];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - attributes set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - attributes set');
        $asset = new Css('css/docs.css', true, true, ['data' => 'phalcon']);

        $expected = ['data' => 'phalcon'];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }
}
