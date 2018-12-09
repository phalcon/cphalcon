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
 * Class SetSourcePathCest
 *
 * @package Phalcon\Test\Unit\Assets\Resource\Css
 */
class SetSourcePathCest
{
    /**
     * Tests Phalcon\Assets\Resource\Css :: setSourcePath()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function assetsResourceCssSetSourcePath(UnitTester $I)
    {
        $I->wantToTest("Assets\Resource\Css - setSourcePath()");
        $I->skipTest("Need implementation");
    }
}
