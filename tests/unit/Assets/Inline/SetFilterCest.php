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

class SetFilterCest
{
    /**
     * Tests Phalcon\Assets\Inline :: setFilter()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineSetFilterCss(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - setFilter() - css');

        $asset = new Inline(
            'css',
            'p {color: #000099}'
        );

        $I->assertTrue(
            $asset->getFilter()
        );

        $asset->setFilter(false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }

    /**
     * Tests Phalcon\Assets\Inline :: setFilter() - js
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineSetFilterJs(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - setFilter() - js');

        $asset = new Inline(
            'js',
            '<script>alert("Hello");</script>'
        );

        $I->assertTrue(
            $asset->getFilter()
        );

        $asset->setFilter(false);

        $I->assertFalse(
            $asset->getFilter()
        );
    }
}
