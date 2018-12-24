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

/**
 * Class GetContentCest
 */
class GetContentCest
{
    /**
     * Tests Phalcon\Assets\Asset :: getContent()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsAssetJsGetContent(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset - getContent()');
        $asset = new Js('assets/assets/signup.js');

        $expected = file_get_contents(dataFolder('assets/assets/signup.js'));
        $actual   = $asset->getContent(dataFolder());
        $I->assertEquals($expected, $actual);
    }
}
