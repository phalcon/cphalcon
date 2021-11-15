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

/**
 * Class GetSetAttributesCest
 *
 * @package Phalcon\Tests\Unit\Assets\Inline\Css
 */
class GetSetAttributesCest
{
    /**
     * Tests Phalcon\Assets\Inline\Css :: getAttributes()/setAttributes()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineCssGetSetAttributes(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Css - getAttributes()/setAttributes()');

        $asset    = new Css('p {color: #000099}');
        $expected = [
            'data-key' => 'phalcon',
        ];

        $asset->setAttributes($expected);

        $I->assertEquals(
            $expected,
            $asset->getAttributes()
        );
    }
}
