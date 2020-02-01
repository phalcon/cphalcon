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

namespace Phalcon\Test\Unit\Config\Config;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class OffsetUnsetCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config :: offsetUnset()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-19
     */
    public function configOffsetUnset(UnitTester $I)
    {
        $I->wantToTest('Config - offsetUnset()');
        $this->checkOffsetUnset($I);
    }
}
