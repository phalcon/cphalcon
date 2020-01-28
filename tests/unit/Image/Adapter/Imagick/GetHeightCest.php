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

namespace Phalcon\Test\Unit\Image\Adapter\Imagick;

use UnitTester;

class GetHeightCest
{
    /**
     * Unit Tests Phalcon\Image\Adapter\Imagick :: getHeight()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function imageAdapterImagickGetHeight(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Imagick - getHeight()');

        $I->skipTest('Need implementation');
    }
}
