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
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Fixtures\Traits\SessionTrait;

use function cacheDir;
use function uniqid;

class DestroyCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Stream :: destroy()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionAdapterStreamDestroy(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - destroy()');

        $adapter = $this->newService('sessionStream');

        /**
         * Create a file in the session folder
         */
        $I->writeToFile(
            cacheDir('sessions/test1'),
            uniqid()
        );

        $I->assertTrue(
            $adapter->destroy('test1')
        );

        $I->amInPath(
            cacheDir('sessions')
        );

        $I->dontSeeFileFound('test1');
    }
}
