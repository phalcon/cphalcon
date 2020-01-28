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

namespace Phalcon\Test\Unit\Assets\Inline\Css;

use Phalcon\Assets\Inline\Css;
use UnitTester;

class GetAssetKeyCest
{
    /**
     * Tests Phalcon\Assets\Inline\Css :: getAssetKey()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineCssGetAssetKey(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - getAssetKey()');

        $content = 'p {color: #000099}';

        $asset = new Css($content);

        $expected = md5(
            'css:' . $content
        );

        $I->assertEquals(
            $expected,
            $asset->getAssetKey()
        );
    }
}
