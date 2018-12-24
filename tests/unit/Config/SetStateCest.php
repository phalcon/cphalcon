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
 * Class SetStateCest
 */
class SetStateCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config :: __set_state()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configSetState(UnitTester $I)
    {
        $I->wantToTest("Config - __set_state()");
        $config = $this->getConfig();

        $expected = $this->getSetState();
        $actual   = $config;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Sets the state on a config object to check __set_state
     *
     * @return Config
     */
    private function getSetState(): Config
    {
        return Config::__set_state(
            [
                'phalcon'     => Config::__set_state(
                    [
                        'baseuri' => '/phalcon/',
                    ]
                ),
                'models'      => Config::__set_state(
                    [
                        'metadata' => 'memory',
                    ]
                ),
                'database'    => Config::__set_state(
                    [
                        'adapter'  => 'mysql',
                        'host'     => 'localhost',
                        'username' => 'user',
                        'password' => 'passwd',
                        'name'     => 'demo',
                    ]
                ),
                'test'        => Config::__set_state(
                    [
                        'parent' => Config::__set_state(
                            [
                                'property'  => 1,
                                'property2' => 'yeah',
                            ]
                        ),
                    ]
                ),
                'issue-12725' => Config::__set_state(
                    [
                        'channel' => Config::__set_state(
                            [
                                'handlers' => Config::__set_state(
                                    [
                                        0 => Config::__set_state(
                                            [
                                                'name'           => 'stream',
                                                'level'          => 'debug',
                                                'fingersCrossed' => 'info',
                                                'filename'       => 'channel.log',
                                            ]
                                        ),
                                        1 => Config::__set_state(
                                            [
                                                'name'           => 'redis',
                                                'level'          => 'debug',
                                                'fingersCrossed' => 'info',
                                            ]
                                        ),
                                    ]
                                ),
                            ]
                        ),
                    ]
                ),
            ]
        );
    }
}
