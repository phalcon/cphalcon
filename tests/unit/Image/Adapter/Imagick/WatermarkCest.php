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
 * Class WatermarkCest
 */
class WatermarkCest
{
    /**
     * Tests Phalcon\Image\Adapter\Imagick :: watermark()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function imageAdapterImagickWatermark(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - watermark()');
        $I->skipTest('Need implementation');
    }
}
