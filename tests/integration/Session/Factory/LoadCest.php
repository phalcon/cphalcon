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

namespace Phalcon\Test\Integration\Session\Factory;

use IntegrationTester;
use Phalcon\Session\Adapter\Files;
use Phalcon\Session\Factory;
use Phalcon\Test\Fixtures\Traits\FactoryTrait;

class LoadCest
{
    use FactoryTrait;

    public function _before(IntegrationTester $I)
    {
        $I->skipTest('CHECKME');

        $this->init();
    }

    /**
     * Tests Phalcon\Session\Factory :: load() - Config
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function sessionFactoryLoadConfig(IntegrationTester $I)
    {
        $I->wantToTest("Session\Factory - load() - Config");

        $options = $this->config->session;
        $data    = $options->toArray();

        $this->runTests($I, $options, $data);
    }

    private function runTests(IntegrationTester $I, $options, array $data)
    {
        /** @var Memcache $session */
        $session = Factory::load($options);

        $I->assertInstanceOf(Files::class, $session);


        $expected = $session->getOptions();

        $actual = array_intersect_assoc(
            $session->getOptions(),
            $data
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Session\Factory :: load() - array
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2017-03-02
     */
    public function sessionFactoryLoadArray(IntegrationTester $I)
    {
        $I->wantToTest("Session\Factory - load() - array");

        $options = $this->arrayConfig['session'];
        $data    = $options;

        $this->runTests($I, $options, $data);
    }
}
