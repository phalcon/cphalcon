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

namespace Phalcon\Test\Unit\Config\ConfigFactory;

use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\Adapter\Json;
use Phalcon\Config\Adapter\Php;
use Phalcon\Config\Adapter\Yaml;
use Phalcon\Config\ConfigFactory;
use UnitTester;
use function dataDir;
use function var_dump;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Logger\LoggerFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-03
     */
    public function configFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Config\ConfigFactory - newInstance()');

        $factory = new ConfigFactory();
        $config = $factory->newInstance(
            'ini',
            dataDir('assets/config/config.ini')
        );

        $I->assertInstanceOf(Ini::class, $config);

        $config = $factory->newInstance(
            'json',
            dataDir('assets/config/config.json')
        );

        $I->assertInstanceOf(Json::class, $config);

        $config = $factory->newInstance(
            'php',
            dataDir('assets/config/config.php')
        );

        $I->assertInstanceOf(Php::class, $config);

        $config = $factory->newInstance(
            'yaml',
            dataDir('assets/config/config.yml')
        );

        $I->assertInstanceOf(Yaml::class, $config);
    }
}
