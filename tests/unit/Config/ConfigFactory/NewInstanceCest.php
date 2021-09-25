<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Config\ConfigFactory;

use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\Adapter\Json;
use Phalcon\Config\Adapter\Php;
use Phalcon\Config\Adapter\Yaml;
use Phalcon\Config\ConfigFactory;
use UnitTester;

use function dataDir;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Logger\LoggerFactory :: newInstance()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-03
     */
    public function configFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Config\ConfigFactory - newInstance()');

        $factory = new ConfigFactory();
        $config  = $factory->newInstance(
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
