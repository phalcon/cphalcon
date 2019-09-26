<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Session\Adapter\Stream;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;
use Phalcon\Session\Manager;
use Phalcon\Session\Adapter\Stream;

class OpenCest
{
    use DiTrait;
    use SessionTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();
    }

    /**
     * Tests Phalcon\Session\Adapter\Stream :: open()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionAdapterStreamOpen(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - open()');

        $adapter = $this->getSessionStream();

        $I->assertTrue(
            $adapter->open(
                cacheDir('sessions'),
                'test1'
            )
        );
    }

    /**
     * Tests Phalcon\Session\Adapter\Stream :: open()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-08-06
     */
    public function issue14265(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - open() for issue 14265');
        $session = new Manager();
        $stream = new Stream(getOptionsSessionStream());
        $session->setAdapter($stream);
        $I->assertTrue(
            $session->start()
        );
        $value   = uniqid();
        $stream->write('test1', $value);
        $I->amInPath(cacheDir('sessions'));
        $I->seeFileFound('test1');
        $I->seeInThisFile($value);
        $I->safeDeleteFile(cacheDir('sessions/test1'));
    }
}
