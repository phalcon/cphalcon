<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Assets\Asset\Js;

use Phalcon\Assets\Asset\Js;
use UnitTester;

use function dataDir;
use function file_get_contents;

/**
 * Class GetContentCest
 *
 * @package Phalcon\Tests\Unit\Assets\Asset\Js
 */
class GetContentCest
{
    /**
     * Tests Phalcon\Assets\Asset\Js :: getContent()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsAssetJsGetContent(UnitTester $I)
    {
        $I->wantToTest('Assets\Asset\Js - getContent()');

        if (PHP_OS_FAMILY === 'Windows') {
            $I->markTestSkipped('Need to fix Windows new lines...');
        }

        $asset = new Js('assets/assets/signup.js');

        $expected = file_get_contents(dataDir('assets/assets/signup.js'));
        $actual   = $asset->getContent(dataDir());
        $I->assertEquals($expected, $actual);
    }
}
