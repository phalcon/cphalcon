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

namespace Phalcon\Tests\Unit\Config\Adapter\Yaml;

use Codeception\Stub;
use Phalcon\Config\Adapter\Yaml;
use Phalcon\Config\Exception;
use Phalcon\Tests\Fixtures\Traits\ConfigTrait;
use UnitTester;

use function dataDir;

class ConstructCest
{
    use ConfigTrait;

    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('yaml');
    }

    /**
     * Tests Phalcon\Config\Adapter\Yaml :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-21
     */
    public function configAdapterYamlConstruct(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Yaml - construct');

        $this->checkConstruct($I, 'Yaml');
    }

    /**
     * Tests Phalcon\Config\Adapter\Yaml :: __construct() - callbacks
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-21
     */
    public function configAdapterYamlConstructCallbacks(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Yaml - construct - callbacks');

        $config = new Yaml(
            dataDir('assets/config/callbacks.yml'),
            [
                '!decrypt' => function ($value) {
                    return hash('sha256', $value);
                },
                '!approot' => function ($value) {
                    return PATH_DATA . $value;
                },
            ]
        );

        $expected = PATH_DATA . '/app/controllers/';
        $actual   = $config->application->controllersDir;
        $I->assertEquals($expected, $actual);

        $expected = '9f7030891b235f3e06c4bff74ae9dc1b9b59d4f2e4e6fd94eeb2b91caee5d223';
        $actual   = $config->database->password;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Config\Adapter\Yaml :: __construct() - exceptions
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-21
     */
    public function configAdapterYamlConstructExceptions(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Yaml - construct - exceptions');

        $filePath = dataDir('assets/config/callbacks.yml');

        $I->expectThrowable(
            new Exception(
                'Yaml extension is not loaded'
            ),
            function () use ($filePath) {
                $mock = Stub::make(
                    Yaml::class,
                    [
                        'phpExtensionLoaded' => false,
                    ]
                );

                $mock->__construct($filePath);
            }
        );

        $I->expectThrowable(
            new Exception(
                'Configuration file ' . basename($filePath) . ' can\'t be loaded'
            ),
            function () use ($filePath) {
                $mock = Stub::make(
                    Yaml::class,
                    [
                        'phpYamlParseFile' => false,
                    ]
                );

                $mock->__construct($filePath);
            }
        );
    }
}
