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

namespace Phalcon\Test\Unit\Assets\Inline;

use Phalcon\Assets\Inline;
use UnitTester;

class GetFilterCest
{
    /**
     * Tests Phalcon\Assets\Inline :: getFilter() - css
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetFilterCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getFilter() - css');

        $asset = new Inline(
            'css',
            'p {color: #000099}'
        );

        $I->assertTrue(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline :: getFilter() - js
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetFilterJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getFilter() - js');

        $asset = new Inline(
            'js',
            '<script>alert("Hello");</script>'
        );

        $I->assertTrue(
            $asset->getFilter()
        );
    }
}
