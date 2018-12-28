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

use Phalcon\Config\Adapter\Ini;
use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Ini :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configAdapterIniConstruct(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Ini - construct');
        $this->checkConstruct($I, 'Ini');
    }

    /**
     * Tests Phalcon\Config\Adapter\Ini :: __construct() - constants
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configAdapterIniConstructConstants(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Ini - construct - constants');

        define('TEST_CONST', 'foo');

        $config = new Ini(dataFolder('assets/config/config-with-constants.ini'), INI_SCANNER_NORMAL);

        $expected = [
            'test'    => 'foo',
            'path'    => 'foo/something/else',
            'section' => [
                'test'   => 'foo',
                'path'   => 'foo/another-thing/somewhere',
                'parent' => [
                    'property'  => 'foo',
                    'property2' => 'foohello',
                ],
            ],
        ];
        $actual   = $config->toArray();
        $I->assertEquals($expected, $actual);
    }
}
