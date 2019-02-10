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

namespace Phalcon\Test\Unit\Assets\Inline\Js;

use UnitTester;

/**
 * Class GetFilterCest
 */
class GetFilterCest
{
    /**
     * Tests Phalcon\Assets\Inline\Js :: getFilter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function assetsInlineJsGetFilter(UnitTester $I)
    {
        $I->wantToTest('Assets\Inline\Js - getFilter()');
        $I->skipTest('Need implementation');
    }
}
