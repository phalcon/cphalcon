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

class GetSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getSourcePath() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetSourcePathCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getSourcePath() - css local');

        $asset = new Asset('css', 'css/docs.css');

        $expected = '/phalcon/path';

        $asset->setSourcePath($expected);

        $I->assertEquals(
            $expected,
            $asset->getSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getSourcePath() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetSourcePathCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getSourcePath() - css remote');

        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css', false);

        $expected = '/phalcon/path';

        $asset->setSourcePath($expected);

        $I->assertEquals(
            $expected,
            $asset->getSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getSourcePath() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetSourcePathJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getSourcePath() - js local');

        $asset = new Asset('js', 'js/jquery.js');

        $expected = '/phalcon/path';

        $asset->setSourcePath($expected);

        $I->assertEquals(
            $expected,
            $asset->getSourcePath()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getSourcePath() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetSourcePathJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getSourcePath() - js remote');

        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js', false);

        $expected = '/phalcon/path';

        $asset->setSourcePath($expected);

        $I->assertEquals(
            $expected,
            $asset->getSourcePath()
        );
    }
}
