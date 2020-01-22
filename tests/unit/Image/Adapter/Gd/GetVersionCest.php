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

namespace Phalcon\Test\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use Phalcon\Test\Fixtures\Traits\GdTrait;
use UnitTester;

class GetVersionCest
{
    use GdTrait;

    /**
     * Unit Tests Phalcon\Image\Adapter\Gd :: getVersion()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function imageAdapterGdGetVersion(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getVersion()');

        $gd = new Gd(dataDir('assets/images/phalconphp.jpg'));

        $I->assertRegExp(
            '/^2.[0-9].[0-9]/',
            $gd->getVersion()
        );
    }
}
