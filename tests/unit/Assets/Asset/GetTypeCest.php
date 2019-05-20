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

class GetTypeCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getType() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTypeCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getType() - css local');

        $asset = new Asset('css', 'css/docs.css');

        $I->assertEquals(
            'css',
            $asset->getType()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getType() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTypeCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getType() - css remote');

        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

        $I->assertEquals(
            'css',
            $asset->getType()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getType() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTypeJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getType() - js local');

        $asset = new Asset('js', 'js/jquery.js');

        $I->assertEquals(
            'js',
            $asset->getType()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: getType() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetGetTypeJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getType() - js remote');

        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $I->assertEquals(
            'js',
            $asset->getType()
        );
    }
}
