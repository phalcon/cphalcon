<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Annotations;

use Phalcon\Annotations\Adapter\Apc;
use Phalcon\Annotations\Factory;
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
        /** @var Apc $annotations */
        $options = $this->config->annotations;
        $annotations = Factory::load($options);
        $I->assertInstanceOf(Apc::class, $annotations);
    }

    /**
     * Test factory using array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function testArrayFactory(UnitTester $I)
    {
        /** @var Apc $annotations */
        $options = $this->arrayConfig["annotations"];
        $annotations = Factory::load($options);
        $I->assertInstanceOf(Apc::class, $annotations);
    }
}
