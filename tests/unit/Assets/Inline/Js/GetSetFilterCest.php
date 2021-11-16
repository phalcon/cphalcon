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
 * Class GetSetFilterCest
 *
 * @package Phalcon\Tests\Unit\Assets\Inline\Js
 */
class GetSetFilterCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: getFilter()/setFilter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function assetsInlineJsGetSetFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - getFilter()/setFilter()');

        $asset  = new Js('<script>alert("Hello");</script>');
        $actual = $asset->getFilter();
        $I->assertTrue($actual);

        $asset->setFilter(false);

        $actual = $asset->getFilter();
        $I->assertFalse($actual);
    }
}
