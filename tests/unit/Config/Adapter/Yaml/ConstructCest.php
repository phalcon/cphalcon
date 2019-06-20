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

namespace Phalcon\Test\Unit\Config\Adapter\Yaml;

use Phalcon\Config\Adapter\Yaml;
use Phalcon\Config\Exception;
use Phalcon\Test\Fixtures\Traits\ConfigTrait;
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
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configAdapterYamlConstruct(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Yaml - construct');

        $this->checkConstruct($I, 'Yaml');
    }

    /**
     * Tests Phalcon\Config\Adapter\Yaml :: __construct() - callbacks
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
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

        $I->assertEquals(
            PATH_DATA . '/app/controllers/',
            $config->application->controllersDir
        );

        $I->assertEquals(
            '9f7030891b235f3e06c4bff74ae9dc1b9b59d4f2e4e6fd94eeb2b91caee5d223',
            $config->database->password
        );
    }
}
