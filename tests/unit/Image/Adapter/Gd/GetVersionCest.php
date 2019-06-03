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

namespace Phalcon\Test\Unit\Image\Adapter\Gd;

use Phalcon\Image\Adapter\Gd;
use UnitTester;

class GetVersionCest
{
    /**
     * Unit Tests Phalcon\Image\Adapter\Gd :: getVersion()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function imageAdapterGdGetVersion(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter\Gd - getVersion()');

        $gd = new Gd(dataDir('assets/images/phalconphp.jpg'));

        $I->assertEquals(
            "2.0.35",
            $gd->getVersion()
        );
    }
}
