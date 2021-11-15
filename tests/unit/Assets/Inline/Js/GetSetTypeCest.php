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

namespace Phalcon\Tests\Unit\Assets\Inline\Js;

use Phalcon\Assets\Inline\Js;
use UnitTester;

/**
 * Class SetTypeCest
 *
 * @package Phalcon\Tests\Unit\Assets\Inline\Js
 */
class GetSetTypeCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: getType()/setType()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineJsGetSetType(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - getType()/setType()');

        $asset   = new Js('<script>alert("Hello");</script>');
        $newType = 'js';

        $asset->setType($newType);
        $actual = $asset->getType();

        $I->assertEquals($newType, $actual);
    }
}
