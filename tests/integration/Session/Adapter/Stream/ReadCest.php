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

namespace Phalcon\Tests\Integration\Session\Adapter\Stream;

use Codeception\Stub;
use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use function cacheDir;
use function uniqid;

class ReadCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Stream :: read()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionAdapterStreamRead(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - read()');

        $adapter = $this->newService('sessionStream');

        $value = uniqid();
        $adapter->write('test1', $value);

        $actual = $adapter->read('test1');
        $I->assertEquals($value, $actual);

        $I->safeDeleteFile(cacheDir('sessions/test1'));
    }

    /**
     * Tests Phalcon\Session\Adapter\Stream :: read() - no data
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionAdapterStreamReadNoData(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - read()');

        $adapter = $this->newService('sessionStream');

        $value = uniqid();
        $adapter->write('test1', $value);

        $mock   = Stub::make(
            $adapter,
            [
                'phpFileGetContents' => false,
            ]
        );
        $actual = $mock->read('test1');
        $I->assertEmpty($actual);

        $I->safeDeleteFile(cacheDir('sessions/test1'));
    }
}
