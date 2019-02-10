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

namespace Phalcon\Test\Unit\Image\Adapter\Imagick;

use UnitTester;

/**
 * Class CheckCest
 */
class CheckCest
{
    /**
     * Tests Phalcon\Image\Adapter\Imagick :: check()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function imageAdapterImagickCheck(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - check()');
        $I->skipTest('Need implementation');
    }
}
