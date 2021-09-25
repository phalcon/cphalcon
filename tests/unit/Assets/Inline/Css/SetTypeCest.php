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

namespace Phalcon\Tests\Unit\Assets\Inline\Css;

use Phalcon\Assets\Inline\Css;
use UnitTester;

class SetTypeCest
{
    /**
     * Tests Phalcon\Assets\Inline\Css :: setType()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function assetsInlineCssSetType(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - setType()');

        $asset = new Css(
            'p {color: #000099}'
        );

        $newType = 'js';

        $asset->setType($newType);

        $I->assertEquals(
            $newType,
            $asset->getType()
        );
    }
}
