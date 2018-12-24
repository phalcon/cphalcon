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

namespace Phalcon\Test\Unit\Config\Adapter\Json;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

/**
 * Class CountCest
 */
class CountCest
{
    use ConfigTrait;

    /**
     * @param UnitTester $I
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('json');
    }

    /**
     * Tests Phalcon\Config\Adapter\Json :: count()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configAdapterJsonCount(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Json - count()');
        $this->checkCount($I, 'Json');
    }
}
