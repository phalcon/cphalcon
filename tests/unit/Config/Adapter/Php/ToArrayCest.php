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

namespace Phalcon\Test\Unit\Config\Adapter\Php;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class ToArrayCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Php :: toArray()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterPhpToArray(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Php - toArray()');
        $this->checkToArray($I, 'Php');
    }
}
