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

namespace Phalcon\Test\Unit\Assets\Inline\Css;

use Phalcon\Assets\Inline\Css;
use UnitTester;

class GetTypeCest
{
    /**
     * Tests Phalcon\Assets\Inline :: getType()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsInlineGetType(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline - getType()');

        $asset = new Css(
            'p {color: #000099}'
        );

        $I->assertEquals(
            'css',
            $asset->getType()
        );
    }
}
