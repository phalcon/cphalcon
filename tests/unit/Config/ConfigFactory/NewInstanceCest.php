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

use Codeception\Example;
use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\Adapter\Json;
use Phalcon\Config\Adapter\Php;
use Phalcon\Config\Adapter\Yaml;
use Phalcon\Config\ConfigFactory;
use Phalcon\Config\Exception;
use UnitTester;

use function dataDir;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Logger\LoggerFactory :: newInstance()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-10-18
     */
    public function configFactoryNewInstance(UnitTester $I, Example $example)
    {
        $I->wantToTest(
            'Config\ConfigFactory - newInstance() ' . $example['label']
        );

        $factory = new ConfigFactory();
        $config  = $factory->newInstance(
            $example['service'],
            $example['options']
        );

        $expected = $example['expected'];
        $I->assertInstanceOf($expected, $config);
    }

    /**
     * Tests Phalcon\Config\ConfigFactory :: newInstance() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function configFactoryNewInstanceException(UnitTester $I)
    {
        $I->wantToTest('Config\ConfigFactory - newInstance() - exception');

        $I->expectThrowable(
            new Exception("Service unknown is not registered"),
            function () {
                $factory = new ConfigFactory();
                $adapter = $factory->newInstance(
                    "unknown",
                    "config.php"
                );
            }
        );
    }

    /**
     * @return array<array-key, array<string, string>>
     */
    private function getExamples(): array
    {
        return [
            [
                'label'    => 'ini',
                'service'  => 'ini',
                'options'  => dataDir('assets/config/config.ini'),
                'expected' => Ini::class,
            ],
            [
                'label'    => 'json',
                'service'  => 'json',
                'options'  => dataDir('assets/config/config.json'),
                'expected' => Json::class,
            ],
            [
                'label'    => 'php',
                'service'  => 'php',
                'options'  => dataDir('assets/config/config.php'),
                'expected' => Php::class,
            ],
            [
                'label'    => 'yaml',
                'service'  => 'yaml',
                'options'  => dataDir('assets/config/config.yml'),
                'expected' => Yaml::class,
            ],
        ];
    }
}
