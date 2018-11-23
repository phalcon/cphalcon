<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Logger;

use Phalcon\Logger\Adapter\File;
use Phalcon\Logger\Factory;
use Phalcon\Test\Fixtures\Traits\FactoryTrait;
use Phalcon\Test\Unit\Factory\Helper\FactoryBase;
use UnitTester;

class FactoryCest
{
    use FactoryTrait;

    public function _before(UnitTester $I)
    {
        $this->init();
    }

    /**
     * Test factory using Phalcon\Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testConfigFactory(UnitTester $I)
    {
        $options = $this->config->logger;
        $this->runTests($I, $options);
    }

    /**
     * Runs the tests based on different configurations
     *
     * @param UnitTester   $I
     * @param Config|array $options
     */
    private function runTests(UnitTester $I, $options)
    {
        /** @var File $logger */
        $logger = Factory::load($options);

        $class  = File::class;
        $actual = $logger;
        $I->assertInstanceOf($class, $actual);

        $expected = $options["name"];
        $actual   = $logger->getPath();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Test factory using array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testArrayFactory(UnitTester $I)
    {
        $options = $this->arrayConfig["logger"];
        $this->runTests($I, $options);
    }
}
