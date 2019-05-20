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

class SetTargetUriCest
{
    /**
     * Tests Phalcon\Assets\Asset :: setTargetUri() - css local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetTargetUriCssLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setTargetUri() - css local');

        $asset = new Asset('css', 'css/docs.css');

        $targetUri = '/new/path';

        $asset->setTargetUri($targetUri);

        $I->assertEquals(
            $targetUri,
            $asset->getTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setTargetUri() - css remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetTargetUriCssRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setTargetUri() - css remote');

        $asset = new Asset('css', 'https://phalcon.ld/css/docs.css');

        $targetUri = '/new/path';

        $asset->setTargetUri($targetUri);

        $I->assertEquals(
            $targetUri,
            $asset->getTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setTargetUri() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetTargetUriJsLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setTargetUri() - js local');

        $asset = new Asset('js', 'js/jquery.js');

        $targetUri = '/new/path';

        $asset->setTargetUri($targetUri);

        $I->assertEquals(
            $targetUri,
            $asset->getTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset :: setTargetUri() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetSetTargetUriJsRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setTargetUri() - js remote');

        $asset = new Asset('js', 'https://phalcon.ld/js/jquery.js');

        $targetUri = '/new/path';

        $asset->setTargetUri($targetUri);

        $I->assertEquals(
            $targetUri,
            $asset->getTargetUri()
        );
    }
}
