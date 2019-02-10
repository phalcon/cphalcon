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

namespace Phalcon\Test\Unit\Image\Adapter;

use UnitTester;

/**
 * Class FlipCest
 */
class FlipCest
{
    /**
     * Tests Phalcon\Image\Adapter :: flip()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function imageAdapterFlip(UnitTester $I)
    {
        $I->wantToTest('Image\Adapter - flip()');
        $I->skipTest('Need implementation');
    }
}
