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

namespace Phalcon\Test\Unit\Config;

use Phalcon\Config;
use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

/**
 * Class MergeCest
 */
class MergeCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config :: merge()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-15
     */
    public function configMergeConfig(UnitTester $I)
    {
        $I->wantToTest("Config - merge() - Config");
        $config = $this->getConfig();

        $expected = $this->getMergedByConfig();
        $actual   = $config;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Config :: merge()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-15
     */
    public function configMergeArr(UnitTester $I)
    {
        $I->wantToTest("Config - merge() - array");
        $config = $this->getConfig();

        $expected = $this->getMergedByArray();
        $actual   = $config;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Merges the reference config object into an empty config object.
     *
     * @return Config
     */
    private function getMergedByConfig(): Config
    {
        $config = new Config();
        $config->merge($this->getConfig());

        return $config;
    }

    /**
     * Merges the reference config array data into an empty config object.
     *
     * @return Config
     */
    private function getMergedByArray(): Config
    {
        $config = new Config();
        $config->merge(require dataFolder('assets/config/config.php'));

        return $config;
    }
}
