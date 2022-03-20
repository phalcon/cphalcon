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

use IntegrationTester;
use Phalcon\Session\Manager;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class OpenCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Stream :: open()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionAdapterStreamOpen(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - open()');

        $adapter = $this->newService('sessionStream');

        $actual = $adapter->open(cacheDir('sessions'), 'test1');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Session\Adapter\Stream :: open()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function issue14265(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - open() for issue 14265');
        $session = new Manager();
        $stream  = $this->newService('sessionStream');
        $session->setAdapter($stream);

        $actual = $session->start();
        $I->assertTrue($actual);

        $value = uniqid();
        $stream->write('test1', $value);
        $I->amInPath(cacheDir('sessions'));
        $I->seeFileFound('test1');
        $I->seeInThisFile($value);
        $I->safeDeleteFile(cacheDir('sessions/test1'));
    }
}
