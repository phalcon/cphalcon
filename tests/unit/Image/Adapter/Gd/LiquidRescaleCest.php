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

namespace Phalcon\Tests\Unit\Image\Adapter\Gd;

use Phalcon\Tests\Fixtures\Traits\GdTrait;
use UnitTester;

class LiquidRescaleCest
{
    use GdTrait;

    /**
     * Tests Phalcon\Image\Adapter\Gd :: liquidRescale()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function imageAdapterGdLiquidRescale(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - liquidRescale()');

        $I->skipTest('Need implementation on GD adapter first');
    }
}
