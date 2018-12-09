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

namespace Phalcon\Test\Unit\Assets\Resource\Css;

use UnitTester;

/**
 * Class GetTargetPathCest
 *
 * @package Phalcon\Test\Unit\Assets\Resource\Css
 */
class GetTargetPathCest
{
    /**
     * Tests Phalcon\Assets\Resource\Css :: getTargetPath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsResourceCssGetTargetPath(UnitTester $I)
    {
        $I->wantToTest("Assets\Resource\Css - getTargetPath()");
        $I->skipTest("Need implementation");
    }
}
