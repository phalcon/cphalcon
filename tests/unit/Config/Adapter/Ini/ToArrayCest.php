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

/**
 * Class ToArrayCest
 */
class ToArrayCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Ini :: toArray()
     *
     * @param UnitTester $I
     *
     * @author kjdev
     * @since  2013-07-18
     */
    public function configAdapterIniToArray(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Ini - toArray()');
        $this->checkToArray($I, 'Ini');
    }
}
