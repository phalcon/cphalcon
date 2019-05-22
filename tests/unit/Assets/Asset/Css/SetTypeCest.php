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

class SetTypeCest
{
    /**
     * Tests Phalcon\Assets\Asset\Css :: setType() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssSetTypeLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setType() - css local');

        $asset = new Css('css/docs.css');

        $type = 'js';

        $asset->setType($type);

        $I->assertEquals(
            $type,
            $asset->getType()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Css :: setType() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetCssSetTypeRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setType() - css remote');

        $asset = new Css('https://phalcon.ld/css/docs.css');

        $type = 'js';

        $asset->setType($type);

        $I->assertEquals(
            $type,
            $asset->getType()
        );
    }
}
