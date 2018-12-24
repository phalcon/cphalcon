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

namespace Phalcon\Test\Unit\Assets\Asset;

use Phalcon\Assets\Asset;
use Phalcon\Test\Fixtures\Traits\AssetsTrait;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use AssetsTrait;

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css local');
        $asset = new Asset('css', 'css/docs.css');

        $actual = $asset->getLocal();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css remote');
        $asset = new Asset('css', 'css/docs.css', false);
        // ( bool filter = true, array attributes = [])


        $actual = $asset->getLocal();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css filter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructCssFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css filter');
        $asset = new Asset('css', 'css/docs.css');

        $actual = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css filter set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructCssFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css filter set');
        $asset = new Asset('css', 'css/docs.css', true, false);

        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css attributes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructCssAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css attributes');
        $asset = new Asset('css', 'css/docs.css');

        $expected = [];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css attributes set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructCssAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css attributes set');
        $asset = new Asset('css', 'css/docs.css', true, true, ['data' => 'phalcon']);

        $expected = ['data' => 'phalcon'];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js local
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js local');
        $asset = new Asset('js', 'js/jquery.js');

        $actual = $asset->getLocal();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js remote
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js remote');
        $asset = new Asset('js', 'js/jquery.js', false);
        // ( bool filter = true, array attributes = [])


        $actual = $asset->getLocal();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js filter
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructJsFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js filter');
        $asset = new Asset('js', 'js/jquery.js');

        $actual = $asset->getFilter();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js filter set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructJsFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js filter set');
        $asset = new Asset('js', 'js/jquery.js', true, false);

        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js attributes
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructJsAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js attributes');
        $asset = new Asset('js', 'js/jquery.js');

        $expected = [];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js attributes set
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructJsAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js attributes set');
        $asset = new Asset('js', 'js/jquery.js', true, true, ['data' => 'phalcon']);

        $expected = ['data' => 'phalcon'];
        $actual   = $asset->getAttributes();
        $I->assertEquals($expected, $actual);
    }
}
