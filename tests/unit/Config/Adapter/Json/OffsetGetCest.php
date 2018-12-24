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
 * Class OffsetGetCest
 */
class OffsetGetCest
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
     * Tests Phalcon\Config\Adapter\Json :: offsetGet()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configAdapterJsonOffsetGet(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Json - offsetGet()');
        $this->checkOffsetGet($I, 'Json');
    }
}
