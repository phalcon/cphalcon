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
use UnitTester;

class SetTargetUriCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: setTargetUri() - js local
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetTargetUriLocal(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setTargetUri() - js local');

        $asset = new Js('js/jquery.js');

        $targetUri = '/new/path';

        $asset->setTargetUri($targetUri);

        $I->assertEquals(
            $targetUri,
            $asset->getTargetUri()
        );
    }

    /**
     * Tests Phalcon\Assets\Asset\Js :: setTargetUri() - js remote
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsSetTargetUriRemote(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - setTargetUri() - js remote');

        $asset = new Js('https://phalcon.ld/js/jquery.js');

        $targetUri = '/new/path';

        $asset->setTargetUri($targetUri);

        $I->assertEquals(
            $targetUri,
            $asset->getTargetUri()
        );
    }
}
