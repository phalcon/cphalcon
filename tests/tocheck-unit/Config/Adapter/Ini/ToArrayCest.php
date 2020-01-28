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

namespace Phalcon\Test\Unit\Config\Adapter\Ini;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class ToArrayCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Ini :: toArray()
     *
     * @author kjdev
     * @since  2013-07-18
     */
    public function configAdapterIniToArray(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Ini - toArray()');

        $this->config['database']['num1'] = false;
        $this->config['database']['num2'] = false;
        $this->config['database']['num3'] = false;
        $this->config['database']['num4'] = true;
        $this->config['database']['num5'] = true;
        $this->config['database']['num6'] = true;
        $this->config['database']['num7'] = null;
        $this->config['database']['num8'] = 123;
        $this->config['database']['num9'] = (float) 123.45;
        $config                           = $this->getConfig('Ini');

        $I->assertEquals(
            $this->config,
            $config->toArray()
        );
    }
}
