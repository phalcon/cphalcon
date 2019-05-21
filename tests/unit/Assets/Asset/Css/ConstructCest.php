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
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - local');

        $asset = new Css('css/docs.css');

        $I->assertTrue(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - remote');

        $asset = new Css('css/docs.css', false);

        $I->assertFalse(
            $asset->getLocal()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - filter
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter');

        $asset = new Css('css/docs.css');

        $I->assertTrue(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - filter set
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructFilterSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - filter set');

        $asset = new Css('css/docs.css', true, false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - attributes
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - attributes');

        $asset = new Css('css/docs.css');

        $I->assertEquals(
            [],
            $asset->getAttributes()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: __construct() - attributes set
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetConstructAttributesSet(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - __construct() - attributes set');

        $attributes = [
            'data' => 'phalcon',
        ];

        $asset = new Css(
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
}
