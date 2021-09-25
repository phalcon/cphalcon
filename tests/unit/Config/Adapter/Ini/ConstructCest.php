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

namespace Phalcon\Tests\Unit\Config\Adapter\Ini;

use Phalcon\Config\Adapter\Ini;
use Phalcon\Tests\Fixtures\Traits\ConfigTrait;
use UnitTester;

use function dataDir;

class ConstructCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Ini :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterIniConstruct(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Ini - construct');

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

        $this->compareConfig($I, $this->config, $config);
    }


    /**
     * Tests Phalcon\Config\Adapter\Ini :: __construct() - constants
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterIniConstructConstants(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Ini - construct - constants');

        define('TEST_CONST', 'foo');

        $config = new Ini(
            dataDir('assets/config/config-with-constants.ini'),
            INI_SCANNER_NORMAL
        );

        $expected = [
            'test'    => 'foo',
            'path'    => 'foo/something/else',
            'section' => [
                'test'      => 'foo',
                'path'      => 'foo/another-thing/somewhere',
                'parent'    => [
                    'property'  => 'foo',
                    'property2' => 'foohello',
                ],
                'testArray' => [
                    'value1',
                    'value2',
                ],
            ],

        ];

        $I->assertEquals(
            $expected,
            $config->toArray()
        );
    }
}
