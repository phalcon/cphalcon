<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Config;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class ConstructCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configConstruct(UnitTester $I)
    {
        $I->wantToTest('Config - construct');
        $this->checkOffsetGet($I);
    }
}
