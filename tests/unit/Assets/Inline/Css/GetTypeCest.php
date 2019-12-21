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

class GetTypeCest
{
    /**
     * Tests Phalcon\Assets\Inline\Css :: getType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineCssGetType(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - getType()');

        $asset = new Css(
            'p {color: #000099}'
        );

        $I->assertEquals(
            'css',
            $asset->getType()
        );
    }
}
