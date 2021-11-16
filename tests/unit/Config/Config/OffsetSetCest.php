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

namespace Phalcon\Tests\Unit\Config\Config;

use Phalcon\Tests\Fixtures\Traits\ConfigTrait;
use UnitTester;

class OffsetSetCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Config :: offsetSet()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-21
     */
    public function configOffsetSet(UnitTester $I)
    {
        $I->wantToTest('Config - offsetSet()');

        $this->checkOffsetSet($I);
    }
}
