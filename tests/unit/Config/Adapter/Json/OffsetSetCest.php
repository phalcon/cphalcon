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

namespace Phalcon\Test\Unit\Config\Adapter\Json;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class OffsetSetCest
{
    use ConfigTrait;

    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('json');
    }

    /**
     * Tests Phalcon\Config\Adapter\Json :: offsetSet()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterJsonOffsetSet(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Json - offsetSet()');
        $this->checkOffsetSet($I, 'Json');
    }
}
