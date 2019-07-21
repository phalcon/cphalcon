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

namespace Phalcon\Test\Unit\Config\Adapter\Ini;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class GetCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Ini :: get()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configAdapterIniGet(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Ini - get()');
        $this->checkGet($I, 'Ini');
    }
}
