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

class SetTypeCest
{
    /**
     * Tests Phalcon\Assets\Asset :: setType() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetTypeCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setType() - css local');

        $asset = new Asset('css', 'css/docs.css');

        $type = 'js';

        $asset->setType($type);

        $I->assertEquals(
            $type,
            $asset->getType()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setType() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetTypeCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setType() - css remote');

        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

        $type = 'js';

        $asset->setType($type);

        $I->assertEquals(
            $type,
            $asset->getType()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setType() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetTypeJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setType() - js local');

        $asset = new Asset('js', 'js/jquery.js');

        $type = 'css';

        $asset->setType($type);

        $I->assertEquals(
            $type,
            $asset->getType()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setType() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetTypeJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setType() - js remote');

        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $type = 'css';

        $asset->setType($type);

        $I->assertEquals(
            $type,
            $asset->getType()
        );
    }
}
