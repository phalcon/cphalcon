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

class CountCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Config :: count()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-21
     */
    public function configCount(UnitTester $I)
    {
        $I->wantToTest('Config - count()');

        $this->checkCount($I);
    }
}
