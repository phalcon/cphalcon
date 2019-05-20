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
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css local');

        $asset = new Asset('css', 'css/docs.css');

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css remote');

        $asset = new Asset('css', 'css/docs.css', false);

        $I->assertFalse(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css filter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructCssFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css filter');

        $asset = new Asset('css', 'css/docs.css');

        $I->assertTrue(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css filter set
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructCssFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css filter set');

        $asset = new Asset('css', 'css/docs.css', true, false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css attributes
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructCssAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css attributes');

        $asset = new Asset('css', 'css/docs.css');

        $I->assertEquals(
            [],
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - css attributes set
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructCssAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - css attributes set');

        $attributes = [
            'data' => 'phalcon',
        ];

        $asset = new Asset(
            'css',
            'css/docs.css',
            true,
            true,
            $attributes
        );

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js local');

        $asset = new Asset('js', 'js/jquery.js');

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js remote');

        $asset = new Asset('js', 'js/jquery.js', false);

        $I->assertFalse(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js filter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructJsFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js filter');

        $asset = new Asset('js', 'js/jquery.js');

        $I->assertTrue(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js filter set
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructJsFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js filter set');

        $asset = new Asset('js', 'js/jquery.js', true, false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js attributes
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructJsAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js attributes');

        $asset = new Asset('js', 'js/jquery.js');

        $I->assertEquals(
            [],
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: __construct() - js attributes set
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructJsAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - js attributes set');

        $attributes = [
            'data' => 'phalcon',
        ];

        $asset = new Asset(
            'js',
            'js/jquery.js',
            true,
            true,
            $attributes
        );

        $I->assertEquals(
            $attributes,
            $asset->getAttributes()
        );
    }
}
