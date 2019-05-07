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

class GetContentCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getContent()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetContent(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getContent()');
        $asset = new Js('assets/assets/signup.js');

        $expected = file_get_contents(dataDir('assets/assets/signup.js'));
        $actual   = $asset->getContent(dataDir());
        $I->assertEquals($expected, $actual);
    }
}
