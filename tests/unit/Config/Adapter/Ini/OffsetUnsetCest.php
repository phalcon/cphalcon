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
 * Class OffsetUnsetCest
 */
class OffsetUnsetCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Ini :: offsetUnset()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configAdapterIniOffsetUnset(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Ini - offsetUnset()');
        $this->checkOffsetUnset($I, 'Ini');
    }
}
