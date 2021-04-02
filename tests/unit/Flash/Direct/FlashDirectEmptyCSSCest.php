<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Flash\Direct;

use Phalcon\Test\Unit\Flash\Direct\Helper\FlashBase;
use UnitTester;

class FlashDirectEmptyCSSCest extends FlashBase
{
    /**
     * Executed before each test
     *
     * @param  UnitTester $I
     * @return void
     */
    public function _before(UnitTester $I): void
    {
        parent::_before($I);

        $this->setClasses([]);
    }
}
